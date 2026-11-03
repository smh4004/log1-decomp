"""The story: quests, their tasks and what happens when they are done (used by assets.py). Legacy of Goku.

gQuestTable (0x085439E0): 75 pointers to quest records {u32 name (or 0), u32 task count, u32 -> task list,
u32 action count, u32 -> action list}. Tasks and actions are small C++ objects {vtable, fields...}; the vtable is the
type. Each frame of story logic (sub_080054AE): a quest whose tasks are all done is marked done (bit in the quest flags
at 0x03000038), its actions run in order, and "quest done" is announced to the tasks of other quests.

Tasks (common fields: id = task bit at 0x03000028, area = where it is active; a task is done once):
  talk_with_item   talk to `sprite` while carrying pickup `item`: the item is used up, conversation set/entry plays
  talk_with_kind   the same with any pickup of kind `kind`
  defeat           defeat an enemy with sprite set `sprite`
  activate         a quest object with sprite set `sprite` is used (picked up / switched)
  after_quest      quest `quest` is done
  after_conversation  conversation set `set` reaches entry `entry`
  spawn_item         pickup `item` lies at x, y in `area` until picked up
  enter_zone         walking into the rectangle (a trigger zone record: callback sub_08006244) does it
  spawn_character    character `sprite` stands at x, y in `area` with conversation `set`/`entry` (b8: ?)
  follower           character `sprite` at x, y (used by the rescue quests; b7-b9 not decoded)
  spot, spot_ae0     a rectangle in `area` (b6/b7 not decoded)
Actions:
  conversation (set, entry)   play conversation `set` from `entry`
  set_entry (set, entry)      next time, conversation `set` starts at `entry`
  give_exp (amount)           "You receive N experience points!"
  give_pickup (item)          one more of pickup `item` (capsules, beans ...), with its message
  speed_up (amount)           "Your speed increases!"
  music (track)               play music track
  warp (area, x, y)           go to area at x, y
  learn (bit)                 sets a bit in the ability flags (0x0300004D)
  scene (index)               cutscene `index` (table 0x0815A778)
  actor_leave (area, sprite)  that character leaves (if the player is in `area`)
  change_actor (area, sprite, param)  give a character in `area` another conversation set
  set_walkable (x1, y1, x2, y2, area) mark a rectangle of `area` walkable
  end_game                    game state change (credits)
  add_warp (area, item, rectangle, to_area, to_x, to_y)  an object `item` plus a warp zone in `area`
  add_zone (area, rectangle)  a trigger zone with another callback (`callback` is a code address: don't change it)
Actor `flag`s in areas/*.json are numbers into gActorFlagQuests (0x08543988): flag N shows/hides by quest
quest_of_flag[N]. Fields named bN are not decoded (N = byte offset); `callback` fields are code addresses and must stay. Edit fields in place; lists of tasks and actions can be reordered, shortened or extended (new
objects of any listed type; give `type` and its fields, `raw` may be left out).
"""
import os, json, struct, re
import labels as L

ROM = 0x08000000
QUESTS, N_QUESTS = 0x5439E0, 75
FLAGS, N_FLAGS = 0x543988, 88
# vtable -> (name, total size, field spec after the vtable [(name, struct fmt)])
TYPES = {
    0x08166AC0: ('conversation', 8, [('set', 'B'), ('entry', 'B')]),
    0x08166AC8: ('give_pickup', 8, [('item', 'B')]),
    0x08166AF0: ('scene', 8, [('index', 'B')]),
    0x08166AF8: ('speed_up', 8, [('amount', 'B')]),
    0x08166B00: ('music', 8, [('track', 'B')]),
    0x08166B08: ('warp', 12, [('area', 'I'), ('x', 'H'), ('y', 'H')]),
    0x08166B20: ('end_game', 4, []),
    0x08166B28: ('learn', 8, [('bit', 'B')]),
    0x08166B30: ('actor_leave', 8, [('area', 'B'), ('sprite', 'B')]),
    0x08166B38: ('set_entry', 8, [('set', 'B'), ('entry', 'B')]),
    0x08166B50: ('change_actor', 8, [('area', 'B'), ('sprite', 'B'), ('param', 'B')]),
    0x08166B58: ('set_walkable', 16, [('x1', 'h'), ('y1', 'h'), ('x2', 'h'), ('y2', 'h'), ('area', 'B')]),
    0x08166B90: ('give_exp', 8, [('amount', 'i')]),
    0x08166BB8: ('add_warp', 28, [('area', 'B'), ('item', 'B'), ('b6', 'H'), ('callback', 'I'), ('x1', 'h'), ('y1', 'h'),
                                  ('x2', 'h'), ('y2', 'h'), ('mode', 'B'), ('b13', 'B'), ('to_area', 'H'), ('to_x', 'H'),
                                  ('to_y', 'H')]),
    0x08166BE0: ('add_zone', 24, [('area', 'B'), ('b5', 'B'), ('b6', 'H'), ('callback', 'I'), ('x1', 'h'), ('y1', 'h'),
                                  ('x2', 'h'), ('y2', 'h'), ('mode', 'B'), ('b13', 'B')]),
    # tasks
    0x08166AD0: ('spawn_item', 12, [('id', 'B'), ('area', 'B'), ('item', 'B'), ('b7', 'B'), ('x', 'H'), ('y', 'H'), ('b14', 'H')]),
    0x08166AE0: ('spot_ae0', 16, [('id', 'B'), ('area', 'B'), ('b6', 'H'), ('x1', 'h'), ('y1', 'h'), ('x2', 'h'), ('y2', 'h')]),
    0x08166B10: ('talk_with_item', 12, [('id', 'B'), ('area', 'B'), ('item', 'B'), ('sprite', 'B'), ('set', 'B'),
                                        ('entry', 'B')]),
    0x08166B40: ('spot', 16, [('id', 'B'), ('area', 'B'), ('b6', 'B'), ('b7', 'B'), ('x1', 'h'), ('y1', 'h'), ('x2', 'h'),
                              ('y2', 'h')]),
    0x08166B60: ('spawn_character', 16, [('id', 'B'), ('area', 'B'), ('sprite', 'B'), ('set', 'B'), ('b8', 'B'),
                                         ('entry', 'B'), ('x', 'H'), ('y', 'H')]),
    0x08166B70: ('talk_with_kind', 12, [('id', 'B'), ('area', 'B'), ('kind', 'B'), ('sprite', 'B'), ('set', 'B'),
                                        ('entry', 'B')]),
    0x08166B80: ('enter_zone', 24, [('id', 'B'), ('area', 'B'), ('b6', 'H'), ('callback', 'I'), ('x1', 'h'), ('y1', 'h'),
                                    ('x2', 'h'), ('y2', 'h'), ('mode', 'B'), ('b13', 'B')]),
    0x08166B98: ('defeat', 8, [('id', 'B'), ('area', 'B'), ('sprite', 'B')]),
    0x08166BA8: ('activate', 8, [('id', 'B'), ('area', 'B'), ('sprite', 'B')]),
    0x08166BC0: ('after_quest', 8, [('id', 'B'), ('area', 'B'), ('quest', 'B')]),
    0x08166BD0: ('after_conversation', 8, [('id', 'B'), ('area', 'B'), ('set', 'B'), ('entry', 'B')]),
    0x08166BE8: ('follower', 16, [('id', 'B'), ('area', 'B'), ('sprite', 'B'), ('b7', 'B'), ('b8', 'B'), ('b9', 'B'),
                                  ('x', 'H'), ('y', 'H'), ('b14', 'H')]),
}
BYNAME = {v[0]: k for k, v in TYPES.items()}


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def fmt(spec): return '<' + ''.join(f for n, f in spec)


def read_obj(d, o):
    vt = u32(d, o)
    name, size, spec = TYPES[vt]
    vals = struct.unpack_from(fmt(spec), d, o + 4)
    e = dict(type=name)
    e.update(zip((n for n, f in spec), vals))
    n = struct.calcsize(fmt(spec))
    if size - 4 - n: e['raw'] = d[o + 4 + n:o + size].hex()
    return e


def obj_bytes(e, old_raw=None):
    vt = BYNAME[e['type']]; name, size, spec = TYPES[vt]
    b = struct.pack(fmt(spec), *[e.get(n, 0) for n, f in spec])
    rest = size - 4 - len(b)
    raw = bytes.fromhex(e['raw']) if 'raw' in e else bytes(rest)
    if len(raw) != rest: raise SystemExit('%s: raw must be %d bytes' % (e['type'], rest))
    return vt, b + raw


def read_quests(d):
    out = []
    for i in range(N_QUESTS):
        q = u32(d, QUESTS + 4 * i) - ROM
        name, nt, tl, na, al = struct.unpack_from('<5I', d, q)
        nm = d[name - ROM:d.index(b'\0', name - ROM)].decode('latin-1') if name else None
        out.append(dict(quest=i, name=nm,
                        tasks=[dict(read_obj(d, u32(d, tl - ROM + 4 * k) - ROM), label=L.name_at(u32(d, tl - ROM + 4 * k) - ROM))
                               for k in range(nt)],
                        actions=[dict(read_obj(d, u32(d, al - ROM + 4 * k) - ROM), label=L.name_at(u32(d, al - ROM + 4 * k) - ROM))
                                 for k in range(na)]))
    return out


def obj_addrs(d):
    out = {}
    for i in range(N_QUESTS):
        q = u32(d, QUESTS + 4 * i) - ROM
        name, nt, tl, na, al = struct.unpack_from('<5I', d, q)
        for lst, n in ((tl, nt), (al, na)):
            for k in range(n):
                o = u32(d, lst - ROM + 4 * k) - ROM; out[L.name_at(o)] = o
    return out


def compact(js):
    return re.sub(r'\{\n\s+([^{}\[\]]*?)\n\s*\}', lambda m: '{' + re.sub(r'\n\s*', ' ', m.group(1)) + '}', js)


def extract(d, out, reg):
    sd = os.path.join(out, 'story'); os.makedirs(sd, exist_ok=True)
    p = os.path.join(sd, 'quests.json')
    doc = dict(quests=read_quests(d), quest_of_flag=list(d[FLAGS:FLAGS + N_FLAGS]))
    open(p, 'w').write(compact(json.dumps(doc, indent=1)) + '\n')
    reg('quests', p, kind='quests')


def build(d, a, path, ctx):
    new = json.load(open(path)); old = dict(quests=read_quests(d), quest_of_flag=list(d[FLAGS:FLAGS + N_FLAGS]))
    if new['quest_of_flag'] != old['quest_of_flag']:
        if len(new['quest_of_flag']) != N_FLAGS: raise SystemExit('quest_of_flag must keep %d entries' % N_FLAGS)
        ctx['put'](FLAGS, FLAGS + N_FLAGS, bytes(new['quest_of_flag']), 'qflags')
    if len(new['quests']) != N_QUESTS: raise SystemExit('%s: keep the %d quests' % (path, N_QUESTS))
    by_label, addrs = {}, obj_addrs(d)
    for q in old['quests']:
        for e in q['tasks'] + q['actions']: by_label[e['label']] = e
    for qi, (nq, oq) in enumerate(zip(new['quests'], old['quests'])):
        q = u32(d, QUESTS + 4 * qi) - ROM
        for key, slot in (('tasks', 4), ('actions', 12)):
            labels = []
            for k, e in enumerate(nq[key]):
                if e.get('label') in by_label:
                    o = by_label[e['label']]
                    if o['type'] != e['type']: raise SystemExit('%s: %s: the type cannot change' % (path, e['label']))
                    if {x: y for x, y in e.items() if x != 'label'} != {x: y for x, y in o.items() if x != 'label'}:
                        addr = addrs[e['label']]
                        vt, b = obj_bytes(e)
                        ob = d[addr + 4:addr + 4 + len(b)]
                        for s0, s1 in runs(b, ob):
                            ctx['put'](addr + 4 + s0, addr + 4 + s1, b[s0:s1], 'quest')
                    labels.append(e['label'])
                else:
                    if e['type'] not in BYNAME: raise SystemExit('%s: unknown type %s' % (path, e['type']))
                    vt, b = obj_bytes(e)
                    lab = ctx['new_s']('gQuest%02d_%s%02d' % (qi, key[:-1].capitalize(), k),
                                       '\t.4byte %s\n%s' % (L.name_at(vt - ROM) or '0x%08X' % vt,
                                                            ''.join('\t.byte %s\n' % ', '.join('0x%02X' % c for c in b[i:i + 16])
                                                                    for i in range(0, len(b), 16))), 4 + len(b))
                    labels.append(lab)
            if labels != [e['label'] for e in oq[key]]:
                n_old = len(oq[key]); lp = u32(d, q + slot + 4) - ROM if n_old else 0
                text = ''.join('\t.4byte %s\n' % l for l in labels)
                if lp and len(labels) <= n_old:
                    ctx['put_s'](lp, lp + 4 * n_old, text + ('\t.space %d\n' % (4 * (n_old - len(labels))) if n_old > len(labels) else ''),
                                 4 * n_old, 'qlist')
                else:
                    lab = ctx['new_s']('gQuest%02d_%s' % (qi, key.capitalize()), text, 4 * len(labels))
                    ctx['put_s'](q + slot + 4, q + slot + 8, '\t.4byte %s\n' % lab, 4, 'qptr')
                if len(labels) != n_old: ctx['put'](q + slot, q + slot + 4, struct.pack('<I', len(labels)), 'qcount')


def runs(a, b):
    out = []; i = 0
    while i < len(a):
        if a[i] != b[i]:
            j = i
            while j < len(a) and a[j] != b[j]: j += 1
            out.append((i, j)); i = j
        else: i += 1
    return out
