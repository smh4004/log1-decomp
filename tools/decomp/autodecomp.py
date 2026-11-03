#!/usr/bin/env python3
"""Automated non-matching decompilation pipeline (see docs/decomp.md).

  autodecomp.py tus       build one C translation unit per replaceable function from Ghidra output
  autodecomp.py compile   compile them with arm-none-eabi-gcc (Thumb, arm7tdmi)
  autodecomp.py test      equivalence-test compiled functions against the original code in Unicorn,
                          using real register/memory snapshots captured by the harness
  autodecomp.py emit      write src/*.c (accepted functions) and config/decomp_accepted.txt
State lives in .analysis/decomp/ (status.json). Inputs: .analysis/ghidra/functions.jsonl (tools/ghidra/ExportFunctions.java),
config/replaceable.txt (tools/bfdis/gen.py), snapshots (tools/harness capture).
"""
import os, sys, re, json, subprocess, struct, zlib, glob, collections
from concurrent.futures import ProcessPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
os.chdir(ROOT)
B = '.analysis/decomp'
CC = ['arm-none-eabi-gcc', '-mthumb', '-mcpu=arm7tdmi', '-O2', '-std=gnu11', '-ffreestanding', '-fsigned-char',
      '-fno-builtin', '-fno-strict-aliasing', '-fwrapv', '-fno-delete-null-pointer-checks', '-fno-common', '-w',
      '-Iinclude', '-ffunction-sections', '-fdata-sections']
LIBGCC = subprocess.run(['arm-none-eabi-gcc', '-mthumb', '-mcpu=arm7tdmi', '-print-libgcc-file-name'],
                        capture_output=True, text=True).stdout.strip()
BAD = ('unaff_', 'in_r', 'extraout_', 'in_lr', 'in_cr', 'in_stack', 'halt_baddata', 'switchD', 'UNRECOVERED',
       'software_interrupt', 'does not return', 'coprocessor', 'FUN_', 'LAB_', 'in_NG', 'in_ZR', 'in_CY', 'in_OV', 'in_sp', 'in_pc')
WIDE = ('undefined8', 'longlong', 'ulonglong', 'double', 'undefined5', 'undefined6', 'undefined7')
ABS_PREFIX = ('DAT_', 'PTR_', 's_', 'u_', 'BYTE_', 'WORD_', 'DWORD_', 'REG_', 'UNK_')


def load_funcs():
    F = {}
    for l in open('.analysis/ghidra/functions.jsonl'):
        x = json.loads(l)
        F[x['name']] = x
    return F


def replaceable():
    R = {}
    for l in open('config/replaceable.txt'):
        a, e, n = l.split()
        R[n] = (int(a, 16), int(e, 16))
    return R


def decl_type(t):
    """Ghidra display type -> (prefix, suffix) for a C declaration, or None if unknown (struct etc.)."""
    t = t.strip()
    m = re.match(r'^(.*?)\s*\[(\d+)\]$', t)
    if m:
        p = decl_type(m.group(1))
        return None if p is None else (p[0], '[%s]' % m.group(2) + p[1])
    base = t.replace('*', '').strip()
    known = {'undefined', 'undefined1', 'undefined2', 'undefined3', 'undefined4', 'undefined8', 'byte', 'sbyte',
             'char', 'uchar', 'short', 'ushort', 'int', 'uint', 'long', 'ulong', 'longlong', 'ulonglong', 'bool',
             'code', 'void', 'word', 'dword', 'float', 'double', 'pointer', 'undefined5', 'undefined6', 'undefined7'}
    if base not in known: return None
    t = t.replace('pointer', 'void *')
    return (t, '')


STACKVAR = re.compile(r'^  ([A-Za-z_][\w ]*?\**)\s*\b((?:[a-z]+Stack|local)_([0-9a-f]+))\s*(\[(\d+)\])?;\s*$', re.M)


def stack_frame(c):
    """Ghidra declares each stack slot as a separate local (local_20, uStack_1c, auStack_70[16], ...). When the code
    passes the address of one of them to a callee, the callee often reads the *neighbouring* slots too (a struct Ghidra
    didn't recover). GCC treats the locals as unrelated objects and drops the stores it thinks nobody reads (seen: a
    rectangle {0,0,30,20} passed by pointer lost three of its fields). So when any stack slot's address escapes, put all slots
    into one frame array at their original offsets (`local_XX` = entry SP - 0xXX)."""
    decls = list(STACKVAR.finditer(c))
    if not decls: return c
    names = [m.group(2) for m in decls]
    escapes = any(m.group(4) for m in decls) or any(re.search(r'&\s*' + n + r'\b', c) for n in names)
    if not escapes: return c
    top = max(int(m.group(3), 16) for m in decls)
    size = (top + 3) // 4
    out = c
    first = True
    for m in decls:
        t, n, off, arr = m.group(1).strip(), m.group(2), int(m.group(3), 16), m.group(4)
        pos = top - off
        if arr:
            d = '#define %s ((%s *)((char *)__frame + 0x%x))' % (n, t, pos)
        else:
            d = '#define %s (*(%s *)((char *)__frame + 0x%x))' % (n, t, pos)
        if first:
            d = '  unsigned int __frame[%d];   /* stack slots at their original offsets (see autodecomp.stack_frame) */\n' % size + d
            first = False
        out = out.replace(m.group(0), d, 1)
    return out


_ROMSYMS = None


def absval(a): return a if isinstance(a, str) else '0x%08X' % a


def rom_symbol(a):
    """'label' or 'label + 0xN' for a ROM data address (labels from log1.elf)"""
    global _ROMSYMS
    if _ROMSYMS is None:
        import bisect
        out = subprocess.run(['arm-none-eabi-nm', '-n', 'log1.elf'], capture_output=True, text=True).stdout
        syms = []
        for l in out.split('\n'):
            p = l.split()
            if len(p) == 3 and p[1] in 'tTdDrRbB' and not p[2].startswith(('$', '.')):
                v = int(p[0], 16)
                if 0x08000000 <= v < 0x0A000000: syms.append((v, p[2]))
        _ROMSYMS = sorted(syms)
    import bisect
    i = bisect.bisect_right(_ROMSYMS, (a, '\uffff')) - 1
    if i < 0: return None
    v, n = _ROMSYMS[i]
    if a - v > 0x10000: return None
    return n if a == v else '%s + 0x%X' % (n, a - v)


PARTIAL = re.compile(r'\b([A-Za-z_]\w*)\._(\d+)_(\d+)_')
RAWADDR = re.compile(r'\b(_?DAT_|[a-z]{0,3}Ram|ram0x)([0-9a-fA-F]{8})\b')
PREFIX_T = {'': None, 'u': 'uint', 'i': 'int', 's': 'short', 'us': 'ushort', 'c': 'char', 'uc': 'uchar',
            'b': 'byte', 'p': 'undefined4', 'pp': 'undefined4', 'pu': 'undefined4', 'pi': 'undefined4', 'f': None}
_WIDTHS = {}


def access_widths(a, e):
    """{address: bytes} for the absolute RAM/IO addresses the function at [a, e) loads or stores, from its machine code
    (literal-pool constant in a register, then ldr/ldrh/ldrb/str... [rN, #k])."""
    if (a, e) in _WIDTHS: return _WIDTHS[(a, e)]
    import capstone
    rom = open('log1.gba', 'rb').read()
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB); md.detail = True
    from capstone import arm
    const, out = {}, {}
    signed = set()
    for ins in md.disasm(rom[a - 0x08000000:e - 0x08000000], a):
        ops = ins.operands
        m = ins.mnemonic
        if m.startswith(('ldr', 'str')) and len(ops) >= 2 and ops[1].type == arm.ARM_OP_MEM:
            mem = ops[1].mem
            if mem.base == arm.ARM_REG_PC and m == 'ldr':
                lit = ((ins.address + 4) & ~3) + mem.disp
                const[ops[0].reg] = int.from_bytes(rom[lit - 0x08000000:lit - 0x07FFFFFC], 'little'); continue
            if mem.base in const and mem.index == 0:
                w = 1 if m[3:].startswith(('b', 'sb')) else 2 if m[3:].startswith(('h', 'sh')) else 4
                out.setdefault(const[mem.base] + mem.disp, w)
                if m.startswith('ldrs'): signed.add(const[mem.base] + mem.disp)
        if m in ('adds', 'add') and len(ops) == 2 and ops[0].reg in const and ops[1].type == arm.ARM_OP_IMM:
            const[ops[0].reg] += ops[1].imm; continue
        if m in ('adds', 'add', 'subs', 'sub') and len(ops) == 3 and ops[1].type == arm.ARM_OP_REG and ops[1].reg in const \
                and ops[2].type == arm.ARM_OP_IMM:
            const[ops[0].reg] = const[ops[1].reg] + (ops[2].imm if m.startswith('add') else -ops[2].imm); continue
        if m in ('movs', 'mov') and len(ops) == 2 and ops[1].type == arm.ARM_OP_REG and ops[1].reg in const:
            const[ops[0].reg] = const[ops[1].reg]; continue
        if m.startswith(('ldr', 'mov', 'add', 'sub', 'lsl', 'lsr', 'asr', 'and', 'orr', 'eor', 'mul', 'neg', 'mvn', 'bic', 'adc', 'sbc', 'ror', 'pop')) or m == 'bl':
            for o in ops:
                if o.type == arm.ARM_OP_REG and o is ops[0]: const.pop(o.reg, None)
            if m == 'bl': [const.pop(r, None) for r in (arm.ARM_REG_R0, arm.ARM_REG_R1, arm.ARM_REG_R2, arm.ARM_REG_R3)]
    out = {k: (-v if k in signed else v) for k, v in out.items()}      # negative = loaded sign-extended
    _WIDTHS[(a, e)] = out
    return out


def fix_names(c, f, declared, rng):
    """Ghidra notations that aren't C: `x._2_2_` (2 bytes at offset 2 of x) and raw addresses it never exported as
    globals (`Ram040000dc`, `_DAT_030005f0` = DAT_030005f0 accessed with another size, `sRam0300086e`)."""
    c = PARTIAL.sub(lambda m: '(*(undefined%s *)((char *)&%s + %s))' % (m.group(3), m.group(1), m.group(2)), c)
    defs = []
    seen = set()
    for m in RAWADDR.finditer(c):
        name = m.group(0)
        if name in declared or name in seen: continue
        seen.add(name)
        addr = int(m.group(2), 16)
        pre = m.group(1)
        t = None
        if pre.endswith('Ram'):
            t = PREFIX_T.get(pre[:-3])
        if t is None:
            w = access_widths(*rng).get(addr) if rng else None
            w = abs(w) if w else w
            if w is None and pre in ('_DAT_', 'Ram'): w = 4    # Ghidra's spelling for a 4-byte access
            if w is None: return None, 'width:' + name
            t = {1: 'undefined1', 2: 'undefined2', 4: 'undefined4'}[w]
        if 0x08000000 <= addr < 0x0A000000: return None, 'rom-abs:' + name
        defs.append('#define %s (*(%s volatile *)0x%08X)' % (name, t, addr))
    return c, defs


def make_tu(f, F, allnames, rng=None):
    c = f.get('c')
    if not c: return None, 'no-c'
    c = stack_frame(c)
    code = re.sub(r'/\*.*?\*/|//[^\n]*', '', c, flags=re.S)       # (hand-written files explain these words in comments)
    for p in BAD:
        if re.search(r'(?<![A-Za-z0-9_])' + re.escape(p), code): return None, 'pattern:' + p
    me = f['name']
    lines = ['#include "ghidra_types.h"']
    wide_locals = re.findall(r'^\s+undefined8\s+(\w+);', c, re.M)
    absdefs = {}
    declared = set()
    for name, proto, addr in f.get('callees', []):
        if name == me or name in declared: continue
        declared.add(name)
        rt = proto.split('(')[0].rsplit(' ', 1)[0].strip() if '(' in proto else 'int'
        if any(rt.startswith(w) for w in WIDE): lines.append('extern %s %s();' % (rt.replace('pointer', 'void *'), name))
        elif any(re.search(r'\b%s\s*=\s*%s\(' % (v, re.escape(name)), c) for v in wide_locals):
            # Ghidra keeps both result registers (r0:r1, e.g. quotient and remainder of __rt_sdiv) in an undefined8
            lines.append('extern undefined8 %s();' % name)
        else: lines.append('extern int %s();' % name)
    rng = rng
    for name, t, addr, size in f.get('globals', []):
        if not re.match(r'^\w+$', name):          # PTR_sub_08002910+1_08010868: a pointer to a Thumb function
            clean = re.sub(r'\W', '_', name); c = c.replace(name, clean); name = clean
        if name in declared or name == me: continue
        declared.add(name)
        if name in allnames:
            lines.append('extern int %s();' % name); continue
        if t in ('undefined', 'undefined1', 'undefined2', 'undefined4') and addr and rng:
            # Ghidra had no type for it (size from the first use it saw); the machine code says how it's accessed
            w = access_widths(*rng).get(int(addr))
            if w: t = {1: 'byte', -1: 'sbyte', 2: 'ushort', -2: 'short', 4: 'undefined4', -4: 'undefined4'}[w]
        d = decl_type(t)
        if d is None: return None, 'type:' + t
        if t == 'code': lines.append('extern int %s();' % name); continue
        # volatile: the original re-reads RAM/IO on every access (IRQ handlers and DMA change it behind the code's back);
        # without it GCC may hoist a load out of a wait loop and hang. The qualifier sits after the type, so for
        # pointers it qualifies the variable itself.
        lines.append('extern %s volatile %s%s;' % (d[0], name, d[1]))
        if name.startswith(ABS_PREFIX) and addr:
            a = int(addr)
            if 0x08000000 <= a < 0x0A000000:
                # ROM data: refer to it through the label that contains it, so the address follows the data
                # if the layout ever changes (the decomp build itself never moves an original byte)
                sym = rom_symbol(a)
                if sym is None: return None, 'rom-abs:' + name
                absdefs[name] = sym
            else:
                absdefs[name] = a
    c, defs = fix_names(c, f, declared, rng)
    if c is None: return None, defs
    lines += defs
    lines.append('')
    lines.append(c)
    return '\n'.join(lines), absdefs


def cmd_tus():
    F = load_funcs(); R = replaceable()
    allnames = set(F)
    os.makedirs(B + '/tu', exist_ok=True)
    st = {}
    rom = open('log1.gba', 'rb').read()
    for n, (a, e) in R.items():
        f = F.get(n)
        if not f: st[n] = {'status': 'no-ghidra'}; continue
        # variadic functions start by spilling their argument registers next to the caller's stack arguments
        # (`push {r0-r3}` / `push {r2, r3}` without lr), then walk them with a pointer. Ghidra's C copies only the
        # named registers into locals, so the extra arguments are lost. Leave these in assembly.
        h = rom[a - 0x08000000] | rom[a - 0x08000000 + 1] << 8
        if (h & 0xFF00) == 0xB400 and (h & 0x08) and not (h & 0xF0) \
                and not os.path.exists('tools/decomp/manual/%s.c' % n):     # push {..r3} without r4-r7 or lr; unless hand-written
            st[n] = {'status': 'rejected', 'why': 'varargs: push {..r3} prologue'}; continue
        man = 'tools/decomp/manual/%s.c' % n
        if os.path.exists(man):
            # hand-written C (see tools/decomp/manual/README.md) in place of Ghidra's text; it gets the same
            # extern declarations for the callees and globals Ghidra found
            f = dict(f, c=open(man).read())
        tu, info = make_tu(f, F, allnames, (a, e))
        if os.path.exists(man):
            if tu is None: st[n] = {'status': 'rejected', 'why': 'manual: ' + info}; continue
            open('%s/tu/%s.c' % (B, n), 'w').write(tu)
            st[n] = {'status': 'tu', 'abs': info, 'addr': a, 'end': e, 'manual': True}; continue
        if tu is None: st[n] = {'status': 'rejected', 'why': info}; continue
        open('%s/tu/%s.c' % (B, n), 'w').write(tu)
        st[n] = {'status': 'tu', 'abs': info, 'addr': a, 'end': e}
    json.dump(st, open(B + '/status.json', 'w'), indent=0)
    print(collections.Counter(v['status'] for v in st.values()))
    print(collections.Counter(v.get('why', '').split(':')[0] for v in st.values() if v['status'] == 'rejected').most_common(12))


def compile_one(n):
    src = '%s/tu/%s.c' % (B, n); obj = '%s/obj/%s.o' % (B, n)
    r = subprocess.run(['tools/decomp/cc.sh', obj, src] + CC[1:], capture_output=True, text=True)
    if r.returncode:
        errs = [l for l in r.stderr.split('\n') if ': error: ' in l]
        return n, False, ('\n'.join(errs[:3]) or r.stderr.strip()[-300:])
    # link standalone at a scratch address against the original ROM symbols
    absf = '%s/obj/%s.abs.ld' % (B, n)
    elf = '%s/obj/%s.elf' % (B, n)
    # the ROM symbol table also defines `n` (at the original address): rename ours so the test runs *our* code
    cobj = obj[:-2] + '.cand.o'
    subprocess.run(['arm-none-eabi-objcopy', '--redefine-sym', '%s=__candidate' % n, obj, cobj], check=True)
    r = subprocess.run(['arm-none-eabi-ld', '-o', elf, '-Ttext=0x09000000', '-e', '__candidate',
                        '--just-symbols=' + B + '/allsyms.elf', absf, cobj, LIBGCC], capture_output=True, text=True)
    if r.returncode: return n, False, 'link: ' + (r.stderr.strip().split('\n') or [''])[0][-200:]
    return n, True, ''


def cmd_compile():
    st = json.load(open(B + '/status.json'))
    os.makedirs(B + '/obj', exist_ok=True)
    # symbol table of the matching build (make first); candidates link against it
    subprocess.run(['cp', 'log1.elf', B + '/allsyms.elf'], check=True)
    todo =[n for n, v in st.items() if v['status'] not in ('rejected', 'no-ghidra')]
    for n in todo:
        with open('%s/obj/%s.abs.ld' % (B, n), 'w') as f:
            for k, a in st[n].get('abs', {}).items(): f.write('%s = %s;\n' % (k, absval(a)))
    with ProcessPoolExecutor() as ex:
        for n, ok, err in ex.map(compile_one, todo, chunksize=16):
            st[n]['status'] = 'compiled' if ok else 'compile-failed'
            if not ok: st[n]['err'] = err
    json.dump(st, open(B + '/status.json', 'w'), indent=0)
    print(collections.Counter(v['status'] for v in st.values()))
    errs = collections.Counter(re.sub(r"'[^']*'", "'X'", v.get('err', ''))[:90] for v in st.values() if v['status'] == 'compile-failed')
    for e, c in errs.most_common(10): print(c, e)


# ------------------------------------------------------------------ equivalence testing (Unicorn)
SNAPDIR = os.environ.get('SNAPDIR', '.analysis/snaps')
MAGIC = 0x0A000000
R0_DEAD = {int(l, 16) for l in open('.analysis/decomp/r0_dead.txt')} if os.path.exists('.analysis/decomp/r0_dead.txt') else set()
R0_DIRECT = {int(l, 16) for l in open('.analysis/decomp/r0_direct_dead.txt')} if os.path.exists('.analysis/decomp/r0_direct_dead.txt') else set()


def read_snap(path):
    d = open(path, 'rb').read()
    regs = struct.unpack_from('<18I', d, 0); p = 72
    mem = {}
    while p < len(d):
        base, size, zl = struct.unpack_from('<3I', d, p); p += 12
        mem[base] = zlib.decompress(d[p:p + zl]); p += zl
    return regs, mem


def bios_hle(uc):
    """High-level emulation of the BIOS calls the game makes (decompression and Div), so functions that use them can
    still be tested: returns False for anything else (Halt, SoftReset, semihosting), which stops the run as
    inconclusive. Both the original and the candidate run through the same emulation. The frame wait (Halt in
    WaitForVBlank) is modelled as the VBlank interrupt having set the flag it waits for."""
    from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R3, UC_ARM_REG_PC, UC_ARM_REG_CPSR, UC_ARM_REG_LR
    sys.path.insert(0, os.path.join(ROOT, 'tools', 'bfdis')); sys.path.insert(0, os.path.join(ROOT, 'tools', 'assets'))
    import lz as dec, bios
    pc = uc.reg_read(UC_ARM_REG_PC)
    thumb = uc.reg_read(UC_ARM_REG_CPSR) & 0x20
    # Unicorn reports the exception with PC at the svc instruction itself or just after it, depending on version
    for at in ((pc - 2, pc) if thumb else (pc - 4, pc)):
        try: ins = bytes(uc.mem_read(at, 2 if thumb else 4))
        except Exception: continue
        if thumb and ins[1] == 0xDF: num, nxt = ins[0], at + 2; break
        if not thumb and ins[3] & 0x0F == 0x0F: num, nxt = ins[2], at + 4; break
    else:
        return False
    r0, r1 = uc.reg_read(UC_ARM_REG_R0), uc.reg_read(UC_ARM_REG_R1)
    if num == 2 and at == 0x080099EA:
        # Halt inside WaitForVBlank: it sleeps until the interrupt handler sets one of the bits it waits for (r4) in
        # the halfword at r5+2. Model the interrupt as having happened: set those bits (and nothing else), so a
        # function that waits for frames runs to completion, the same way in both runs.
        from unicorn.arm_const import UC_ARM_REG_R4, UC_ARM_REG_R5
        p = uc.reg_read(UC_ARM_REG_R5) + 2
        v = int.from_bytes(uc.mem_read(p, 2), 'little') | (uc.reg_read(UC_ARM_REG_R4) & 0xFFFF)
        uc.mem_write(p, v.to_bytes(2, 'little'))
    elif num == 6:
        a, b = struct.unpack('<ii', struct.pack('<II', r0, r1))
        if b == 0: return False
        q = abs(a) // abs(b) * (1 if (a < 0) == (b < 0) else -1); r = a - q * b
        uc.reg_write(UC_ARM_REG_R0, q & 0xFFFFFFFF); uc.reg_write(UC_ARM_REG_R1, r & 0xFFFFFFFF); uc.reg_write(UC_ARM_REG_R3, abs(q))
    elif num in (0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18):
        try:
            src = bytes(uc.mem_read(r0, 4)); n = int.from_bytes(src[1:4], 'little')
            src = bytes(uc.mem_read(r0, min(0x40000, max(4, (n * 9) // 8 + 0x1000))))
        except Exception:
            try: src = bytes(uc.mem_read(r0, 0x1000))
            except Exception: return False
        f = {0x11: dec.lz77, 0x12: dec.lz77, 0x13: dec.huffman, 0x14: dec.rle, 0x15: dec.rle}.get(num)
        r = f(src, 0) if f else bios.diff_decode(src, 0, 1 if num in (0x16, 0x17) else 2)
        if r is None: return False
        try: uc.mem_write(r1, bytes(r[0]))
        except Exception: return False
    else:
        return False
    uc.reg_write(UC_ARM_REG_PC, nxt | (1 if thumb else 0))
    return True


def run_fn(rom, cand_img, entry, regs, mem, limit=3_000_000, cover=None):
    from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE, UC_HOOK_INTR, UcError
    from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_CPSR
    uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    uc.mem_map(0, 0x4000)
    for base, data in mem.items():
        uc.mem_map(base, max(0x1000, (len(data) + 0xFFF) & ~0xFFF)); uc.mem_write(base, data)
    uc.mem_map(0x08000000, 0x01000000); uc.mem_write(0x08000000, rom)
    if cand_img:
        uc.mem_map(0x09000000, 0x100000); uc.mem_write(0x09000000, cand_img)
    uc.mem_map(MAGIC, 0x1000)
    for i in range(13): uc.reg_write(UC_ARM_REG_R0 + i, regs[i])
    uc.reg_write(UC_ARM_REG_SP, regs[13]); uc.reg_write(UC_ARM_REG_LR, MAGIC | 1)
    ev = {'swi': None}
    def intr(uc_, intno, ud):
        if not bios_hle(uc_):
            ev['swi'] = intno; uc_.emu_stop()
    uc.hook_add(UC_HOOK_INTR, intr)
    if cover is not None:
        lo, hi, hits = cover
        uc.hook_add(UC_HOOK_CODE, lambda uc_, a, sz, ud: hits.add(a), None, lo, hi - 1)
    err = None
    try:
        uc.emu_start(entry | 1, MAGIC, count=limit)
    except UcError as e:
        err = str(e)
    pc = uc.reg_read(UC_ARM_REG_PC)
    out = dict(pc=pc & ~1, err=err, swi=ev['swi'],
               regs=[uc.reg_read(UC_ARM_REG_R0 + i) for i in range(13)] + [uc.reg_read(UC_ARM_REG_SP)])
    out['mem'] = {b: bytes(uc.mem_read(b, len(d))) for b, d in mem.items()}
    return out


def compare(o, c, sp0, retvoid=False, r0_in=None, entry=None, lr=None):
    if o['err'] or c['err']:
        return 'inconclusive' if (o['err'] and c['err']) else ('orig-error' if o['err'] else 'cand-error')
    if (o['pc'] == MAGIC) != (c['pc'] == MAGIC): return 'different-exit'
    if o['pc'] != MAGIC:
        return 'inconclusive'                                   # both stopped at a BIOS call or the limit
    if o['regs'][0] != c['regs'][0]:
        if not retvoid: return 'r0'
        # Ghidra says void, but the original returns its first argument: an ADS C++ constructor returning `this`.
        # Callers use it, so this is a real difference (fixed by `autodecomp.py fixthis`).
        if r0_in is not None and o['regs'][0] == r0_in: return 'r0-this'
        # anything else left in r0 by a "void" function may still be used by a caller (e.g. a factory that
        # returns its callee's result): be strict.
        # ... unless tools/decomp/r0live.py proved that no caller reads it
        if entry in R0_DEAD: return 'equal-r0dead'
        # weaker: no direct caller reads it, and the caller this snapshot returns to doesn't either
        if entry in R0_DIRECT and lr is not None:
            sys.path.insert(0, os.path.join(ROOT, 'tools', 'decomp'))
            import r0live
            if r0live.site_dead(lr): return 'equal-r0unread'
        return 'r0-void'
    if o['regs'][1] != c['regs'][1] and False: return 'r1'
    if o['regs'][13] != c['regs'][13]: return 'sp'
    for i in range(4, 12):
        if o['regs'][i] != c['regs'][i]: return 'r%d' % i
    for b in o['mem']:
        x, y = o['mem'][b], c['mem'][b]
        if b == 0x03000000:            # ignore the stack below the entry SP (dead temporaries)
            lo = max(0, sp0 - 0x03000000 - 0x1000); hi = min(len(x), sp0 - 0x03000000)
            x = x[:lo] + x[hi:]; y = y[:lo] + y[hi:]
        if x != y: return 'mem@%08X' % b
    return 'equal'


def test_one(args):
    n, addr, snaps = args[:3]
    end, ninsn = (args[3], args[4]) if len(args) > 4 else (addr + 2, 1)
    retvoid = args[5] if len(args) > 5 else False
    hits = set()
    rom0 = open('log1.gba', 'rb').read()
    # snapshots taken with a capture-only ROM variant (tools/harness/capture_variants.py) run against that ROM
    rmap = json.load(open(SNAPDIR + '/roms.json')) if os.path.exists(SNAPDIR + '/roms.json') else {}
    roms = {}
    def rom_for(path):
        tag = os.path.basename(path)[:-5].split('_', 1)[1]          # e.g. warp021 = tag warp02, snapshot 1
        p = next((rmap[k] for k in sorted(rmap, key=len, reverse=True) if tag.startswith(k)), None)
        if not p: return rom0
        if p not in roms: roms[p] = open(p, 'rb').read()
        return roms[p]
    elf = '%s/obj/%s.elf' % (B, n)
    img = subprocess.run(['arm-none-eabi-objcopy', '-O', 'binary', '-j', '.text', elf, '/dev/stdout'],
                         capture_output=True).stdout
    sym = subprocess.run(['arm-none-eabi-nm', elf], capture_output=True, text=True).stdout
    ent = None
    for l in sym.split('\n'):
        p = l.split()
        if len(p) == 3 and p[2] == '__candidate': ent = int(p[0], 16)
    # stubs/veneers live in other sections: take everything from 0x09000000
    img = subprocess.run(['arm-none-eabi-objcopy', '-O', 'binary', elf, '/dev/stdout'], capture_output=True).stdout
    results = []
    import random
    for s in snaps:
        regs, mem = read_snap(s)
        rom = rom_for(s)
        o = run_fn(rom, None, addr, regs, mem, cover=(addr, end, hits))
        c = run_fn(rom, img, ent & ~1, regs, mem)
        r = compare(o, c, regs[13], retvoid, regs[0], addr, regs[14])
        if r in ('equal', 'equal-r0dead', 'equal-r0unread') and 0x03000000 in mem:
            # Same state, but the free stack below SP filled with noise. Some original functions read stack slots
            # they never wrote (garbage left by earlier calls); a C version keeps its locals elsewhere, so it only
            # behaves the same if the garbage doesn't matter. Catches results that agree only by luck.
            m2 = dict(mem); iw = bytearray(mem[0x03000000]); sp = regs[13] - 0x03000000
            rnd = random.Random(addr); lo = max(0, sp - 0x800)
            iw[lo:sp] = bytes(rnd.getrandbits(8) for _ in range(sp - lo)); m2[0x03000000] = bytes(iw)
            o2 = run_fn(rom, None, addr, regs, m2); c2 = run_fn(rom, img, ent & ~1, regs, m2)
            r2 = compare(o2, c2, regs[13], retvoid, regs[0], addr, regs[14])
            if r2 not in ('equal', 'equal-r0dead', 'equal-r0unread', 'inconclusive'): r = 'stack-garbage:' + r2
        results.append(r)
    return n, results, len(hits) / max(1, ninsn)


MAXSNAP = int(os.environ.get('MAXSNAP', 30))


def pick(paths):
    """at most MAXSNAP snapshots, taken round-robin over the routes they come from (most varied states)"""
    by = collections.defaultdict(list)
    for p in sorted(paths):
        by[os.path.basename(p)[:-5].split('_', 1)[1][:-1]].append(p)      # route tag (last digit = snapshot no.)
    out, k = [], 0
    while len(out) < MAXSNAP and any(k < len(v) for v in by.values()):
        for t in sorted(by):
            if k < len(by[t]) and len(out) < MAXSNAP: out.append(by[t][k])
        k += 1
    return out


def cmd_test():
    st = json.load(open(B + '/status.json'))
    snaps = collections.defaultdict(list)
    for p in glob.glob(SNAPDIR + '/*.snap'):
        snaps[int(os.path.basename(p).split('_')[0], 16)].append(p)
    import pickle
    db = pickle.load(open('.analysis/analysis.pickle', 'rb'))
    ins = sorted(db['insn'])
    import bisect
    def ninsn(a, e): return bisect.bisect_left(ins, e) - bisect.bisect_left(ins, a)
    F = load_funcs()
    def isvoid(n): return (F.get(n, {}).get('sig') or '').strip().startswith('void ')
    only = set(sys.argv[sys.argv.index('--only') + 1].split(',')) if '--only' in sys.argv else None
    todo = [(n, v['addr'], pick(snaps[v['addr']]), v['end'], ninsn(v['addr'], v['end']), isvoid(n)) for n, v in st.items()
            if (only is None or n in only) and v['status'] in ('compiled', 'untested', 'accepted', 'rejected-equiv', 'inconclusive') and snaps.get(v['addr'])]
    for n, v in st.items():
        if v['status'] == 'compiled' and not snaps.get(v['addr']): v['status'] = 'untested'
    with ProcessPoolExecutor() as ex:
        for n, res, cov in ex.map(test_one, todo, chunksize=1 if only else 4):
            if only: print(n, 'coverage %.0f%%' % (100 * cov), collections.Counter(res))
            st[n]['tests'] = res; st[n]['coverage'] = round(cov, 3)
            if any(r not in ('equal', 'equal-r0dead', 'equal-r0unread', 'inconclusive') for r in res): st[n]['status'] = 'rejected-equiv'
            elif 'equal' in res or 'equal-r0dead' in res or 'equal-r0unread' in res: st[n]['status'] = 'accepted'
            else: st[n]['status'] = 'inconclusive'
    json.dump(st, open(B + '/status.json', 'w'), indent=0)
    print(collections.Counter(v['status'] for v in st.values()))
    print(collections.Counter(r for v in st.values() for r in v.get('tests', [])).most_common(12))
    acc = [v for v in st.values() if v['status'] == 'accepted']
    for t in (1.0, 0.9, 0.75, 0.5):
        print('accepted with coverage >= %.2f: %d' % (t, sum(1 for v in acc if v.get('coverage', 0) >= t)))


def cmd_fixthis():
    """Functions rejected only with 'r0-this': make the Ghidra `void f(T param_1, ...)` return param_1."""
    st = json.load(open(B + '/status.json'))
    n_fixed = 0
    for n, v in st.items():
        t = v.get('tests', [])
        if v['status'] != 'rejected-equiv' or not set(t) <= {'equal', 'equal-r0dead', 'inconclusive', 'r0-this', 'r0-void'} or 'r0-this' not in t: continue
        p = '%s/tu/%s.c' % (B, n); src = open(p).read()
        m = re.search(r'^void (%s)\(([^,)]*?)\bparam_1\b' % n, src, re.M)
        if not m: continue
        ptype = m.group(2).strip() or 'int'
        body = src[m.end():]
        src = src[:m.start()] + '%s %s(%sparam_1' % (ptype, n, m.group(2)) + body
        src = re.sub(r'\breturn;', 'return param_1;', src)
        src = src.rstrip()
        assert src.endswith('}')
        src = src[:-1].rstrip() + '\n  return param_1;   /* ADS constructor: returns this */\n}\n'
        open(p, 'w').write(src); v['status'] = 'tu'; v.pop('tests', None); n_fixed += 1
    json.dump(st, open(B + '/status.json', 'w'), indent=0)
    print('rewrote', n_fixed, '-- now run compile and test again')


CALLSTMT = re.compile(r'^([ \t]+)((?!(?:if|while|for|switch|return|do)\b)(?:[A-Za-z_]\w*|\(\*[^;\n]*?\))[ \t]*\([^;\n]*\);)[ \t]*$', re.M)


def cmd_fixvoid():
    """Functions rejected only because a "void" function leaves something in r0 that callers may read: what the
    original leaves there is usually its last callee's result, or its own first argument if it calls nothing after
    computing it. Rewrite `void f(...)` to keep the r0 value in `__r0` (initially param_1, then each call's result)
    and return it. Then compile and test again: functions where r0 is something else still fail."""
    st = json.load(open(B + '/status.json'))
    n_fixed = 0
    for n, v in st.items():
        t = v.get('tests', [])
        if v['status'] != 'rejected-equiv' or v.get('manual') or not set(t) <= {'equal', 'equal-r0dead', 'inconclusive', 'r0-void', 'r0-this'}: continue
        p = '%s/tu/%s.c' % (B, n); src = open(p).read()
        m = re.search(r'^void (%s)\(([^)]*)\)\s*\{' % n, src, re.M)
        if not m: continue
        args = m.group(2).strip()
        init = '(undefined4)param_1' if re.search(r'\bparam_1\b', args) else '0'
        head = 'undefined4 %s(%s)\n{\n  undefined4 __r0 = %s;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */' % (n, m.group(2), init)
        body = src[m.end():]
        body = CALLSTMT.sub(lambda k: k.group(1) + '__r0 = (undefined4)' + k.group(2), body)
        body = re.sub(r'\breturn;', 'return __r0;', body).rstrip()
        assert body.endswith('}')
        body = body[:-1].rstrip() + '\n  return __r0;\n}\n'
        open(p, 'w').write(src[:m.start()] + head + body); v['status'] = 'tu'; v.pop('tests', None); v['fixvoid'] = True
        n_fixed += 1
    json.dump(st, open(B + '/status.json', 'w'), indent=0)
    print('rewrote', n_fixed, '-- now run compile and test again')


def cmd_emit():
    """src/<asm file>/<function>.c for every compiled function, plus tier lists:
         config/decomp_verified.txt   equivalent on every snapshot, >= 90% of instructions executed
         config/decomp_tested.txt     equivalent on every snapshot, lower coverage
         config/decomp_untested.txt   compiles, never reached by the capture routes"""
    st = json.load(open(B + '/status.json'))
    files = {}
    for l in open('.analysis/ghidra/ranges.txt'):
        n, a, e = l.split(); files[n] = (int(a, 16), int(e, 16))
    import shutil
    shutil.rmtree('src', ignore_errors=True)
    tiers = collections.defaultdict(list)
    # config/decomp_blocklist.txt: "name  reason" for functions that pass the snapshot tests but break the whole game
    block = {}
    if os.path.exists('config/decomp_blocklist.txt'):
        for l in open('config/decomp_blocklist.txt'):
            if l.strip() and not l.startswith('#'):
                k, _, why = l.strip().partition(' '); block[k] = why.strip()
    for n, v in sorted(st.items(), key=lambda kv: kv[1].get('addr', 0)):
        if v['status'] not in ('accepted', 'untested', 'inconclusive', 'rejected-equiv'): continue
        if n in block: v = dict(v, status='blocked')
        f = next((k for k, (a, e) in files.items() if a <= v['addr'] < e), 'misc')
        os.makedirs('src/' + f, exist_ok=True)
        tu = open('%s/tu/%s.c' % (B, n)).read()
        tests = v.get('tests', [])
        tag = {'accepted': 'equivalent on %d/%d snapshots, %d%% of instructions covered' % (sum(t.startswith('equal') for t in tests), len(tests), 100 * v.get('coverage', 0)),
               'untested': 'not reached by the capture routes (compiles; unverified)',
               'inconclusive': 'snapshots inconclusive (BIOS call or fault before return)',
               'rejected-equiv': 'NOT equivalent: %s' % ', '.join(sorted(set(tests))),
               'blocked': 'BLOCKED: %s' % block.get(n, '')}[v['status']]
        hdr = '/* %s  (original: 0x%08X-0x%08X in asm/%s.s)\n * Ghidra decompilation, compiled with GCC; %s.\n */\n' % (n, v['addr'], v['end'], f, tag)
        open('src/%s/%s.c' % (f, n), 'w').write(hdr + tu)
        for k, a in v.get('abs', {}).items(): pass
        if v['status'] == 'accepted':
            tiers['verified' if v.get('coverage', 0) >= 0.9 else 'tested'].append((f, n))
        elif v['status'] in ('untested', 'inconclusive'): tiers['untested'].append((f, n))
        else: tiers['failing'].append((f, n))
    absdefs = {}
    for v in st.values(): absdefs.update(v.get('abs', {}))
    with open('src/absolute.ld', 'w') as f:
        f.write('/* Absolute addresses of RAM/IO globals named by Ghidra (DAT_xxxxxxxx) */\n')
        for k, a in sorted(absdefs.items()): f.write('%s = %s;\n' % (k, absval(a)))
    for t in ('verified', 'tested', 'untested', 'failing'):
        open('config/decomp_%s.txt' % t, 'w').write(''.join('%s/%s\n' % x for x in tiers[t]))
        print(t, len(tiers[t]))


if __name__ == '__main__':
    {'tus': cmd_tus, 'compile': cmd_compile, 'test': cmd_test, 'fixthis': cmd_fixthis, 'fixvoid': cmd_fixvoid, 'emit': cmd_emit}[sys.argv[1]]()
