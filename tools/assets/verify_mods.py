#!/usr/bin/env python3
"""End-to-end check of the modding toolkit (needs baserom.gba and the harness, about a minute):
  1. fresh `make extract` + `make modern` with no edits -> byte-identical ROM
  2. tools/assets/bios.py self-test (Huffman / LZ77 / RLE encoders round trip)
  3. demo_edits.py + `make modern`, then in the emulator: the edited story text is in the ROM, the title screen shows the
     re-packed logo tiles (screen differs from the original), the smoke route still reaches the first area and the menu,
     the area palette edit shows in game, the map edit (tiles + walkable mask) is in the ROM, the level-table edit
     gives the player 999 max HP in game, an added wolf is created with the edited enemy HP, and a new warp zone
     takes the player to another area, an edited conversation shows its rewritten and added lines, an edited quest completes and gives its new EXP reward, a
     sprite sheet edit changes how Goku is drawn, the title music plays a replaced (longer) sample, the
     title song re-encoded and moved by the music tool plays the same audio (mixer buffers), and transposed it doesn't;
     movie 2 (boot) re-encoded from its frames looks identical while booting, and edited frames show
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
import struct, re
check('enemy table edit: snake HP 30 in the ROM', struct.unpack_from('<i', rom, 0x6B6094 + 0x40 + 0x38)[0] == 30)
open('build_modern/f.txt', 'w').write('08006D90\n')
route = open('tools/harness/smoke.txt').read().split('shot s16')[0]
open('build_modern/area.txt', 'w').write('hitlog build_modern/f.txt\n' + route + 'keys RIGHT\nrun 60\nkeys\nrun 200\nmem 030005FC 4\n')
out = run('tools/harness/harness log1_modern.gba build_modern/area.txt build_modern/verify_area')
wolf = [int(m.group(1), 16) for m in re.finditer(r'hit 08006d90 \S+ \d+ r0-r3 (\w+) 00000002 00000002', out)]
check('area edit: the added wolf is created in area 0', bool(wolf))
if wolf:
    open('build_modern/hp2.txt', 'w').write(route + 'mem %08X 4\n' % (wolf[0] + 0x4C))
    out2 = run('tools/harness/harness log1_modern.gba build_modern/hp2.txt build_modern/verify_hp2')
    check('enemy table edit: that wolf has 777 HP in game', 'mem %08x: 00000309' % (wolf[0] + 0x4C) in out2)
check('area edit: the new warp zone leads to area 2', re.search(r'mem 030005fc: 00000002', out) is not None)
# the conversation check uses a build with only the dialogue edit (the other edits change where Goku walks)
shutil.rmtree('assets', ignore_errors=True)
run('make -s extract && python3 tools/assets/demo_edits.py dialogue && make -s modern')
rom = open('log1_modern.gba', 'rb').read()
open('build_modern/f3.txt', 'w').write('0800930A\n')
lines = open('tools/harness/long.txt').read().split('\n')
talk = lines[:lines.index('shot s22_back') + 5]          # walk left, then A next to Krillin
open('build_modern/talk.txt', 'w').write('hitlog build_modern/f3.txt\n' + '\n'.join(talk) + '\n' + 'tap A 50\n' * 30)
out = run('tools/harness/harness log1_modern.gba build_modern/talk.txt build_modern/verify_talk')
shown = []
for m in re.finditer(r'hit 0800930a \S+ \d+ r0-r3 \w+ (\w+)', out):
    a = int(m.group(1), 16) - 0x08000000
    if 0 <= a < len(rom): shown.append(rom[a:rom.index(b'\0', a)])
check('dialogue edit: the rewritten line is shown in game', b'MOD TEST: Hey Gohan, this line was edited and grew longer!' in shown)
check('dialogue edit: the added line is shown in game', b'MOD TEST: a brand new line from Master Roshi.' in shown)
shutil.rmtree('assets', ignore_errors=True)
run('make -s extract && python3 tools/assets/demo_edits.py story && make -s modern')
open('build_modern/exp.txt', 'w').write(open('tools/harness/long.txt').read() + '\nmem 03000038 4\nmem 030007D8 4\n')
out = run('tools/harness/harness log1_modern.gba build_modern/exp.txt build_modern/verify_exp')
check('story edit: quest 1 completes and its new action gives 1234 EXP',
      re.search(r'mem 03000038: \w{6}(\w\w)', out) and int(re.search(r'mem 03000038: \w{6}(\w\w)', out).group(1), 16) & 2
      and 'mem 030007d8: 000004d2' in out)
shutil.rmtree('assets', ignore_errors=True)
run('make -s extract && python3 tools/assets/demo_edits.py sprites && make -s modern')
sp = shots('log1_modern.gba', 'tools/harness/smoke.txt', 'build_modern/verify_spr')
check('sprite edit: Goku is drawn with the swapped colours', sp['s15_walk_RIGHT'] != ref['s15_walk_RIGHT'])
shutil.rmtree('assets', ignore_errors=True)
run('make -s extract && python3 tools/assets/demo_edits.py sound && make -s modern')
rom = open('log1_modern.gba', 'rb').read()
p, loop, ls, ln, rate = struct.unpack_from('<IHHHH', rom, 0x591E4C + 12 * 9)
open('build_modern/snd.txt', 'w').write('run 3200\ndump iw 03000000 8000\ndump ew 02000000 40000\n')
os.makedirs('build_modern/verify_snd', exist_ok=True)
run('tools/harness/harness log1_modern.gba build_modern/snd.txt build_modern/verify_snd')
mem = open('build_modern/verify_snd/iw.bin', 'rb').read() + open('build_modern/verify_snd/ew.bin', 'rb').read()
used = any(p <= struct.unpack_from('<I', mem, i)[0] < p + ln for i in range(0, len(mem) - 3, 4))
check('sound edit: the title music plays the new, longer sample 9', ln == 32000 and rate == 16000 and used)
def mixer(rom, tag):
    out = 'build_modern/verify_mix_' + tag; os.makedirs(out, exist_ok=True)
    open('build_modern/mix.txt', 'w').write('run 3000\n' + ''.join('run 3\ndump b%d 0203F800 800\n' % i for i in range(60)))
    run('tools/harness/harness %s build_modern/mix.txt %s' % (rom, out))
    return [open('%s/b%d.bin' % (out, i), 'rb').read() for i in range(60)]
ref_mix = mixer('log1.gba', 'ref')
for mode in ('music_same', 'music'):
    shutil.rmtree('assets', ignore_errors=True)
    run('make -s extract && python3 tools/assets/demo_edits.py %s && make -s modern' % mode)
    rom = open('log1_modern.gba', 'rb').read()
    moved = struct.unpack_from('<I', rom, 0x591F3C + 12 * 15)[0] >= 0x087A6418
    mix = mixer('log1_modern.gba', mode)
    same = sum(a == b for a, b in zip(mix, ref_mix))
    if mode == 'music_same':
        check('music: the title song, re-encoded and moved, sounds the same (60/60 buffers)', moved and same == 60)
    else:
        check('music: the transposed title song sounds different', moved and same < 10)
open('build_modern/boot.txt', 'w').write('run 30\nshot f0\n' + ''.join('run 30\nshot f%d\n' % i for i in range(1, 110)))
ref_boot = shots('log1.gba', 'build_modern/boot.txt', 'build_modern/verify_boot_ref')
for mode in ('movie_same', 'movie'):
    shutil.rmtree('assets', ignore_errors=True)
    run('make -s extract && python3 tools/assets/demo_edits.py %s && make -s modern' % mode)
    rom = open('log1_modern.gba', 'rb').read()
    b = shots('log1_modern.gba', 'build_modern/boot.txt', 'build_modern/verify_boot_' + mode)
    same = sum(b[k] == ref_boot[k] for k in ref_boot)
    if mode == 'movie_same':
        sys.path[:0] = ['tools/assets']
        import movies as MV, numpy as np
        base = open('baserom.gba', 'rb').read()
        fa = MV.decode(base[0x337248:0x337248 + MV.u32(base, 0x337248)])
        fb = MV.decode(rom[0x337248:0x337248 + MV.u32(rom, 0x337248)])
        exact = len(fa) == len(fb) and all(np.array_equal(x[0], y[0]) and np.array_equal(x[1], y[1]) for x, y in zip(fa, fb))
        # a re-encoded movie decodes to the same frames; the game may show a frame one VBlank later or earlier,
        # because decode time depends on the encoding, so a few sampled screens can differ
        check('movie: movie 2 re-encoded from its frames: same frames, boot looks the same (%d/%d screens)'
              % (same, len(ref_boot)), exact and rom[0x337248:0x337250] != base[0x337248:0x337250] and same >= 0.9 * len(ref_boot))
        same_resaved = same
    else:
        check('movie: the edited frames of movie 2 show in game (%d more screens differ)' % (same_resaved - same),
              same_resaved - same >= 5)
print('ALL OK' if ok else 'SOME CHECKS FAILED'); sys.exit(0 if ok else 1)
