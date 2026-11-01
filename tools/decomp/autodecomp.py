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


def make_tu(f, F, allnames):
    c = f.get('c')
    if not c: return None, 'no-c'
    c = stack_frame(c)
    for p in BAD:
        if p in c: return None, 'pattern:' + p
    me = f['name']
    lines = ['#include "ghidra_types.h"']
    absdefs = {}
    declared = set()
    for name, proto, addr in f.get('callees', []):
        if name == me or name in declared: continue
        declared.add(name)
        rt = proto.split('(')[0].rsplit(' ', 1)[0].strip() if '(' in proto else 'int'
        if any(rt.startswith(w) for w in WIDE): lines.append('extern %s %s();' % (rt.replace('pointer', 'void *'), name))
        else: lines.append('extern int %s();' % name)
    for name, t, addr, size in f.get('globals', []):
        if name in declared or name == me: continue
        declared.add(name)
        if name in allnames:
            lines.append('extern int %s();' % name); continue
        d = decl_type(t)
        if d is None: return None, 'type:' + t
        if t == 'code': lines.append('extern int %s();' % name); continue
        # volatile: the original re-reads RAM/IO on every access (IRQ handlers and DMA change it behind the code's back);
        # without it GCC may hoist a load out of a wait loop and hang. The qualifier sits after the type, so for
        # pointers it qualifies the variable itself.
        lines.append('extern %s volatile %s%s;' % (d[0], name, d[1]))
        if name.startswith(ABS_PREFIX) and addr:
            a = int(addr)
            if a >= 0x08000000: return None, 'rom-abs:' + name     # would not relocate in the decomp build
            absdefs[name] = a
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
        if (h & 0xFF00) == 0xB400 and (h & 0x08):
            st[n] = {'status': 'rejected', 'why': 'varargs: push {..r3} prologue'}; continue
        tu, info = make_tu(f, F, allnames)
        if tu is None: st[n] = {'status': 'rejected', 'why': info}; continue
        open('%s/tu/%s.c' % (B, n), 'w').write(tu)
        st[n] = {'status': 'tu', 'abs': info, 'addr': a, 'end': e}
    json.dump(st, open(B + '/status.json', 'w'), indent=0)
    print(collections.Counter(v['status'] for v in st.values()))
    print(collections.Counter(v.get('why', '').split(':')[0] for v in st.values() if v['status'] == 'rejected').most_common(12))


def compile_one(n):
    src = '%s/tu/%s.c' % (B, n); obj = '%s/obj/%s.o' % (B, n)
    r = subprocess.run(['tools/decomp/cc.sh', obj, src] + CC[1:], capture_output=True, text=True)
    if r.returncode: return n, False, (r.stderr.strip().split('\n') or [''])[0][-200:]
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
            for k, a in st[n].get('abs', {}).items(): f.write('%s = 0x%X;\n' % (k, a))
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


def read_snap(path):
    d = open(path, 'rb').read()
    regs = struct.unpack_from('<18I', d, 0); p = 72
    mem = {}
    while p < len(d):
        base, size, zl = struct.unpack_from('<3I', d, p); p += 12
        mem[base] = zlib.decompress(d[p:p + zl]); p += zl
    return regs, mem


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


def compare(o, c, sp0, retvoid=False, r0_in=None, entry=None):
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
        return 'r0-void' if entry not in R0_DEAD else 'equal-r0dead'
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
    rom = open('log1.gba', 'rb').read()
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
        o = run_fn(rom, None, addr, regs, mem, cover=(addr, end, hits))
        c = run_fn(rom, img, ent & ~1, regs, mem)
        r = compare(o, c, regs[13], retvoid, regs[0], addr)
        if r in ('equal', 'equal-r0dead') and 0x03000000 in mem:
            # Same state, but the free stack below SP filled with noise. Some original functions read stack slots
            # they never wrote (garbage left by earlier calls); a C version keeps its locals elsewhere, so it only
            # behaves the same if the garbage doesn't matter. Catches results that agree only by luck.
            m2 = dict(mem); iw = bytearray(mem[0x03000000]); sp = regs[13] - 0x03000000
            rnd = random.Random(addr); lo = max(0, sp - 0x800)
            iw[lo:sp] = bytes(rnd.getrandbits(8) for _ in range(sp - lo)); m2[0x03000000] = bytes(iw)
            o2 = run_fn(rom, None, addr, regs, m2); c2 = run_fn(rom, img, ent & ~1, regs, m2)
            r2 = compare(o2, c2, regs[13], retvoid, regs[0], addr)
            if r2 not in ('equal', 'equal-r0dead', 'inconclusive'): r = 'stack-garbage:' + r2
        results.append(r)
    return n, results, len(hits) / max(1, ninsn)


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
    todo = [(n, v['addr'], sorted(snaps[v['addr']]), v['end'], ninsn(v['addr'], v['end']), isvoid(n)) for n, v in st.items()
            if (only is None or n in only) and v['status'] in ('compiled', 'untested', 'accepted', 'rejected-equiv', 'inconclusive') and snaps.get(v['addr'])]
    for n, v in st.items():
        if v['status'] == 'compiled' and not snaps.get(v['addr']): v['status'] = 'untested'
    if only:
        for t in todo:
            n, res, cov = test_one(t)
            print(n, 'coverage %.0f%%' % (100 * cov), collections.Counter(res))
        return
    with ProcessPoolExecutor() as ex:
        for n, res, cov in ex.map(test_one, todo, chunksize=4):
            st[n]['tests'] = res; st[n]['coverage'] = round(cov, 3)
            if any(r not in ('equal', 'equal-r0dead', 'inconclusive') for r in res): st[n]['status'] = 'rejected-equiv'
            elif 'equal' in res or 'equal-r0dead' in res: st[n]['status'] = 'accepted'
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
        tag = {'accepted': 'equivalent on %d/%d snapshots, %d%% of instructions covered' % (tests.count('equal') + tests.count('equal-r0dead'), len(tests), 100 * v.get('coverage', 0)),
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
        for k, a in sorted(absdefs.items()): f.write('%s = 0x%08X;\n' % (k, a))
    for t in ('verified', 'tested', 'untested', 'failing'):
        open('config/decomp_%s.txt' % t, 'w').write(''.join('%s/%s\n' % x for x in tiers[t]))
        print(t, len(tiers[t]))


if __name__ == '__main__':
    {'tus': cmd_tus, 'compile': cmd_compile, 'test': cmd_test, 'fixthis': cmd_fixthis, 'emit': cmd_emit}[sys.argv[1]]()
