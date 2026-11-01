#!/usr/bin/env python3
"""End-to-end check of the modding toolkit (needs baserom.gba and the harness, about a minute):
  1. fresh `make extract` + `make modern` with no edits -> byte-identical ROM
  2. tools/assets/bios.py self-test (Huffman / LZ77 / RLE encoders round trip)
  3. demo_edits.py + `make modern`, then in the emulator: the edited story text is in the ROM, the title screen shows the
     re-packed logo tiles (screen differs from the original), and the smoke route still reaches the first area and the menu
Exits non-zero on any failure."""
import os, sys, subprocess, shutil, hashlib
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
ok = True


def run(cmd):
    r = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    if r.returncode: print(r.stdout[-2000:], r.stderr[-2000:]); sys.exit('FAILED: ' + cmd)
    return r.stdout


def check(name, cond):
    global ok
    print('%-62s %s' % (name, 'ok' if cond else 'FAILED')); ok &= bool(cond)


def shots(rom, route, out):
    shutil.rmtree(out, ignore_errors=True); os.makedirs(out)
    return {l.split()[1]: l.split()[5] for l in run('tools/harness/harness %s %s %s' % (rom, route, out)).split('\n') if l.startswith('shot')}


shutil.rmtree('assets', ignore_errors=True); shutil.rmtree('build_modern', ignore_errors=True)
run('make -s harness && make -s && make -s extract && make -s modern')
sha = lambda p: hashlib.sha1(open(p, 'rb').read()).hexdigest()
check('unedited assets rebuild the original ROM', sha('log1_modern.gba') == sha('baserom.gba'))
check('BIOS compression encoders round trip', 'OK' in run('python3 tools/assets/bios.py'))
ref = shots('log1.gba', 'tools/harness/smoke.txt', 'build_modern/verify_ref')
title = 'run 3100\nshot title\n'
open('build_modern/title.txt', 'w').write(title)
t0 = shots('log1.gba', 'build_modern/title.txt', 'build_modern/verify_t0')
run('python3 tools/assets/demo_edits.py && make -s modern')
rom = open('log1_modern.gba', 'rb').read()
check('edited story text is in the ROM', b'this story text was edited and grew longer' in rom)
t1 = shots('log1_modern.gba', 'build_modern/title.txt', 'build_modern/verify_t1')
check('title screen shows the re-packed logo tiles', t0['title'] != t1['title'])
new = shots('log1_modern.gba', 'tools/harness/smoke.txt', 'build_modern/verify')
check('edited ROM still plays to the first area and the menu', set(new) == set(ref) and new['s21_menu'] != '')
print('ALL OK' if ok else 'SOME CHECKS FAILED'); sys.exit(0 if ok else 1)
