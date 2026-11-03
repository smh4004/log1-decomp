#!/usr/bin/env python3
"""Find C functions that break the game.

usage: gamebisect.py LIST ROUTE [JOBS]      (ROUTE: normally tools/harness/decomp_route.txt)
Builds `make DECOMP=1 DECOMP_LIST=...` ROMs from subsets of LIST (lines `file/function`) and plays ROUTE
(a tools/harness script) on each. A subset is good when every `shot` hash equals the matching ROM's. The C runs at
a different speed and the game drops frames differently, so ROUTE must count time in game-loop passes (`syncpc`, as in
tools/harness/decomp_route.txt), not video frames. The list is split
into JOBS chunks, which are bisected in parallel (each in its own build directory) down to single culprit functions.
Prints the culprits and writes them to build/LIST.bad. The decomp build moves no original byte, so any other difference comes from the C code.
"""
import sys, os, subprocess
from concurrent.futures import ProcessPoolExecutor

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))
os.chdir(ROOT)


WARPS = [int(a) for a in os.environ.get('WARPS', '').split(',') if a]


def shots(rom, route, out):
    """Frame hash at every `shot` checkpoint of ROUTE. With WARPS=a,b,... (an env variable), ROUTE is instead played
    once per area on a copy of ROM whose Kame House warp leads to that area (tools/harness/capture_variants.py:
    one data record changed, the same in the original and the decomp ROM), and the hashes of all runs are compared."""
    os.makedirs(out, exist_ok=True)
    roms = [(rom, None)]
    if WARPS:
        sys.path.insert(0, 'tools/harness')
        import capture_variants as CV, json
        roms = []
        for a in WARPS:
            x, y = json.load(open('assets/areas/area%02d.json' % a))['start']
            roms.append((CV.make_rom(a, x, y, src=rom, dst='%s/warp%02d.gba' % (out, a)), a))
    h = []
    for r_, a in roms:
        r = subprocess.run(['tools/harness/harness', r_, route, out], capture_output=True, text=True).stdout
        h += ['%s:%s' % (a, l.split()[5]) for l in r.split('\n') if l.startswith('shot')]
    return h


def same(a, b):
    return a == b


def good(sub, route, ref, w):
    d = 'build_decomp_w%d' % w
    lst = 'build/bisect_w%d.txt' % w
    open(lst, 'w').write(''.join(x + '\n' for x in sub))
    r = subprocess.run(['make', '-s', 'DECOMP=1', 'DECOMP_DIR=' + d, 'DECOMP_LIST=' + lst,
                        'log1_decomp_w%d.gba' % w], capture_output=True, text=True)
    if r.returncode:
        print('build failed', r.stderr[-300:], flush=True); return False
    return same(shots('log1_decomp_w%d.gba' % w, route, 'build/bisect_out_w%d' % w), ref)


def worker(args):
    chunk, route, ref, w = args
    bad = []
    def search(sub):
        if good(sub, route, ref, w): return
        if len(sub) == 1:
            bad.append(sub[0]); print('culprit', sub[0], flush=True); return
        h = len(sub) // 2
        search(sub[:h]); search(sub[h:])
    search(chunk)
    return bad


def main():
    lst, route = sys.argv[1], sys.argv[2]
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 4
    names = [l.strip() for l in open(lst) if l.strip()]
    os.makedirs('build', exist_ok=True)
    ref = shots('log1.gba', route, 'build/bisect_ref')
    k = (len(names) + jobs - 1) // jobs
    chunks = [names[i:i + k] for i in range(0, len(names), k)]
    with ProcessPoolExecutor(len(chunks)) as ex:
        bad = sum(ex.map(worker, [(c, route, ref, i) for i, c in enumerate(chunks)]), [])
    os.makedirs('build', exist_ok=True)
    open('build/' + os.path.basename(lst) + '.bad', 'w').write(''.join(x + '\n' for x in bad))
    print('culprits:', bad)


if __name__ == '__main__':
    main()
