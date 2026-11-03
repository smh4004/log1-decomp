#!/usr/bin/env python3
"""Capture snapshots in the parts of the game the normal routes never reach (for tools/decomp/autodecomp.py test).

    python3 tools/harness/capture_variants.py [AREA ...]      (default: every area 1-41)

The capture routes start a new game and play from Kame House (area 0), so code that only runs in later areas
(other maps, their enemies, objects and events) never gets snapshots. For each AREA this makes a *capture-only* ROM:
log1.gba with one data change, the warp zone of area 0 (the record at 0x086B0ED4) widened to the whole island and
pointed at AREA's start position. Nothing in the code changes. A route then plays the normal intro, walks into the
warp, and explores AREA with random input (tools/harness/make_explore.py). Snapshots go to .analysis/snaps as
ADDR_warpNN<k>.snap, and .analysis/snaps/roms.json records which ROM each tag was taken with, so the tester runs
the functions against that ROM's data.

STRONG=1 makes a second set (tag warpNNs) with a strong level-1 Goku and another random seed.
FRAMES (default 12000) sets the length of the random walk, PER_FN (default 3) the snapshots per function.

SAVE=path.sav [SEEDS=4]: instead of warping, start from a save file (raw save-chip data: for a GameShark .gsv, the
512 bytes at 0x430 with each 8-byte block reversed; the harness loads it read-only through HARNESS_SAVE), choose
Continue and slot 1 at the title, and play at random from there (tag save_NAME_K, K = seed).

These ROMs and snapshots are made from your ROM and stay in .analysis (git-ignored).
"""
import os, sys, json, struct, subprocess, glob, shutil, random

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
os.chdir(ROOT)
WARP = 0x6B0ED4                      # area 0's warp zone record {cb, x1, y1, x2, y2, mode, arg, to_area, to_x, to_y}
SNAPS = '.analysis/snaps'
OUT = '.analysis/caprom'
FRAMES = int(os.environ.get('FRAMES', 12000))
PER_FN = int(os.environ.get('PER_FN', 3))


LEVELS = 0x114A8                     # gLevelTable: 25 x {exp, max_hp, power, ki}
STRONG = os.environ.get('STRONG') == '1'


def make_rom(area, x, y, src='log1.gba', dst=None):
    d = bytearray(open(src, 'rb').read())
    if STRONG:
        # STRONG=1: level 1 gets 900 HP, power 60 and ki 40, so the random walk wins its fights (EXP, level-ups,
        # drops) instead of ending at the game-over screen
        struct.pack_into('<3i', d, LEVELS + 4, 900, 60, 40)
    cb = struct.unpack_from('<I', d, WARP)[0]
    assert cb == 0x0800356D, 'unexpected warp record (rebuild log1.gba with make)'
    struct.pack_into('<4hBBHHH', d, WARP + 4, 0, 0, 0x7FFF, 0x7FFF, 3, d[WARP + 13], area, x, y)
    os.makedirs(OUT, exist_ok=True)
    p = dst or '%s/warp%02d%s.gba' % (OUT, area, 's' if STRONG else '')
    open(p, 'wb').write(d)
    return p


def route(area, seed):
    r = subprocess.run([sys.executable, 'tools/harness/make_explore.py', str(seed), str(FRAMES)],
                       capture_output=True, text=True, check=True).stdout.split('\n')
    # make_explore's route starts with the intro (smoke.txt): capture from the start
    return '\n'.join(['capture .analysis/capture_list.txt %s %d' % ('%s', PER_FN)] + r + ['capstat'])


LOAD = ['run 3290', 'keys START', 'run 8', 'keys', 'run 80',        # title: Continue is the default with a save
        'keys START', 'run 8', 'keys', 'run 120',                      # Load Game: slot 1
        'keys A', 'run 8', 'keys', 'run 500']


def capture_save(path):
    name = os.path.splitext(os.path.basename(path))[0]
    roms = json.load(open(SNAPS + '/roms.json')) if os.path.exists(SNAPS + '/roms.json') else {}
    for k in range(int(os.environ.get('SEEDS', 4))):
        tag = 'save_%s_%d_' % (name, k)
        body = subprocess.run([sys.executable, 'tools/harness/make_explore.py', str(9000 + k), str(FRAMES)],
                              capture_output=True, text=True, check=True).stdout.split('\n')
        intro = [l for l in open('tools/harness/smoke.txt').read().split('\n')
                 if l and not l.startswith('#') and not l.startswith('shot')]
        body = [l for l in body[1 + len(intro):]]                       # drop make_explore's new-game intro
        raw = '.analysis/snaps_raw/' + tag
        shutil.rmtree(raw, ignore_errors=True); os.makedirs(raw)
        rp = '%s/%s.txt' % (OUT, tag); os.makedirs(OUT, exist_ok=True)
        open(rp, 'w').write('\n'.join(['capture .analysis/capture_list.txt %s %d' % (raw, PER_FN)] + LOAD + body + ['capstat']))
        r = subprocess.run(['tools/harness/harness', 'log1.gba', rp, raw], capture_output=True, text=True,
                           env=dict(os.environ, HARNESS_SAVE=os.path.abspath(path)))
        n = 0
        for s_ in glob.glob(raw + '/*.snap'):
            addr, i = os.path.basename(s_)[:-5].split('_')
            shutil.move(s_, '%s/%s_%s%s.snap' % (SNAPS, addr, tag, i)); n += 1
        print(tag, 'snapshots:', n, (r.stdout.strip().split('\n') or [''])[-1], r.stderr.strip()[:200])


def main():
    if os.environ.get('SAVE'): return capture_save(os.environ['SAVE'])
    areas = [int(a) for a in sys.argv[1:]] or list(range(1, 42))
    info = {}
    for i in range(42):
        p = 'assets/areas/area%02d.json' % i
        if os.path.exists(p): info[i] = json.load(open(p))['start']
    if not info: sys.exit('run `make extract` first (area start positions come from assets/areas)')
    roms = json.load(open(SNAPS + '/roms.json')) if os.path.exists(SNAPS + '/roms.json') else {}
    for a in areas:
        x, y = info[a]
        rom = make_rom(a, x, y)
        tag = 'warp%02d%s' % (a, 's' if STRONG else '')
        raw = '.analysis/snaps_raw/' + tag
        shutil.rmtree(raw, ignore_errors=True); os.makedirs(raw)
        rt = route(a, (5000 if STRONG else 1000) + a).replace('%s', raw, 1)
        rp = '%s/%s.txt' % (OUT, tag); open(rp, 'w').write(rt)
        r = subprocess.run(['tools/harness/harness', rom, rp, raw], capture_output=True, text=True)
        n = 0
        for s in glob.glob(raw + '/*.snap'):
            addr, k = os.path.basename(s)[:-5].split('_')
            shutil.move(s, '%s/%s_%s%s.snap' % (SNAPS, addr, tag, k)); n += 1
        roms[tag] = rom
        print(tag, 'snapshots:', n, (r.stdout.strip().split('\n') or [''])[-1])
        json.dump(roms, open(SNAPS + '/roms.json', 'w'), indent=1)


if __name__ == '__main__':
    main()
