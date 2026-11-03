#!/usr/bin/env python3
"""Demo edits for a freshly extracted assets/ tree (`make extract`), then `make modern`:
  1. text:   the opening story text gets a longer first sentence (the string moves; its pointer follows)
  2. blocks: the top half of the title screen (gUnknown_084DEDE4) is drawn with inverted palette indexes, re-packed
             as Huffman + LZ77 like the original
  3. palette: Kame House's area palette (gUnknown_086AB884) gets red and blue swapped (the sea turns red)
  4. map:    area 0 (Kame House island) gets a 6x4 patch of sand tiles in the sea, bottom-left of the island, on the
             BG2 layer, and the patch is marked walkable
  5. tables: level 1 max HP 105 -> 999 (levels.csv); the snake gets 30 HP instead of 3 (enemies.csv)"""
import os
import numpy as np
from PIL import Image
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
p = 'assets/text/strings.txt'; s = open(p, encoding='utf-8').read()
old = 'gUnknown_085C2E1A\tOur story begins with our humble hero, Goku.'
assert old in s, 'story text not found (already edited?)'
open(p, 'w', encoding='utf-8').write(s.replace(old, 'gUnknown_085C2E1A\tLegacy of Goku 1 mod: this story text was edited and grew longer. Our story begins with our humble hero, Goku.'))
p = 'assets/gfx/blocks/gUnknown_084DEDE4.png'
im = Image.open(p); a = np.array(im); pal = im.getpalette()
a[:a.shape[0] // 2, :] = 15 - a[:a.shape[0] // 2, :]
o = Image.fromarray(a, 'P'); o.putpalette(pal); o.save(p)
p = 'assets/palettes/gUnknown_086AB884.pal'
lines = open(p).read().split('\n')
lines[3:3 + 256] = [' '.join(reversed(l.split())) for l in lines[3:3 + 256]]
open(p, 'w').write('\n'.join(lines))
import xml.etree.ElementTree as ET
p = 'assets/maps/area00.tmx'; t = ET.parse(p)
for layer in t.getroot().findall('layer'):
    if layer.get('name') not in ('bg2', 'walkable'): continue
    data = layer.find('data'); rows = [r.rstrip(',').split(',') for r in data.text.strip().split('\n')]
    sand = '202' if layer.get('name') == 'bg2' else '1026'      # gid 202 = tile slot 201, sand; 1026 = flag set
    for y in range(31, 35):
        for x in range(3, 9): rows[y][x] = sand
    data.text = '\n' + ',\n'.join(','.join(r) for r in rows) + '\n'
t.write(p, encoding='UTF-8', xml_declaration=True)
import csv
for p, key, col, val in (('assets/tables/levels.csv', 'level', 'max_hp', '999'), ('assets/tables/enemies.csv', 'name', 'hp', '30')):
    rows = list(csv.DictReader(open(p, newline='')))
    rows[0 if key == 'level' else 1][col] = val
    with open(p, 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)
print('demo edits applied; now run: make modern')
