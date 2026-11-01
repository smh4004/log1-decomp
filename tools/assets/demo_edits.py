#!/usr/bin/env python3
"""Demo edits for a freshly extracted assets/ tree (`make extract`), then `make modern`:
  1. text:   the opening story text gets a longer first sentence (the string moves; its pointer follows)
  2. blocks: the top half of the title logo tiles (gUnknown_084DEDE4) is drawn with inverted palette indexes, re-packed
             as Huffman + LZ77 like the original"""
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
print('demo edits applied; now run: make modern')
