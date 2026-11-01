#!/usr/bin/env python3
"""Find stale ROM pointers in RAM: compare RAM dumps of the matching ROM and a SHIFT build.
A ROM pointer at or above the shift point must differ by exactly SHIFT; a word that holds the
same ROM-range value in both runs is reported as STALE (an unconverted pointer?); any other difference as DIFF.
usage: ramdiff.py dir0 dir1 shift [shift_point]"""
import sys, struct
d0, d1, shift = sys.argv[1], sys.argv[2], int(sys.argv[3], 0)
sp = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0x08000158
for name, base in (('ew', 0x02000000), ('iw', 0x03000000)):
    a = open('%s/%s.bin' % (d0, name), 'rb').read(); b = open('%s/%s.bin' % (d1, name), 'rb').read()
    stale = ok = other = 0
    for o in range(0, min(len(a), len(b)) - 3, 4):
        x = struct.unpack_from('<I', a, o)[0]; y = struct.unpack_from('<I', b, o)[0]
        if sp <= x < 0x08800000:
            if y == x + shift: ok += 1
            elif y == x:
                stale += 1
                print('STALE %08X: %08X' % (base + o, x))
            else:
                other += 1
                print('OTHER %08X: %08X / %08X' % (base + o, x, y))
        elif x != y:
            other += 1
            print('DIFF  %08X: %08X / %08X' % (base + o, x, y))
    print('%s: moved-ok %d, stale %d, other-diff %d' % (name, ok, stale, other))
