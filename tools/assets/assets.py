#!/usr/bin/env python3
"""Editable assets for the Legacy of Goku II disassembly.

  assets.py extract     baserom.gba -> assets/ (editable files + assets/manifest.json)
  assets.py build       assets/ -> build_modern/overrides.json + replacement blobs (only edited assets)

Asset kinds (all pulled from the user's baserom.gba; nothing copyrighted is committed):
  palette   assets/palette/master.txt        512 lines "R G B" (24-bit master palette at 0x083ECBA4, in place)
  exp       assets/tables/exp.csv            EXP needed per level, 50 x u32 at 0x081D9834 (in place)
  ui        assets/text/ui_strings.txt       260 ASCII strings from the UI string table (0x080E2840); any length
  events    assets/scripts/<label>.evt       every event list (cutscenes, NPC talks, signs, triggers): steps with
                                             dialogue text and script bytecode as text (tools/scripts/events.py,
                                             l2script.py). Steps can be edited, added and removed.
  maps      assets/maps/<map>/...            all maps: whole-layer CSVs, tile lists, collision masks (mapassets.py)
  tiles     assets/gfx/tiles/page_NNN.png    the global BG tile pages as indexed PNGs (gfx.py)
  sprites   assets/gfx/sprites/<anim>/*.png  sprite frames (256-colour; sprites.py)
  tables    assets/tables/*.csv              game tables (tables.py)
  (`extract --previews` also renders every map layer to PNG; slow)
Overrides are applied to the generated data/*.s by tools/assets/apply.py (make modern).
"""
import sys, os, json, struct, hashlib, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', 'wfz'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, '..', 'scripts'))
from wfz import unpack
from wfz_compress import compress
import maps as mapsmod
import mapassets
import sprites
import tables
import events as evmod
import l2script as script

from const import ROM, PALETTE, UI_PTRS, RODATA, UI_ENCODING, EXP



def sha(path): return hashlib.sha1(open(path, 'rb').read()).hexdigest()
def u32(d, o): return struct.unpack_from('<I', d, o)[0]


# ------------------------------------------------------------------ text escaping
def esc(s):
    out = []
    for ch in s:
        c = ord(ch)
        if ch == '{': out.append('{{')
        elif c < 0x20 or c in (0x7F,): out.append('{%02X}' % c)
        else: out.append(ch)
    return ''.join(out)


def unesc(s):
    return re.sub(r'\{\{|\{([0-9A-Fa-f]{2})\}', lambda m: '{' if m.group(0) == '{{' else chr(int(m.group(1), 16)), s)


def wfz_blocks():
    path = '.analysis/wfz_blocks.json'
    if not os.path.exists(path):
        import subprocess
        os.makedirs('.analysis', exist_ok=True)
        subprocess.check_call([sys.executable, os.path.join(HERE, '..', 'wfz', 'scan_wfz.py'), 'baserom.gba', path, '%X' % RODATA[0], '%X' % RODATA[1]])
    return json.load(open(path))


def wfz_ranges(d):
    blocks = wfz_blocks()
    return {o: e for o, s, e, t in blocks}


# ------------------------------------------------------------------ extract
def extract(rom, out):
    d = open(rom, 'rb').read()
    man = {'assets': {}}
    os.makedirs(out, exist_ok=True)

    def reg(name, path, **kw):
        kw['file'] = os.path.relpath(path, out); kw['sha1'] = sha(path)
        man['assets'][name] = kw

    # palette
    p = os.path.join(out, 'palette', 'master.txt'); os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, 'w') as f:
        f.write('# Master palette (24-bit RGB). Lines 0-255 BG, 256-511 OBJ. Edit values 0-255.\n')
        for i in range(512):
            r, g, b = d[PALETTE + 3 * i:PALETTE + 3 * i + 3]
            f.write('%3d %3d %3d  # %d\n' % (r, g, b, i))
    reg('palette', p, kind='palette', start=PALETTE, length=512 * 3)

    # EXP table
    p = os.path.join(out, 'tables', 'exp.csv'); os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, 'w') as f:
        f.write('level,exp\n')
        for i in range(EXP[1]): f.write('%d,%d\n' % (i + 1, u32(d, EXP[0] + 4 * i)))
    reg('exp', p, kind='exp', start=EXP[0], length=EXP[1] * 4)

    # UI strings (ASCII, 0-terminated)
    p = os.path.join(out, 'text', 'ui_strings.txt'); os.makedirs(os.path.dirname(p), exist_ok=True)
    ptrs = [u32(d, UI_PTRS[0] + 4 * i) - ROM for i in range(UI_PTRS[1])]
    spans = []
    with open(p, 'w', encoding='utf-8') as f:
        f.write('# UI strings: "index<TAB>text". Any length; strings shared by several indexes are listed once.\n')
        f.write('# {XX} = control character, {{ = literal brace.\n')
        seen = set()
        for i, o in enumerate(ptrs):
            e = d.index(b'\0', o)
            if o in seen: continue
            seen.add(o); spans.append((i, o, e + 1))
            f.write('%d\t%s\n' % (i, esc(d[o:e].decode(UI_ENCODING))))
    reg('ui', p, kind='ui', spans=spans)

    # event lists (dialogue + scripts)
    lists = evmod.find_lists(d)
    owner = {}
    for o, it, term in lists:
        for t in it: owner.setdefault(t, o)
    names = script.load_names()
    sd = os.path.join(out, 'scripts'); os.makedirs(sd, exist_ok=True)
    for o, it, term in lists:
        lab = evmod.L.name_at(o)
        p = os.path.join(sd, '%s.evt' % lab)
        open(p, 'w', encoding='utf-8').write(evmod.export_list(d, o, it, term, None, names, owner))
        reg('events:%s' % lab, p, kind='events', start=o, items=it, term=term)
    # speaker ids are not named in the ROM: list a few lines per speaker so they can be identified
    spk = {}
    for o, it, term in lists:
        for t in it:
            if d[t + 2] in (1, 2):
                spk.setdefault(d[t + 3], []).append(evmod.parse_step(d, t)['text'])
    with open(os.path.join(sd, 'SPEAKERS.txt'), 'w', encoding='utf-8') as f:
        f.write('# Speaker ids used by `step N say SPEAKER ...` (the id picks the portrait), with sample lines.\n')
        for k in sorted(spk):
            f.write('0x%02X  (%d lines)\n' % (k, len(spk[k])))
            for l in spk[k][:3]: f.write('      %s\n' % re.sub(r'[\x00-\x1f]', ' ', l)[:90])

    # tile pages, all maps (layers, tile lists, collision masks)
    wfzidx = {o: (o, sz, e, t) for o, sz, e, t in wfz_blocks()}
    mapassets.extract(d, out, reg, wfzidx, previews='--previews' in sys.argv)
    sprites.extract(d, out, reg, wfzidx)

    # game tables
    td = os.path.join(out, 'tables'); os.makedirs(td, exist_ok=True)
    for tn in tables.SPECS:
        p = os.path.join(td, '%s.csv' % tn); tables.export(d, tn, p)
        reg('table:%s' % tn, p, kind='table', table=tn)

    json.dump(man, open(os.path.join(out, 'manifest.json'), 'w'), indent=1)
    print('extracted %d assets to %s' % (len(man['assets']), out))


# ------------------------------------------------------------------ build
def build(rom, src, out):
    d = open(rom, 'rb').read()
    man = json.load(open(os.path.join(src, 'manifest.json')))
    wfz = wfz_ranges(d)
    os.makedirs(out, exist_ok=True)
    ov = []          # {start, end, file}
    changed = []

    def put(start, end, data, tag):
        fn = os.path.join(out, 'ov_%06X_%s.bin' % (start, tag))
        open(fn, 'wb').write(data)
        ov.append({'start': start, 'end': end, 'file': fn})

    names = script.load_names()
    mctx = mapassets.Ctx(d, {o: (o, sz, e, t) for o, sz, e, t in wfz_blocks()}, out, ov)
    for name, a in man['assets'].items():
        path = os.path.join(src, a['file'])
        if sha(path) == a['sha1']: continue
        changed.append(name)
        k = a['kind']
        if k == 'palette':
            vals = [l.split('#')[0].split() for l in open(path) if l.split('#')[0].strip()]
            data = bytes(int(x) & 0xFF for v in vals[:512] for x in v[:3])
            assert len(data) == 1536, 'palette needs 512 lines'
            put(a['start'], a['start'] + a['length'], data, 'palette')
        elif k == 'exp':
            rows = [l.strip().split(',') for l in open(path)][1:]
            data = b''.join(struct.pack('<I', int(r[1])) for r in rows if len(r) > 1)
            assert len(data) == a['length'], 'exp.csv must keep %d rows' % (a['length'] // 4)
            put(a['start'], a['start'] + a['length'], data, 'exp')
        elif k in ('tilepage', 'layer', 'tilelist', 'mask'):
            mapassets.build(d, a, path, mctx)
        elif k == 'sprite':
            sprites.build(d, a, path, mctx)
        elif k == 'table':
            tables.build(d, a['table'], path, mctx)
        elif k == 'ui':
            lines = {}
            for l in open(path, encoding='utf-8'):
                if l.startswith('#') or '\t' not in l: continue
                i, t = l.rstrip('\n').split('\t', 1); lines[int(i)] = unesc(t)
            for i, o, e in a['spans']:
                new = lines[i].encode(UI_ENCODING) + b'\0'
                if new != d[o:e]: put(o, e, new, 'ui%d' % i)
        elif k == 'events':
            ov += evmod.compile_list(d, a['start'], a['items'], a['term'], open(path, encoding='utf-8').read(),
                                     names, None, out, 'ev')
    json.dump(ov, open(os.path.join(out, 'overrides.json'), 'w'), indent=1)
    print('changed assets: %s' % (', '.join(changed) or 'none'))
    print('%d overrides -> %s' % (len(ov), os.path.join(out, 'overrides.json')))


if __name__ == '__main__':
    os.chdir(os.path.join(HERE, '..', '..'))
    if len(sys.argv) < 2 or sys.argv[1] not in ('extract', 'build'):
        sys.exit(__doc__)
    if sys.argv[1] == 'extract': extract('baserom.gba', 'assets')
    else: build('baserom.gba', 'assets', 'build_modern/overrides')
