#!/usr/bin/env python3
"""Stress test: replace EVERY WFZ container in .rodata with tools/wfz/wfz_compress.py output.
Sizes change almost everywhere, so nearly all data moves by different amounts.
usage: recompress_all.py out_dir   -> out_dir/overrides.json (use with apply.py, make MODERN=1)"""
import sys, os, json
from multiprocessing import Pool
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', 'wfz'))
from wfz import unpack
from wfz_compress import compress
ROM_DATA = None

def work(blk):
    o, s, e, t = blk
    raw = unpack(ROM_DATA, o)[0]
    c = compress(raw, t)
    c += b'\0' * (-len(c) % 4)
    return o, e, c

def init(path):
    global ROM_DATA
    ROM_DATA = open(path, 'rb').read()

if __name__ == '__main__':
    os.chdir(os.path.join(HERE, '..', '..'))
    out = sys.argv[1]; os.makedirs(out, exist_ok=True)
    blocks = json.load(open('.analysis/wfz_blocks.json'))
    ov = []; delta = 0
    with Pool(initializer=init, initargs=('baserom.gba',)) as p:
        for o, e, c in p.imap(work, blocks, chunksize=32):
            fn = os.path.join(out, '%06X.wfz' % o)
            open(fn, 'wb').write(c)
            ov.append({'start': o, 'end': e, 'file': fn}); delta += len(c) - (e - o)
    json.dump(ov, open(os.path.join(out, 'overrides.json'), 'w'))
    print('%d containers recompressed, total size change %+d bytes' % (len(ov), delta))
