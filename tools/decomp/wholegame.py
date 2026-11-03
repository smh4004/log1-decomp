#!/usr/bin/env python3
"""Whole-game check of a set of C functions, judged against a timing control (see docs/decomp.md, "Timing").

    python3 tools/decomp/wholegame.py LIST        (e.g. config/decomp_verified.txt)

1. builds the decomp ROM with the C for LIST (make DECOMP=1 DECOMP_LIST=LIST),
2. builds the timing control: the same functions replaced by their own original instructions, relocated
   (timing_control.py), i.e. the original game with only its timing changed,
3. plays tools/harness/decomp_route, decomp_long, decomp_explore and decomp_warp (in all 41 areas) on the original,
   the C ROM and the control, and compares the C ROM with the original at every checkpoint up to the first one where
   the control already differs (in each run): past that point the original game itself plays differently when only
   its speed changes, so a difference there says nothing about the C.
Exit status 0 when no compared checkpoint differs.
"""
import os, sys, subprocess
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..')); os.chdir(ROOT)
sys.path.insert(0, 'tools/decomp')
import gamebisect as G

ROUTES = ['decomp_route', 'decomp_long', 'decomp_explore', 'decomp_warp']


def main():
    lst = sys.argv[1]
    os.makedirs('build', exist_ok=True)
    r = subprocess.run(['make', '-s', 'DECOMP=1', 'DECOMP_DIR=build_decomp_wg', 'DECOMP_LIST=' + lst, 'log1_decomp_wg.gba'],
                       capture_output=True, text=True)
    if r.returncode: sys.exit('build failed: ' + r.stderr[-500:])
    subprocess.run([sys.executable, 'tools/decomp/timing_control.py', lst, 'build/wg_control.gba'], check=True)
    tot = bad = 0
    for route in ROUTES:
        G.WARPS[:] = list(range(1, 42)) if route == 'decomp_warp' else []
        rt = 'tools/harness/%s.txt' % route
        o = G.shots('log1.gba', rt, 'build/wg_o'); c = G.shots('log1_decomp_wg.gba', rt, 'build/wg_c')
        k = G.shots('build/wg_control.gba', rt, 'build/wg_k')
        usable, diff, stop = 0, [], set()
        for x, y, z in zip(o, c, k):
            g = x.split(':')[0]
            if g in stop: continue
            if z != x: stop.add(g); continue
            usable += 1
            if y != x: diff.append(x)
        if len(c) != len(o): diff.append('checkpoint count')
        tot += usable; bad += len(diff)
        print('%-15s %3d of %3d checkpoints before timing drift, %d differ' % (route, usable, len(o), len(diff)))
    print('compared %d checkpoints, %d differ' % (tot, bad))
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
