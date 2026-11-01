#!/usr/bin/env python3
"""Argument counts for the armlink veneers (config/game.json: between the ctor vector and the vtables).

Each veneer jumps to an ARM routine (mostly in the IWRAM image: memset/memcpy-style blitters, the WFZ decoder, ...).
Ghidra can't see through them, so it guesses a different parameter list at every call site, and calls lose
arguments (seen: memset(dst, 0, 0x200) decompiled as memset(dst)). This counts how many of r0-r3 each target reads
before writing them (following straight-line code and both sides of branches) and writes
`.analysis/ghidra/veneer_sigs.txt` ("veneer_addr nargs"). tools/ghidra/FixFlow.java applies it.
"""
import os, struct, pickle
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_THUMB
from capstone.arm import ARM_REG_R0, ARM_REG_R1, ARM_REG_R2, ARM_REG_R3

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')); os.chdir(ROOT)
d = open('baserom.gba', 'rb').read()
import sys; sys.path.insert(0, os.path.join(ROOT, 'tools', 'bfdis'))
from game import IWRAM, CTOR_HI, VT_LO
IW_LMA = IWRAM[0]
ARGS = [ARM_REG_R0, ARM_REG_R1, ARM_REG_R2, ARM_REG_R3]


def read(addr, n):
    if 0x03000000 <= addr < 0x03000000 + IWRAM[2]: o = IW_LMA + addr - 0x03000000
    elif 0x08000000 <= addr < 0x08800000: o = addr - 0x08000000
    else: return None
    return d[o:o + n]


def used_args(entry, thumb):
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB if thumb else CS_MODE_ARM); md.detail = True
    used = set(); seen = set()
    work = [(entry, frozenset())]
    while work:
        a, written = work.pop()
        for _ in range(200):
            if (a, written) in seen: break
            seen.add((a, written))
            b = read(a, 4)
            if not b: break
            ins = list(md.disasm(b, a, 1))
            if not ins: break
            i = ins[0]
            rd, wr = i.regs_access()
            for r in rd:
                if r in ARGS and r not in written: used.add(ARGS.index(r))
            written = written | {r for r in wr if r in ARGS}
            m = i.mnemonic
            if m in ('bx', 'blx') or (m.startswith('pop') and 'pc' in i.op_str) or (m.startswith('ldm') and 'pc' in i.op_str) \
                    or (m.startswith('ldr') and i.op_str.startswith('pc')) or m == 'bl':
                break
            if m.startswith('b') and i.operands and i.operands[0].type == 4 and m not in ('bic', 'bics'):   # imm branch
                work.append((i.operands[0].imm, written))
                if m in ('b', 'b.w'): break
            a += i.size
    return (max(used) + 1) if used else 0


out = []
for va in range(0x08000000 + CTOR_HI, 0x08000000 + VT_LO, 2):
    o = va - 0x08000000
    h = struct.unpack_from('<H', d, o)[0]
    if h == 0x4778:                                   # bx pc ; nop ; ldr pc, [pc, #-4] ; .word target
        w = struct.unpack_from('<I', d, o + 4)[0]
        if w == 0xE51FF004:
            t = struct.unpack_from('<I', d, o + 8)[0]
            out.append((va, t, used_args(t & ~1, t & 1)))
os.makedirs('.analysis/ghidra', exist_ok=True)
with open('.analysis/ghidra/veneer_sigs.txt', 'w') as f:
    for va, t, n in out: f.write('%08X %d\n' % (va, n))
for va, t, n in out: print('%08X -> %08X  args %d' % (va, t, n))
