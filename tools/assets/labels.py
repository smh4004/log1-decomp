"""Label index of the generated .rodata sources (data/rodata_*.s): ROM offset <-> label name.

Objects in .rodata are delimited by labels: an object starts at a label and ends at the next one. Asset builders use
this to know how many bytes an object may occupy in place, and which name to use for symbolic pointers.
"""
import os, re, glob, bisect

ROM = 0x08000000
INC = re.compile(r'^\t\.incbin "baserom\.gba", 0x([0-9A-F]+), 0x([0-9A-F]+)$')
LAB = re.compile(r'^([A-Za-z_]\w*):')
_cache = {}


def index(datadir='data'):
    if datadir in _cache: return _cache[datadir]
    at = {}
    for path in sorted(glob.glob(os.path.join(datadir, 'rodata_*.s'))):
        if 'appendix' in path: continue
        q = int(os.path.basename(path)[7:15], 16) - ROM
        for l in open(path):
            l = l.rstrip('\n')
            m = INC.match(l)
            if m: q = int(m.group(1), 16) + int(m.group(2), 16); continue
            if l.startswith('\t.4byte'): q += 4; continue
            m = LAB.match(l)
            if m: at.setdefault(q, m.group(1))
    keys = sorted(at)
    _cache[datadir] = (at, keys)
    return at, keys


def name_at(off, datadir='data'):
    """Label at ROM offset `off`, or None."""
    return index(datadir)[0].get(off)


def symbol(off, datadir='data'):
    """Assembly expression for the bus address ROM+off: `label` or `label + k`."""
    at, keys = index(datadir)
    if off in at: return at[off]
    i = bisect.bisect_right(keys, off) - 1
    return '%s + 0x%X' % (at[keys[i]], off - keys[i])


def object_end(off, datadir='data'):
    """Offset of the next label after `off` (end of the object starting at `off`)."""
    at, keys = index(datadir)
    i = bisect.bisect_right(keys, off)
    return keys[i] if i < len(keys) else None
