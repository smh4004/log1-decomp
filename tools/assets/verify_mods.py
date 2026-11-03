#!/usr/bin/env python3
"""End-to-end check of the modding toolkit (needs baserom.gba and the harness, about a minute):
  1. fresh `make extract` + `make modern` with no edits -> byte-identical ROM
  2. tools/assets/bios.py self-test (Huffman / LZ77 / RLE encoders round trip)
  3. demo_edits.py + `make modern`, then in the emulator: the edited story text is in the ROM, the title screen shows the
     re-packed logo tiles (screen differs from the original), the smoke route still reaches the first area and the menu,
     the area palette edit shows in game, the map edit (tiles + walkable mask) is in the ROM, the level-table edit
     gives the player 999 max HP in game, and the enemy-table edit is in the ROM
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
check('BIOS compression encoders round trip (incl. diff filters)', 'OK' in run('python3 tools/assets/bios.py'))
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
check('palette edit shows in game (Kame House sea)', new['s15_walk_RIGHT'] != ref['s15_walk_RIGHT'])
sys.path[:0] = ['tools/assets', 'tools/bfdis']
import gfxinfo as G, maps as M
a = G.areas(rom)[0]
grid = M.layer_grid(rom, a, 1); mask = M.mask_grid(rom, a, 0)
check('map edit: area 0 patch tiles and walkable mask in the ROM',
      (grid[31:35, 3:9] == 202).all() and mask[31:35, 3:9].all())
open('build_modern/hp.txt', 'w').write(open('tools/harness/smoke.txt').read() + '\nmem 030007CC 4\n')
out = run('tools/harness/harness log1_modern.gba build_modern/hp.txt build_modern/verify_hp')
check('level table edit: the player has 999 max HP in game', 'mem 030007cc: 000003e7' in out)
import struct
check('enemy table edit: snake HP 30 in the ROM', struct.unpack_from('<i', rom, 0x6B6094 + 0x40 + 0x38)[0] == 30)
print('ALL OK' if ok else 'SOME CHECKS FAILED'); sys.exit(0 if ok else 1)
