#!/usr/bin/env python3
"""Editable assets for the Legacy of Goku disassembly.

  assets.py extract     baserom.gba -> assets/ (editable files + assets/manifest.json)
  assets.py build       assets/ -> build_modern/overrides/overrides.json + replacement blobs (only edited assets)

Asset kinds (all pulled from the user's baserom.gba; nothing copyrighted is committed):
  text      assets/text/strings.txt       every other string the game points to (menus, names, story): "LABEL<TAB>text".
                                          Any length: a longer string moves to the end of the data and every pointer
                                          to it follows (pointers are symbols in data/*.s).
  blocks    assets/gfx/blocks/LABEL.bin   every BIOS-compressed block (Huffman / LZ77 / run-length / diff filter, decoded
            assets/gfx/blocks/LABEL.png   the way the game does): raw bytes, plus an indexed PNG drawn the way the game
                                          draws it, in its own palette (tools/assets/gfxinfo.py: faces, full screens,
                                          area tile sets; others as grey 4bpp tiles). Edit either; the build re-packs
                                          with the same stages.
  palettes  assets/palettes/LABEL.pal     every palette those images and the areas use (JASC-PAL text: one "R G B" line
                                          per colour, 0-255). Same number of colours; written back in place.
  maps      assets/maps/areaNN.tmx        the 42 areas as Tiled maps: 3 tile layers + walkable/mask layers (maps.py)
  tables    assets/tables/*.csv           enemy stats and the player's level table (tables.py)
  areas     assets/areas/areaNN.json      characters, enemies, pickups, objects and trigger zones (warps...) (areas.py)
  dialogue  assets/dialogue/setNN.txt     the 80 conversation sets: speaker, next line, text (dialogue.py)
  story     assets/story/quests.json      the 75 quests: tasks and what happens when they are done (quests.py)
  sprites   assets/sprites/NAME.png       character sprite sheets, 19 rows x 4 directions (sprites.py)
  sound     assets/sound/sampleNN.wav     the 20 instrument / sound samples, any length and rate (sound.py)
  music     assets/music/songNN.txt       the 18 songs as tracker text: tempo, order, patterns, notes (music.py)
  movies    assets/movies/movieN.fli      the 3 intro movies as FLI files and PNG frames (movies.py)
Overrides are applied to the generated data/*.s by tools/assets/apply.py (make modern).
"""
import sys, os, json, struct, hashlib, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, '..', 'bfdis'))
import labels as L
import bios
import gfxinfo as G
import maps as M
import tables as T
import areas as AR
import dialogue as DLG
import quests as QST
import sprites as SPR
import sound as SND
import music as MUS
import movies as MOV
from const import ROM, RODATA


def sha(path): return hashlib.sha1(open(path, 'rb').read()).hexdigest()


def esc(s):
    out = []
    for ch in s:
        c = ord(ch)
        if ch == '{': out.append('{{')
        elif c < 0x20 or c == 0x7F: out.append('{%02X}' % c)
        else: out.append(ch)
    return ''.join(out)


def unesc(s):
    return re.sub(r'\{\{|\{([0-9A-Fa-f]{2})\}', lambda m: '{' if m.group(0) == '{{' else chr(int(m.group(1), 16)), s)


def strings(d):
    """labelled objects that start with a C string: [(offset, text, object end)]"""
    at, keys = L.index()
    out = []
    for o in keys:
        e = L.object_end(o) or o
        m = re.match(rb'([ -~\n\t]{3,})\x00', d[o:min(e, o + 4096)])
        if m and re.search(rb'[A-Za-z]{2}', m.group(1)): out.append((o, m.group(1).decode('latin-1'), e))
    return out


def blocks():
    return json.load(open('.analysis/lz_blocks.json'))


def to_png(raw, path):
    from PIL import Image
    import numpy as np
    nt = len(raw) // 32
    if nt == 0: return False
    rows = (nt + 15) // 16
    a = np.zeros((rows * 8, 128), dtype=np.uint8)
    b = np.frombuffer(raw[:nt * 32], dtype=np.uint8)
    px = np.empty(nt * 64, dtype=np.uint8); px[0::2] = b & 15; px[1::2] = b >> 4
    t = px.reshape(nt, 8, 8)
    for i in range(nt):
        a[(i // 16) * 8:(i // 16) * 8 + 8, (i % 16) * 8:(i % 16) * 8 + 8] = t[i]
    im = Image.fromarray(a, 'P'); im.putpalette([v for i in range(16) for v in (i * 17,) * 3] + [0] * 720)
    im.save(path); return True


def from_png(path, raw):
    from PIL import Image
    import numpy as np
    a = np.array(Image.open(path).convert('P') if Image.open(path).mode != 'P' else Image.open(path), dtype=np.uint8) & 15
    nt = len(raw) // 32; out = bytearray()
    for i in range(nt):
        t = a[(i // 16) * 8:(i // 16) * 8 + 8, (i % 16) * 8:(i % 16) * 8 + 8].reshape(64)
        out += bytes((t[0::2] | (t[1::2] << 4)).tolist())
    return bytes(out) + raw[nt * 32:]


def extract(rom, out):
    d = open(rom, 'rb').read()
    man = {'assets': {}}
    os.makedirs(out, exist_ok=True)

    def reg(name, path, **kw):
        kw['file'] = os.path.relpath(path, out); kw['sha1'] = sha(path)
        man['assets'][name] = kw

    p = os.path.join(out, 'text', 'strings.txt'); os.makedirs(os.path.dirname(p), exist_ok=True)
    conv = DLG.dialogue_texts(d)
    st = [x for x in strings(d) if x[0] not in conv]
    with open(p, 'w', encoding='utf-8') as f:
        f.write('# Every string the game points to: "LABEL<TAB>text". Any length. {XX} = control character (0A = new line), {{ = brace.\n')
        for o, t, e in st: f.write('%s\t%s\n' % (L.name_at(o), esc(t)))
    reg('text', p, kind='text', items=[(o, len(t), e) for o, t, e in st])

    bd = os.path.join(out, 'gfx', 'blocks'); os.makedirs(bd, exist_ok=True)
    blks = blocks(); decoded = {}
    for o, size, end, typ in blks:
        decoded[o] = bios.unpack(d, o)[0]
    info = G.classify(d, blks, decoded)
    pals = {}
    for o, size, end, typ in blks:
        raw, stages, e = bios.unpack(d, o)
        if raw is None: continue
        lab = L.name_at(o) or 'blk_%06X' % o
        pb = os.path.join(bd, lab + '.bin'); open(pb, 'wb').write(raw)
        pp = os.path.join(bd, lab + '.png')
        inf = info.get(o, dict(layout='tiles4', palette=None, colours=0))
        pal = G.palette_rgb(d, inf['palette'], inf['colours']) if inf['palette'] is not None and inf['colours'] else G.grey()
        if inf['palette'] is not None and inf['colours']:
            pals[inf['palette']] = max(pals.get(inf['palette'], 0), inf['colours'])
        has = G.save_png(raw, inf['layout'], pal, pp)
        reg('block:%s' % lab, pb, kind='block', start=o, end=e, stages=stages)
        if has: reg('blockpng:%s' % lab, pp, kind='blockpng', start=o, end=e, stages=stages, bin=os.path.relpath(pb, out),
                    layout=inf['layout'], palette=pal)
    for a in G.areas(d): pals[a['palette'] - ROM] = 256
    for c in range(SPR.N_CHARS): pals.setdefault(SPR.record(d, c)[1], 16)
    pd = os.path.join(out, 'palettes'); os.makedirs(pd, exist_ok=True)
    for po, n in sorted(pals.items()):
        lab = L.name_at(po) or 'pal_%06X' % po
        rgb = G.palette_rgb(d, po, n)
        p = os.path.join(pd, lab + '.pal')
        open(p, 'w').write('JASC-PAL\n0100\n%d\n' % n + ''.join('%d %d %d\n' % tuple(rgb[i * 3:i * 3 + 3]) for i in range(n)))
        reg('palette:%s' % lab, p, kind='palette', start=po, colours=n)
    M.extract(d, out, reg, decoded, {b[0] for b in blks})
    T.extract(d, out, reg)
    AR.extract(d, out, reg)
    DLG.extract(d, out, reg, AR.sprites(d))
    QST.extract(d, out, reg)
    SPR.extract(d, out, reg, AR.sprites(d))
    SND.extract(d, out, reg)
    MUS.extract(d, out, reg)
    MOV.extract(d, out, reg)
    json.dump(man, open(os.path.join(out, 'manifest.json'), 'w'), indent=1)
    print('extracted %d assets to %s' % (len(man['assets']), out))


def build(rom, src, out):
    d = open(rom, 'rb').read()
    man = json.load(open(os.path.join(src, 'manifest.json')))
    os.makedirs(out, exist_ok=True)
    ov = []; changed = []

    def put(start, end, data, tag):
        fn = os.path.join(out, 'ov_%06X_%s.bin' % (start, tag)); open(fn, 'wb').write(data)
        ov.append({'start': start, 'end': end, 'file': fn})

    done_blocks = set()
    news = []

    def put_s(start, end, text, size, tag):
        fn = os.path.join(out, 'ov_%06X_%s.s' % (start, tag)); open(fn, 'w').write(text)
        ov.append({'start': start, 'end': end, 'file': fn, 'size': size})

    def new(label, data):
        fn = os.path.join(out, 'new_%s.bin' % label); open(fn, 'wb').write(data)
        ov.append({'new': label, 'file': fn, 'size': len(data)}); return label
    def new_s(label, text, size):
        fn = os.path.join(out, 'new_%s.s' % label); open(fn, 'w').write(text)
        ov.append({'new': label, 'file': fn, 'size': size}); return label
    ctx = dict(put=put, put_s=put_s, new=new, new_s=new_s)
    for name, a in man['assets'].items():
        path = os.path.join(src, a['file'])
        if sha(path) == a['sha1'] and a['kind'] != 'movie': continue          # movie: its frame PNGs are checked by movies.py
        k = a['kind']
        if k != 'movie': changed.append(name)
        if k == 'text':
            lines = {}
            for l in open(path, encoding='utf-8'):
                if l.startswith('#') or '\t' not in l: continue
                lab, t = l.rstrip('\n').split('\t', 1); lines[lab] = unesc(t)
            for o, n, e in a['items']:
                new = lines.get(L.name_at(o))
                if new is None or new.encode('latin-1') == d[o:o + n]: continue
                b = new.encode('latin-1') + b'\0'
                if len(b) <= n + 1: put(o, o + n + 1, b + bytes(n + 1 - len(b)), 'str')
                else: put(o, e, b + d[o + n + 1:e], 'str')          # grows: the whole object moves
        elif k in ('block', 'blockpng'):
            if a['start'] in done_blocks: continue
            raw0, stages, e = bios.unpack(d, a['start'])
            if k == 'blockpng':
                if 'layout' in a: raw = G.from_index(G.load_png(path, a['palette']), raw0, a['layout'])
                else: raw = from_png(path, open(os.path.join(src, a['bin']), 'rb').read())
            else: raw = open(path, 'rb').read()
            if raw == raw0: continue
            done_blocks.add(a['start'])
            put(a['start'], a['end'], bios.pack(raw, a['stages']), 'blk')
        elif k == 'palette':
            lines = [l.split() for l in open(path) if l.strip()][3:3 + a['colours']]
            o = a['start']; data = bytearray()
            for i, (r, g, b) in enumerate(lines):
                old = struct.unpack_from('<H', d, o + 2 * i)[0]
                c = round(int(r) * 31 / 255) | round(int(g) * 31 / 255) << 5 | round(int(b) * 31 / 255) << 10 | (old & 0x8000)
                data += struct.pack('<H', c)
            if bytes(data) != d[o:o + len(data)]: put(o, o + len(data), bytes(data), 'pal')
        elif k == 'map':
            M.build(d, a, path, ctx)
        elif k == 'table':
            T.build(d, a, path, put)
        elif k == 'area':
            AR.build(d, a, path, ctx)
        elif k == 'dialogue':
            DLG.build(d, a, path, ctx, AR.sprites(d))
        elif k == 'quests':
            QST.build(d, a, path, ctx)
        elif k == 'sprite':
            SPR.build(d, a, path, ctx)
        elif k in ('sample', 'samples'):
            SND.build(d, a, path, ctx, src)
        elif k == 'music':
            MUS.build(d, a, path, ctx)
        elif k == 'movie':
            n0 = len(ov); MOV.build(d, a, path, ctx, src)
            if len(ov) > n0: changed.append(name)
    json.dump(ov, open(os.path.join(out, 'overrides.json'), 'w'), indent=1)
    print('changed assets: %s' % (', '.join(changed) or 'none'))
    print('%d overrides -> %s' % (len(ov), os.path.join(out, 'overrides.json')))


if __name__ == '__main__':
    os.chdir(os.path.join(HERE, '..', '..'))
    if len(sys.argv) < 2 or sys.argv[1] not in ('extract', 'build'):
        sys.exit(__doc__)
    if sys.argv[1] == 'extract': extract('baserom.gba', 'assets')
    else: build('baserom.gba', 'assets', 'build_modern/overrides')
