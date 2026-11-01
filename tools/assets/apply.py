#!/usr/bin/env python3
"""Apply asset overrides to the generated .rodata sources (used by `make modern`).

usage: apply.py overrides.json src_dir out_dir [--shift]

Default mode is "relocate" (layout-preserving), which is what the game tolerates best:
  * replacement <= original size  -> written in place, padded with zeros to the original size
  * replacement  > original size  -> the original bytes stay where they are (nothing moves), and the new
    data goes to rodata_appendix.s at the end of .rodata under the object's label. Every symbolic
    pointer to the object (gUnknown_..., sub_...) follows the label to the appendix.
  * small patches that don't start at a label (text refs, table fields) are written in place.
An override is {start, end, file}. `file` may be a binary (.bin) or an assembly snippet (.s, with an explicit `size`),
which can hold symbolic pointers (`.4byte gUnknown_...`). {new: LABEL, file, size} adds a new object to the appendix
under a new global label (used by the script compiler for added event steps).
--shift instead splices replacements in place and lets everything after them move (needs a fully
shiftable data area; see docs/shifting.md for the known non-pointer dependencies).
"""
import sys, os, re, json, glob

ROM = 0x08000000
INC = re.compile(r'^\t\.incbin "baserom\.gba", 0x([0-9A-F]+), 0x([0-9A-F]+)$')
LAB = re.compile(r'^([A-Za-z_]\w*):')


def main(ovf, src, out, shift=False):
    allov = json.load(open(ovf))
    news = [o for o in allov if o.get('new')]
    ovs = sorted([o for o in allov if not o.get('new')], key=lambda o: o['start'])
    os.makedirs(out, exist_ok=True)
    for o in allov:
        if 'size' not in o: o['size'] = os.path.getsize(o['file'])
    files = sorted(glob.glob(os.path.join(src, 'rodata_*.s')))
    files = [f for f in files if 'appendix' not in f]
    labels_at = {}
    for path in files:
        q = int(os.path.basename(path)[7:15], 16) - ROM
        for l in open(path).read().split('\n'):
            m = INC.match(l)
            if m: q = int(m.group(1), 16) + int(m.group(2), 16); continue
            if l.startswith('\t.4byte'): q += 4; continue
            m = LAB.match(l)
            if m: labels_at.setdefault(q, []).append(m.group(1))
    pins = []
    if os.path.exists('config/pinned.txt'):
        for l in open('config/pinned.txt'):
            if l.startswith('#') or not l.strip(): continue
            a, b = l.split()[:2]; pins.append((int(a, 16), int(b, 16)))
    appendix = []
    for o in ovs:
        pinned = any(a < o['end'] and o['start'] < b for a, b in pins)
        if pinned and o['size'] > o['end'] - o['start']:
            if '--skip-unrelocatable' in sys.argv:
                o['mode'] = 'skip'; continue
            sys.exit('override 0x%X grows but the code addresses it as symbol+offset (config/pinned.txt); '
                     'it must keep its size' % o['start'])
        n = o['end'] - o['start']
        if o.get('mode') == 'skip': continue
        o['mode'] = 'splice' if shift and not pinned else 'inplace'
        if o['mode'] == 'inplace' and o['size'] > n:
            if o['start'] not in labels_at:
                if '--skip-unrelocatable' in sys.argv:
                    o['mode'] = 'skip'; continue
                sys.exit('override 0x%X grows but has no label to relocate (%s)' % (o['start'], o['file']))
            o['mode'] = 'relocate'
            appendix.append(o)
    def body(o, note):
        if o['file'].endswith('.s'):
            return ['@ %s (%s)' % (note, o['file'])] + open(o['file']).read().rstrip('\n').split('\n')
        return ['\t.incbin "%s"   @ %s' % (o['file'], note)]

    moved = set()
    for o in appendix:
        for x in labels_at:
            if o['start'] <= x < o['end']: moved.update(labels_at[x])
    active = [o for o in ovs if o['mode'] not in ('relocate', 'skip')]
    used = 0
    for path in files:
        base = int(os.path.basename(path)[7:15], 16) - ROM
        res = []

        def emit_range(a, b):
            nonlocal used
            p = a
            while p < b:
                o = next((o for o in active if o['start'] <= p < o['end'] or p < o['start'] < b), None)
                if o is None:
                    res.append('\t.incbin "baserom.gba", 0x%X, 0x%X' % (p, b - p)); return
                if o['start'] > p:
                    res.append('\t.incbin "baserom.gba", 0x%X, 0x%X' % (p, o['start'] - p)); p = o['start']
                if p == o['start']:
                    n = o['end'] - o['start']
                    res.extend(body(o, 'override 0x%X-0x%X' % (o['start'], o['end']))); used += 1
                    if o['mode'] == 'inplace' and o['size'] < n:
                        res.append('\t.space %d' % (n - o['size']))
                p = min(b, o['end'])

        pos = base
        for l in open(path).read().split('\n'):
            m = INC.match(l)
            if m:
                a, n = int(m.group(1), 16), int(m.group(2), 16)
                emit_range(a, a + n); pos = a + n
                continue
            if l.startswith('\t.4byte'):
                o = next((o for o in active if o['start'] <= pos < o['end']), None)
                if o is None: res.append(l)
                elif o['start'] == pos: emit_range(pos, pos + 4)
                pos += 4
                continue
            m = LAB.match(l)
            if m and m.group(1) in moved:
                res.append('@ %s moved to rodata_appendix.s' % m.group(1)); continue
            if l.startswith('\t.global ') and l.split()[1] in moved: continue
            res.append(l)
        open(os.path.join(out, os.path.basename(path)), 'w').write('\n'.join(res))
    app = ['@ Relocated (grown) objects -- generated by tools/assets/apply.py', '\t.section .rodata', '\t.align 2', '']
    for o in appendix:
        inner = sorted((x, labels_at[x]) for x in labels_at if o['start'] <= x < o['end'])
        if o['file'].endswith('.s'):
            for x, names in inner:
                for nm in names: app += ['\t.global %s' % nm, '%s:' % nm]
            app += body(o, 'was 0x%X-0x%X' % (o['start'], o['end'])); app.append('\t.align 2, 0'); used += 1
            continue
        k0 = 0
        for x, names in inner:
            k = min(x - o['start'], o['size'])
            if k > k0: app.append('\t.incbin "%s", %d, %d' % (o['file'], k0, k - k0)); k0 = k
            for nm in names: app += ['\t.global %s' % nm, '%s:' % nm]
        app.append('\t.incbin "%s", %d   @ was 0x%X-0x%X' % (o['file'], k0, o['start'], o['end']))
        app.append('\t.align 2, 0'); used += 1
    for o in news:
        app += ['\t.global %s' % o['new'], '%s:' % o['new']] + body(o, 'new object') + ['\t.align 2, 0']; used += 1
    open(os.path.join(out, 'rodata_appendix.s'), 'w').write('\n'.join(app) + '\n')
    print('applied %d overrides (%d relocated to the appendix, %d in place)'
          % (used, len(appendix), len(ovs) - len(appendix)))


if __name__ == '__main__':
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    main(a[0], a[1], a[2], shift='--shift' in sys.argv)
