"""Music as editable tracker text (used by assets.py). Legacy of Goku.

Webfoot's tracker-style format. The layout and the row encoding were worked out with the help of
webfootaudioengine (github.com/ghxstboyy/webfootaudioengine), which reads and writes this format for .it modules;
this file is a separate implementation for this source tree.

gTrackTable (0x08591F3C): 18 songs x {u32 -> pattern pointer list, u32 -> order list, u32 meta (tempo = low byte,
speed = ticks per row = next byte)}. Song data lies as: order list (pattern numbers, 0xFF = end, then loop to the
start), the patterns, then the pattern pointer list. Samples are the global gSampleTable (sound.py); masks can come
from a global 14-byte dictionary (0x08142388).

Pattern: u8 row count, then per row a list of tokens ended by 0x00. Token byte: low nibble = channel + 1 (1-15);
high nibble 0 = a mask byte follows (and is remembered for the channel), 1 = the channel's remembered mask,
n >= 2 = dictionary[n - 2]. Mask bits: 0x01 note byte follows, 0x02 sample, 0x04 volume (0-64), 0x08 effect + parameter
(2 bytes); 0x10 / 0x20 / 0x40 / 0x80 = play the channel's previous note / sample / volume / effect again.
Notes: 0 = C-0 ... 119 = B-9, 254 = note cut (^^^), 255 = note off (===). Effects use Impulse Tracker numbering:
1 = A (speed) ... 20 = T (tempo) ... 26 = Z; other numbers are written ?NNPP.

assets/music/songNN.txt:
    tempo 135
    speed 6
    order 0 1 2 3
    pattern 0 64                   (pattern number, row count)
    0: 1 C-5 03 40 A06 | 4 = = .. ...
Each row lists the channels that do something: CHANNEL NOTE SAMPLE VOLUME EFFECT. A field is a value, "=" (repeat
the channel's previous value), or ".." / "..." / "---" (nothing). Rows with nothing are written as "N:" or left out.
The whole song is re-encoded when it changes and moved to the end of the data; unchanged songs keep their bytes.
"""
import os, struct, re

ROM = 0x08000000
TRACKS, N_TRACKS, DESC = 0x591F3C, 18, 12
DICT = 0x142388
NAMES = ['C-', 'C#', 'D-', 'D#', 'E-', 'F-', 'F#', 'G-', 'G#', 'A-', 'A#', 'B-']


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def note_name(n):
    if n == 254: return '^^^'
    if n == 255: return '==='
    if n < 120: return '%s%d' % (NAMES[n % 12], n // 12)
    return 'N%02X' % n


def note_value(s):
    if s == '^^^': return 254
    if s == '===': return 255
    if s.startswith('N'): return int(s[1:], 16)
    return NAMES.index(s[:2]) + 12 * int(s[2:])


def song(d, k):
    tp, sp, meta = struct.unpack_from('<III', d, TRACKS + DESC * k)
    to, so = tp - ROM, sp - ROM
    order = []
    p = so
    while True:
        order.append(d[p]); p += 1
        if order[-1] == 0xFF: break
    ptrs = []
    q = to
    while q + 4 <= len(d) and ROM + so <= u32(d, q) < ROM + to: ptrs.append(u32(d, q) - ROM); q += 4
    return dict(table=to, start=so, end=q, order=order, ptrs=ptrs, tempo=meta & 0xFF, speed=meta >> 8 & 0xFF,
                meta=meta)


def decode_pattern(d, o, dic):
    """-> rows: list of [(channel, note, sample, vol, (cmd, param))]; each field None / '=' / value; end offset"""
    rows = d[o]; p = o + 1; out = []; masks = {}
    for _ in range(rows):
        row = []
        while True:
            t = d[p]; p += 1
            if t == 0: break
            ch, ct = t & 15, t >> 4
            if ct == 0: m = d[p]; p += 1; masks[ch] = m
            elif ct == 1: m = masks.get(ch, 0)
            else: m = dic[ct - 2]
            note = inst = vol = fx = None
            if m & 1: note = d[p]; p += 1
            elif m & 0x10: note = '='
            if m & 2: inst = d[p]; p += 1
            elif m & 0x20: inst = '='
            if m & 4: vol = d[p]; p += 1
            elif m & 0x40: vol = '='
            if m & 8: fx = (d[p], d[p + 1]); p += 2
            elif m & 0x80: fx = '='
            row.append((ch, note, inst, vol, fx))
        out.append(row)
    return out, p


def encode_pattern(rows, dic):
    out = bytearray([len(rows)]); masks = {}
    for row in rows:
        for ch, note, inst, vol, fx in row:
            m = 0; body = bytearray()
            for v, bit in ((note, 1), (inst, 2), (vol, 4)):
                if v == '=': m |= bit << 4
                elif v is not None: m |= bit; body.append(v)
            if fx == '=': m |= 0x80
            elif fx is not None: m |= 8; body += bytes(fx)
            if m in dic: out.append(((dic.index(m) + 2) << 4) | ch)
            elif masks.get(ch) == m: out.append(0x10 | ch)
            else: out += bytes([ch, m]); masks[ch] = m
            out += body
        out.append(0)
    return bytes(out)


def fmt_cell(c):
    ch, note, inst, vol, fx = c
    f = lambda v, w, form: '=' if v == '=' else ('.' * w if v is None else form(v))
    return '%d %s %s %s %s' % (ch, f(note, 2, note_name) if note is not None else '..', f(inst, 2, lambda v: '%02X' % v),
                               f(vol, 2, lambda v: '%02d' % v),
                               '=' if fx == '=' else ('...' if fx is None else '%s%02X' % (chr(64 + fx[0]) if 1 <= fx[0] <= 26 else '?%02X' % fx[0], fx[1])))


def parse_cell(s):
    w = s.split()
    if len(w) != 5: raise ValueError('cell needs 5 fields: %r' % s)
    ch = int(w[0])
    note = None if w[1] in ('..', '...') else '=' if w[1] == '=' else note_value(w[1])
    inst = None if w[2] == '..' else '=' if w[2] == '=' else int(w[2], 16)
    vol = None if w[3] == '..' else '=' if w[3] == '=' else int(w[3])
    if w[4] in ('...', '---'): fx = None
    elif w[4] == '=': fx = '='
    elif w[4].startswith('?'): fx = (int(w[4][1:3], 16), int(w[4][3:], 16))
    else: fx = (ord(w[4][0]) - 64, int(w[4][1:], 16))
    if not 1 <= ch <= 15: raise ValueError('channel 1-15')
    return ch, note, inst, vol, fx


def to_text(d, k):
    s = song(d, k); dic = list(d[DICT:DICT + 14])
    x = ['# Song %d. Format: top of tools/assets/music.py. "CHANNEL NOTE SAMPLE VOLUME EFFECT", "=" = repeat.' % k,
         'tempo %d' % s['tempo'], 'speed %d' % s['speed'], 'order ' + ' '.join(str(v) for v in s['order'][:-1])]
    for i, p in enumerate(s['ptrs']):
        rows, e = decode_pattern(d, p, dic)
        x.append(''); x.append('pattern %d %d' % (i, len(rows)))
        for r, row in enumerate(rows):
            if row: x.append('%d: ' % r + ' | '.join(fmt_cell(c) for c in row))
    return '\n'.join(x) + '\n'


def from_text(text):
    tempo = speed = None; order = []; pats = {}; cur = None
    for line in text.split('\n'):
        line = '' if line.lstrip().startswith('#') else line.strip()
        if not line: continue
        w = line.split()
        if w[0] == 'tempo': tempo = int(w[1])
        elif w[0] == 'speed': speed = int(w[1])
        elif w[0] == 'order': order = [int(v) for v in w[1:]]
        elif w[0] == 'pattern':
            cur = [[] for _ in range(int(w[2]))]; pats[int(w[1])] = cur
        else:
            r, rest = line.split(':', 1)
            cells = [parse_cell(c) for c in rest.split('|') if c.strip()]
            cur[int(r)] = cells
    n = max(pats) + 1 if pats else 0
    if sorted(pats) != list(range(n)): raise ValueError('patterns must be numbered 0..%d' % (n - 1))
    if any(o >= n for o in order): raise ValueError('order uses a pattern that does not exist')
    return dict(tempo=tempo, speed=speed, order=order, patterns=[pats[i] for i in range(n)])


def song_semantics(d, k):
    s = song(d, k); dic = list(d[DICT:DICT + 14])
    return dict(tempo=s['tempo'], speed=s['speed'], order=s['order'][:-1],
                patterns=[decode_pattern(d, p, dic)[0] for p in s['ptrs']])


def extract(d, out, reg):
    md = os.path.join(out, 'music'); os.makedirs(md, exist_ok=True)
    for k in range(N_TRACKS):
        p = os.path.join(md, 'song%02d.txt' % k)
        open(p, 'w').write(to_text(d, k))
        reg('music:%02d' % k, p, kind='music', song=k)


def build(d, a, path, ctx):
    k = a['song']; new = from_text(open(path).read()); old = song_semantics(d, k)
    s = song(d, k); desc = TRACKS + DESC * k
    if (new['tempo'], new['speed']) != (old['tempo'], old['speed']):
        meta = (s['meta'] & ~0xFFFF) | new['tempo'] | new['speed'] << 8
        ctx['put'](desc + 8, desc + 12, struct.pack('<I', meta), 'songmeta')
    if new['order'] == old['order'] and new['patterns'] == old['patterns']: return
    dic = list(d[DICT:DICT + 14])
    lines = ['\t.byte %s' % ', '.join(str(v) for v in new['order'] + [0xFF])]
    for i, rows in enumerate(new['patterns']):
        b = encode_pattern(rows, dic)
        lines.append('gSong%02d_Pattern%02d:' % (k, i))
        lines += ['\t.byte %s' % ', '.join('0x%02X' % c for c in b[j:j + 16]) for j in range(0, len(b), 16)]
    lines.append('\t.align 2, 0')
    lines.append('\t.global gSong%02d_Patterns' % k)
    lines.append('gSong%02d_Patterns:' % k)
    lines += ['\t.4byte gSong%02d_Pattern%02d' % (k, i) for i in range(len(new['patterns']))]
    text = '\n'.join(lines) + '\n'
    size = len(text)          # only used to reserve; the appendix entry is assembled from the text
    lab = ctx['new_s']('gSong%02d_Order' % k, text, size)
    ctx['put_s'](desc, desc + 8, '\t.4byte gSong%02d_Patterns\n\t.4byte %s\n' % (k, lab), 8, 'songptr')
