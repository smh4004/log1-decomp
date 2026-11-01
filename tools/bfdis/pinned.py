#!/usr/bin/env python3
"""Find data objects that code addresses as `symbol + constant` reaching outside the symbol's object.

Pattern (Thumb):  ldr rN, =label ; ... ; adds/subs rN, #k   or   ldr/ldm via rN after adding k
If label+k lands outside [label, next_label) the objects around `label` form a fixed-layout group:
they must keep their size and their relative position (no resizing, no relocation).
Writes config/pinned.txt:  start end  label  (ROM offsets, end exclusive).
"""
import os, sys, pickle, struct, bisect, re
ROM = 0x08000000
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from game import TEXT_END, IWRAM


def scan(d, db, labels_sorted):
    insn = db['insn']
    pins = {}
    addrs = sorted(a for a, (m, s) in insn.items() if m == 't' and a >= ROM)
    idx = {a: i for i, a in enumerate(addrs)}
    for a in addrs:
        h = struct.unpack_from('<H', d, a - ROM)[0]
        if (h >> 11) != 0x09: continue                      # ldr rN, [pc, #imm]
        rn = (h >> 8) & 7
        la = ((a + 4) & ~3) + (h & 0xFF) * 4
        w = struct.unpack_from('<I', d, la - ROM)[0] if la >= ROM else 0
        if not (ROM + TEXT_END <= w < ROM + IWRAM[0]): continue
        lo = hi = cur = 0
        i = idx[a]
        for j in range(i + 1, min(i + 8, len(addrs))):
            b = addrs[j]
            if insn[b][1] != 2: break
            g = struct.unpack_from('<H', d, b - ROM)[0]
            top5 = g >> 11
            if top5 == 0x06 and (g >> 8) & 7 == rn:            # adds rN, #k
                cur += g & 0xFF; lo, hi = min(lo, cur), max(hi, cur)
            elif top5 == 0x07 and (g >> 8) & 7 == rn:          # subs rN, #k
                cur -= g & 0xFF; lo, hi = min(lo, cur), max(hi, cur)
            elif top5 in (0x0D, 0x0F, 0x11) and (g >> 3) & 7 == rn:   # ldr/ldrb/ldrh rD, [rN, #imm]
                sc = {0x0D: 4, 0x0F: 1, 0x11: 2}[top5]
                off = cur + ((g >> 6) & 0x1F) * sc
                lo, hi = min(lo, off), max(hi, off + sc)
                if (g & 7) == rn: break
            elif (g & 0xF800) == 0xC800 and (g >> 8) & 7 == rn:   # ldmia rN!, {..}
                hi = max(hi, cur + 4 * bin(g & 0xFF).count('1')); break
            elif top5 >= 0x1C or (g >> 12) == 0xD or (g & 0xFF00) == 0xBD00: break
            elif g < 0x4000 and (g & 7) == rn: break           # rN overwritten
            elif top5 in (0x04, 0x09) and (g >> 8) & 7 == rn: break
        if lo == 0 and hi == 0: continue
        t = w - ROM
        i2 = bisect.bisect_right(labels_sorted, t)
        nxt = labels_sorted[i2] if i2 < len(labels_sorted) else t + 4
        if lo < 0 or t + hi > nxt:
            s, e = t + min(lo, 0), max(t + hi, nxt)
            pins[(s, e)] = 'gUnknown_%08X' % w
    return pins


if __name__ == '__main__':
    root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    os.chdir(root)
    d = open('baserom.gba', 'rb').read()
    db = pickle.load(open('.analysis/analysis.pickle', 'rb'))
    labs = set()
    for p in os.listdir('data'):
        if p.startswith('rodata_'):
            for m in re.finditer(r'^gUnknown_([0-9A-F]{8}):', open('data/' + p).read(), re.M):
                labs.add(int(m.group(1), 16) - ROM)
    pins = scan(d, db, sorted(labs))
    with open('config/pinned.txt', 'w') as f:
        f.write('# Fixed-layout data (code reaches it as symbol +/- constant). start end label -- ROM offsets\n')
        for (s, e), n in sorted(pins.items()): f.write('%06X %06X %s\n' % (s, e, n))
    print(len(pins), 'pinned ranges')
