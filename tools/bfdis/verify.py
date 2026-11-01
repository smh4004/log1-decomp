#!/usr/bin/env python3
"""Compare the built ROM against baserom.gba and map differences to source instructions.

usage: verify.py [--write-raw]   (--write-raw appends mismatching instructions to config/raw_insns.txt)
"""
import sys, os, pickle, struct, collections
sys.path.insert(0, os.path.dirname(__file__))
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM
ROM = 0x08000000
from game import NAME
os.chdir(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
a = open('baserom.gba', 'rb').read(); b = open(NAME + '.gba', 'rb').read()
db = pickle.load(open('.analysis/analysis.pickle', 'rb'))
iw_off, iw_vma, iw_size = db['iwram']
def bus(o):
    if iw_off <= o < iw_off + iw_size: return iw_vma + o - iw_off
    return ROM + o
diff = [i for i in range(len(a)) if i >= len(b) or a[i] != b[i]]
print('differing bytes:', len(diff))
hits = collections.OrderedDict()
for o in diff:
    x = bus(o)
    for k in (0, 1, 2, 3):
        s = x - k
        if s in db['insn'] and db['insn'][s][1] > k:
            hits[s] = db['insn'][s]; break
    else:
        hits.setdefault(('data', x & ~3), None)
th = Cs(CS_ARCH_ARM, CS_MODE_THUMB); ar = Cs(CS_ARCH_ARM, CS_MODE_ARM)
raw = []
for k, v in hits.items():
    if isinstance(k, tuple):
        print('  data  %08X' % k[1]); continue
    m, s = v
    o = k - iw_vma + iw_off if k < ROM else k - ROM
    i = next((th if m == 't' else ar).disasm(a[o:o + s], k), None)
    j = next((th if m == 't' else ar).disasm(b[o:o + s], k), None)
    print('  %s %08X  want %-28s got %s' % (m, k, (i.mnemonic + ' ' + i.op_str) if i else a[o:o+s].hex(),
                                            (j.mnemonic + ' ' + j.op_str) if j else b[o:o+s].hex()))
    raw.append(k)
if '--write-raw' in sys.argv and raw:
    with open('config/raw_insns.txt', 'a') as f:
        for k in raw: f.write('%08X\n' % k)
    print('appended', len(raw), 'to config/raw_insns.txt')
