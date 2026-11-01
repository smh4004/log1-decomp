#!/usr/bin/env python3
"""Make or apply a BPS patch (the usual format for sharing GBA ROM hacks; Floating IPS, beat, RetroArch and most
emulators read it).

  python3 tools/bps.py make  baserom.gba log1_modern.gba mymod.bps
  python3 tools/bps.py apply baserom.gba mymod.bps patched.gba

The encoder uses SourceRead for unchanged runs, SourceCopy for data that moved, and TargetRead for new bytes. It's simple, not
the smallest possible patch, but it's valid BPS with CRC32 checks.
"""
import sys, zlib, struct


def _num(n):
    out = bytearray()
    while True:
        x = n & 0x7F; n >>= 7
        if n == 0: out.append(0x80 | x); return bytes(out)
        out.append(x); n -= 1


def _rnum(b, p):
    data, shift = 0, 1
    while True:
        x = b[p]; p += 1
        data += (x & 0x7F) * shift
        if x & 0x80: return data, p
        shift <<= 7; data += shift


def make(src, tgt):
    out = bytearray(b'BPS1') + _num(len(src)) + _num(len(tgt)) + _num(0)
    i = 0; n = len(tgt)
    # index 32-byte blocks of the source for moved data
    idx = {}
    for k in range(0, len(src) - 32, 16):
        idx.setdefault(src[k:k + 32], k)
    src_rel = 0
    while i < n:
        j = i
        while j < n and j < len(src) and src[j] == tgt[j]: j += 1
        if j - i >= 4 or (j == n and j > i):
            out += _num(((j - i - 1) << 2) | 0); i = j; continue
        k = idx.get(tgt[i:i + 32]) if i + 32 <= n else None
        if k is not None:
            m = 0
            while i + m < n and k + m < len(src) and src[k + m] == tgt[i + m]: m += 1
            out += _num(((m - 1) << 2) | 2)
            off = k - src_rel; out += _num((abs(off) << 1) | (1 if off < 0 else 0))
            src_rel = k + m; i += m; continue
        j = i + 1
        while j < n and not (j + 4 <= min(n, len(src)) and src[j:j + 4] == tgt[j:j + 4]) and \
                not (j + 32 <= n and tgt[j:j + 32] in idx):
            j += 1
        out += _num(((j - i - 1) << 2) | 1) + tgt[i:j]; i = j
    out += struct.pack('<I', zlib.crc32(src)) + struct.pack('<I', zlib.crc32(tgt))
    out += struct.pack('<I', zlib.crc32(bytes(out)))
    return bytes(out)


def apply(src, patch):
    assert patch[:4] == b'BPS1', 'not a BPS patch'
    p = 4
    ss, p = _rnum(patch, p); ts, p = _rnum(patch, p); ms, p = _rnum(patch, p); p += ms
    assert ss == len(src), 'wrong source ROM size'
    assert struct.unpack_from('<I', patch, len(patch) - 12)[0] == zlib.crc32(src), 'wrong source ROM (CRC32)'
    tgt = bytearray(); sr = tr = 0
    end = len(patch) - 12
    while p < end:
        v, p = _rnum(patch, p); cmd, ln = v & 3, (v >> 2) + 1
        if cmd == 0: tgt += src[len(tgt):len(tgt) + ln]
        elif cmd == 1: tgt += patch[p:p + ln]; p += ln
        else:
            o, p = _rnum(patch, p); o = -(o >> 1) if o & 1 else o >> 1
            if cmd == 2:
                sr += o; tgt += src[sr:sr + ln]; sr += ln
            else:
                tr += o
                for _ in range(ln): tgt.append(tgt[tr]); tr += 1
    assert len(tgt) == ts and zlib.crc32(bytes(tgt)) == struct.unpack_from('<I', patch, len(patch) - 8)[0], 'output CRC mismatch'
    return bytes(tgt)


if __name__ == '__main__':
    if len(sys.argv) != 5 or sys.argv[1] not in ('make', 'apply'): sys.exit(__doc__)
    a = open(sys.argv[2], 'rb').read(); b = open(sys.argv[3], 'rb').read()
    if sys.argv[1] == 'make':
        pt = make(a, b); assert apply(a, pt) == b, 'self-check failed'
        open(sys.argv[4], 'wb').write(pt); print('wrote %s (%d bytes)' % (sys.argv[4], len(pt)))
    else:
        open(sys.argv[4], 'wb').write(apply(a, b)); print('wrote', sys.argv[4])
