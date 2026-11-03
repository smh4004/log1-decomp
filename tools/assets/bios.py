"""GBA BIOS compression encoders (the decoders are in tools/bfdis/lz.py), for re-packing edited Legacy of Goku data.

The game unpacks with `Decompress(src, flags)` (0x08009524): bit 4 = Huffman (swi 0x13), bit 3 = LZ77 (swi 0x11),
bit 2 = run-length (swi 0x14), applied in that order. An edited block must be re-packed with the same stages.
Huffman is always written with 4-bit symbols (header 0x24): any data can be coded that way and the 16-leaf tree always
fits the BIOS node format (6-bit child offsets).
"""
import os, sys, struct, heapq
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'bfdis'))
import lz as dec


def hdr(t, n): return bytes([t, n & 0xFF, n >> 8 & 0xFF, n >> 16 & 0xFF])


def pad4(b): return b + bytes(-len(b) % 4)


def rle(data):
    out = bytearray(hdr(0x30, len(data))); i = 0; lit = bytearray()
    def flush():
        while lit:
            c = lit[:128]; del lit[:128]; out.append(len(c) - 1); out.extend(c)
    while i < len(data):
        j = i
        while j < len(data) and j - i < 130 and data[j] == data[i]: j += 1
        if j - i >= 3:
            flush(); out.append(0x80 | (j - i - 3)); out.append(data[i]); i = j
        else:
            lit.append(data[i]); i += 1
    flush()
    return pad4(bytes(out))


def lz77(data):
    out = bytearray(hdr(0x10, len(data))); i = 0; n = len(data)
    index = {}
    while i < n:
        flagpos = len(out); out.append(0); flags = 0
        for bit in range(8):
            if i >= n: break
            best, bd = 0, 0
            key = data[i:i + 3]
            if len(key) == 3:
                for p in reversed(index.get(key, [])[-64:]):
                    disp = i - p
                    if disp > 4096: break
                    if disp < 1: continue
                    l = 0
                    while l < 18 and i + l < n and data[p + l] == data[i + l]: l += 1
                    if l > best: best, bd = l, disp
                    if l == 18: break
            if best >= 3:
                flags |= 0x80 >> bit
                v = (best - 3) << 12 | (bd - 1)
                out += bytes([v >> 8, v & 0xFF])
                for k in range(best):
                    if i + k + 3 <= n: index.setdefault(data[i + k:i + k + 3], []).append(i + k)
                i += best
            else:
                out.append(data[i])
                if i + 3 <= n: index.setdefault(data[i:i + 3], []).append(i)
                i += 1
        out[flagpos] = flags
    return pad4(bytes(out))


def huffman4(data):
    """BIOS Huffman, 4-bit symbols (low nibble first)."""
    syms = []
    for b in data: syms += [b & 0xF, b >> 4]
    freq = [0] * 16
    for s in syms: freq[s] += 1
    heap = [(f, i, ('leaf', i)) for i, f in enumerate(freq) if f]
    if len(heap) == 1: heap.append((0, 99, ('leaf', (heap[0][2][1] + 1) % 16)))
    heapq.heapify(heap); k = 100
    while len(heap) > 1:
        a = heapq.heappop(heap); b = heapq.heappop(heap)
        heapq.heappush(heap, (a[0] + b[0], k, ('node', a[2], b[2]))); k += 1
    root = heap[0][2]
    codes = {}
    def walk(t, c):
        if t[0] == 'leaf': codes[t[1]] = c
        else: walk(t[1], c + '0'); walk(t[2], c + '1')
    walk(root, '')
    # tree table, breadth first: table[0] = size byte, table[1] = root node; children pairs follow
    table = [0, 0]; queue = [(root, 1)]
    while queue:
        t, pos = queue.pop(0)
        pair = len(table)
        table += [0, 0]
        off = (pair - (pos & ~1) - 2) // 2
        assert 0 <= off < 64
        v = off
        for side, ch in enumerate((t[1], t[2])):
            if ch[0] == 'leaf':
                v |= 0x80 >> side; table[pair + side] = ch[1]
            else:
                queue.append((ch, pair + side))
        table[pos] = v
    table[0] = len(table) // 2 - 1
    if len(table) % 4: table += [0] * (-len(table) % 4)       # bitstream starts word aligned (header 4 + table)
    table[0] = (len(table)) // 2 - 1
    bits = ''.join(codes[s] for s in syms)
    bits += '0' * (-len(bits) % 32)
    words = b''.join(struct.pack('<I', int(bits[i:i + 32], 2)) for i in range(0, len(bits), 32))
    return hdr(0x24, len(data)) + bytes(table) + words


def diff_decode(d, o, width):
    """BIOS Diff8bitUnFilter (header 0x81) / Diff16bitUnFilter (0x82) -> (data, end)"""
    n = int.from_bytes(d[o + 1:o + 4], 'little'); src = d[o + 4:o + 4 + n]
    if len(src) < n: return None
    if width == 1:
        out = bytearray(n); acc = 0
        for i, b in enumerate(src): acc = (acc + b) & 0xFF; out[i] = acc
    else:
        out = bytearray(n); acc = 0
        for i in range(0, n - 1, 2):
            acc = (acc + (src[i] | src[i + 1] << 8)) & 0xFFFF; out[i] = acc & 0xFF; out[i + 1] = acc >> 8
    return bytes(out), o + 4 + n


def diff8(data):
    out = bytearray(hdr(0x81, len(data))); prev = 0
    for b in data: out.append((b - prev) & 0xFF); prev = b
    return pad4(bytes(out))


def diff16(data):
    out = bytearray(hdr(0x82, len(data))); prev = 0
    for i in range(0, len(data) - 1, 2):
        v = data[i] | data[i + 1] << 8; dv = (v - prev) & 0xFFFF; prev = v
        out += bytes([dv & 0xFF, dv >> 8])
    return pad4(bytes(out))


def pack(raw, stages):
    """stages: list in decode order, e.g. ['huff', 'lz'] -> Huffman of (LZ77 of raw)."""
    data = raw
    for st in reversed(stages):
        data = {'huff': huffman4, 'lz': lz77, 'rl': rle, 'diff8': diff8, 'diff16': diff16}[st](data)
    return data


def unpack(d, o):
    """Decode a chained block at ROM offset o -> (raw, stages, end of the first stage)."""
    stages = []; data = d; pos = o; end = None
    while True:
        t = data[pos]
        r = dec.huffman(data, pos) if t in (0x24, 0x28) else dec.lz77(data, pos) if t == 0x10 else \
            dec.rle(data, pos) if t == 0x30 else (diff_decode(data, pos, t - 0x80) if stages else None) if t in (0x81, 0x82) else None
        if r is None: break
        stages.append({0x24: 'huff', 0x28: 'huff', 0x10: 'lz', 0x30: 'rl', 0x81: 'diff8', 0x82: 'diff16'}[t])
        if end is None: end = r[1]
        data, pos = r[0], 0
        if len(data) < 4: break
    return (data if stages else None), stages, end


if __name__ == '__main__':
    import random
    r = random.Random(1)
    for trial in range(30):
        raw = bytes(r.choice([0, 0, 1, 2, 3, 0x11, 0xFF, r.randrange(256)]) for _ in range(r.randrange(16, 3000)))
        for st in (['huff', 'lz'], ['huff', 'lz', 'rl'], ['lz'], ['huff'], ['huff', 'rl'], ['lz', 'rl'], ['huff', 'diff8'], ['huff', 'diff16']):
            if 'diff16' in st: raw = raw[:len(raw) & ~1]
            p = pack(raw, st)
            got, s2, e = unpack(p, 0)
            assert got == raw and s2 == st, (st, len(raw))
    print('bios encoders: round trip OK')
