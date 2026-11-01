#!/usr/bin/env python3
"""Scan a ROM range for WFZ containers (type 1/2 compressed, plausible size, decodes to exactly `size`).
usage: scan_wfz.py baserom.gba out.json [start end]"""
import sys, os, struct, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from wfz import decompress_stream
rom = open(sys.argv[1], 'rb').read()
lo = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0
hi = int(sys.argv[4], 16) if len(sys.argv) > 4 else len(rom)
res = []
o = lo
while o < hi - 8:
    t, s = struct.unpack_from('<II', rom, o)
    if t in (1, 2) and 0x20 <= s <= 0x100000:
        try:
            out, end = decompress_stream(rom, o + 8, s)
            if len(out) == s and end <= hi:
                res.append([o, s, end, t])
                o = (end + 3) & ~3
                continue
        except (IndexError, struct.error):
            pass
    o += 4
json.dump(res, open(sys.argv[2], 'w'))
print(len(res), 'blocks', sum(r[2] - r[0] for r in res), 'compressed bytes', sum(r[1] for r in res), 'raw bytes')
