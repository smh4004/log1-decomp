#!/usr/bin/env python3
"""How many argument registers (r0-r3) each function really reads, for tools/ghidra/ApplyArgCounts.java.

Ghidra infers a function's parameters from what its decompiler sees used, and often misses one: a parameter that is
only passed on to a callee in the same register (f(obj, ch) { put(obj, ch); }), or a callee it decompiled before
the caller. The caller is then decompiled without that argument, and a C version of the caller silently drops it
(seen: the text printer lost the character it prints).

For every function in the disassembler's function list this counts which of r0-r3 are read before being written,
following both sides of branches. At a call (`bl g`, or a tail call `b g`), the argument registers g reads count as
read here if they haven't been written yet; after the call r0-r3 hold g's results / scratch. Calls through a register
(`bl __call_via_rN`) read the argument registers below rN. Repeated until nothing changes (calls can be recursive).

    python3 tools/ghidra/arg_counts.py  -> .analysis/ghidra/arg_counts.txt ("addr nargs", Thumb functions only)
"""
import os, sys, struct, pickle
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
from capstone.arm import ARM_REG_R0, ARM_REG_R1, ARM_REG_R2, ARM_REG_R3, ARM_OP_IMM

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')); os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, 'tools', 'bfdis'))
from game import CALL_VIA
d = open('baserom.gba', 'rb').read()
db = pickle.load(open('.analysis/analysis.pickle', 'rb'))
ARGS = [ARM_REG_R0, ARM_REG_R1, ARM_REG_R2, ARM_REG_R3]
VIA = {CALL_VIA + 2 * n: n for n in range(8)}
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB); md.detail = True
_cache = {}


def dec(a):
    if a not in _cache:
        m, sz = db['insn'].get(a, (None, 0))
        l = list(md.disasm(d[a - 0x08000000:a - 0x08000000 + sz], a, 1)) if m == 't' else []
        _cache[a] = l[0] if l else None
    return _cache[a]


def used_args(entry, known):
    used = set(); seen = set()
    work = [(entry, frozenset())]
    while work:
        a, written = work.pop()
        for _ in range(400):
            if (a, written) in seen: break
            seen.add((a, written))
            i = dec(a)
            if i is None: break
            m = i.mnemonic
            if m == 'bl':
                t = i.operands[0].imm
                n = min(4, VIA[t] if t in VIA else known.get(t, 4 if t not in db["funcs"] else 0))
                used |= {k for k in range(n) if ARGS[k] not in written}
                written = written | set(ARGS)
                a += i.size; continue
            rd, wr = i.regs_access()
            if m.startswith('push'): rd = []          # `push {r3, ...}` only saves r3 (stack alignment): not a use
            for r in rd:
                if r in ARGS and r not in written: used.add(ARGS.index(r))
            written = written | {r for r in wr if r in ARGS}
            if m in ('bx', 'blx') or (m.startswith('pop') and 'pc' in i.op_str) or (m.startswith('mov') and i.op_str.startswith('pc')):
                break
            if m.startswith('b') and i.operands and i.operands[0].type == ARM_OP_IMM and m not in ('bic', 'bics'):
                t = i.operands[0].imm
                if m == 'b' and t in db['funcs'] and t != entry:            # tail call
                    used |= {k for k in range(known.get(t, 0)) if ARGS[k] not in written}
                    break
                work.append((t, written))
                if m == 'b': break
            a += i.size
    return (max(used) + 1) if used else 0


def main():
    funcs = sorted(f for f in db['funcs'] if db['insn'].get(f, ('',))[0] == 't')
    # armlink veneers (`bx pc` into ARM code): counted by veneer_sigs.py from their targets
    fixed = {}
    vp = '.analysis/ghidra/veneer_sigs.txt'
    if not os.path.exists(vp): sys.exit('run tools/ghidra/veneer_sigs.py first')
    for l in open(vp):
        a, n = l.split(); fixed[int(a, 16)] = int(n)
    known = dict(fixed)
    for it in range(20):
        changed = 0
        for f in funcs:
            if f in fixed: continue
            n = used_args(f, known)
            if n != known.get(f):
                known[f] = n; changed += 1
        if not changed: break
    with open('.analysis/ghidra/arg_counts.txt', 'w') as fo:
        for f in funcs: fo.write('%08X %d\n' % (f, known[f]))
    print('functions:', len(funcs), 'passes:', it + 1)


if __name__ == '__main__':
    main()
