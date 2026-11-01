#!/usr/bin/env python3
"""Find the first divergence between the matching ROM and the SHIFT ROM (debugging aid for `make shift-test`).
usage: shiftdiff.py [SHIFT] [STEP] [MAXFRAMES]
1. plays both ROMs in STEP-frame steps until the screen differs (frame F)
2. dumps VRAM, palette, OAM, EWRAM, IWRAM at frame F in both and lists differing words that are NOT explained by the
   shift (a word equal to original + SHIFT is a correctly moved pointer)
Next step by hand: `watchon ADDR` on a differing word, then compare the bytes the writer read in both ROMs."""
import os, sys, subprocess, struct, tempfile
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
SHIFT = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x100
STEP = int(sys.argv[2]) if len(sys.argv) > 2 else 20
MAX = int(sys.argv[3]) if len(sys.argv) > 3 else 6000
name = open('config/game.json').read().split('"name": "')[1].split('"')[0]
T = tempfile.mkdtemp()


def run(rom, script, out):
    os.makedirs(out, exist_ok=True)
    open(T + '/s.txt', 'w').write(script)
    return subprocess.run(['tools/harness/harness', rom, T + '/s.txt', out], capture_output=True, text=True).stdout


s = ''.join('run %d\nhash\n' % STEP for _ in range(MAX // STEP))
a = [l for l in run(name + '.gba', s, T + '/a').split('\n') if 'hash' in l]
b = [l for l in run(name + '_shift.gba', s, T + '/b').split('\n') if 'hash' in l]
F = next(((i + 1) * STEP for i, (x, y) in enumerate(zip(a, b)) if x.split()[-1] != y.split()[-1]), None)
if F is None: sys.exit('no difference in %d frames' % MAX)
print('screens differ first at frame', F)
regs = [('vram', 0x06000000, 0x18000), ('pal', 0x05000000, 0x400), ('oam', 0x07000000, 0x400), ('ew', 0x02000000, 0x40000), ('iw', 0x03000000, 0x8000)]
s = 'run %d\n' % F + ''.join('dump %s %08x %x\n' % r for r in regs)
run(name + '.gba', s, T + '/a'); run(name + '_shift.gba', s, T + '/b')
for n, base, size in regs:
    x = open(T + '/a/%s.bin' % n, 'rb').read(); y = open(T + '/b/%s.bin' % n, 'rb').read()
    diffs = []
    for o in range(0, size, 4):
        u, v = struct.unpack_from('<I', x, o)[0], struct.unpack_from('<I', y, o)[0]
        if u != v and not (0x08000000 <= u < 0x0A000000 and v == u + SHIFT): diffs.append((base + o, u, v))
    print('%-4s %d differing words' % (n, len(diffs)), ' '.join('%08X:%08X/%08X' % t for t in diffs[:6]))
