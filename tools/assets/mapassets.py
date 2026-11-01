"""All maps, tile pages and collision masks as editable files (used by assets.py).

assets/gfx/tiles/page_NNN.png          global BG tile pages (see gfx.py)
assets/maps/index.csv                  every map record: folder, address, layers (w x h in 256 px chunks)
assets/maps/<map>/L<k>.csv             whole layer k as one grid (hex u16 per 8x8 cell: bits 0-9 tile slot,
                                       bit 10 h-flip, bit 11 v-flip). Size stays fixed.
assets/maps/<map>/tiles.txt            the map's tile list: slot -> tile id (page:tile, hex), strictly increasing
assets/maps/<map>/floor.png, area.png  256x256 collision masks (1 px per 8x8 cell): walkable floor / play area
assets/maps/<map>/L<k>.png             preview (only with `assets.py extract --previews`; not read by the build)

Build rules: a changed chunk that is used only once is recompressed in place (or relocated if it grew); a chunk shared
with another map or position is copied (copy-on-write) and only this layer's pointer is changed. Tile lists and masks
work the same way.
"""
import os, re, struct, json
import numpy as np
import maps as M
import gfx
import labels as L
from wfz import unpack
from wfz_compress import compress

from const import ROM, AREAS, ui_string


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def map_name(o):
    return L.name_at(o) or 'map_%06X' % o




def area_links(d):
    """map record -> [(world, area, area name)]: area +0x2C -> scene record, whose first word is map record + 4."""
    out = {}
    for i in range(AREAS[1]):
        r = AREAS[0] + AREAS[2] * i
        sc = u32(d, r + 0x2C)
        if not sc: continue
        mo = u32(d, sc - ROM) - ROM - 4
        name = ui_string(d, u32(d, r + 0xC))
        out.setdefault(mo, []).append((d[r], d[r + 1], name))
    return out


def refcounts(d, maps_, wfz):
    rc = {}
    for mo in maps_:
        m = M.read_map(d, mo)
        for Ly in m['layers']:
            if Ly and M.layer_ok(d, Ly, wfz):
                for c in Ly['chunks']: rc[c] = rc.get(c, 0) + 1
        for f in (0x38, 0x3C, 0x4C):
            p = u32(d, mo + f) - ROM; rc[p] = rc.get(p, 0) + 1
    return rc


def mask_png(raw, path):
    from PIL import Image
    bits = np.unpackbits(np.frombuffer(raw[:8192], dtype=np.uint8), bitorder='little').reshape(256, 256)
    Image.fromarray((bits * 255).astype(np.uint8), 'L').convert('1').save(path)


def png_mask(path):
    from PIL import Image
    a = np.array(Image.open(path).convert('L')) > 127
    if a.shape != (256, 256): raise ValueError('%s must be 256x256' % path)
    return np.packbits(a.astype(np.uint8).flatten(), bitorder='little').tobytes()


def extract(d, out, reg, wfz, previews=False):
    pal = gfx.bg_palette(d)
    pages = gfx.page_offsets(d, wfz)
    gd = os.path.join(out, 'gfx', 'tiles'); os.makedirs(gd, exist_ok=True)
    cache = {}

    def page(p):
        if p not in cache: cache[p] = unpack(d, pages[p])[0]
        return cache[p]
    for i, po in enumerate(pages):
        p = os.path.join(gd, 'page_%03d.png' % i)
        gfx.page_to_png(page(i), pal, p)
        reg('tiles:%03d' % i, p, kind='tilepage', start=po, ntiles=len(page(i)) // 64)
    maps_ = M.find_maps(d)
    md0 = os.path.join(out, 'maps'); os.makedirs(md0, exist_ok=True)
    idx = ['folder,address,layers,areas (world-area name)']
    users = area_links(d)
    names = {}
    for mo in maps_:
        a = users.get(mo)
        names[mo] = ('w%02X_a%02X_%s' % (a[0][0], a[0][1], re.sub(r'\W+', '_', a[0][2]).strip('_') or 'area')) if a else map_name(mo)
    taken = {}
    for mo in maps_:
        n = names[mo]; taken[n] = taken.get(n, 0) + 1
        if taken[n] > 1: names[mo] = '%s_%d' % (n, taken[n])
    ccache = {}
    for mo in maps_:
        m = M.read_map(d, mo); name = names[mo]
        md = os.path.join(md0, name); os.makedirs(md, exist_ok=True)
        lay = []
        for k, Ly in enumerate(m['layers']):
            if not Ly or not M.layer_ok(d, Ly, wfz): continue
            g = M.layer_grid(d, Ly, ccache)
            p = os.path.join(md, 'L%d.csv' % k); M.grid_to_csv(g, p)
            reg('layer:%s:%d' % (name, k), p, kind='layer', map=mo, layer=k, header=Ly['header'],
                cw=Ly['cw'], ch=Ly['ch'], chunks=Ly['chunks'])
            lay.append('L%d %dx%d' % (k, Ly['cw'], Ly['ch']))
            if previews:
                try: M.render_fast(d, m, k, page, pal).save(os.path.join(md, 'L%d.png' % k))
                except Exception as ex: print('preview failed', name, k, ex)
        p = os.path.join(md, 'tiles.txt')
        with open(p, 'w') as f:
            f.write('# slot: page:tile (hex). Strictly increasing. Add tiles here to use them in this map (slot = line order).\n')
            for s, t in enumerate(m['tiles']): f.write('%X:%02X    # slot %d\n' % (t >> 8, t & 0xFF, s))
        reg('tilelist:%s' % name, p, kind='tilelist', map=mo, start=u32(d, mo + 0x4C) - ROM)
        for f, nm in ((0x38, 'floor'), (0x3C, 'area')):
            mo_ = u32(d, mo + f) - ROM
            p = os.path.join(md, '%s.png' % nm); mask_png(unpack(d, mo_)[0], p)
            reg('mask:%s:%s' % (name, nm), p, kind='mask', map=mo, field=f, start=mo_)
        idx.append('%s,0x%08X,%s,%s' % (name, ROM + mo, ' '.join(lay),
                   ' / '.join('%02X-%02X %s' % a for a in users.get(mo, []))))
    open(os.path.join(md0, 'index.csv'), 'w').write('\n'.join(idx) + '\n')


class Ctx:
    """Override helpers handed in by assets.build."""
    def __init__(self, d, wfz, out, ov):
        self.d, self.wfz, self.out, self.ov = d, wfz, out, ov
        self._rc = None

    def rc(self):
        if self._rc is None: self._rc = refcounts(self.d, M.find_maps(self.d), self.wfz)
        return self._rc

    def put(self, start, end, data, tag):
        fn = os.path.join(self.out, 'ov_%06X_%s.bin' % (start, tag)); open(fn, 'wb').write(data)
        self.ov.append({'start': start, 'end': end, 'file': fn})

    def new(self, name, data):
        fn = os.path.join(self.out, 'new_%s.bin' % name); open(fn, 'wb').write(data)
        self.ov.append({'new': name, 'file': fn})

    def asm(self, start, end, text, size, tag):
        fn = os.path.join(self.out, 'ov_%06X_%s.s' % (start, tag)); open(fn, 'w').write(text)
        self.ov.append({'start': start, 'end': end, 'file': fn, 'size': size})

    def ptr(self, at, sym, tag):
        fn = os.path.join(self.out, 'ov_%06X_%s.s' % (at, tag)); open(fn, 'w').write('\t.4byte %s\n' % sym)
        self.ov.append({'start': at, 'end': at + 4, 'file': fn, 'size': 4})

    def replace_block(self, off, data, ptr_at, newname, tag):
        """Replace WFZ block `off` (raw data `data`): in place if only one user, else copy and repoint `ptr_at`."""
        blob = compress(data)
        if self.rc().get(off, 0) <= 1:
            self.put(off, self.wfz[off][2], blob, tag)
        else:
            self.new(newname, blob); self.ptr(ptr_at, newname, tag + 'p')


def build(d, a, path, ctx):
    k = a['kind']
    if k == 'tilepage':
        pal = gfx.bg_palette(d)
        raw = gfx.png_to_page(path, pal, a['ntiles'])
        if raw != unpack(d, a['start'])[0]:
            ctx.put(a['start'], ctx.wfz[a['start']][2], compress(raw), 'page')
    elif k == 'layer':
        g = M.csv_to_grid(path, (a['ch'] * 32, a['cw'] * 32))
        for ci, co in enumerate(a['chunks']):
            cy, cx = divmod(ci, a['cw'])
            e = g[cy * 32:cy * 32 + 32, cx * 32:cx * 32 + 32].astype('<u2').tobytes()
            orig = unpack(d, co)[0]
            if e == orig[:2048]: continue
            ctx.replace_block(co, e + orig[2048:], a['header'] + 0x18 + 4 * ci,
                              'Chunk_%06X_L%d_%d' % (a['map'], a['layer'], ci), 'chunk')
    elif k == 'tilelist':
        ids = []
        for l in open(path):
            l = l.split('#')[0].strip()
            if not l: continue
            p, t = l.split(':'); ids.append(int(p, 16) << 8 | int(t, 16))
        raw = M.tile_list_bytes(ids)
        if raw != unpack(d, a['start'])[0]:
            ctx.replace_block(a['start'], raw, a['map'] + 0x4C, 'Tiles_%06X' % a['map'], 'tiles')
    elif k == 'mask':
        raw = png_mask(path)
        if raw != unpack(d, a['start'])[0][:8192]:
            ctx.replace_block(a['start'], raw, a['map'] + a['field'], 'Mask_%06X_%X' % (a['map'], a['field']), 'mask')
