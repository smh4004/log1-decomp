#!/usr/bin/env python3
"""Timing control for a whole decomp build (see docs/decomp.md, "Timing").

    python3 tools/decomp/timing_control.py LIST OUT.gba

Builds the decomp ROM for LIST (lines `file/function`, as config/decomp_*.txt) with every listed function replaced
not by its C but by an exact copy of its own original instructions, linked the same way (long jump from the original
address, body in the .decomp section). The result behaves like the original game except for timing: the jumps cost
cycles and the code runs from another place. Played on the same routes, it shows which checkpoints a timing change of
that size already alters, and those can't be used to judge the C (timing_horizon.py --control OUT.gba).

Functions whose code depends on its own address (`add rN, pc`) can't be moved and keep their original code (they
are listed); so do functions that branch to a label outside themselves.
"""
import os, re, sys, glob, shutil, subprocess
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')); os.chdir(ROOT)


def block(name):
    for p in glob.glob('asm/code_*.s'):
        s = open(p).read()
        m = re.search(r'\tthumb_func_start %s\n(.*?)\n\t\.else\n' % re.escape(name), s, re.S)
        if m: return m.group(1)
    return None


_POOL = None


def pool_value(label):
    """the .4byte after `label:` anywhere in asm/ (ADS functions share literal pools)"""
    global _POOL
    if _POOL is None:
        _POOL = {}
        for p in glob.glob('asm/code_*.s'):
            for m in re.finditer(r'^(\w+):\n\t\.4byte ([^\n@]+)', open(p).read(), re.M): _POOL[m.group(1)] = m.group(2).strip()
    return _POOL.get(label)


def wrapper(name, body):
    labels = set(re.findall(r'^(\w+):', body, re.M))
    lines = []
    for l in body.split('\n'):
        t = l.split('@')[0].rstrip()
        if not t.strip() or t.strip().startswith('thumb_func_start'): continue
        if re.match(r'^%s:' % re.escape(name), t): continue
        if re.search(r'\badd r\d+, pc\b', t) or re.search(r'\badd r\d+, r\d+, pc\b', t): return None, 'pc-relative'
        m = re.match(r'(\s+ldr r\d+, )(\w+)$', t)
        if m and m.group(2) not in labels:
            v = pool_value(m.group(2))
            if v is None: return None, 'literal outside itself'
            t = m.group(1) + '=' + v
        m = re.match(r'(\s+)adr (r\d+), (\w+)$', t)
        if m and m.group(3) not in labels:                 # data placed after another function: load its address
            t = '%sldr %s, =%s' % m.groups()
        m = re.match(r'\s+(b|b[a-z]{2})\s+(\w+)$', t)
        if m and m.group(2) not in labels: return None, 'branches outside itself'
        lines.append(t.strip())
    asm = '\\n'.join(l.replace('\\', '\\\\').replace('"', '\\"') for l in lines)
    return ('/* timing control: the original instructions of %s, relocated */\n'
            '__attribute__((naked)) void %s(void)\n{\n  __asm__ volatile (".syntax unified\\n%s\\n.ltorg\\n.syntax divided");\n}\n'
            % (name, name, asm)), None


def main():
    lst, out = sys.argv[1], sys.argv[2]
    names = [l.strip() for l in open(lst) if l.strip()]
    keep, skipped = [], []
    backups = []
    try:
        for fn in names:
            n = fn.split('/')[-1]
            b = block(n)
            w, why = wrapper(n, b) if b else (None, 'no assembly block')
            if w is None: skipped.append((n, why)); continue
            src = 'src/%s.c' % fn
            shutil.copy(src, src + '.tbak'); backups.append(src)
            open(src, 'w').write(w); keep.append(fn)
        open('build/timing_ctl.txt', 'w').write(''.join(x + '\n' for x in keep))
        r = subprocess.run(['make', '-s', 'DECOMP=1', 'DECOMP_DIR=build_decomp_ctl', 'DECOMP_LIST=build/timing_ctl.txt',
                            'log1_decomp_ctl.gba'], capture_output=True, text=True)
    finally:
        for src in backups: shutil.move(src + '.tbak', src)
    if r.returncode: sys.exit('build failed:\n' + '\n'.join(l for l in r.stderr.split('\n') if 'rror' in l)[:2000])
    shutil.copy('log1_decomp_ctl.gba', out)
    print('control: %d functions relocated, %d kept original%s' % (len(keep), len(skipped),
          (': ' + ', '.join('%s (%s)' % s for s in skipped)) if skipped else ''))


if __name__ == '__main__':
    main()
