#!/usr/bin/env python3
"""Which functions' return value (r0) is ever used by a caller?

Ghidra often types a function as `void` when the original actually leaves a meaningful value in r0 (C++ constructors
return `this`, factories return their callee's result). A GCC version of a "void" function leaves something else in r0.
That's harmless only if no caller reads r0 after the call. This scans every direct call site (`bl f`) in the
code area and follows the caller's instructions until r0 is read (live) or overwritten (dead). A caller that
returns before touching r0 passes the value on, so that counts as live. So does a tail call (`b f`), and so does any function
whose address is taken (vtables, data pointers, literal pools), since callers through a pointer can't be enumerated.

usage: r0live.py  -> writes .analysis/decomp/r0_dead.txt (functions whose r0 is provably unused) and
                     r0_direct_dead.txt (unused by every direct caller; calls through pointers not considered)
A call site whose function returns r0 unchanged to its own caller is followed up the call graph.
site_dead(lr): is r0 unread after returning to lr (used by autodecomp.py for the return site in a snapshot)?
"""
import os, sys, pickle, struct, collections
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
from capstone.arm import ARM_REG_R0, ARM_OP_REG

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')); os.chdir(ROOT)
ROM = 0x08000000
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'bfdis'))
from game import CALL_VIA, TEXT_END
d = open('baserom.gba', 'rb').read()
db = pickle.load(open('.analysis/analysis.pickle', 'rb'))
insn = db['insn']
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB); md.detail = True
cache = {}


def dec(a):
    if a not in cache:
        m, sz = insn.get(a, (None, 0))
        if m != 't': cache[a] = None
        else:
            l = list(md.disasm(d[a - ROM:a - ROM + sz], a, 1)); cache[a] = l[0] if l else None
    return cache[a]


def bl_target(a):
    h1, h2 = struct.unpack_from('<HH', d, a - ROM)
    if (h1 >> 11) == 0x1E and (h2 >> 11) == 0x1F:
        off = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
        if off & 0x400000: off -= 0x800000
        return a + 4 + off
    return None


_SIGS = None


def takes_args(f):
    """Does f read r0 as an argument? From Ghidra's signature (functions.jsonl); unknown -> yes."""
    global _SIGS
    if _SIGS is None:
        import json
        _SIGS = {}
        p = '.analysis/ghidra/functions.jsonl'
        if os.path.exists(p):
            for l in open(p):
                x = json.loads(l); _SIGS[int(x['addr'], 16) if isinstance(x['addr'], str) else x['addr']] = x.get('sig') or ''
    sig = _SIGS.get(f)
    if not sig: return True
    args = sig[sig.find('(') + 1:sig.rfind(')')].strip()
    return args not in ('void', '')


ret_seen = set()


def live_after(a, depth=0, seen=None):
    """Is r0 read on some path starting at a, before being written? True / False / 'ret' (not read here, but passed
    back to this function's own caller on some path)"""
    top = seen is None
    if top: ret_seen.clear()
    r = _live_after(a, depth, seen)
    if top and r is False and ret_seen: r = 'ret'
    return r


def _live_after(a, depth=0, seen=None):
    seen = seen if seen is not None else set()
    while True:
        if a in seen or depth > 40: return False
        seen.add(a)
        i = dec(a)
        if i is None: return True                       # unknown: be conservative
        rd, wr = i.regs_access()
        mn = i.mnemonic
        if mn == 'bl':                                  # a call with r0 still holding the value: it's the callee's first
            return takes_args(i.operands[0].imm)        # argument (g(f()) compiles to `bl f; bl g`), unless g takes none
        if ARM_REG_R0 in rd: return True
        if mn.startswith('pop') and 'pc' in i.op_str: return 'ret'    # returned to our caller: live if the caller's is
        if mn == 'bx' or (mn.startswith('mov') and i.op_str.startswith('pc')): return 'ret'
        if ARM_REG_R0 in wr: return False
        if mn == 'b':
            a = i.operands[0].imm; depth += 1; continue
        if mn.startswith('b') and len(mn) in (3, 4) and i.operands and i.operands[0].type != ARM_OP_REG and mn not in ('bic', 'bics'):
            r = _live_after(i.operands[0].imm, depth + 1, set(seen))
            if r is True: return True
            if r == 'ret': ret_seen.add(1)
        a += i.size; depth += 1


_DEAD = None


def site_dead(lr):
    global _DEAD, _FUNCS
    if _DEAD is None:
        _DEAD = {int(l, 16) for l in open('.analysis/decomp/r0_dead.txt')}
        _FUNCS = sorted(db['funcs'])
    v = live_after(lr & ~1)
    if v is False: return True
    if v == 'ret':
        import bisect
        return _FUNCS[bisect.bisect_right(_FUNCS, lr & ~1) - 1] in _DEAD
    return False


def main():
    used = set()
    called = collections.defaultdict(list)
    for a, (m, sz) in insn.items():
        if m == 't' and sz == 4:
            t = bl_target(a)
            if t is not None: called[t].append(a)
    # address taken anywhere -> live
    for la in db['pool']:
        if la >= ROM and la + 4 <= ROM + len(d):
            v = struct.unpack_from('<I', d, la - ROM)[0]
            if v & 1: used.add(v & ~1)
    # virtual methods: called as `ldr rA,[obj]; ldr rB,[rA,#k]; add rB,rA; bl __call_via_rB`. A method in slot k is
    # live if r0 is live after any virtual call through slot k.
    via = {CALL_VIA + 2 * n for n in range(8)}
    slot_live = collections.defaultdict(bool)
    unknown_slot = False
    for c, (m, sz) in insn.items():
        if m != 't' or sz != 4 or bl_target(c) not in via: continue
        k = None
        for back in range(2, 14, 2):
            i = dec(c - back)
            if i is not None and i.mnemonic == 'ldr' and len(i.operands) == 2 and i.operands[1].mem.base != 0 \
                    and 'pc' not in i.op_str and 'sp' not in i.op_str:
                k = i.operands[1].mem.disp; break
        live = live_after(c + 4) is not False       # passing it on through a virtual call: assume read
        if k is None:
            unknown_slot |= live
        else:
            slot_live[k] |= live
    for e, (b, t, m) in db['vt_ents'].items():
        if unknown_slot or slot_live.get(e - b, True): used.add(t)
    for o, (t, m) in db['ctor'].items(): used.add(t)
    # data pointers in .rodata
    # (only words the disassembler converted to symbols: raw scanning would count PCM/graphics noise)
    import glob, re
    for p in glob.glob('data/*.s') + glob.glob('asm/iwram.s'):
        for m in re.finditer(r'\.4byte (?:sub|_)([0-9A-F]{8})(?: \+ 1)?\b', open(p).read()):
            used.add(int(m.group(1), 16))
    addr_taken = set(used)
    # tail calls
    for a, (m, sz) in insn.items():
        if m == 't' and sz == 2:
            h = struct.unpack_from('<H', d, a - ROM)[0]
            if (h >> 11) == 0x1C:
                off = h & 0x7FF; off = off - 0x800 if off & 0x400 else off; t = a + 4 + off * 2
                if t in db['funcs']: used.add(t)
            elif (h >> 12) == 0xD and ((h >> 8) & 0xF) < 0xE:
                off = h & 0xFF; off = off - 0x100 if off & 0x80 else off; t = a + 4 + off * 2
                if t in db['funcs']: used.add(t)
    vt_targets = {t for e, (b, t, m) in db['vt_ents'].items()}
    funcs = sorted(db['funcs'])
    import bisect
    def owner(a): return funcs[bisect.bisect_right(funcs, a) - 1]
    tails = collections.defaultdict(list)          # tail calls: target -> functions that end by jumping to it
    for a, (m, sz) in insn.items():
        if m == 't' and sz == 2:
            h = struct.unpack_from('<H', d, a - ROM)[0]
            if (h >> 11) == 0x1C:
                off = h & 0x7FF; off = off - 0x800 if off & 0x400 else off; t = a + 4 + off * 2
                if t in db['funcs'] and owner(a) != t: tails[t].append(owner(a))
            elif (h >> 12) == 0xD and ((h >> 8) & 0xF) < 0xE:
                off = h & 0xFF; off = off - 0x100 if off & 0x80 else off; t = a + 4 + off * 2
                if t in db['funcs'] and owner(a) != t: tails[t].append(owner(a))
    memo = {}
    ignore_taken = [False]
    def fn_live(f):
        """Is f's r0 read by anyone? A call site that returns r0 unchanged to its own caller is live only if that
        function's r0 is live (followed up the call graph; a cycle counts as not read, since a real read would show
        up on some other path)."""
        if f in memo: return memo[f]
        memo[f] = False
        if f in addr_taken and not ignore_taken[0]: memo[f] = True; return True
        r = False
        for c in called.get(f, []):
            v = live_after(c + 4)
            if v is True or (v == 'ret' and fn_live(owner(c))): r = True; break
        if not r:
            r = any(fn_live(g) for g in tails.get(f, []))
        memo[f] = r
        return r
    print('virtual slots seen:', len(slot_live), 'live:', sum(slot_live.values()), 'call via unknown slot live:', unknown_slot)
    dead = []
    for f in db['funcs']:
        if f in addr_taken: continue
        if not called.get(f) and not tails.get(f) and f not in vt_targets: continue
        if not fn_live(f): dead.append(f)
    os.makedirs('.analysis/decomp', exist_ok=True)
    open('.analysis/decomp/r0_dead.txt', 'w').write(''.join('%08X\n' % f for f in sorted(dead)))
    # Second list: functions whose r0 no *direct* caller reads (bl / tail call), ignoring calls through pointers.
    # autodecomp.py accepts an r0 difference for these only if the return site in that snapshot (its LR) doesn't
    # read r0 either ('equal-r0unread').
    memo.clear(); ignore_taken[0] = True
    direct = [f for f in db['funcs'] if not fn_live(f)]
    open('.analysis/decomp/r0_direct_dead.txt', 'w').write(''.join('%08X\n' % f for f in sorted(direct)))
    print('r0 unused by every direct caller:', len(direct))
    print('functions:', len(db['funcs']), 'address taken / tail-called:', len(used), 'r0 provably unused:', len(dead))


if __name__ == '__main__':
    main()
