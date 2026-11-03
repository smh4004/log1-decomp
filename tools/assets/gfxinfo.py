"""What each BIOS-compressed block is and which palette draws it (Legacy of Goku).

The game describes an image as {u32 palette, u32 data, u32 flags} (flags = Decompress stages). Most images keep this
header right before their compressed data; full-screen pictures are listed in tables of such triples. Area tile sets
are {data, flags} pairs, drawn with the area's 256-colour palette (area record +0x2C, see maps.py).

Layouts (how the decoded bytes become a picture):
  portrait   512 bytes: 32x32, 4x4 tiles of 4 bpp (dialogue faces), 16 colours
  screen8    38,400 bytes: 240x160, 30x20 tiles of 8 bpp, 256 colours
  bitmap8    38,400 bytes: 240x160 bitmap, 1 byte per pixel (mode 4), 256 colours
  tiles8     area tile sets: 8 bpp tiles, 16 per row, 256 colours
  tiles4     everything else: 4 bpp tiles, 16 per row (grey levels = colour index unless a 16-colour palette is known)
"""
import struct, re
import numpy as np

ROM = 0x08000000
AREA_TABLE, AREA_COUNT, AREA_SIZE = 0x1C7C48, 42, 0x34       # gAreaTable (pointer list at 0x081CA09C)


def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def isrom(v, d): return ROM <= v < ROM + len(d)


def areas(d):
    """-> list of dicts: screens wide/high, size in tiles, field pointers (see maps.py)"""
    out = []
    for i in range(AREA_COUNT):
        r = struct.unpack_from('<4H11I', d, AREA_TABLE + AREA_SIZE * i)
        out.append(dict(index=i, rec=AREA_TABLE + AREA_SIZE * i, sw=r[0], sh=r[1], w=r[2], h=r[3],
                        masks=list(r[4:7]), info=r[7], bytes=r[8], extras=r[9], layers=list(r[10:13]),
                        palette=r[13], tileset=r[14]))
    return out


def area_tiles(d, a, starts):
    """-> [(block offset, first tile slot)]: tile set at slot 146, extra tile blocks from slot 346"""
    out = [(u32(d, a['tileset'] - ROM) - ROM, 146)]
    if a['extras']:
        q = a['extras'] - ROM; slot = 346
        while True:
            dsc = u32(d, q)
            if not isrom(dsc, d) or u32(d, dsc - ROM) - ROM not in starts: break
            out.append((u32(d, dsc - ROM) - ROM, slot)); slot += 550; q += 4
    return out


def smooth(img):
    return np.mean(img[:, 1:] == img[:, :-1]) + np.mean(img[1:, :] == img[:-1, :])


def classify(d, blocks, decoded):
    """-> {block offset: dict(layout, palette (ROM offset or None), colours, area)}"""
    starts = {b[0] for b in blocks}
    info = {}
    for a in areas(d):
        for o, slot in area_tiles(d, a, starts):
            info.setdefault(o, dict(layout='tiles8', palette=a['palette'] - ROM, colours=256, area=a['index']))
    for o, _, _, _ in blocks:
        if o in info: continue
        raw = decoded.get(o)
        if raw is None: continue
        pal = None
        if u32(d, o - 8) == o + ROM and isrom(u32(d, o - 12), d):
            pal = u32(d, o - 12) - ROM
        else:
            for m in re.finditer(re.escape(struct.pack('<I', o + ROM)), d):
                r = m.start()
                if r % 4 == 0 and r >= 4 and u32(d, r + 4) < 0x100 and isrom(u32(d, r - 4), d) \
                        and u32(d, r - 4) - ROM not in starts:
                    pal = u32(d, r - 4) - ROM; break
        if len(raw) == 512 and pal is not None:
            info[o] = dict(layout='portrait', palette=pal, colours=16)
        elif len(raw) == 38400 and pal is not None:
            a = np.frombuffer(raw, np.uint8)
            lin = a.reshape(160, 240)
            til = a.reshape(20, 30, 8, 8).transpose(0, 2, 1, 3).reshape(160, 240)
            info[o] = dict(layout='bitmap8' if smooth(lin) > smooth(til) else 'screen8', palette=pal, colours=256)
        else:
            info[o] = dict(layout='tiles4', palette=pal, colours=16 if pal is not None else 0)
    return info


def palette_rgb(d, o, n):
    out = []
    for i in range(n):
        c = struct.unpack_from('<H', d, o + 2 * i)[0]
        out += [(c & 31) * 255 // 31, (c >> 5 & 31) * 255 // 31, (c >> 10 & 31) * 255 // 31]
    return out


def grey():
    return [v for i in range(16) for v in (i * 17,) * 3]


# ---- decoded bytes <-> index image
def to_index(raw, layout):
    """-> 2D uint8 array of colour indexes (and the number of whole tiles / bytes it covers)"""
    b = np.frombuffer(raw, np.uint8)
    if layout == 'bitmap8': return b[:38400].reshape(160, 240)
    if layout == 'screen8': return b[:38400].reshape(20, 30, 8, 8).transpose(0, 2, 1, 3).reshape(160, 240)
    if layout in ('tiles8',):
        nt = len(raw) // 64; px = b[:nt * 64]; wide = 16
    else:
        nt = len(raw) // 32; px = np.empty(nt * 64, np.uint8); px[0::2] = b[:nt * 32] & 15; px[1::2] = b[:nt * 32] >> 4
        wide = 4 if layout == 'portrait' else 16
    rows = (nt + wide - 1) // wide
    t = np.zeros((rows * wide, 8, 8), np.uint8); t[:nt] = px.reshape(nt, 8, 8)
    return t.reshape(rows, wide, 8, 8).transpose(0, 2, 1, 3).reshape(rows * 8, wide * 8)


def from_index(img, raw, layout):
    """inverse of to_index; bytes not covered by whole tiles are kept from `raw`"""
    img = np.asarray(img, np.uint8)
    if layout == 'bitmap8': return img.reshape(-1).tobytes() + raw[38400:]
    if layout == 'screen8': return img.reshape(20, 8, 30, 8).transpose(0, 2, 1, 3).reshape(-1).tobytes() + raw[38400:]
    if layout == 'tiles8':
        nt = len(raw) // 64; wide = 16
    else:
        nt = len(raw) // 32; wide = 4 if layout == 'portrait' else 16
    rows = img.shape[0] // 8
    t = img.reshape(rows, 8, wide, 8).transpose(0, 2, 1, 3).reshape(-1, 8, 8)[:nt].reshape(-1)
    if layout == 'tiles8': return t.tobytes() + raw[nt * 64:]
    t = t & 15
    return (t[0::2] | (t[1::2] << 4)).astype(np.uint8).tobytes() + raw[nt * 32:]


def save_png(raw, layout, pal, path):
    from PIL import Image
    idx = to_index(raw, layout)
    if idx.size == 0: return False
    im = Image.fromarray(idx, 'P'); p = list(pal) + [0] * (768 - len(pal)); im.putpalette(p[:768])
    im.save(path); return True


def load_png(path, pal):
    """-> index array. Indexed PNGs give their indexes; RGB images are matched to the palette (nearest colour)."""
    from PIL import Image
    im = Image.open(path)
    if im.mode == 'P': return np.array(im, np.uint8)
    rgb = np.array(im.convert('RGB'), np.int32)
    P = np.array(pal, np.int32).reshape(-1, 3)
    cols, inv = np.unique(rgb.reshape(-1, 3), axis=0, return_inverse=True)
    best = ((cols[:, None, :] - P[None, :, :]) ** 2).sum(-1).argmin(-1).astype(np.uint8)
    return best[inv.reshape(-1)].reshape(rgb.shape[:2])
