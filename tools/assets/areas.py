"""What is in each area: characters, enemies, pickups, objects and trigger zones (used by assets.py). Legacy of Goku.

assets/areas/areaNN.json, one per area record (see maps.py). The area record's +0x14 points to an info block, read by
the area loader sub_08001FA8:
  +0x00 u8 music track (0xFF = none), 7 more bytes ("header", kept as hex)
  +0x08 count, +0x0C -> actors   12 bytes each, created by sub_080058D6:
        u16 x, u16 y (pixels), u8 sprite (character sprite set, see SPRITES), u8 show (0 always, 1 unless the story
        flag is set, 2 only if it is set), u16 flag, u8 kind (2 = enemy; 0 and 1 = characters, param = what they say),
        u8 param, u8 b10, u8 b11
  +0x10 count, +0x14 -> pickups  8 bytes each: u16 x, u16 y, u32 id (sub_0800D1A0: what you find, e.g. a capsule)
  +0x18 count, +0x1C -> triggers pointer list to zone records {u32 callback, s16 x1, y1, x2, y2, u8 mode, u8 b13, ...}:
        warp     (sub_0800356C) u16 to_area, u16 x, u16 y: walking into the rectangle loads that area at x, y
        hp_zone  (sub_080042B4) u16 b14, s32 hp: changes HP by that much once a second while inside
        event    (sub_080061B0) u8 set, u8 entry (b13 = set): starts that conversation
        message  (sub_080061D0) shows a text (the text itself is in assets/text/strings.txt)
  +0x20 count, +0x24 -> objects  8 bytes each: u16 type (gUnknown_0815B948), u16 b2, u16 x, u16 y (sub_0800697E)
  +0x28 u16 x, u16 y: where the debug area select puts the player
Lists can grow or shrink (they are moved to the end of the data if they grow). Trigger zones can be edited and new
warps / hp zones / events added; a trigger's kind can't change.
"""
import os, json, struct, re
import gfxinfo as G
import labels as L

ROM = 0x08000000
CALLBACKS = {0x0800356D: 'warp', 0x080042B5: 'hp_zone', 0x080061B1: 'event', 0x080061D1: 'message'}
CB_SYM = {'warp': 'sub_0800356C + 1', 'hp_zone': 'sub_080042B4 + 1', 'event': 'sub_080061B0 + 1',
          'message': 'sub_080061D0 + 1'}
SPRITE_NAMES = 0x109F0          # 109 pointers to sprite set names ("armyguy1" ... "yamcha")


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def sprites(d):
    out = []
    for i in range(109):
        p = u32(d, SPRITE_NAMES + 4 * i) - ROM; out.append(d[p:d.index(b'\0', p)].decode())
    return out


def info_of(d, a):
    o = a['info'] - ROM
    w = struct.unpack_from('<10I', d, o + 8)
    return o, dict(actors=(w[0], w[1]), pickups=(w[2], w[3]), triggers=(w[4], w[5]), objects=(w[6], w[7]))


def read_area(d, a, names):
    o, lists = info_of(d, a)
    out = dict(area=a['index'], size_tiles=[a['w'], a['h']], music=d[o], header=d[o + 1:o + 8].hex(),
               start=list(struct.unpack_from('<2H', d, o + 0x28)))
    n, p = lists['actors']; acts = []
    for k in range(n):
        x, y, spr, show, flag, kind, param, b10, b11 = struct.unpack_from('<HHBBHBBBB', d, p - ROM + 12 * k)
        acts.append(dict(x=x, y=y, sprite=names[spr] if spr < len(names) else spr, show=show, flag=flag, kind=kind,
                         param=param, b10=b10, b11=b11))
    out['actors'] = acts
    n, p = lists['pickups']
    out['pickups'] = [dict(zip(('x', 'y', 'id'), struct.unpack_from('<HHI', d, p - ROM + 8 * k))) for k in range(n)]
    n, p = lists['objects']
    out['objects'] = [dict(zip(('type', 'b2', 'x', 'y'), struct.unpack_from('<4H', d, p - ROM + 8 * k))) for k in range(n)]
    n, p = lists['triggers']; trs = []
    for k in range(n):
        t = u32(d, p - ROM + 4 * k) - ROM
        kind = CALLBACKS.get(u32(d, t), 'raw')
        x1, y1, x2, y2, mode, b13 = struct.unpack_from('<4hBB', d, t + 4)
        e = dict(label=L.name_at(t), kind=kind, rect=[x1, y1, x2, y2], mode=mode, b13=b13)
        if kind == 'warp':
            e.update(zip(('to_area', 'to_x', 'to_y'), struct.unpack_from('<3H', d, t + 0xE)))
        elif kind == 'hp_zone':
            e['b14'], e['hp'] = struct.unpack_from('<Hi', d, t + 0xE)
        elif kind == 'event':
            e['entry'], e['b15'] = d[t + 0xE], d[t + 0xF]
        elif kind == 'message':
            e['b14'] = struct.unpack_from('<H', d, t + 0xE)[0]
            e['text'] = L.name_at(u32(d, t + 0x10) - ROM)
        trs.append(e)
    out['triggers'] = trs
    return out


SIZES = {'warp': 0x14, 'hp_zone': 0x14, 'event': 0x10, 'message': 0x14}


def trigger_body(e):
    """bytes after the callback word (message: up to the text pointer)"""
    b = struct.pack('<4hBB', *e['rect'], e['mode'], e['b13'])
    if e['kind'] == 'warp': b += struct.pack('<3H', e['to_area'], e['to_x'], e['to_y'])
    elif e['kind'] == 'hp_zone': b += struct.pack('<Hi', e['b14'], e['hp'])
    elif e['kind'] == 'event': b += bytes([e['entry'], e['b15']])
    elif e['kind'] == 'message': b += struct.pack('<H', e['b14'])
    return b


def extract(d, out, reg):
    ad = os.path.join(out, 'areas'); os.makedirs(ad, exist_ok=True)
    names = sprites(d)
    for a in G.areas(d):
        p = os.path.join(ad, 'area%02d.json' % a['index'])
        js = json.dumps(read_area(d, a, names), indent=1)
        # one list entry per line
        js = re.sub(r'\[\n\s+(-?\d+),\n\s+(-?\d+)(?:,\n\s+(-?\d+),\n\s+(-?\d+))?\n\s*\]',
                    lambda m: '[' + ', '.join(g for g in m.groups() if g is not None) + ']', js)
        js = re.sub(r'\{\n\s+([^{}]*?)\n\s*\}', lambda m: '{' + re.sub(r'\n\s*', ' ', m.group(1)) + '}', js)
        open(p, 'w').write(js + '\n')
        reg('area:%02d' % a['index'], p, kind='area', area=a['index'])
    open(os.path.join(ad, 'SPRITES.txt'), 'w').write(''.join('%d %s\n' % (i, n) for i, n in enumerate(names)))


def build(d, a_entry, path, ctx):
    names = sprites(d)
    a = G.areas(d)[a_entry['area']]
    new, old = json.load(open(path)), read_area(d, a, names)
    o, lists = info_of(d, a)
    put, put_s = ctx['put'], ctx['put_s']
    if new['music'] != old['music'] or new['header'] != old['header']:
        put(o, o + 8, bytes([new['music']]) + bytes.fromhex(new['header']), 'ainfo')
    if new['start'] != old['start']: put(o + 0x28, o + 0x2C, struct.pack('<2H', *new['start']), 'astart')

    def sprite_id(s):
        return names.index(s) if isinstance(s, str) else int(s)

    packers = {
        'actors': (12, lambda e: struct.pack('<HHBBHBBBB', e['x'], e['y'], sprite_id(e['sprite']), e['show'], e['flag'],
                                              e['kind'], e['param'], e['b10'], e['b11'])),
        'pickups': (8, lambda e: struct.pack('<HHI', e['x'], e['y'], e['id'])),
        'objects': (8, lambda e: struct.pack('<4H', e['type'], e['b2'], e['x'], e['y']))}
    slot = {'actors': 0x08, 'pickups': 0x10, 'triggers': 0x18, 'objects': 0x20}
    for key, (size, pack) in packers.items():
        if new[key] == old[key]: continue
        n, p = lists[key]
        data = b''.join(pack(e) for e in new[key])
        if p:
            end = L.object_end(p - ROM) or p - ROM + size * n
            put(p - ROM, end, data + bytes(max(0, end - (p - ROM) - len(data))) if len(data) <= end - (p - ROM) else data,
                'alist')
        elif data:
            lab = ctx['new']('gArea%02d_%s' % (a['index'], key.capitalize()), data)
            put_s(o + slot[key] + 4, o + slot[key] + 8, '\t.4byte %s\n' % lab, 4, 'aptr')
        if len(new[key]) != n: put(o + slot[key], o + slot[key] + 4, struct.pack('<I', len(new[key])), 'acount')
    # triggers
    if new['triggers'] != old['triggers']:
        n, p = lists['triggers']
        labels = []
        for k, e in enumerate(new['triggers']):
            if e.get('label'):
                t = next((t for t in old['triggers'] if t['label'] == e['label']), None)
                if t is None: raise SystemExit('%s: unknown trigger label %s' % (path, e['label']))
                if t['kind'] != e['kind']: raise SystemExit('%s: %s: a trigger kind cannot change' % (path, e['label']))
                if e != t:
                    addr = next(u32(d, p - ROM + 4 * j) - ROM for j in range(n) if old['triggers'][j]['label'] == e['label'])
                    body = trigger_body(e)
                    put(addr + 4, addr + 4 + len(body), body, 'trig')
                labels.append(e['label'])
            else:
                if e['kind'] not in ('warp', 'hp_zone', 'event'):
                    raise SystemExit('%s: new triggers can be warp, hp_zone or event' % path)
                lab = 'gArea%02d_Trigger%02d' % (a['index'], k)
                ctx['new_s'](lab, '\t.4byte %s\n%s' % (CB_SYM[e['kind']], ''.join(
                    '\t.byte %s\n' % ', '.join('0x%02X' % c for c in trigger_body(e)[i:i + 16])
                    for i in range(0, len(trigger_body(e)), 16))), 4 + len(trigger_body(e)))
                labels.append(lab)
        if labels != [t['label'] for t in old['triggers']]:
            text = ''.join('\t.4byte %s\n' % l for l in labels)
            if p and len(labels) <= n:
                put_s(p - ROM, p - ROM + 4 * n, text + '\t.space %d\n' % (4 * (n - len(labels))), 4 * n, 'tlist')
            else:
                lab = ctx['new_s']('gArea%02d_Triggers' % a['index'], text, 4 * len(labels))
                put_s(o + 0x1C, o + 0x20, '\t.4byte %s\n' % lab, 4, 'aptr')
            if len(labels) != n: put(o + 0x18, o + 0x1C, struct.pack('<I', len(labels)), 'acount')
