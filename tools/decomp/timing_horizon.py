#!/usr/bin/env python3
"""Timing horizon of the whole-game check routes (see docs/decomp.md, "Timing").

    python3 tools/decomp/timing_horizon.py      -> build/horizon.json

The C build runs at a different speed, and some of the game's state follows video frames rather than game loops
(the interrupt handler runs once per frame). `syncpc` keeps inputs in step with the game loop, but when a loop pass
runs over a frame, frame-driven state still drifts, and from some point on the game takes a different turn. That
point can be found without any C at all: each file in tools/decomp/timing/ is an exact copy of a function's original
instructions, linked like the C (same long jump, same .decomp section). A ROM with such a copy behaves exactly like
the original except for timing, so the first checkpoint where it differs is where the route stops being able to judge
C code. This script builds each control, plays every route on it, and records the earliest such checkpoint per route
(per area for decomp_warp.txt). gamebisect.py compares checkpoints before the horizon only (HORIZON=build/horizon.json).
"""
import os, sys, json, glob, shutil, subprocess
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')); os.chdir(ROOT)
sys.path.insert(0, 'tools/decomp')
import gamebisect as G

ROUTES = ['tools/harness/decomp_route.txt', 'tools/harness/decomp_long.txt', 'tools/harness/decomp_explore.txt']
WARP = 'tools/harness/decomp_warp.txt'
AREAS = list(range(1, 42))


def first_diff(a, b):
    """{group: index of the first differing checkpoint within that group} (group = area for warp routes, None else)"""
    out, seen = {}, {}
    for x, y in zip(a, b):
        g = x.split(':')[0]; i = seen.get(g, 0); seen[g] = i + 1
        if x != y and g not in out: out[g] = i
    return out


def main():
    os.makedirs('build', exist_ok=True)
    ref = {r: G.shots('log1.gba', r, 'build/hz_ref') for r in ROUTES}
    G.WARPS[:] = AREAS; ref[WARP] = G.shots('log1.gba', WARP, 'build/hz_ref'); G.WARPS[:] = []
    horizon = {r: {g.split(':')[0]: 10 ** 6 for g in ref[r]} for r in ref}
    for ctl in sorted(glob.glob('tools/decomp/timing/*.c')):
        n = os.path.basename(ctl)[:-2]
        src = glob.glob('src/*/%s.c' % n)[0]
        lst = 'build/timing_%s.txt' % n
        open(lst, 'w').write(os.path.relpath(src, 'src')[:-2] + '\n')
        shutil.copy(src, src + '.bak'); shutil.copy(ctl, src)
        try:
            r = subprocess.run(['make', '-s', 'DECOMP=1', 'DECOMP_DIR=build_decomp_timing', 'DECOMP_LIST=' + lst,
                                'log1_decomp_timing.gba'], capture_output=True, text=True)
        finally:
            shutil.move(src + '.bak', src)
        if r.returncode: sys.exit('build failed: ' + r.stderr[-400:])
        for rt in ROUTES + [WARP]:
            if rt == WARP: G.WARPS[:] = AREAS
            got = G.shots('log1_decomp_timing.gba', rt, 'build/hz_out'); G.WARPS[:] = []
            for g, i in first_diff(ref[rt], got).items():
                horizon[rt][g] = min(horizon[rt][g], i)
        print(n, {os.path.basename(k): sorted(v.values())[:3] for k, v in horizon.items()}, flush=True)
    json.dump(horizon, open('build/horizon.json', 'w'), indent=1)
    for rt, h in horizon.items():
        per = {}
        for x in ref[rt]: g = x.split(':')[0]; per[g] = per.get(g, 0) + 1
        usable = sum(min(h[g], per[g]) for g in per)
        print('%s: %d checkpoints, %d before the timing horizon' % (rt, len(ref[rt]), usable))


if __name__ == '__main__':
    main()
