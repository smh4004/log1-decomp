#!/usr/bin/env python3
"""WFZ compressor: the inverse of tools/wfz/wfz.py (the game's own decoder, ported).

Bitstream: 32-bit little-endian words, bits consumed MSB-first. Commands (decoder view):
  1  + bits(r3)                          literal (r3=8 after the mode switch we emit first)
  01 + gamma(g>=3) + bits(8) + gamma(n)  match, offset = ((g-3)<<8) | low8, length = n + bonus(offset)
  01 + gamma(2) + gamma(n)               repeat last offset, length n
  000 + bits(7)!=0 + bits(2)             short match, offset 1..127, length 2..5
  000 + bits(7)=0 + bits(2)=0            end of stream
  001 + bits(4)=v+1, v>0                 copy 1 byte from offset v (1..14); v=0 writes a 0 byte
  001 + 0000 + 0 + 1                     literal mode -> 8-bit literals, base 0
gamma(v): v>=2, binary digits after the leading 1, each followed by a continue bit.

The encoder is a straightforward greedy/lazy LZ with an exact bit-cost model. It does not try to reproduce the
original compressor's output (the matching build keeps the original blobs); every output is verified by decoding.
"""
import struct, sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from wfz import decompress_stream

OFFBITS = 8
MAXOFF = 0xFFFF          # keep offsets below the 0x10000 length bonus tier for simplicity
MAXCHAIN = 48


def bonus(off):
    if off >= 0x10000: return 3
    if off >= 0x37FF: return 2
    if off >= 0x27F: return 1
    if off <= 0x7F: return 4
    return 0


def glen(v):
    return 2 * (v.bit_length() - 1)


class BitWriter:
    def __init__(self):
        self.words = []
        self.cur = 0
        self.n = 0

    def put(self, v, nbits):
        for i in range(nbits - 1, -1, -1):
            self.cur = (self.cur << 1) | ((v >> i) & 1)
            self.n += 1
            if self.n == 32:
                self.words.append(self.cur); self.cur = 0; self.n = 0

    def gamma(self, v):
        assert v >= 2
        bl = v.bit_length()
        for i in range(bl - 2, -1, -1):
            self.put((v >> i) & 1, 1)
            self.put(1 if i > 0 else 0, 1)

    def finish(self):
        if self.n:
            self.words.append(self.cur << (32 - self.n)); self.cur = 0; self.n = 0
        return b''.join(struct.pack('<I', w) for w in self.words)


def compress_stream(data):
    data = bytes(data)
    n = len(data)
    w = BitWriter()
    w.put(0b001, 3); w.put(0, 4); w.put(0, 1); w.put(1, 1)      # 8-bit literal mode
    heads = {}
    last = -1
    i = 0

    def insert(p):
        if p + 2 < n:
            k = data[p:p + 3]
            lst = heads.get(k)
            if lst is None: heads[k] = [p]
            else:
                lst.append(p)
                if len(lst) > 4 * MAXCHAIN: del lst[:len(lst) - MAXCHAIN]

    def best_match(p):
        """(length, offset) of the best match at p (length>=2), or (0,0)."""
        bl, bo = 0, 0
        if p + 2 < n:
            for q in reversed(heads.get(data[p:p + 3], ())[-MAXCHAIN:]):
                off = p - q
                if off > MAXOFF: break
                l = 3
                while p + l < n and data[q + l] == data[p + l] and l < 0x1000: l += 1
                if l > bl or (l == bl and off < bo): bl, bo = l, off
        # short 2-byte matches within 127
        if bl < 2 and p + 1 < n:
            for off in range(1, min(127, p) + 1):
                if data[p - off] == data[p] and data[p - off + 1] == data[p + 1]:
                    bl, bo = 2, off; break
        return bl, bo

    def forms(l, off):
        """cheapest (cost, kind) to encode match (l, off), or None."""
        opts = []
        if off == last: opts.append((2 + glen(2) + glen(l), 'rep'))
        if off <= 127 and 2 <= l <= 5: opts.append((12, 'short'))
        if l - bonus(off) >= 2: opts.append((2 + glen((off >> OFFBITS) + 3) + OFFBITS + glen(l - bonus(off)), 'gamma'))
        return min(opts) if opts else None

    def literal_cost(p):
        b = data[p]
        if b == 0: return 7
        for v in range(1, 15):
            if p - v >= 0 and data[p - v] == b: return 7
        return 9

    while i < n:
        l, off = best_match(i)
        f = forms(l, off) if l >= 2 else None
        if f is None and l > 5 and off <= 127:          # fall back to a short match of 5
            l = 5; f = forms(l, off)
        use = False
        if f is not None and f[0] < sum(literal_cost(p) for p in range(i, i + l)):
            use = True
            if i + 1 < n:                                # lazy evaluation one byte ahead
                l2, o2 = best_match(i + 1)
                f2 = forms(l2, o2) if l2 >= 2 else None
                if f2 is not None and l2 > l and literal_cost(i) + f2[0] < f[0] + 9 * (l2 - l):
                    use = False
        if use:
            kind = f[1]
            if kind == 'rep':
                w.put(0b01, 2); w.gamma(2); w.gamma(l)
            elif kind == 'short':
                w.put(0b000, 3); w.put(off, 7); w.put(l - 2, 2)
            else:
                w.put(0b01, 2); w.gamma((off >> OFFBITS) + 3); w.put(off & 0xFF, OFFBITS); w.gamma(l - bonus(off))
            last = off
            for p in range(i, i + l): insert(p)
            i += l
            continue
        b = data[i]
        if b == 0:
            w.put(0b001, 3); w.put(1, 4)                            # zero byte, 7 bits
        else:
            for v in range(1, 15):
                if i - v >= 0 and data[i - v] == b:
                    w.put(0b001, 3); w.put(v + 1, 4); break        # 1-byte copy, 7 bits
            else:
                w.put(1, 1); w.put(b, 8)                            # literal, 9 bits
        insert(i)
        i += 1
    w.put(0b000, 3); w.put(0, 7); w.put(0, 2)                       # end
    return w.finish()


def compress(data, typ=1):
    """Return a full WFZ container: u32 type, u32 size, bitstream. Verified by decoding."""
    s = compress_stream(data)
    blob = struct.pack('<II', typ, len(data)) + s
    out, end = decompress_stream(blob, 8, len(data))
    if out != bytes(data):
        raise ValueError('WFZ roundtrip failed')
    return blob


def stored(data):
    """Type-0 (stored) container."""
    return struct.pack('<II', 0, len(data)) + bytes(data)


if __name__ == '__main__':
    import argparse
    ap = argparse.ArgumentParser(description='Compress a file into a WFZ container')
    ap.add_argument('input'); ap.add_argument('output')
    ap.add_argument('--stored', action='store_true', help='write a type-0 (uncompressed) container')
    a = ap.parse_args()
    raw = open(a.input, 'rb').read()
    blob = stored(raw) if a.stored else compress(raw)
    open(a.output, 'wb').write(blob)
    print('%s: %d -> %d bytes' % (a.output, len(raw), len(blob)))
