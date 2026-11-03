"""Game tables as CSV (used by assets.py). Legacy of Goku. Edits are written back in place (sizes are fixed).

assets/tables/enemies.csv   gEnemyTable (0x086B6094, 34 x 0x40 bytes), read by the enemy constructor sub_08006D90:
    +0x00 index      +0x04 name (sprite set name; shown here, not editable)    +0x08 kind (copied to object +0x02)
    +0x0C exp        EXP awarded (copied where the player keeps its EXP)
    +0x10..+0x30     17 signed 16-bit values copied to the object (AI and movement settings; s10 = +0x10 ...).
                     s18 > 1 makes the enemy lead a group.
    +0x34 power      copied to object +0x54/+0x58 (the player keeps its "power" from the level table there)
    +0x38 hp         hit points (object +0x4C current / +0x50 max; at least 1)
    +0x3C defense    object +0x60: each hit is reduced by defense, defense/2 or defense/4 at random (sub_08007352)
assets/tables/levels.csv    gLevelTable (0x080114A8, 25 x 16 bytes): the player's level is the last row whose exp
                            the player has reached. exp, max_hp, power (+8), ki (+12: a counter that is spent one at a
                            time and refilled up to this value).
"""
import os, csv, struct

ROM = 0x08000000
ENEMIES, N_ENEMIES, ENEMY_SIZE = 0x6B6094, 34, 0x40
LEVELS, N_LEVELS = 0x114A8, 25
SHORTS = ['s%02X' % o for o in range(0x10, 0x32, 2)]
ENEMY_COLS = ['index', 'name', 'kind', 'exp'] + SHORTS + ['power', 'hp', 'defense']
LEVEL_COLS = ['level', 'exp', 'max_hp', 'power', 'ki']


def cstr(d, p):
    o = p - ROM; return d[o:d.index(b'\0', o)].decode('latin-1')


def enemy_row(d, i):
    o = ENEMIES + ENEMY_SIZE * i
    idx, name, kind, exp = struct.unpack_from('<IIiI', d, o)
    sh = struct.unpack_from('<17h', d, o + 0x10)
    power, hp, defense = struct.unpack_from('<3i', d, o + 0x34)
    return [idx, cstr(d, name), kind, exp] + list(sh) + [power, hp, defense]


def extract(d, out, reg):
    td = os.path.join(out, 'tables'); os.makedirs(td, exist_ok=True)
    p = os.path.join(td, 'enemies.csv')
    with open(p, 'w', newline='') as f:
        w = csv.writer(f); w.writerow(ENEMY_COLS)
        for i in range(N_ENEMIES): w.writerow(enemy_row(d, i))
    reg('table:enemies', p, kind='table', table='enemies')
    p = os.path.join(td, 'levels.csv')
    with open(p, 'w', newline='') as f:
        w = csv.writer(f); w.writerow(LEVEL_COLS)
        for i in range(N_LEVELS):
            w.writerow([i + 1] + list(struct.unpack_from('<4i', d, LEVELS + 16 * i)))
    reg('table:levels', p, kind='table', table='levels')


def build(d, a, path, put):
    rows = list(csv.DictReader(open(path, newline='')))
    if a['table'] == 'enemies':
        if len(rows) != N_ENEMIES: raise SystemExit('%s: must keep %d rows' % (path, N_ENEMIES))
        for i, r in enumerate(rows):
            o = ENEMIES + ENEMY_SIZE * i
            new = struct.pack('<i', int(r['kind'])) + struct.pack('<I', int(r['exp'])) + \
                struct.pack('<17h', *[int(r[c]) for c in SHORTS]) + \
                struct.pack('<3i', int(r['power']), int(r['hp']), int(r['defense']))
            new = new[:8 + 34] + d[o + 0x32:o + 0x34] + new[8 + 34:]      # 2 padding bytes after the shorts
            if new != d[o + 8:o + 0x40]: put(o + 8, o + 0x40, new, 'enemy')
    else:
        if len(rows) != N_LEVELS: raise SystemExit('%s: must keep %d rows' % (path, N_LEVELS))
        for i, r in enumerate(rows):
            o = LEVELS + 16 * i
            new = struct.pack('<4i', *[int(r[c]) for c in LEVEL_COLS[1:]])
            if new != d[o:o + 16]: put(o, o + 16, new, 'level')
