#!/usr/bin/env python3
"""Demo edits for a freshly extracted assets/ tree (`make extract`), then `make modern`:
  1. text:   the opening story text gets a longer first sentence (the string moves; its pointer follows)
  2. blocks: the top half of the title screen (gUnknown_084DEDE4) is drawn with inverted palette indexes, re-packed
             as Huffman + LZ77 like the original
  3. palette: Kame House's area palette (gUnknown_086AB884) gets red and blue swapped (the sea turns red)
  4. map:    area 0 (Kame House island) gets a 6x4 patch of sand tiles in the sea, bottom-left of the island, on the
             BG2 layer, and the patch is marked walkable
  5. tables: level 1 max HP 105 -> 999 (levels.csv); the snake gets 30 HP instead of 3 and the wolf 777 (enemies.csv)
  6. areas:  area 0 gets a wolf on the sand patch (an enemy where there were none) and a new warp zone right of the
             spot where the opening scene leaves Goku, leading to the forest by Goku's house (area 2)
  7. dialogue: in Krillin's first conversation (set 47) the first line is rewritten and a new line from Master Roshi
             is added after "Hmm, that's no fun..."
  8. story:  quest 1 is done as soon as its magazine is picked up (its "give it to Roshi" task is removed) and also gives
             1234 EXP (a new give_exp action)
  9. sprites: Goku's sprite sheet gets two colours swapped (orange gi <-> blue undershirt indexes 6 and 13)
  10. sound: sample 9 (used by the title music) is replaced by a longer 440 Hz tone (it moves to the end of the data)
  11. music: the title song (song 15) is transposed up 5 semitones
`demo_edits.py dialogue` / `story` / `sprites` / `sound` / `music` apply only 7 / 8 / 9 / 10 / 11;
`demo_edits.py music_same` only appends an unused copy of a pattern to song 15 (the song moves; it must sound the same) (the other edits change where Goku walks on the test routes)."""
import os
import numpy as np
from PIL import Image
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
import sys
ONLY = sys.argv[1] if len(sys.argv) > 1 else None      # `dialogue` / `story` / `sprites` / `sound` / `music` / `music_same`
if ONLY is None:
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
    for p, row, col, val in (('assets/tables/levels.csv', 0, 'max_hp', '999'), ('assets/tables/enemies.csv', 1, 'hp', '30'),
                             ('assets/tables/enemies.csv', 2, 'hp', '777')):
        rows = list(csv.DictReader(open(p, newline='')))
        rows[row][col] = val
        with open(p, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)
    import json
    p = 'assets/areas/area00.json'; a = json.load(open(p))
    a['actors'].append({'x': 48, 'y': 256, 'sprite': 'wolf', 'show': 0, 'flag': 0, 'kind': 2, 'param': 0, 'b10': 0, 'b11': 0})
    a['triggers'].append({'kind': 'warp', 'rect': [300, 200, 360, 280], 'mode': 1, 'b13': 0, 'to_area': 2, 'to_x': 632, 'to_y': 384})
    open(p, 'w').write(json.dumps(a, indent=1))
if ONLY in (None, 'dialogue'):
    p = 'assets/dialogue/set47.txt'; s = open(p, encoding='utf-8').read()
    n = sum(1 for l in s.split('\n') if l[:1].isdigit())
    s = s.replace('0: krillin1 > 1 | Hey Gohan, are you going to be a great martial artist like your dad?',
                  '0: krillin1 > 1 | MOD TEST: Hey Gohan, this line was edited and grew longer!')
    s = s.replace("3: krillin1 > 4 | Hmm, that's no fun...", "3: krillin1 > %d | Hmm, that's no fun..." % n)
    s = s.rstrip('\n') + '\n%d: roshi > 4 | MOD TEST: a brand new line from Master Roshi.\n' % n
    open(p, 'w', encoding='utf-8').write(s)
if ONLY in (None, 'story'):
    import json
    p = 'assets/story/quests.json'; q = json.load(open(p))
    q['quests'][1]['tasks'] = q['quests'][1]['tasks'][:1]
    q['quests'][1]['actions'].append({'type': 'give_exp', 'amount': 1234})
    open(p, 'w').write(json.dumps(q, indent=1))
if ONLY in (None, 'sprites'):
    p = 'assets/sprites/goku.png'
    im = Image.open(p); a = np.array(im); pal = im.getpalette()
    a = np.where(a == 6, 13, np.where(a == 13, 6, a)).astype(np.uint8)
    o = Image.fromarray(a, 'P'); o.putpalette(pal); o.save(p)
if ONLY in (None, 'sound'):
    import wave
    rate = 16000; t = np.arange(rate * 2)
    tone = (np.sin(2 * np.pi * 440 * t / rate) * 100 + 128).astype(np.uint8)
    with wave.open('assets/sound/sample09.wav', 'wb') as w:
        w.setnchannels(1); w.setsampwidth(1); w.setframerate(rate); w.writeframes(tone.tobytes())
if ONLY in (None, 'music', 'music_same'):
    import re
    p = 'assets/music/song15.txt'; s = open(p).read()
    if ONLY == 'music_same':
        n = len(re.findall(r'^pattern ', s, re.M))
        pat0 = s[s.index('pattern 0 '):].split('\npattern ')[0]
        s = s.rstrip('\n') + '\n\n' + pat0.replace('pattern 0 ', 'pattern %d ' % n, 1) + '\n'
    else:
        names = ['C-', 'C#', 'D-', 'D#', 'E-', 'F-', 'F#', 'G-', 'G#', 'A-', 'A#', 'B-']
        def up(m):
            v = names.index(m.group(1)) + 12 * int(m.group(2)) + 5
            return '%s%d' % (names[v % 12], v // 12)
        s = re.sub(r'(?<= )([A-G][-#])(\d)(?= )', up, s)
    open(p, 'w').write(s)
print('demo edits applied; now run: make modern')
