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
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM
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


mda = Cs(CS_ARCH_ARM, CS_MODE_ARM); mda.detail = True


_arm = {}


def arm_used_args(entry, depth=0):
    """argument registers read by ARM code at entry (the body behind a Thumb `bx pc` stub, e.g. __rt_sdiv); ARM calls
    (bl) are followed"""
    if entry in _arm: return _arm[entry]
    _arm[entry] = 0
    used = set(); seen = set(); work = [(entry, frozenset())]
    while work:
        a, written = work.pop()
        for _ in range(400):
            if (a, written) in seen or not (0x08000000 <= a < 0x08800000): break
            seen.add((a, written))
            l = list(mda.disasm(d[a - 0x08000000:a - 0x08000000 + 4], a, 1))
            if not l: break
            i = l[0]; m = i.mnemonic
            rd, wr = i.regs_access()
            if m.startswith(('push', 'stm')):          # same rule as Thumb: a lone r3 is only stack alignment
                low = [r for r in rd if r in ARGS[:3]]
                rd = low + ([ARM_REG_R3] if low and ARM_REG_R3 in rd else []) + [r for r in rd if r not in ARGS]
            for r in rd:
                if r in ARGS and r not in written: used.add(ARGS.index(r))
            if i.cc in (0, 15):                       # unconditional writes only
                written = written | {r for r in wr if r in ARGS}
            if m == 'bl' and depth < 8:
                n = arm_used_args(i.operands[0].imm, depth + 1)
                used |= {k for k in range(n) if ARGS[k] not in written}
                written = written | set(ARGS); a += 4; continue
            if m in ('bx', 'blx', 'bl') or (m.startswith(('pop', 'ldm')) and 'pc' in i.op_str) or \
                    (m.startswith(('mov', 'ldr')) and i.op_str.startswith('pc')):
                if i.cc in (0, 15): break
            elif m.startswith('b') and i.operands and i.operands[0].type == ARM_OP_IMM and m not in ('bic', 'bics'):
                work.append((i.operands[0].imm, written))
                if i.cc in (0, 15): break
            a += 4
    _arm[entry] = (max(used) + 1) if used else 0
    return _arm[entry]


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
            if m.startswith('push'):
                # pushing r0-r2 spills arguments that are read back from the stack (`push {r0, r1, lr}`); r3 pushed
                # without them only keeps the stack 8-byte aligned (`push {r3, r4, lr}`): not a use
                low = [r for r in rd if r in ARGS[:3]]
                rd = low + ([ARM_REG_R3] if low and ARM_REG_R3 in rd else [])
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
    # variadic functions (`push {r0-r3}` / `push {r2, r3}` without lr: they walk their arguments on the stack): every
    # argument register is "read" by the spill, so count only the named ones; ApplyArgCounts marks them varargs
    variadic = set()
    for f in funcs:
        h = struct.unpack_from('<H', d, f - 0x08000000)[0]
        if (h & 0xFF00) == 0xB400 and (h & 0x08) and not (h & 0xF0):
            fixed[f] = 4 - bin(h & 0x0F).count('1'); variadic.add(f)     # named = the registers not spilled
    # Thumb entry stubs into ARM code (`bx pc; nop`, then ARM): count the ARM body
    for f in funcs:
        if struct.unpack_from('<H', d, f - 0x08000000)[0] == 0x4778 and f not in fixed:
            fixed[f] = arm_used_args((f + 4) & ~3)
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
        for f in funcs: fo.write('%08X %d%s\n' % (f, known[f], ' varargs' if f in variadic else ''))
    print('functions:', len(funcs), 'passes:', it + 1)


if __name__ == '__main__':
    main()
