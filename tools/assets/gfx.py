"""Background tile pages <-> PNG.

All maps draw from one global table of tile pages (gUnknown_08179764, 187 WFZ blocks). A page holds up to 256 8x8 tiles,
8 bits per pixel, indices into the BG half (colours 0-255) of the master palette (assets/palette/master.txt).
A tile id is page << 8 | tile.

PNG layout: 16 tiles per row (128 px wide), tile n at ((n % 16) * 8, (n // 16) * 8). Pages are written as indexed PNGs
with the BG palette. On import an indexed PNG is taken index for index; an RGB image is matched to the nearest BG palette
colour (exact colours are kept exactly), so any editor works. The tile count must stay the same (rows of 16).
"""
import struct
import numpy as np

from const import ROM, PAGE_TABLE, PALETTE


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def bg_palette(d, pal_override=None):
    p = pal_override or d[PALETTE:PALETTE + 3 * 256]
    return np.frombuffer(bytes(p[:768]), dtype=np.uint8).reshape(256, 3)


def page_offsets(d, wfz_index):
    out = []; n = 0
    while u32(d, PAGE_TABLE + 4 * n) - ROM in wfz_index:
        out.append(u32(d, PAGE_TABLE + 4 * n) - ROM); n += 1
    return out


def page_to_png(raw, pal, path):
    from PIL import Image
    nt = len(raw) // 64
    rows = (nt + 15) // 16
    a = np.zeros((rows * 8, 128), dtype=np.uint8)
    t = np.frombuffer(raw[:nt * 64], dtype=np.uint8).reshape(nt, 8, 8)
    for i in range(nt):
        a[(i // 16) * 8:(i // 16) * 8 + 8, (i % 16) * 8:(i % 16) * 8 + 8] = t[i]
    im = Image.fromarray(a, 'P'); im.putpalette(pal.flatten().tolist()); im.save(path)


def png_to_page(path, pal, ntiles):
    from PIL import Image
    im = Image.open(path)
    if im.mode == 'P':
        a = np.array(im, dtype=np.uint8)
    else:
        rgb = np.array(im.convert('RGB'), dtype=np.int32)
        flat = rgb.reshape(-1, 3)
        dist = ((flat[:, None, :] - pal[None, :, :].astype(np.int32)) ** 2).sum(-1)
        a = dist.argmin(1).astype(np.uint8).reshape(rgb.shape[:2])
    rows = (ntiles + 15) // 16
    if a.shape != (rows * 8, 128):
        raise ValueError('%s: expected %dx%d pixels, got %dx%d' % (path, 128, rows * 8, a.shape[1], a.shape[0]))
    out = bytearray()
    for i in range(ntiles):
        out += a[(i // 16) * 8:(i // 16) * 8 + 8, (i % 16) * 8:(i % 16) * 8 + 8].tobytes()
    return bytes(out)
