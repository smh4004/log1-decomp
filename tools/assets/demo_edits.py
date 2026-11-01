#!/usr/bin/env python3
"""Demo edits for every asset kind, applied to a freshly extracted assets/ tree (`make extract`), then `make modern`.
  1. events:   the opening narration (gUnknown_083B8340): step 1 gets new text (longer, so the step moves), step 2
               (compressed text) is rewritten, and a brand-new step is inserted after it
  2. ui:       area name "Outside Pepper Town" -> a longer name (the string moves; the pointer follows)
  3. palette:  BG colour 1 -> red
  4. map:      Outside Pepper Town (w01_a01) layer 2: a strip of tiles copied over the cliff top
  5. sprite:   every frame of the first sprite animation gets a red band
  6. tables:   area 0 (Outside Pepper Town) plays music track 7 instead of 23"""
import os, glob, csv, io
import numpy as np
from PIL import Image
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))


def edit(path, old, new, enc='utf-8'):
    s = open(path, encoding=enc).read()
    assert old in s, '%s: %r not found (already edited?)' % (path, old[:40])
    open(path, 'w', encoding=enc).write(s.replace(old, new, 1))


ev = 'assets/scripts/gUnknown_083B8340.evt'
edit(ev, 'step 1 say 0x00 "@^Sixteen years from the present day..."',
     'step 1 say 0x00 "@^Legacy of Goku 4: this line was rewritten with the script compiler!"')
s = open(ev, encoding='utf-8').read()
i = s.index('step 2 zsay 0x00 "'); j = s.index('   ; gUnknown_083B81D8', i)
s = s[:i] + 'step 2 zsay 0x00 "@^Compressed text is recompressed on build.\\x0bA second page."' + s[j:]
s = s.replace('step 3 code', 'step auto say 0x00 "@^This line is a new step added to the event list."\nstep 3 code', 1)
open(ev, 'w', encoding='utf-8').write(s)

edit('assets/text/ui_strings.txt', '227\tOutside Pepper Town\n', '227\tOutside Pepper Town (Legacy of Goku 4 edit)\n')

p = 'assets/palette/master.txt'; L = open(p).read().split('\n')
L[1 + 1] = '255   0   0  # 1  (edited)'; open(p, 'w').write('\n'.join(L))

p = 'assets/maps/w01_a01_Outside_Pepper_Town/L2.csv'
g = np.array([[int(x, 16) for x in r.split(',')] for r in open(p).read().split()])
g[30:32, 14:40] = g[44, 20]
open(p, 'w').write(''.join(','.join('%03X' % v for v in r) + '\n' for r in g))

first = sorted(glob.glob('assets/gfx/sprites/*'))[0]
for f in glob.glob(first + '/*.png'):
    im = Image.open(f); a = np.array(im); pal = im.getpalette()
    a[2:5, :] = np.where(a[2:5, :] != 0, 35, 0).astype(np.uint8)
    o = Image.fromarray(a, 'P'); o.putpalette(pal); o.save(f, transparency=0)

p = 'assets/tables/areas.csv'; lines = open(p, encoding='utf-8').read().split('\n')
hdr = lines[1].split(','); rows = list(csv.reader(lines[2:]))
rows[0][hdr.index('music')] = '7'
buf = io.StringIO(); csv.writer(buf, lineterminator='\n').writerows([r for r in rows if r])
open(p, 'w', encoding='utf-8').write(lines[0] + '\n' + lines[1] + '\n' + buf.getvalue())
print('demo edits applied; now run: make modern')
