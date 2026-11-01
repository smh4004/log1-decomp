#!/usr/bin/env python3
"""Map records (format from RE_NOTES, earlier session; re-verified here).

Map record M:
  +0x18..+0x24  layer headers BG0..BG3 (0 = unused)
  +0x38 / +0x3C walkable floor mask / play-area mask (WFZ 8 KB, 1 bit per 8x8 tile)
  +0x4C         tile list: WFZ u16 deltas, id[i] = id[i-1] + v + 1; high byte = page, low byte = tile
  +0x50         page table: pointers to WFZ pages (256 tiles, 8bpp, 16 KB)
Layer header: +0 handler, +4/+8 parallax X/Y (0x400 = 1.0), +0xC layer<<16, +0x14 dims (byte0 = chunks wide, byte1 = high),
              +0x18 chunk pointers, row-major.
Chunk: WFZ, 32x32 u16: bits 0-9 tile slot, bit 10 hflip, bit 11 vflip.
"""
import struct, sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'wfz'))
from wfz import unpack

from const import ROM, PALETTE, PAGE_TABLE, RODATA


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def palette(d, n=512):
    p = d[PALETTE:PALETTE + 3 * n]
    return [(p[3 * i], p[3 * i + 1], p[3 * i + 2]) for i in range(n)]


def read_map(d, M):
    layers = []
    for k in range(4):
        L = u32(d, M + 0x18 + 4 * k)
        if not L: layers.append(None); continue
        L -= ROM
        dims = u32(d, L + 0x14); cw, ch = dims & 0xFF, (dims >> 8) & 0xFF
        chunks = [u32(d, L + 0x18 + 4 * i) - ROM for i in range(cw * ch)]
        layers.append(dict(header=L, cw=cw, ch=ch, chunks=chunks, prio=(u32(d, L + 0xC) >> 16)))
    tl = unpack(d, u32(d, M + 0x4C) - ROM)[0]
    ids, cur = [], -1
    for i in range(0, len(tl), 2):
        cur = cur + struct.unpack_from('<H', tl, i)[0] + 1
        ids.append(cur)
    return dict(M=M, layers=layers, tiles=ids, pages=u32(d, M + 0x50) - ROM)


def chunk_entries(d, off):
    raw = unpack(d, off)[0]
    return list(struct.unpack('<1024H', raw[:2048]))


def render_layer(d, m, k, page_cache=None):
    from PIL import Image
    L = m['layers'][k]
    pal = palette(d, 256)
    page_cache = {} if page_cache is None else page_cache
    def page(p):
        if p not in page_cache:
            page_cache[p] = unpack(d, u32(d, m['pages'] + 4 * p) - ROM)[0]
        return page_cache[p]
    W, H = L['cw'] * 256, L['ch'] * 256
    im = Image.new('P', (W, H)); im.putpalette([c for rgb in pal for c in rgb])
    px = im.load()
    for ci, co in enumerate(L['chunks']):
        cx, cy = (ci % L['cw']) * 256, (ci // L['cw']) * 256
        ent = chunk_entries(d, co)
        for e_i, e in enumerate(ent):
            slot = e & 0x3FF
            if slot >= len(m['tiles']): continue
            tid = m['tiles'][slot]
            pg = page(tid >> 8); t = tid & 0xFF
            hf, vf = e >> 10 & 1, e >> 11 & 1
            bx, by = cx + (e_i % 32) * 8, cy + (e_i // 32) * 8
            for y in range(8):
                for x in range(8):
                    sx = 7 - x if hf else x; sy = 7 - y if vf else y
                    px[bx + x, by + y] = pg[t * 64 + sy * 8 + sx]
    return im


# ------------------------------------------------------------------ whole-layer access (all maps)


def find_maps(d):
    """Every map record: they all point at the global tile page table at +0x50."""
    out = []
    for o in range(RODATA[0], RODATA[1], 4):
        if u32(d, o) == ROM + PAGE_TABLE: out.append(o - 0x50)
    return out


def layer_ok(d, L, wfz_index):
    """Chunked layers only: every chunk pointer is a 2 KB WFZ block (other layer kinds are left alone)."""
    return all(c in wfz_index and wfz_index[c][1] == 2048 for c in L['chunks'])


def layer_grid(d, L, cache=None):
    import numpy as np
    g = np.zeros((L['ch'] * 32, L['cw'] * 32), dtype=np.uint16)
    for ci, co in enumerate(L['chunks']):
        if cache is not None and co in cache: e = cache[co]
        else:
            e = np.frombuffer(unpack(d, co)[0][:2048], dtype='<u2').reshape(32, 32)
            if cache is not None: cache[co] = e
        cy, cx = divmod(ci, L['cw'])
        g[cy * 32:cy * 32 + 32, cx * 32:cx * 32 + 32] = e
    return g


def grid_to_csv(g, path):
    with open(path, 'w') as f:
        for row in g: f.write(','.join('%03X' % v for v in row) + '\n')


def csv_to_grid(path, shape):
    import numpy as np
    rows = [l.strip() for l in open(path) if l.strip()]
    g = np.array([[int(x, 16) for x in r.split(',')] for r in rows], dtype=np.uint16)
    if g.shape != shape: raise ValueError('%s: expected %dx%d entries, got %dx%d' % (path, shape[1], shape[0], g.shape[1], g.shape[0]))
    return g


def render_fast(d, m, k, pages, pal):
    """numpy renderer: layer k of map m -> PIL image (palette indices of the BG palette)."""
    import numpy as np
    from PIL import Image
    L = m['layers'][k]
    g = layer_grid(d, L)
    tiles = m['tiles']
    out = np.zeros((g.shape[0] * 8, g.shape[1] * 8), dtype=np.uint8)
    for (y, x), e in np.ndenumerate(g):
        slot = e & 0x3FF
        if slot >= len(tiles): continue
        tid = tiles[slot]; pg = pages(tid >> 8)
        t = pg[(tid & 0xFF) * 64:(tid & 0xFF) * 64 + 64]
        if len(t) < 64: continue
        a = np.frombuffer(t, dtype=np.uint8).reshape(8, 8)
        if e >> 10 & 1: a = a[:, ::-1]
        if e >> 11 & 1: a = a[::-1, :]
        out[y * 8:y * 8 + 8, x * 8:x * 8 + 8] = a
    im = Image.fromarray(out, 'P'); im.putpalette(pal.flatten().tolist())
    return im


def tile_list_bytes(ids):
    """Inverse of the tile list decoding: ids must be strictly increasing."""
    out = bytearray(); cur = -1
    for t in ids:
        if t <= cur: raise ValueError('tile list must be strictly increasing (got %d after %d)' % (t, cur))
        out += struct.pack('<H', t - cur - 1); cur = t
    return bytes(out)
