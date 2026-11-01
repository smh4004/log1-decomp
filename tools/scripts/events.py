#!/usr/bin/env python3
"""Event lists ("cutscenes", NPC talks, triggers) <-> editable .evt text files (Legacy of Goku II).

An event list is an array of u32 pointers to steps, 0-terminated. A step is [u16 id][u8 type][...]; ids are usually
1, 2, 3... (the id is what dialogue choices and jumps refer to), so the text keeps them. Step handlers: table at
0x083EC84C (6 types):
  type 0  code         bytecode (l2script) until `end`
  type 1  say          [u8 speaker] + ASCII text up to a 0 byte
  type 2  zsay         [u8 speaker] + WFZ bitstream of the text (word aligned)
  type 3  sayf         [u8 speaker][u32 -> format text] + bytecode that computes the %d/%s arguments
  type 4  zsayf        [u8 speaker][u32 -> bytecode for the arguments] + WFZ bitstream of the format text
  type 5  goto         [u8 pad][u32 -> another event list]
Text control codes are kept as written (`@`, `^`, `#`, `!` prefixes select portrait/box styles; \x0b = new page).
Lists are found by scanning .rodata for 0-terminated pointer arrays whose targets carry ids 1, 2, 3... and decode cleanly.

.evt syntax:
  step ID code              ; followed by indented bytecode lines (see l2script.py)
  step ID say SPEAKER "text"
  step ID zsay SPEAKER "text"           (stored compressed)
  step ID sayf SPEAKER LABEL            then indented bytecode (LABEL = the format text object, kept as is)
  step ID zsayf SPEAKER LABEL "format"  (LABEL = the argument bytecode object, kept as is)
  step ID goto LABEL
  step ID raw TYPE hexbytes             (bytes after the 3-byte header)
  step ref LABEL                        reuse an existing step object unchanged
Steps can be added, removed and reordered. In lists numbered 1, 2, 3... (almost all) the build renumbers steps by
position, because the game finds the next step by id; there the written id only says which original step a line is,
and new steps can use `auto`. Lists with other ids (dialogue trees) keep the ids exactly as written.
"""
import os, sys, struct, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [HERE, os.path.join(HERE, '..', 'wfz'), os.path.join(HERE, '..', 'assets')]
import l2script as B
import wfz
from wfz_compress import compress_stream
import labels as L

from const import ROM, RODATA
ZBUF = 0x800                   # compressed text is decompressed into a 2 KB buffer


def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def u16(d, o): return struct.unpack_from('<H', d, o)[0]
def isptr(v): return ROM + RODATA[0] <= v < ROM + RODATA[1]


def zdecode(d, p):
    """WFZ bitstream at p (text streams start with a literal-mode switch) -> (bytes, end)."""
    out, end = wfz.decompress_stream(d, p, 0, lit_bits=8)
    return out, end


def cstr(b):
    return b[:b.index(0)].decode('latin-1') if 0 in b else b.decode('latin-1')


def parse_step(d, t, banks=None):
    """-> dict(type, ...) or raises. `end` = first byte after the step's own data."""
    ty = d[t + 2]
    if ty == 0:
        ins, e = B.decode(d, t + 3); return {'type': 0, 'code': (t + 3, e), 'end': e}
    if ty == 1:
        e = d.index(b'\0', t + 4)
        return {'type': 1, 'speaker': d[t + 3], 'text': d[t + 4:e].decode('latin-1'), 'end': e + 1}
    if ty == 2:
        if t % 4: raise B.BadCode('unaligned zsay')
        out, e = zdecode(d, t + 4)
        if len(out) > ZBUF or 0 not in out: raise B.BadCode('bad zsay')
        return {'type': 2, 'speaker': d[t + 3], 'text': cstr(out), 'end': e}
    if ty == 3:
        f = u32(d, t + 4)
        if not isptr(f): raise B.BadCode('bad sayf')
        ins, e = B.decode(d, t + 8)
        return {'type': 3, 'speaker': d[t + 3], 'fmt': f - ROM, 'code': (t + 8, e), 'end': e}
    if ty == 4:
        c = u32(d, t + 4)
        if not isptr(c) or t % 4: raise B.BadCode('bad zsayf')
        out, e = zdecode(d, t + 8)
        if len(out) > ZBUF or 0 not in out: raise B.BadCode('bad zsayf')
        B.decode(d, c - ROM)
        return {'type': 4, 'speaker': d[t + 3], 'argcode': c - ROM, 'text': cstr(out), 'end': e}
    if ty == 5:
        g = u32(d, t + 4)
        if not isptr(g): raise B.BadCode('bad goto')
        return {'type': 5, 'pad': d[t + 3], 'target': g - ROM, 'end': t + 8}
    raise B.BadCode('unknown step type %d' % ty)


def read_list(d, o):
    items = []; p = o
    while isptr(u32(d, p)): items.append(u32(d, p) - ROM); p += 4
    return items, u32(d, p) == 0


def valid_list(d, o, items, banks):
    if not items or L.name_at(o) is None: return False
    try:
        for t in items:
            if L.name_at(t) is None: return False
            parse_step(d, t, banks)
    except (B.BadCode, IndexError, ValueError, UnicodeDecodeError):
        return False
    return True


GLOBAL_TABLE = None           # Buu's Fury has a global event table (run_event); not identified in LoG2 yet


def find_lists(d, banks=None):
    """-> [(offset, items, terminated)] sorted by offset."""
    found = {}
    # 1. the global script table
    p = GLOBAL_TABLE
    while p is not None and isptr(u32(d, p)):
        o = u32(d, p) - ROM; p += 4
        if o in found: continue
        items, term = read_list(d, o)
        if valid_list(d, o, items, banks): found[o] = (items, term)
    # 2. scan for 0-terminated pointer arrays whose targets look like steps with ids 1, 2, 3...
    o = RODATA[0]
    while o < RODATA[1] - 4:
        if not isptr(u32(d, o)) or isptr(u32(d, o - 4)) or o in found:
            o += 4; continue
        items, term = read_list(d, o)
        if term and all(u16(d, t) == i + 1 for i, t in enumerate(items)) and valid_list(d, o, items, banks):
            found[o] = (items, term); o += 4 * (len(items) + 1)
        else:
            o += 4
    return sorted((o, it, term) for o, (it, term) in found.items())


def preview(banks, ref, n=48):
    b, off, ln = ref
    if not banks: return ''
    s = banks[b][off:off + ln].replace('\n', ' ')
    s = re.sub(r'[\x00-\x1f]', '', s)
    return s[:n] + ('...' if len(s) > n else '')


def indent(text): return text.rstrip('\n')


_gi = None
_refs = None


def global_index(d):
    global _gi
    if _gi is None:
        _gi = {}; p = GLOBAL_TABLE; i = 0
        while p is not None and isptr(u32(d, p)):
            _gi.setdefault(u32(d, p) - ROM, i); p += 4; i += 1
    return _gi


def referrers(d):
    """rodata offset -> labels of the objects holding a pointer to it (outside the global table)."""
    global _refs
    if _refs is None:
        _refs = {}
        at, keys = L.index()
        import bisect
        for p in range(RODATA[0], RODATA[1] - 3, 4):
            v = u32(d, p)
            if isptr(v) and not (GLOBAL_TABLE is not None and GLOBAL_TABLE <= p < GLOBAL_TABLE + 4 * 600):
                i = bisect.bisect_right(keys, p) - 1
                if i >= 0:
                    nm = at[keys[i]]
                    lst = _refs.setdefault(v - ROM, [])
                    if nm not in lst: lst.append(nm)
    return _refs


def qstr(t):
    r"""Quote text for .evt files: \\, \", \n and \xNN for other control characters (\x0b = new text box page)."""
    out = []
    for c in t:
        if c == '\\': out.append('\\\\')
        elif c == '"': out.append('\\"')
        elif c == '\n': out.append('\\n')
        elif ord(c) < 32 or 127 <= ord(c) < 160: out.append('\\x%02x' % ord(c))
        else: out.append(c)
    return '"%s"' % ''.join(out)


def export_list(d, o, items, term, banks, names, owner):
    """`owner`: step offset -> list offset that writes it in full (shared steps become `step ref`)."""
    lab = L.name_at(o)
    out = ['# Event list %s (0x%08X), %d steps%s.' % (lab, ROM + o, len(items),
           '' if term else ', FIXED LENGTH (no 0 terminator: steps can be edited, not added or removed)'),
           '# Syntax: see the top of tools/scripts/events.py. Native names: config/script_natives.txt.']
    gi = global_index(d).get(o)
    if gi is not None: out.append('# Global script %d: other scripts start it with run_event(%d, a, b).' % (gi, gi))
    refs = referrers(d).get(o)
    if refs: out.append('# Pointed to from: %s' % ', '.join(refs[:8]) + (' ...' if len(refs) > 8 else ''))
    out.append('')
    for t in items:
        s = parse_step(d, t, banks); tl = L.name_at(t); sid = u16(d, t)
        if owner.get(t, o) != o:
            out.append('step ref %s' % tl); continue
        ty = s['type']
        if ty == 0:
            out.append('step %d code        ; %s' % (sid, tl)); out.append(indent(B.disasm(d[:s['code'][1]], s['code'][0], names)[0]))
        elif ty in (1, 2):
            out.append('step %d %s 0x%02X %s   ; %s' % (sid, 'say' if ty == 1 else 'zsay', s['speaker'], qstr(s['text']), tl))
        elif ty == 3:
            f = s['fmt']; fe = d.index(b'\0', f)
            out.append('step %d sayf 0x%02X %s   ; %s format: %s' % (sid, s['speaker'], L.symbol(f), tl, qstr(d[f:fe].decode('latin-1'))))
            out.append(indent(B.disasm(d[:s['code'][1]], s['code'][0], names)[0]))
        elif ty == 4:
            out.append('step %d zsayf 0x%02X %s %s   ; %s' % (sid, s['speaker'], L.symbol(s['argcode']), qstr(s['text']), tl))
        elif ty == 5:
            out.append('step %d goto %s   ; %s' % (sid, L.symbol(s['target']), tl))
        else:
            e = L.object_end(t)
            out.append('step %d raw %d %s   ; %s' % (sid, ty, d[t + 3:e].hex(' '), tl))
    return '\n'.join(out).rstrip('\n') + '\n'


# ------------------------------------------------------------------ compile
def parse_evt(text):
    """-> list of steps: dict(id, kind, rest, body lines, line)."""
    steps = []; cur = None
    for ln, l in enumerate(text.split('\n'), 1):
        if l.startswith('#') or not l.strip():
            if cur is not None and cur.get('body') is not None: cur['body'].append('')
            continue
        if l.startswith('step '):
            m = re.match(r'^step\s+ref\s+(\w+)', l)
            if m:
                cur = {'id': None, 'kind': 'ref', 'rest': m.group(1), 'line': ln, 'body': None}; steps.append(cur); continue
            m = re.match(r'^step\s+(\d+|auto)\s+(\w+)\s*(.*)$', l)
            if not m: raise ValueError('line %d: expected `step ID KIND ...`' % ln)
            kind, rest = m.group(2), m.group(3)
            if '"' not in rest: rest = rest.split(';')[0]
            cur = {'id': m.group(1), 'kind': kind, 'rest': rest.strip(), 'line': ln,
                   'body': [] if kind in ('code', 'sayf') else None}
            steps.append(cur); continue
        if cur is None or cur['body'] is None: raise ValueError('line %d: code outside a code step' % ln)
        cur['body'].append(l)
    ids = [int(x['id']) for x in steps if x['id'] not in (None, 'auto')]
    nxt = max(ids, default=0) + 1
    for x in steps:
        if x['id'] == 'auto': x['id'] = nxt; nxt += 1
        elif x['id'] is not None: x['id'] = int(x['id'])
    return steps


def unquote(s):
    m = re.match(r'^"((?:[^"\\]|\\.)*)"', s.strip())
    if not m: raise ValueError('expected a "quoted string": %r' % s)
    return re.sub(r'\\(x[0-9a-fA-F]{2}|.)', lambda k: chr(int(k.group(1)[1:], 16)) if len(k.group(1)) == 3 else
                  {'n': '\n', 'r': '\r'}.get(k.group(1), k.group(1)), m.group(1))


def parse_text_arg(rest):
    """`0x02 @3:100:20` or `0x02 "Hello"` -> (speaker, ref tuple or str)."""
    m = re.match(r'^(\S+)\s+@(\d+):(\d+):(\d+)', rest)
    if m: return int(m.group(1), 0), tuple(int(x) for x in m.group(2, 3, 4))
    m = re.match(r'^(\S+)\s+(".*)$', rest)
    if m: return int(m.group(1), 0), unquote(m.group(2))
    raise ValueError('expected SPEAKER @bank:off:len or SPEAKER "text": %r' % rest)


def _pad(rest):
    m = re.match(r'^pad=(\d+)\s*(.*)$', rest)
    return (int(m.group(1)), m.group(2)) if m else (0, rest)


def _spk_text(rest):
    m = re.match(r'^(\S+)\s+(".*)$', rest)
    if not m: raise ValueError('expected SPEAKER "text": %r' % rest)
    return int(m.group(1), 0), unquote(m.group(2))


def step_bytes(step, names, new_text=None):
    """Encode one step. Pointers (sayf/zsayf/goto) are returned as assembly; see compile_list."""
    k = step['kind']; sid = step['id']
    types = {'code': 0, 'say': 1, 'zsay': 2, 'sayf': 3, 'zsayf': 4, 'goto': 5}
    if k == 'raw':
        p = step['rest'].split(';')[0].split()
        return struct.pack('<HB', sid, int(p[0])) + bytes.fromhex(''.join(p[1:]))
    if k not in types: raise ValueError('line %d: unknown step kind %s' % (step['line'], k))
    hdr = struct.pack('<HB', sid, types[k])
    if k == 'code': return hdr + B.asm('\n'.join(step['body']), names)
    if k == 'say':
        spk, txt = _spk_text(step['rest'])
        return hdr + bytes([spk]) + txt.encode('latin-1') + b'\0'
    if k == 'zsay':
        spk, txt = _spk_text(step['rest'])
        raw = txt.encode('latin-1') + b'\0'
        if len(raw) > ZBUF: raise ValueError('line %d: text longer than %d bytes' % (step['line'], ZBUF))
        return hdr + bytes([spk]) + compress_stream(raw)
    p = step['rest'].split(None, 2)
    if k == 'goto':
        return ('asm', '\t.2byte %d\n\t.byte 5, 0\n\t.4byte %s\n' % (sid, p[0]))
    if k == 'sayf':
        code = B.asm('\n'.join(step['body']), names)
        return ('asm', '\t.2byte %d\n\t.byte 3, %d\n\t.4byte %s\n' % (sid, int(p[0], 0), p[1]) +
                ''.join('\t.byte %s\n' % ', '.join('0x%02X' % x for x in code[i:i + 16]) for i in range(0, len(code), 16)))
    if k == 'zsayf':
        txt = unquote(p[2]).encode('latin-1') + b'\0'
        z = compress_stream(txt)
        return ('asm', '\t.2byte %d\n\t.byte 4, %d\n\t.4byte %s\n' % (sid, int(p[0], 0), p[1]) +
                ''.join('\t.byte %s\n' % ', '.join('0x%02X' % x for x in z[i:i + 16]) for i in range(0, len(z), 16)))


def asm_size(src):
    n = 0
    for l in src.split('\n'):
        l = l.strip()
        if l.startswith('.2byte'): n += 2
        elif l.startswith('.4byte'): n += 4
        elif l.startswith('.byte'): n += len(l[5:].split(','))
    return n


def same_step(d, t, st, data):
    """Does the original step object at t already encode `st`?"""
    k = st['kind']; s = parse_step(d, t)
    if k in ('zsay', 'zsayf'):     # compressed: compare decoded content, not the bitstream
        if d[t + 2] != (2 if k == 'zsay' else 4) or u16(d, t) != st['id']: return False
        if k == 'zsay':
            spk, txt = _spk_text(st['rest']); return d[t + 3] == spk and s['text'] == txt
        p = st['rest'].split(None, 2)
        return d[t + 3] == int(p[0], 0) and L.symbol(s['argcode']) == p[1] and s['text'] == unquote(p[2])
    if isinstance(data, tuple):
        if k == 'goto': return d[t + 2] == 5 and u16(d, t) == st['id'] and L.symbol(s['target']) == st['rest'].split()[0]
        p = st['rest'].split(None, 2)
        return (d[t + 2] == 3 and u16(d, t) == st['id'] and d[t + 3] == int(p[0], 0) and L.symbol(s['fmt']) == p[1]
                and d[s['code'][0]:s['code'][1]] == B.asm('\n'.join(st['body']), None))
    return data == d[t:s['end']]


def compile_list(d, o, items, term, text, names, new_text, outdir, tag):
    """Compare an edited .evt with the original list; return overrides (tools/assets/apply.py format)."""
    steps = parse_evt(text)
    if not term and len(steps) != len(items):
        raise ValueError('%s: this list has no 0 terminator, so it must keep %d steps' % (L.name_at(o), len(items)))
    ov = []; ptrs = []
    # lists numbered 1, 2, 3... must stay that way (the game finds the next step by id): renumber by position.
    # Written ids still say which original step a line is, so unchanged steps keep their objects.
    seq = all(u16(d, t) == i + 1 for i, t in enumerate(items))
    by_id = {}
    for t in items: by_id.setdefault(u16(d, t), []).append(t)
    for i, st in enumerate(steps):
        if st['kind'] == 'ref':
            ptrs.append(st['rest']); continue
        wid = st['id']
        if seq: st = dict(st, id=i + 1)
        data = step_bytes(st, names)
        # the original object of this step: same id (ids identify steps; positions change when steps are inserted)
        cand = [x for x in by_id.get(wid, []) if L.name_at(x) not in ptrs]   # unused objects with this id
        t = cand[0] if cand else None
        if t is not None:
            e = parse_step(d, t)['end'] or L.object_end(t)
            if not same_step(d, t, st, data):
                if isinstance(data, tuple):
                    fn = os.path.join(outdir, 'ov_%06X_%s.s' % (t, tag)); open(fn, 'w').write(data[1])
                    ov.append({'start': t, 'end': e, 'file': fn, 'size': asm_size(data[1])})
                else:
                    if st['kind'] == 'zsay' and len(data) % 4: data += bytes(4 - len(data) % 4)
                    fn = os.path.join(outdir, 'ov_%06X_%s.bin' % (t, tag)); open(fn, 'wb').write(data)
                    ov.append({'start': t, 'end': e, 'file': fn})
            ptrs.append(L.name_at(t))
        else:
            name = 'Event_%06X_s%d_%d' % (o, i, st['id'])
            if isinstance(data, tuple):
                fn = os.path.join(outdir, 'new_%s.s' % name); open(fn, 'w').write(data[1])
                ov.append({'new': name, 'file': fn, 'size': asm_size(data[1])})
            else:
                fn = os.path.join(outdir, 'new_%s.bin' % name); open(fn, 'wb').write(data)
                ov.append({'new': name, 'file': fn})
            ptrs.append(name)
    if len(ptrs) != len(items) or any(p != L.name_at(t) for p, t in zip(ptrs, items)):
        src = ''.join('\t.4byte %s\n' % p for p in ptrs) + ('\t.4byte 0\n' if term else '')
        fn = os.path.join(outdir, 'ov_%06X_%s_list.s' % (o, tag)); open(fn, 'w').write(src)
        ov.append({'start': o, 'end': o + 4 * (len(items) + (1 if term else 0)), 'file': fn,
                   'size': 4 * (len(ptrs) + (1 if term else 0))})
    return ov


if __name__ == '__main__':
    import argparse
    ap = argparse.ArgumentParser(description='Disassemble one event list or script')
    ap.add_argument('addr', help='ROM address of an event list (0x08...)')
    a = ap.parse_args()
    os.chdir(os.path.join(HERE, '..', '..'))
    d = open('baserom.gba', 'rb').read()
    o = int(a.addr, 16) - ROM
    items, term = read_list(d, o)
    print(export_list(d, o, items, term, None, B.load_names(), {}))
