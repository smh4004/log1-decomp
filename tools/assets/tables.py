"""Fixed-size game tables <-> CSV (used by assets.py).

Each table is a run of fixed-size records. Columns are typed (u8/s8/u16/s16/u32/s32/ptr). A `ptr` column holds a label
from data/rodata_*.s (or `label + 0xK`, or a hex address/number), so a pointer can be aimed at any other object,
including objects added by other tools. Columns starting with `_` are read-only hints (UI text for a string index) and
are ignored on build. A changed record is written back in place: records keep their size and the row count is fixed.

Field meanings marked (inferred) come from comparing records with what the game shows; rename columns freely in
SPECS, since only the types and order matter to the build.
"""
import os, re, csv, struct
import labels as L
from const import ROM, RODATA, AREAS, ui_string

# name, offset, count, record size, [(column, offset, type, ui?)]
SPECS = {
    'areas': (AREAS[0], AREAS[1], AREAS[2], [
        ('world', 0, 'u8'), ('area', 1, 'u8'), ('b2', 2, 'u8'), ('b3', 3, 'u8'), ('b4', 4, 'u8'), ('b5', 5, 'u8'),
        ('b6', 6, 'u8'), ('b7', 7, 'u8'), ('w08', 8, 'u32'), ('name', 0xC, 'ptr', 'ui'),
        ('p10', 0x10, 'ptr'), ('p14', 0x14, 'ptr'), ('p18', 0x18, 'ptr'), ('p1C', 0x1C, 'ptr'), ('p20', 0x20, 'ptr'),
        ('music', 0x24, 'ptr'), ('w28', 0x28, 'ptr'), ('scene', 0x2C, 'ptr'), ('p30', 0x30, 'ptr'), ('p34', 0x34, 'ptr')]),
    'items': (0x6ADE24, 50, 56, [
        ('b0', 0, 'u8'), ('b1', 1, 'u8'), ('b2', 2, 'u8'), ('max_count', 3, 'u8'), ('name', 4, 'u16', 'ui'), ('desc', 6, 'u16', 'ui'),
        ('icon_w', 8, 'u32'), ('icon_h', 0xC, 'u32'), ('icon_oam', 0x10, 'u32'), ('icon', 0x14, 'ptr'),
        ('icon2_w', 0x18, 'u32'), ('icon2_h', 0x1C, 'u32'), ('icon2_oam', 0x20, 'u32'), ('icon2', 0x24, 'ptr'),
        ('p28', 0x28, 'ptr'), ('p2C', 0x2C, 'ptr'), ('on_use', 0x30, 'ptr'), ('handler', 0x34, 'ptr')]),
    'enemies': (0x6D56AC, 109, 24, [
        ('exp', 0, 'u32'), ('hp', 4, 'u32'), ('character', 8, 'u32'), ('str', 0xC, 'u8'), ('pow', 0xD, 'u8'),
        ('end', 0xE, 'u8'), ('phys_taken', 0xF, 'u8'), ('ki_taken', 0x10, 'u8'), ('b11', 0x11, 'u8'),
        ('b12', 0x12, 'u8'), ('b13', 0x13, 'u8'), ('behaviour', 0x14, 'ptr')]),
    'spawns': ('list', 'find_spawns', 28, [
        ('id', 4, 'u32'), ('enemy', 8, 'u32'), ('x', 0xC, 'u16'), ('y', 0xE, 'u16'), ('w10', 0x10, 'u32'),
        ('path', 0x14, 'ptr'), ('path_points', 0x18, 'u32')]),
}
FMT = {'u8': '<B', 's8': '<b', 'u16': '<H', 's16': '<h', 'u32': '<I', 's32': '<i', 'ptr': '<I'}
NOTES = {
    'areas': 'Area table (0x08409368): one row per area. name = UI string index (area name). scene -> record whose first '
             'word is the map (map record + 4). name/music/w28 hold a number, or -> bytecode that computes it (inferred). '
             'p10-p20, p30, p34: event lists and actor lists of the area (inferred).',
    'items': 'Item table (0x086ADE24): name/desc = UI string indexes. max_count = how many can be carried (inferred). '
             'icon/icon2: sprite pixel blocks with their size and OAM attributes. on_use = code run when the item is used '
             '(0x0800F45B STR cap, 0x0800F4C3 POW cap, 0x0800F52B END cap, 0x0800F593 heal, 0x0800F639 energy; inferred).',
    'enemies': 'Enemy types (0x086D56AC, 24 bytes, indexed by spawns.enemy; the spawn function sub_0800E77E reads it). '
               'exp = EXP for a kill (above 5 it is scaled to the player level by the game), hp = hit points (also the '
               'health bar maximum). str/pow/end = melee attack / energy attack / defence (inferred from the values: '
               'melee-only enemies have pow 1). phys_taken/ki_taken = damage taken, 128 = 100% (inferred, as in Buu\'s Fury). '
               'character = sprite/animation set (table 0x086D5194). behaviour -> AI handler table.',
    'spawns': 'Every enemy placed in an area: records whose first word is the spawn function 0x0800E77F (666 records). '
              'enemy = row of enemies.csv, x/y = position in map pixels, path -> path_points patrol points (inferred). '
              'The record is followed by its path point pointers, so records keep their size.',
}


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def ptr_text(v):
    if v == 0: return '0'
    o = v - ROM
    if RODATA[0] <= o < RODATA[1]: return L.symbol(o)
    return str(v) if v < 0x10000 else '0x%08X' % v


def ptr_expr(s):
    """CSV text -> assembly expression for .4byte."""
    s = s.strip()
    return s if s and not re.match(r'^-?(0x[0-9A-Fa-f]+|\d+)$', s) else str(int(s, 0) & 0xFFFFFFFF)


SPAWN_FN = 0x0800E77F            # sub_0800E77E + 1, first word of every enemy spawn record


def find_spawns(d):
    return [o for o in range(RODATA[0], RODATA[1], 4) if u32(d, o) == SPAWN_FN]


def rows_of(d, name):
    off, n, size, cols = SPECS[name]
    if off == 'list': return globals()[n](d), size, cols
    return [off + size * i for i in range(n)], size, cols


def hints(d, name):
    """read-only hint columns: name -> function(row index, record offset) -> text"""
    if name == 'spawns':
        areas = spawn_areas(d)
        return {'_address': lambda i, r: L.symbol(r), '_area': lambda i, r: areas.get(r, '')}
    if name == 'enemies':
        cnt = {}
        for r in find_spawns(d): cnt[u32(d, r + 8)] = cnt.get(u32(d, r + 8), 0) + 1
        return {'_placed': lambda i, r: cnt.get(i, 0)}
    return {}


def spawn_areas(d):
    """spawn record -> 'world-area name' (area +0x14 -> list of actor list pointers, area +4 = count)."""
    out = {}
    off, n, size, _ = SPECS['areas']
    sp = set(find_spawns(d))
    for i in range(n):
        r = off + size * i
        lst, cnt = u32(d, r + 0x14), d[r + 4]
        if not RODATA[0] <= lst - ROM < RODATA[1]: continue
        nm = '%02X-%02X %s' % (d[r], d[r + 1], ui_string(d, u32(d, r + 0xC)) if u32(d, r + 0xC) < 0x10000 else '')
        for k in range(cnt):
            a = u32(d, lst - ROM + 4 * k) - ROM
            if a in sp: out.setdefault(a, nm)
    return out


def export(d, name, path):
    recs, size, cols = rows_of(d, name)
    hx = hints(d, name)
    with open(path, 'w', newline='', encoding='utf-8') as f:
        f.write('# %s\n' % NOTES.get(name, ''))
        w = csv.writer(f)
        hdr = ['index'] + list(hx)
        for c in cols:
            hdr.append(c[0])
            if len(c) > 3 and c[3] == 'ui': hdr.append('_' + c[0] + '_text')
        w.writerow(hdr)
        for i, r in enumerate(recs):
            row = [i] + [f(i, r) for f in hx.values()]
            for c in cols:
                v = struct.unpack_from(FMT[c[2]], d, r + c[1])[0]
                row.append(ptr_text(v) if c[2] == 'ptr' else v)
                if len(c) > 3 and c[3] == 'ui': row.append(ui_string(d, v) if v < 0x10000 else '(script)')
            w.writerow(row)


def build(d, name, path, ctx):
    recs, size, cols = rows_of(d, name)
    rows = [r for r in csv.reader(l for l in open(path, encoding='utf-8') if not l.startswith('#'))]
    hdr, rows = rows[0], [r for r in rows[1:] if r]
    if len(rows) != len(recs): raise ValueError('%s: must keep %d rows' % (path, len(recs)))
    ix = {h: i for i, h in enumerate(hdr)}
    for i, row in enumerate(rows):
        r = recs[i]
        orig = d[r:r + size]
        # assemble the record: bytes for numbers, symbolic .4byte for pointers
        parts = []; pos = 0; data = bytearray(orig); syms = {}
        for c in cols:
            v = row[ix[c[0]]]
            if c[2] == 'ptr':
                if ptr_text(u32(orig, c[1])) == v.strip(): continue
                syms[c[1]] = ptr_expr(v)
            else:
                struct.pack_into(FMT[c[2]], data, c[1], int(v, 0))
        if not syms and bytes(data) == orig: continue
        lines = []; p = 0
        for o in sorted(syms):
            if o > p: lines.append('\t.byte %s' % ', '.join(str(b) for b in data[p:o]))
            lines.append('\t.4byte %s' % syms[o]); p = o + 4
        if p < size: lines.append('\t.byte %s' % ', '.join(str(b) for b in data[p:size]))
        ctx.asm(r, r + size, '\n'.join(lines) + '\n', size, '%s%d' % (name, i))


