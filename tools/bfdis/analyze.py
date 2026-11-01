#!/usr/bin/env python3
"""Code discovery for Webfoot GBA games (Legacy of Goku II, Buu's Fury; ARM ADS 1.x C++, Thumb + ARM).

Recursive descent with confidence levels. Every trace has a *root* (seed) and a level
(0 = certain ... 6 = guess). Each instruction/pool word remembers its root, so when a
stronger trace collides with code produced by a weaker guess, the guess is evicted.

Knowledge baked in (verified against the ROM, see docs/toolchain.md):
  * ADS switch:   cmp rI,#N ; bhs d ; adr rT,tbl ; [add rT,rI ; ldrh rT,[rT,rI] | ldrb rT,[rT,rI]] ; lsl rT,#1 ; add pc,rT
                  target = (addr(add pc)+4) + 2*entry
  * vtables:      base-relative words: target = vptr + entry (bit0 = Thumb)
  * ctor vector:  entry-relative words at C$$pi_ctorvec
  * MI thunks:    ARM: ldr ip,[pc,#8]; sub r0,r0,#k; add ip,pc,ip; bx ip; .word rel
"""
import struct, collections
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM

ROM = 0x08000000

import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from game import VT_LO, VT_HI, CTOR_LO, CTOR_HI       # config/game.json


class Conflict(Exception):
    pass


class Analyzer:
    def __init__(self, rom, text_end, iwram=None):
        self.d = rom
        self.text_end = text_end            # ROM offset where code may live
        self.iwram = iwram                  # (rom_off, vma, size)
        self.th = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
        self.ar = Cs(CS_ARCH_ARM, CS_MODE_ARM)
        self.insn = {}        # addr -> (mode, size)
        self.pool = {}        # addr -> set(ref addrs)
        self.jt = {}          # table addr -> (count, base_pc, [targets], esz)
        self.funcs = {}       # addr -> mode
        self.labels = set()
        self.owner = {}       # ('i'|'p'|'j', addr) -> root
        self.roots = {}       # root addr -> level
        self.calls = collections.defaultdict(set)   # target -> callers

    # ---------------------------------------------------------------- memory
    def off(self, a):
        if ROM <= a < ROM + len(self.d): return a - ROM
        if self.iwram and self.iwram[1] <= a < self.iwram[1] + self.iwram[2]:
            return self.iwram[0] + (a - self.iwram[1])
        return None

    def in_code(self, a):
        o = self.off(a)
        if o is None: return False
        if a >= ROM: return 0xC0 <= o < self.text_end
        return True

    def u16(self, a): return struct.unpack_from('<H', self.d, self.off(a))[0]
    def u32(self, a): return struct.unpack_from('<I', self.d, self.off(a))[0]
    def s32(self, a): return struct.unpack_from('<i', self.d, self.off(a))[0]

    # ---------------------------------------------------------------- occupancy
    def occupied_by(self, a):
        """Return the owner root of whatever occupies byte address a, or None."""
        for k in (0, 2):
            x = a - k
            if x in self.insn and self.insn[x][1] > k: return self.owner.get(('i', x))
        for k in (0, 1, 2, 3):
            if (a - k) in self.pool: return self.owner.get(('p', a - k))
        for t, v in self.jt.items():
            if t <= a < t + v[0] * v[3]: return self.owner.get(('j', t))
        return None

    # ---------------------------------------------------------------- tracing
    def trace(self, root, mode, level):
        """Trace a function rooted at `root`. Raises Conflict(addr) on collisions.
        New state is recorded in self._new for rollback."""
        self._new = []
        self._defer = []
        self.cur_level = level
        q = [(root, mode)]
        while q:
            a, m = q.pop()
            if m == 't': self._thumb(a, q, root)
            else: self._arm(a, q, root)

    def _put_insn(self, a, m, size, root):
        for k in range(0, size, 2):
            o = self.occupied_by(a + k)
            if o is not None: raise Conflict(a + k)
        self.insn[a] = (m, size); self.owner[('i', a)] = root; self._new.append(('i', a))

    def _put_pool(self, la, ref, root):
        if la in self.pool:
            self.pool[la].add(ref); return
        for k in range(4):
            o = self.occupied_by(la + k)
            if o is not None: raise Conflict(la + k)
        self.pool[la] = {ref}; self.owner[('p', la)] = root; self._new.append(('p', la))

    def _block(self, a, m, q):
        self.labels.add(a)
        if a in self.insn:
            if self.insn[a][0] != m: raise Conflict(a)
            return
        q.append((a, m))

    def _call(self, src, tgt, m):
        self.calls[tgt].add(src)
        self.labels.add(tgt)
        if not self.in_code(tgt): return
        self._defer.append((tgt, m))

    def _thumb(self, a, q, root):
        hist = []
        while True:
            if not self.in_code(a) or a & 1: raise Conflict(a)
            if a in self.insn:
                if self.insn[a][0] != 't': raise Conflict(a)
                return
            h = self.u16(a)
            if (h >> 11) == 0x1E:                                   # BL pair
                h2 = self.u16(a + 2)
                if (h2 >> 11) != 0x1F: raise Conflict(a)
                off = ((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
                if off & 0x400000: off -= 0x800000
                if not self.in_code(a + 4 + off): raise Conflict(a)
                self._put_insn(a, 't', 4, root)
                self._call(a, a + 4 + off, 't')
                hist.append(None)
                a += 4
                continue
            if h >= 0xE800: raise Conflict(a)                      # not ARMv4T
            if 0x0800 <= h <= 0x083F and self.cur_level >= 2: raise Conflict(a)   # lsr #32 = pointer high half
            if (h >> 12) == 0xD and ((h >> 8) & 0xF) == 0xE: raise Conflict(a)   # undefined
            self._put_insn(a, 't', 2, root)
            hist.append(a)
            if (h >> 11) == 0x09:                                   # ldr rd,[pc,#imm]
                self._put_pool(((a + 4) & ~3) + (h & 0xFF) * 4, a, root)
            if (h >> 12) == 0xD and ((h >> 8) & 0xF) < 0xE:         # b<cond>
                off = h & 0xFF; off = off - 0x100 if off & 0x80 else off
                self._block(a + 4 + off * 2, 't', q)
            elif (h >> 11) == 0x1C:                                 # b
                off = h & 0x7FF; off = off - 0x800 if off & 0x400 else off
                self._block(a + 4 + off * 2, 't', q); return
            elif (h & 0xFF80) == 0x4700:                            # bx rN
                if ((h >> 3) & 0xF) == 15:                          # bx pc -> ARM
                    tgt = (a + 4) & ~3
                    if a & 2 == 0: self._put_insn(a + 2, 't', 2, root)   # nop filler
                    self._block(tgt, 'a', q)
                    self.funcs.setdefault(tgt, 'a')
                return
            elif (h & 0xFF00) == 0xBD00: return                     # pop {..pc}
            elif (h & 0xFF87) == 0x4487:                            # add pc,rN : switch
                self._switch(a, hist, q, root); return
            elif (h & 0xFF87) == 0x4687: raise Conflict(a)          # mov pc,rN (unknown)
            a += 2

    def _switch(self, a, hist, q, root):
        n = tbl = esz = None
        for x in reversed(hist[-12:]):
            if x is None: break
            h = self.u16(x)
            if (h & 0xFE00) == 0x5A00 and esz is None: esz = 2
            if (h & 0xFE00) == 0x5C00 and esz is None: esz = 1
            if (h >> 11) == 0x14 and tbl is None: tbl = ((x + 4) & ~3) + (h & 0xFF) * 4
            if (h >> 11) == 0x05 and tbl is not None: n = h & 0xFF; break
        if n is None or tbl is None or esz is None: raise Conflict(a)
        base = a + 4
        for k in range(n * esz):
            if self.occupied_by(tbl + k) is not None: raise Conflict(tbl + k)
        tg = []
        for i in range(n):
            v = self.d[self.off(tbl + i)] if esz == 1 else self.u16(tbl + 2 * i)
            tg.append(base + 2 * v)
        self.jt[tbl] = (n, base, tg, esz); self.owner[('j', tbl)] = root; self._new.append(('j', tbl))
        for t in tg: self._block(t, 't', q)
        if a + 2 < tbl and (self.u16(a + 2) >> 11) == 0x1C: self._block(a + 2, 't', q)

    def _arm(self, a, q, root):
        while True:
            if not self.in_code(a) or a & 3: raise Conflict(a)
            if a in self.insn:
                if self.insn[a][0] != 'a': raise Conflict(a)
                return
            w = self.u32(a)
            if next(self.ar.disasm(self.d[self.off(a):self.off(a) + 4], a), None) is None: raise Conflict(a)
            self._put_insn(a, 'a', 4, root)
            cond = w >> 28
            if cond == 0xF: raise Conflict(a)
            if (w & 0x0F7F0000) == 0x051F0000:                      # ldr rX,[pc,#imm]
                imm = w & 0xFFF
                la = a + 8 + (imm if w & 0x00800000 else -imm)
                self._put_pool(la, a, root)
                if ((w >> 12) & 0xF) == 15 and cond == 0xE:         # ldr pc,=x (veneer)
                    tgt = self.u32(la)
                    if self.in_code(tgt & ~1): self._call(a, tgt & ~1, 't' if tgt & 1 else 'a')
                    return
            if w == 0xE08FC00C and a - 8 >= 0 and self.off(a - 8) is not None and self.u32(a - 8) == 0xE59FC008:
                tgt = a + 8 + self.s32(a + 8)                       # MI thunk
                self._call(a, tgt & ~1, 't' if tgt & 1 else 'a')
            if (w & 0x0E000000) == 0x0A000000:                      # b / bl
                off = w & 0xFFFFFF
                if off & 0x800000: off -= 0x1000000
                tgt = a + 8 + off * 4
                if w & 0x01000000: self._call(a, tgt, 'a')
                else:
                    self._block(tgt, 'a', q)
                    if cond == 0xE: return
            elif (w & 0x0FFFFFF0) == 0x012FFF10:                    # bx
                if cond == 0xE: return
            elif ((w >> 12) & 0xF) == 15 and (w & 0x0C000000) == 0 and cond == 0xE \
                    and not (8 <= ((w >> 21) & 0xF) <= 11) and (w & 0x02000090) != 0x90:
                return                                              # data-proc to pc
            elif (w & 0x0E108000) == 0x08108000 and cond == 0xE: return   # ldm {..pc}
            elif (w & 0x0C10F000) == 0x0410F000 and cond == 0xE: return   # ldr pc
            a += 4

    # ---------------------------------------------------------------- roots
    def rollback(self, new):
        for kind, a in reversed(new):
            {'i': self.insn, 'p': self.pool, 'j': self.jt}[kind].pop(a, None)
            self.owner.pop((kind, a), None)

    def evict(self, root):
        keys = [k for k, r in self.owner.items() if r == root]
        for kind, a in keys:
            {'i': self.insn, 'p': self.pool, 'j': self.jt}[kind].pop(a, None)
            del self.owner[(kind, a)]
        self.roots.pop(root, None)
        if self.funcs.get(root) is not None and self.root_level.get(root, 9) > 0:
            self.funcs.pop(root, None)
        self.evicted.add(root)

    def try_func(self, a, mode, level, _depth=0):
        """Trace a seed. Returns True if kept. Callees are traced recursively at the same level."""
        if not self.in_code(a): return False
        if a in self.insn:
            if self.insn[a][0] == mode: self.funcs.setdefault(a, mode)
            return self.insn[a][0] == mode
        if self.occupied_by(a) is not None and self.root_level.get(self.occupied_by(a), 0) <= level:
            return False
        try:
            self.trace(a, mode, level)
        except Conflict as c:
            self.rollback(self._new)
            o = self.occupied_by(c.args[0])
            if o is not None and o != a and self.root_level.get(o, 0) > level and _depth < 4:
                self.evict(o)
                return self.try_func(a, mode, level, _depth + 1)
            return False
        self.funcs[a] = mode; self.roots[a] = level; self.root_level[a] = level
        for k in self._new: pass
        defer = self._defer
        for t, m in defer:
            if t in self.insn: self.funcs.setdefault(t, m) if self.insn[t][0] == m else None
            else: self.try_func(t, m, level)
        return True


def ctor_targets(d):
    out = []
    for e in range(CTOR_LO, CTOR_HI, 4):
        v = struct.unpack_from('<i', d, e)[0]; t = e + v
        out.append((e, ROM + (t & ~1), 't' if t & 1 else 'a'))
    return out


def vtable_layout(d, A, text_end):
    """vtables are base-relative: target = base + entry. Bases = pool words pointing into VT area."""
    bases = set()
    for o in list(range(0xC0, VT_LO & ~3, 4)) + list(range(VT_HI, text_end & ~3, 4)):
        w = struct.unpack_from('<I', d, o)[0]
        if ROM + VT_LO <= w < ROM + VT_HI and w % 4 == 0: bases.add(w - ROM)
    bases = sorted(bases)
    ents = {}
    for i, b in enumerate(bases):
        end = bases[i + 1] if i + 1 < len(bases) else VT_HI
        e = b
        while e < end:
            if ROM + e in A.insn: break
            v = struct.unpack_from('<i', d, e)[0]; t = b + v
            if not (0xC0 <= t < text_end): break
            if t & 1: ents[e] = (b, ROM + t - 1, 't')
            elif t % 4 == 0: ents[e] = (b, ROM + t, 'a')
            else: break
            e += 4
    return bases, ents


def cover(A, text_end):
    cov = bytearray(text_end)
    for a, (m, s) in A.insn.items():
        if a >= ROM: cov[a - ROM:a - ROM + s] = b'\x01' * s
    for a in A.pool:
        if a >= ROM: cov[a - ROM:a - ROM + 4] = b'\x02' * 4
    for t, (n, b, tg, esz) in A.jt.items():
        if t >= ROM: cov[t - ROM:t - ROM + esz * n] = b'\x03' * (esz * n)
    return cov


def gaps(cov, start=0xC0):
    out = []; i = start; n = len(cov)
    while i < n:
        if cov[i] == 0:
            j = i
            while j < n and cov[j] == 0: j += 1
            out.append((i, j)); i = j
        else: i += 1
    return out


def is_cstring(d, o, n=4):
    """Printable ASCII run of at least n bytes ending in NUL (assert messages and file names in the code area)."""
    e = o
    while e < len(d) and (32 <= d[e] < 127 or d[e] in (9, 10)): e += 1
    return e - o >= n and e < len(d) and d[e] == 0


def full_analysis(d, text_end, iwram, extra_seeds=()):
    A = Analyzer(d, text_end, iwram)
    A.root_level = {}; A.evicted = set()
    A.try_func(ROM + 0xC0, 'a', 0)
    for a, m in extra_seeds: A.try_func(a, m, 0)

    def stage_rel(level):
        tg = [(t, m) for e, t, m in ctor_targets(d)]
        A.vt_bases, A.vt_ents = vtable_layout(d, A, text_end)
        tg += [(t, m) for e, (b, t, m) in A.vt_ents.items()]
        for t, m in tg: A.try_func(t, m, level)

    def odd_ptrs(level, need_push):
        for o in range(0, len(d) - 3, 4):
            w = struct.unpack_from('<I', d, o)[0]
            if w & 1 and ROM + 0xC0 < w < ROM + text_end and (w - 1) not in A.insn:
                if need_push and d[w - ROM] != 0xB5: continue
                if is_cstring(d, w - 1 - ROM): continue
                A.try_func(w - 1, 't', level)

    def arm_prologues(level):
        cov = cover(A, text_end)
        for g0, g1 in gaps(cov):
            for q in range((g0 + 3) & ~3, g1 - 3, 4):
                if (struct.unpack_from('<I', d, q)[0] & 0xFFFF4000) == 0xE92D4000 and (ROM + q) not in A.insn:
                    A.try_func(ROM + q, 'a', level)

    def gap_prologues(level, hi_bytes):
        cov = cover(A, text_end)
        for g0, g1 in gaps(cov):
            for q in range(g0 + (g0 & 1), g1 - 1, 2):
                if d[q + 1] in hi_bytes and (ROM + q) not in A.insn:
                    A.try_func(ROM + q, 't', level)

    def gap_starts(level):
        cov = cover(A, text_end)
        for g0, g1 in gaps(cov):
            p = g0 + (g0 & 1)
            while p + 4 <= g1:
                w = struct.unpack_from('<I', d, p)[0] if p % 4 == 0 else None
                if w is not None and (0x02000000 <= w < 0x0A000000 or w == 0): p += 4; continue
                if d[p] == 0 and d[p + 1] == 0: p += 2; continue
                # C strings (assert file names and messages reached with `adr`): printable run + NUL
                e = p
                while e < g1 and (32 <= d[e] < 127 or d[e] in (9, 10)): e += 1
                if e - p >= 4 and e < g1 and d[e] == 0:
                    p = e + 1
                    while p < g1 and d[p] == 0: p += 1
                    p += p & 1
                    continue
                break
            if p + 2 <= g1: A.try_func(ROM + p, 't', level)
            q = (g0 + 3) & ~3
            while q + 12 <= g1:
                if all(d[q + 3 + 4 * k] & 0xF0 == 0xE0 for k in range(3)) and (ROM + q) not in A.insn:
                    if A.try_func(ROM + q, 'a', level): break
                q += 4

    stages = [lambda: stage_rel(1), lambda: odd_ptrs(2, True), lambda: gap_prologues(3, (0xB5,)), lambda: arm_prologues(3),
              lambda: odd_ptrs(4, False), lambda: gap_prologues(5, (0xB4,)), lambda: gap_starts(6)]
    for k in range(len(stages)):
        for _ in range(8):
            before = (len(A.insn), len(A.evicted))
            for st in stages[:k + 1]: st()
            if (len(A.insn), len(A.evicted)) == before: break
    A.vt_bases, A.vt_ents = vtable_layout(d, A, text_end)
    return A
