#!/usr/bin/env python3
"""GBA BIOS compression (Huffman 0x24/0x28, LZ77 0x10, run-length 0x30): decoders and block finder.

Legacy of Goku stores its graphics as BIOS streams, often chained (Huffman, then LZ77, then run-length: swi 0x13/0x11/0x14 in
sub_08009524) instead of WFZ. Compressed bytes
are not addressable data: words inside them must never be converted to pointers, so the disassembler treats these
blocks like WFZ containers (tools/bfdis/ptrs.py `inside_wfz`). Header: u8 type, u24 decompressed size.
"""
import struct

ROM = 0x08000000


def lz77(d, o, limit=None):
    """-> (decompressed bytes, end offset) or None if the stream is invalid."""
    if d[o] != 0x10: return None
    size = d[o + 1] | d[o + 2] << 8 | d[o + 3] << 16
    if not 4 <= size <= 0x40000: return None
    out = bytearray(); p = o + 4; n = len(d) if limit is None else limit
    while len(out) < size:
        if p >= n: return None
        flags = d[p]; p += 1
        for bit in range(8):
            if len(out) >= size: break
            if flags & (0x80 >> bit):
                if p + 1 >= n: return None
                b1, b2 = d[p], d[p + 1]; p += 2
                ln = (b1 >> 4) + 3; disp = ((b1 & 0xF) << 8 | b2) + 1
                if disp > len(out): return None
                for _ in range(ln): out.append(out[-disp])
            else:
                if p >= n: return None
                out.append(d[p]); p += 1
    return bytes(out[:size]), p


def rle(d, o, limit=None):
    if d[o] != 0x30: return None
    size = d[o + 1] | d[o + 2] << 8 | d[o + 3] << 16
    if not 4 <= size <= 0x40000: return None
    out = bytearray(); p = o + 4; n = len(d) if limit is None else limit
    while len(out) < size:
        if p >= n: return None
        f = d[p]; p += 1
        if f & 0x80:
            if p >= n: return None
            out += bytes([d[p]]) * ((f & 0x7F) + 3); p += 1
        else:
            ln = f + 1
            if p + ln > n: return None
            out += d[p:p + ln]; p += ln
    return bytes(out[:size]), p


def huffman(d, o, limit=None):
    """BIOS Huffman (type 0x24 4-bit / 0x28 8-bit symbols) -> (bytes, end) or None."""
    t = d[o]
    if t not in (0x24, 0x28): return None
    bits = t & 0xF
    size = d[o + 1] | d[o + 2] << 8 | d[o + 3] << 16
    if not 4 <= size <= 0x40000: return None
    n = len(d) if limit is None else limit
    tree = o + 4
    tsize = (d[tree] + 1) * 2
    root = tree + 1
    p = tree + tsize
    if p > n: return None
    out = bytearray(); acc = 0; nacc = 0
    node = root; word = 0; left = 0
    need = size * 8 // bits
    produced = 0
    while produced < need:
        if left == 0:
            if p + 4 > n: return None
            word = struct.unpack_from('<I', d, p)[0]; p += 4; left = 32
        bit = word >> 31 & 1; word = word << 1 & 0xFFFFFFFF; left -= 1
        nd = d[node]
        child = (node & ~1) + (nd & 0x3F) * 2 + 2 + bit
        if child >= tree + tsize: return None
        if nd & (0x80 >> bit):        # child is a data leaf
            sym = d[child]
            if bits == 8: out.append(sym)
            else:
                acc |= (sym & 0xF) << nacc; nacc += 4
                if nacc == 8: out.append(acc); acc = 0; nacc = 0
            produced += 1; node = root
        else:
            node = child
    return bytes(out[:size]), p


def find_blocks(d, lo, hi):
    """Blocks referenced by any word in the ROM: [(start, size, end, 'lz'|'rl')] sorted, non-overlapping."""
    seen = {}
    for w in set(struct.unpack_from('<%dI' % (len(d) // 4), d)):
        t = w - ROM
        if not lo <= t < hi or t in seen or t % 4: continue        # the BIOS needs word-aligned sources
        # (run-length streams aren't stored in ROM by this game: the RLE stage runs on RAM output, and RLE "decodes"
        # almost any byte run, so it's not scanned for)
        r = lz77(d, t, hi) if d[t] == 0x10 else huffman(d, t, hi) if d[t] in (0x24, 0x28) else None
        if r: seen[t] = (t, len(r[0]), r[1], {0x10: 'lz', 0x30: 'rl'}.get(d[t], 'huff'))
    out = []; end = -1
    for t in sorted(seen):
        if t < end: continue            # a block starting inside another one is noise
        out.append(seen[t]); end = seen[t][2]
    return out


if __name__ == '__main__':
    import sys, json
    d = open(sys.argv[1], 'rb').read()
    b = find_blocks(d, int(sys.argv[3], 16), int(sys.argv[4], 16))
    json.dump(b, open(sys.argv[2], 'w'))
    print(len(b), 'BIOS-compressed blocks', sum(e - s for s, z, e, t in b), 'bytes')
