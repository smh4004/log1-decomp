"""Area maps as Tiled (.tmx) files (used by assets.py). Legacy of Goku.

Area record (gAreaTable, 42 x 0x34 bytes at 0x081C7C48):
  +0x00 u16 screens wide, u16 screens high, u16 width, u16 height (in 8x8 tiles; one screen = 30x20 tiles)
  +0x08 3 x ptr  1-bit masks, 1 bit per tile, row by row: walkable (on foot; also where you can land), flyable
                 (where the player can take off and fly: R button, sub_08002300 area), shots (where ki blasts can
                 travel, sub_0800B5A2)
  +0x14 ptr      area info: music, characters, enemies, pickups, objects, trigger zones (areas.py)
  +0x18 ptr      one byte per screen: which extra tile block (1-based) that screen needs; 0 = any (areas.py)
  +0x1C ptr      list of extra tile blocks {data, flags}, loaded from tile slot 346 on (550 tiles each)
  +0x20 3 x ptr  per-screen tables for BG1 (top), BG2, BG3 (bottom): one pointer per screen (0 = empty) to
                 30x20 u16 entries (bits 0-9 tile slot, 10 h-flip, 11 v-flip; 8 bpp so no palette bits)
  +0x2C ptr      256-colour palette
  +0x30 ptr      tile set {data, flags}, loaded at tile slot 146 (slots 0-145 hold the 4 bpp text font)
Screens live in one array (0x08019BC0-0x08142380, 1,012 screens); 14 are used more than once.

Files: assets/maps/areaNN.tmx (edit in Tiled: https://www.mapeditor.org), assets/maps/tiles/areaNN.png (the area's
1,024 tile slots, for display; edit tile graphics in assets/gfx/blocks/; areas with several extra tile blocks also get
areaNN_blockK.png, for the screens that load block K: see screen_tiles in areas/areaNN.json),
assets/maps/preview/areaNN.png (each screen drawn with its own tile block).
Build: an edited screen used once is rewritten in place; a shared one, or a previously empty one, becomes a new object
and only this area/layer/position's pointer changes. Masks are rewritten in place. The map size can't change.
"""
import os, struct, xml.etree.ElementTree as ET
import numpy as np
import gfxinfo as G

ROM = 0x08000000
FLIPH, FLIPV = 0x80000000, 0x40000000
LAYERS = ['bg1 (top)', 'bg2', 'bg3 (bottom)']
MASKS = ['walkable', 'flyable', 'shots']
FLAG_GID = 1025


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def screen_refs(d):
    refs = {}
    for a in G.areas(d):
        for li, tab in enumerate(a['layers']):
            for k in range(a['sw'] * a['sh']):
                p = u32(d, tab - ROM + 4 * k)
                if p: refs.setdefault(p - ROM, []).append((a['index'], li, k))
    return refs


def vram_tiles(d, a, decoded, starts, block=1):
    """tile slots as the game has them: tile set at 146, extra tile block `block` (1-based) at 346"""
    vram = bytearray(1024 * 64)
    ts = G.area_tiles(d, a, starts)
    for k, (o, slot) in enumerate(ts):
        if k > 0 and k != block: continue
        slot = 146 if k == 0 else 346
        raw = decoded.get(o) or b''
        n = min(len(raw), len(vram) - slot * 64)
        if n > 0: vram[slot * 64:slot * 64 + n] = raw[:n]
    return np.frombuffer(bytes(vram), np.uint8).reshape(1024, 8, 8)


def screen_blocks(d, a):
    """extra tile block per screen (area record +0x18), carrying the last non-zero one forward (as the game does)"""
    raw = d[a['bytes'] - ROM:a['bytes'] - ROM + a['sw'] * a['sh']]
    out, cur = [], next((b for b in raw if b), 1)
    for b in raw:
        cur = b or cur; out.append(cur)
    return out


def layer_grid(d, a, li):
    """-> (H x W uint32 Tiled gids: 0 = empty screen)"""
    g = np.zeros((a['h'], a['w']), np.uint32)
    for k in range(a['sw'] * a['sh']):
        p = u32(d, a['layers'][li] - ROM + 4 * k)
        if not p: continue
        e = np.array(struct.unpack_from('<600H', d, p - ROM), np.uint32).reshape(20, 30)
        gid = (e & 0x3FF) + 1 | np.where(e & 0x400, FLIPH, 0).astype(np.uint32) | np.where(e & 0x800, FLIPV, 0).astype(np.uint32)
        sy, sx = divmod(k, a['sw'])
        g[sy * 20:sy * 20 + 20, sx * 30:sx * 30 + 30] = gid
    return g


def mask_grid(d, a, mi):
    n = a['w'] * a['h']; o = a['masks'][mi] - ROM
    bits = np.unpackbits(np.frombuffer(d[o:o + n // 8], np.uint8), bitorder='little')
    return bits.reshape(a['h'], a['w']).astype(np.uint32)


def render(tiles, pal, grids):
    P = np.array(pal, np.uint8).reshape(-1, 3)
    out = None
    for g in grids:                                       # bottom first
        h, w = g.shape
        img = np.zeros((h * 8, w * 8), np.uint8)
        t = (g & 0x3FFFFFFF).astype(np.int64) - 1
        for y in range(h):
            for x in range(w):
                if t[y, x] < 0: continue
                tile = tiles[t[y, x] & 1023]
                if g[y, x] & FLIPH: tile = tile[:, ::-1]
                if g[y, x] & FLIPV: tile = tile[::-1, :]
                img[y * 8:y * 8 + 8, x * 8:x * 8 + 8] = tile
        out = img if out is None else np.where(img != 0, img, out)
    return P[out]


def csv(g):
    return '\n' + ',\n'.join(','.join(str(int(v)) for v in row) for row in g) + '\n'


def extract(d, out, reg, decoded, starts):
    from PIL import Image
    md = os.path.join(out, 'maps'); os.makedirs(os.path.join(md, 'tiles'), exist_ok=True)
    os.makedirs(os.path.join(md, 'preview'), exist_ok=True)
    fl = np.zeros((8, 16, 4), np.uint8); fl[:, 8:] = (255, 0, 0, 110)
    Image.fromarray(fl, 'RGBA').save(os.path.join(md, 'flags.png'))
    for a in G.areas(d):
        i = a['index']; pal = G.palette_rgb(d, a['palette'] - ROM, 256)
        blocks = screen_blocks(d, a)
        nblk = len(G.area_tiles(d, a, starts)) - 1
        tiles_by = {b: vram_tiles(d, a, decoded, starts, b) for b in set(blocks) | {1}}
        for b in range(1, max(nblk, 1) + 1):
            t = tiles_by.get(b) if b in tiles_by else vram_tiles(d, a, decoded, starts, b)
            sheet = t.reshape(64, 16, 8, 8).transpose(0, 2, 1, 3).reshape(512, 128)
            im = Image.fromarray(sheet, 'P'); im.putpalette(pal)
            im.save(os.path.join(md, 'tiles', 'area%02d%s.png' % (i, '' if b == 1 else '_block%d' % b)))
        grids = [layer_grid(d, a, li) for li in range(3)]
        img = np.zeros((a['h'] * 8, a['w'] * 8, 3), np.uint8)
        for b in set(blocks):         # each screen drawn with the tile block it uses
            part = render(tiles_by[b], pal, grids[::-1])
            for k, bb in enumerate(blocks):
                if bb != b: continue
                sy, sx = divmod(k, a['sw'])
                img[sy * 160:sy * 160 + 160, sx * 240:sx * 240 + 240] = part[sy * 160:sy * 160 + 160, sx * 240:sx * 240 + 240]
        Image.fromarray(img).save(os.path.join(md, 'preview', 'area%02d.png' % i))
        x = ['<?xml version="1.0" encoding="UTF-8"?>',
             '<map version="1.10" orientation="orthogonal" renderorder="right-down" width="%d" height="%d" '
             'tilewidth="8" tileheight="8" infinite="0" nextlayerid="7" nextobjectid="1">' % (a['w'], a['h']),
             ' <properties><property name="area" type="int" value="%d"/>'
             '<property name="screens" value="%dx%d"/></properties>' % (i, a['sw'], a['sh']),
             ' <tileset firstgid="1" name="area%02d" tilewidth="8" tileheight="8" tilecount="1024" columns="16">' % i,
             '  <image source="tiles/area%02d.png" width="128" height="512"/>' % i, ' </tileset>',
             ' <tileset firstgid="%d" name="flags" tilewidth="8" tileheight="8" tilecount="2" columns="2">' % (FLAG_GID - 1),
             '  <image source="flags.png" width="16" height="8"/>', ' </tileset>']
        lid = 1
        for li in (2, 1, 0):
            x.append(' <layer id="%d" name="%s" width="%d" height="%d"><data encoding="csv">%s</data></layer>'
                     % (lid, LAYERS[li], a['w'], a['h'], csv(grids[li]))); lid += 1
        for mi in range(3):
            g = mask_grid(d, a, mi) * (FLAG_GID + 1)               # set bit = the red flag tile (gid 1026)
            vis = '' if mi == 0 else ' visible="0"'
            x.append(' <layer id="%d" name="%s" width="%d" height="%d" opacity="0.6"%s><data encoding="csv">%s</data></layer>'
                     % (lid, MASKS[mi], a['w'], a['h'], vis, csv(g))); lid += 1
        x.append('</map>')
        p = os.path.join(md, 'area%02d.tmx' % i)
        open(p, 'w').write('\n'.join(x) + '\n')
        reg('map:area%02d' % i, p, kind='map', area=i)


def read_tmx(path):
    root = ET.parse(path).getroot()
    out = {}
    for l in root.findall('layer'):
        txt = l.find('data').text
        out[l.get('name')] = np.array([[int(v) for v in row.split(',') if v.strip()]
                                       for row in txt.strip().split('\n') if row.strip()], np.uint64).astype(np.uint32)
    return out


def build(d, a_entry, path, ctx):
    """ctx: put(start, end, data, tag), put_s(start, end, text, size, tag), new(label, data) -> label"""
    a = G.areas(d)[a_entry['area']]
    layers = read_tmx(path)
    refs = ctx.setdefault('screen_refs', screen_refs(d))
    for li in range(3):
        g = layers[LAYERS[li]]
        if g.shape != (a['h'], a['w']): raise SystemExit('%s: layer %s must stay %dx%d' % (path, LAYERS[li], a['w'], a['h']))
        for k in range(a['sw'] * a['sh']):
            sy, sx = divmod(k, a['sw'])
            cell = g[sy * 20:sy * 20 + 20, sx * 30:sx * 30 + 30]
            slot = a['layers'][li] - ROM + 4 * k
            p = u32(d, slot)
            if not p and not cell.any(): continue
            t = (cell & 0x3FFFFFFF).astype(np.int64) - 1
            e = np.where(t < 0, 0, t & 0x3FF) | np.where(cell & FLIPH, 0x400, 0) | np.where(cell & FLIPV, 0x800, 0)
            data = e.astype('<u2').tobytes()
            if p and data == d[p - ROM:p - ROM + 1200]: continue
            if p and len(refs.get(p - ROM, [])) == 1:
                ctx['put'](p - ROM, p - ROM + 1200, data, 'scr')
            else:
                lab = ctx['new']('gArea%02d_%s_Screen%02d' % (a['index'], 'BG%d' % (li + 1), k), data)
                ctx['put_s'](slot, slot + 4, '\t.4byte %s\n' % lab, 4, 'scrptr')
    for mi in range(3):
        g = layers[MASKS[mi]]
        bits = (g != 0).astype(np.uint8).reshape(-1)
        data = np.packbits(bits, bitorder='little').tobytes()
        o = a['masks'][mi] - ROM
        if data != d[o:o + len(data)]: ctx['put'](o, o + len(data), data, 'mask')
