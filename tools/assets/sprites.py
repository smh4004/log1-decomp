"""Character sprite sheets (used by assets.py). Legacy of Goku.

Each of the 109 character sprite sets (names in assets/areas/SPRITES.txt) maps (byte table 0x0815A709) to one of 84
character records (gCharacterTable, 0x085C0C80): {u16 w, u16 h, 4 x (s16 x, s16 y, u16 w, u16 h) collision boxes,
u32 -> 16-colour palette, u32 -> frame table}. The frame table holds 76 pointers (19 rows x 4 facing directions; 0 =
none) to frame records {s16 x, s16 y, u16 w, u16 h, u8 tiles, u8 flags (8 = drawn mirrored), u8 OAM size, u8 OAM
shape, u32 -> tiles}. Frame tiles are uncompressed 4 bpp sprite tiles (1D order: w/8 tiles per row), 0x086B6AC0 on.

assets/sprites/NAME.png: one sheet per character record: 4 columns (directions as stored), 19 rows, each cell holding
that frame (top-left aligned; a mirrored frame is shown mirrored, as in game). An indexed PNG in the character's palette:
draw with its colours (index 0 = transparent). Pixels outside a frame's own size are ignored. Frames shared between
cells or characters are written once; if two cells that share a frame are edited differently, the build stops.
Palettes: assets/palettes (the record's palette label).
"""
import os, struct
import numpy as np
import gfxinfo as G

ROM = 0x08000000
CHARS, N_CHARS = 0x5C0C80, 84
SPRITE_MAP = 0x15A709
ROWS, COLS = 19, 4


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def record(d, c):
    r = u32(d, CHARS + 4 * c) - ROM
    pal, tab = struct.unpack_from('<2I', d, r + 0x24)
    frames = []
    for k in range(ROWS * COLS):
        p = u32(d, tab - ROM + 4 * k)
        if not p: frames.append(None); continue
        o = p - ROM
        x, y, w, h = struct.unpack_from('<hhHH', d, o)
        nt, fl = d[o + 8], d[o + 9]
        frames.append(dict(desc=o, w=w, h=h, tiles=nt, flip=bool(fl & 8), gfx=u32(d, o + 12) - ROM))
    return r, pal - ROM, frames


def tiles_to_img(raw, w, h):
    tw, th = w // 8, h // 8
    b = np.frombuffer(raw[:tw * th * 32], np.uint8)
    px = np.empty(b.size * 2, np.uint8); px[0::2] = b & 15; px[1::2] = b >> 4
    return px.reshape(th, tw, 8, 8).transpose(0, 2, 1, 3).reshape(h, w)


def img_to_tiles(img, w, h):
    tw, th = w // 8, h // 8
    t = (np.asarray(img, np.uint8) & 15).reshape(th, 8, tw, 8).transpose(0, 2, 1, 3).reshape(-1)
    return (t[0::2] | (t[1::2] << 4)).astype(np.uint8).tobytes()


def names_for(d, names):
    m = d[SPRITE_MAP:SPRITE_MAP + len(names)]
    out = {}
    for s, c in enumerate(m):
        out.setdefault(c, names[s])
    return out


def cell_size(frames):
    fs = [f for f in frames if f]
    return (max(f['w'] for f in fs), max(f['h'] for f in fs)) if fs else (8, 8)


def extract(d, out, reg, names):
    from PIL import Image
    sd = os.path.join(out, 'sprites'); os.makedirs(sd, exist_ok=True)
    nm = names_for(d, names)
    for c in range(N_CHARS):
        r, pal, frames = record(d, c)
        cw, ch = cell_size(frames)
        sheet = np.zeros((ROWS * ch, COLS * cw), np.uint8)
        for k, f in enumerate(frames):
            if not f: continue
            img = tiles_to_img(d[f['gfx']:f['gfx'] + f['tiles'] * 32], f['w'], f['h'])
            if f['flip']: img = img[:, ::-1]
            y, x = (k // COLS) * ch, (k % COLS) * cw
            sheet[y:y + f['h'], x:x + f['w']] = img
        name = nm.get(c, 'char%02d' % c)
        p = os.path.join(sd, '%s.png' % name)
        rgb = G.palette_rgb(d, pal, 16)
        im = Image.fromarray(sheet, 'P'); im.putpalette(rgb + [0] * (768 - len(rgb))); im.save(p)
        reg('sprite:%s' % name, p, kind='sprite', char=c, palette=rgb)


def build(d, a, path, ctx):
    r, pal, frames = record(d, a['char'])
    cw, ch = cell_size(frames)
    img = G.load_png(path, a['palette'])
    if img.shape != (ROWS * ch, COLS * cw):
        raise SystemExit('%s: keep the sheet size %dx%d' % (path, COLS * cw, ROWS * ch))
    written = ctx.setdefault('sprite_gfx', {})
    for k, f in enumerate(frames):
        if not f: continue
        y, x = (k // COLS) * ch, (k % COLS) * cw
        cell = img[y:y + f['h'], x:x + f['w']]
        if f['flip']: cell = cell[:, ::-1]
        b = img_to_tiles(cell, f['w'], f['h'])
        old = d[f['gfx']:f['gfx'] + len(b)]
        if b == old: continue
        if f['gfx'] in written:
            if written[f['gfx']] != b:
                raise SystemExit('%s: row %d column %d shares its frame with another edited cell; make both the same'
                                 % (path, k // COLS, k % COLS))
            continue
        written[f['gfx']] = b
        ctx['put'](f['gfx'], f['gfx'] + len(b), b, 'spr')
