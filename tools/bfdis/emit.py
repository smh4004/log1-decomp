#!/usr/bin/env python3
"""Emit GNU-as source for the code area from the analyzer database.

Output is assembled with `.syntax unified`. Every emitted instruction is later verified
byte-for-byte (tools/bfdis/verify.py); anything gas encodes differently is listed in
config/raw_insns.txt and emitted as a raw .2byte/.4byte with the original text as comment.
"""
import re, struct, os, sys
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM

ROM = 0x08000000


def lab(a):
    return '_%08X' % a


class Emitter:
    def __init__(self, rom, db, symbols, raw):
        self.d = rom
        self.db = db
        self.sym = symbols                 # addr -> name (overrides)
        self.raw = raw                     # set of addrs to force raw
        self.th = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
        self.ar = Cs(CS_ARCH_ARM, CS_MODE_ARM)
        self.iw = db['iwram']              # (rom_off, vma, size)
        self.funcs = db['funcs']
        self.insn = db['insn']
        self.pool = db['pool']
        self.jt = db['jt']
        self.labels = set(db['labels'])
        self.vt_ents = db['vt_ents']       # rom_off -> (base_off, target_bus, mode)
        self.ctor = db['ctor']             # rom_off -> (target_bus, mode)
        self.relpool = db.get('relpool', {})   # pool bus addr -> (anchor_bus, target_bus, mode)
        self.needed = set()                # labels referenced
        self.jt_bases = {}
        for t, (n, base, tg, esz) in self.jt.items():
            self.jt_bases[base] = t

    # ------------------------------------------------------------------ helpers
    def off(self, a):
        if a >= ROM: return a - ROM
        return self.iw[0] + (a - self.iw[1])

    def u16(self, a): return struct.unpack_from('<H', self.d, self.off(a))[0]
    def u32(self, a): return struct.unpack_from('<I', self.d, self.off(a))[0]

    def name(self, a):
        if a in self.sym: return self.sym[a]
        if a in self.funcs: return 'sub_%08X' % a
        return lab(a)

    def ref(self, a):
        self.needed.add(a)
        return self.name(a)

    # ------------------------------------------------------------------ thumb
    def thumb(self, a):
        size = self.insn[a][1]
        if size == 4:
            h, h2 = self.u16(a), self.u16(a + 2)
            off = ((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
            if off & 0x400000: off -= 0x800000
            t = a + 4 + off
            if a in self.raw: return '.2byte 0x%04X, 0x%04X @ bl %s' % (h, h2, self.name(t))
            return 'bl %s' % self.ref(t)
        h = self.u16(a)
        i = next(self.th.disasm(self.d[self.off(a):self.off(a) + 2], a))
        mn, ops = i.mnemonic, i.op_str
        txt = None
        if (h >> 12) == 0xD and ((h >> 8) & 0xF) < 0xE or (h >> 11) == 0x1C:
            t = int(ops.lstrip('#'), 16)
            txt = '%s %s' % (mn, self.ref(t))
        elif (h >> 11) == 0x09:
            la = ((a + 4) & ~3) + (h & 0xFF) * 4
            txt = 'ldr r%d, %s' % ((h >> 8) & 7, self.ref(la))
        elif (h >> 11) == 0x14:
            la = ((a + 4) & ~3) + (h & 0xFF) * 4
            txt = 'adr r%d, %s' % ((h >> 8) & 7, self.ref(la))
        elif (h & 0xFC00) == 0x4400 and ((h >> 8) & 3) != 3:   # hi-register add/cmp/mov
            R = ['r0','r1','r2','r3','r4','r5','r6','r7','r8','r9','r10','r11','r12','sp','lr','pc']
            rd = (h & 7) | ((h >> 4) & 8); rm = (h >> 3) & 15
            txt = '%s %s, %s' % (('add', 'cmp', 'mov')[(h >> 8) & 3], R[rd], R[rm])
        else:
            txt = self.fix_ops(mn, ops)
        if a in self.raw: return '.2byte 0x%04X @ %s' % (h, txt)
        return txt

    def fix_ops(self, mn, ops):
        # capstone prints rotated immediates as "#a, #b"
        m = re.search(r'#(0x[0-9a-f]+|\d+), #(\d+)$', ops)
        if m:   # keep the original (non-canonical) rotation: gas accepts "#imm8, rot"
            v = int(m.group(1), 0); r = int(m.group(2))
            val = ((v >> r) | (v << (32 - r))) & 0xFFFFFFFF
            ops = ops[:m.start()] + '#%d, %d @ =0x%X' % (v, r, val)
        return ('%s %s' % (mn, ops)).strip()

    # ------------------------------------------------------------------ arm
    def arm(self, a):
        w = self.u32(a)
        i = next(self.ar.disasm(self.d[self.off(a):self.off(a) + 4], a))
        mn, ops = i.mnemonic, i.op_str
        txt = None
        if (w & 0x0E000000) == 0x0A000000:
            t = int(ops.lstrip('#'), 16)
            txt = '%s %s' % (mn, self.ref(t))
        elif (w & 0x0F7F0000) == 0x051F0000:
            imm = w & 0xFFF
            la = a + 8 + (imm if w & 0x00800000 else -imm)
            txt = '%s %s, %s' % (mn, ops.split(',')[0], self.ref(la))
        else:
            txt = self.fix_ops(mn, ops)
        if a in self.raw: return '.4byte 0x%08X @ %s' % (w, txt)
        return txt

    # ------------------------------------------------------------------ ranges
    def emit_range(self, start, end, out):
        """Emit [start,end) bus addresses. Returns list of lines."""
        mode = None
        a = start
        jt_cover = {}
        for t, (n, base, tg, esz) in self.jt.items():
            for k in range(n): jt_cover[t + k * esz] = (t, k, esz, base, tg[k])
        wrap_end = None
        while a < end:
            if wrap_end is not None and a >= wrap_end:
                self.decomp_else(out); out.append('\t.endif'); wrap_end = None
            if a in getattr(self, 'wrap', {}) and wrap_end is None:
                wrap_end = self.wrap[a]
                self.wrap_start = a
                out.append(''); out.append('\t.ifndef DECOMP_%s' % self.name(a))
            # pools and switch tables are word aligned: keep them so when code before them moves
            if (a in self.pool and (a - 4) not in self.pool) or a in self.jt:
                out.append('\t.align 2, 0')
            # labels
            if a in self.funcs:
                m = self.funcs[a]
                if a in self.insn and self.insn[a][0] == m:
                    out.append('')
                    out.append('\t%s %s' % ('thumb_func_start' if m == 't' else 'arm_func_start', self.name(a)))
                    out.append('%s: @ 0x%08X' % (self.name(a), a))
                    if a in getattr(self, 'even', ()): out.append('%s_even:   @ plain label: address without the Thumb bit' % self.name(a))
                    mode = m
                else:
                    out.append('%s: @ 0x%08X' % (self.name(a), a))
            elif a in self.labels or a in self.pool or a in self.jt or a in self.jt_bases or a in self.sym \
                    or a in self.needed_hint:
                out.append('%s:' % self.name(a))
            if a in self.insn:
                m, s = self.insn[a]
                if m != mode:
                    out.append('\t.thumb' if m == 't' else '\t.arm')
                    mode = m
                out.append('\t' + (self.thumb(a) if m == 't' else self.arm(a)))
                a += s
                continue
            if a in self.pool:
                out.append('\t' + self.word(a))
                a += 4; continue
            if a in jt_cover:
                t, k, esz, base, tgt = jt_cover[a]
                v = self.d[self.off(a)] if esz == 1 else self.u16(a)
                if a in self.raw:
                    out.append('\t.%s 0x%X' % ('byte' if esz == 1 else '2byte', v))
                else:
                    out.append('\t.%s (%s - %s) / 2' % ('byte' if esz == 1 else '2byte', self.ref(tgt), self.ref(base)))
                a += esz; continue
            o = self.off(a)
            if a >= ROM and o in self.vt_ents and a % 4 == 0 and a + 4 <= end:
                b, t, m = self.vt_ents[o]
                out.append('\t.4byte %s%s - %s' % (self.ref(t), ' + 1' if m == 't' else '', self.ref(ROM + b)))
                a += 4; continue
            if a >= ROM and o in self.ctor and a + 4 <= end:
                t, m = self.ctor[o]
                out.append('\t.4byte %s%s - .' % (self.ref(t), ' + 1' if m == 't' else ''))
                a += 4; continue
            # unknown bytes: run until next known thing
            b = a + 1
            while b < end and not self.is_known(b) and not (wrap_end is not None and b >= wrap_end) \
                    and b not in getattr(self, 'wrap', {}): b += 1
            self.data_bytes(a, b, out)
            a = b
        if wrap_end is not None:
            self.decomp_else(out); out.append('\t.endif')
        return out

    def decomp_else(self, out):
        """`make decomp` replacement for a function: a long jump to the C version (`name__c`, linked in free space
        at the end of the ROM), then padding up to the original size. Callers, tail calls, vtables and data pointers
        keep using the original address, and no other byte moves."""
        a, n = self.wrap_start, self.name(self.wrap_start)
        size = self.wrap[a] - a
        out.append('\t.else')
        out.append('\tthumb_func_start %s' % n)
        out.append('%s:' % n)
        if a in getattr(self, 'even', ()): out.append('%s_even:' % n)
        used = 16
        if a % 4:                       # bx pc needs (address + 4) word aligned
            out.append('\tnop'); used = 18
        out += ['\tbx pc', '\tnop', '\t.arm', '\tldr ip, [pc]', '\tbx ip', '\t.4byte %s__c + 1' % n, '\t.thumb']
        if size > used: out.append('\t.space %d' % (size - used))

    def is_known(self, a):
        if a in self.insn or a in self.pool or a in self.funcs or a in self.labels or a in self.jt \
                or a in self.jt_bases or a in self.sym or a in self.needed_hint:
            return True
        o = self.off(a)
        if a >= ROM and a % 4 == 0 and (o in self.vt_ents or o in self.ctor): return True
        for t, (n, base, tg, esz) in self.jt.items():
            if t <= a < t + n * esz: return True
        return False

    def word(self, a):
        w = self.u32(a)
        if a in self.relpool:
            anchor, tgt, m = self.relpool[a]
            return '.4byte %s%s - %s' % (self.ref(tgt), ' + 1' if m == 't' else '', self.ref(anchor))
        s = self.ptr_sym(w)
        return '.4byte %s' % s if s else '.4byte 0x%08X' % w

    def ptr_sym(self, w):
        return None   # phase 2 fills this in

    def data_bytes(self, a, b, out):
        # 2-byte zero padding before an aligned word -> .align 2, 0
        if b - a == 2 and a % 4 == 2 and self.d[self.off(a)] == 0 and self.d[self.off(a) + 1] == 0 and b % 4 == 0:
            out.append('\t.align 2, 0')
            return
        # aligned words that are code pointers become symbols (IRQ tables, callbacks in RW data)
        p = a
        while p < b:
            q = p
            while q < b and not (q % 4 == 0 and q + 4 <= b and self.data_ptr(q)): q += 1
            o0 = self.off(p)
            chunk = self.d[o0:o0 + (q - p)]
            for i in range(0, len(chunk), 16):
                out.append('\t.byte ' + ', '.join('0x%02X' % x for x in chunk[i:i + 16]))
            if q < b:
                out.append('\t.4byte %s' % self.data_ptr(q))
                q += 4
            p = q

    def data_ptr(self, a):
        """Symbol for a data word inside the code/RW area when it is clearly a code pointer."""
        w = self.u32(a)
        if w & 1 and (w - 1) in self.funcs and self.funcs[w - 1] == 't':
            return self.ptr_sym(w)
        # RW image (copied to IWRAM): aligned words into .rodata (e.g. a default table pointer)
        if a < ROM and a % 4 == 0 and not w & 3 and ROM + 0x30000 <= w < ROM + self.iw[0]:
            return self.ptr_sym(w)
        return None
