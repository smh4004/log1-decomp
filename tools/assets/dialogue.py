"""Conversations as editable text (used by assets.py). Legacy of Goku.

gConversationSets (0x0815BF28): 80 pointers to conversation sets. A set is an array of 8-byte lines
  {u8 speaker, u8 next, u16 0, u32 text}; speaker = character sprite set (its face is shown; see SPRITES.txt), 0xFF =
  end of the conversation (no text).
How the game plays one (sub_080051D0): start at an entry line, show it, go to its `next`, until an end line; the end
line's `next` is stored as the entry for the next time. So an NPC can say one thing the first time and something else
afterwards, and story scripts can move a set's entry (sub_0800536C).
Who uses which set: area actors (characters) have `param` = set; kind 1 keeps the entry per set, kind 0 per actor
(starting at the actor's b10). Conversation triggers name a set and an entry.

assets/dialogue/setNN.txt, one line per conversation line:
    INDEX: SPEAKER > NEXT | text            ({0A} = new line, {XX} = control byte, {{ = brace; same as strings.txt)
    INDEX: end > NEXT
Lines can be added at the end, and any text, speaker or next can change. A changed text becomes a new string (the old one
stays for anything else that uses it). The dialogue texts aren't in assets/text/strings.txt (only texts that something
other than a conversation also points to are).
"""
import os, re, struct
import labels as L

ROM = 0x08000000
SETS, N_SETS = 0x15BF28, 80
END = 0xFF


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def esc(s):
    out = []
    for ch in s:
        c = ord(ch)
        if ch == '{': out.append('{{')
        elif c < 0x20 or c == 0x7F: out.append('{%02X}' % c)
        else: out.append(ch)
    return ''.join(out)


def unesc(s):
    return re.sub(r'\{\{|\{([0-9A-Fa-f]{2})\}', lambda m: '{' if m.group(0) == '{{' else chr(int(m.group(1), 16)), s)


def cstr(d, o): return d[o:d.index(b'\0', o)].decode('latin-1')


def read_set(d, i):
    p = u32(d, SETS + 4 * i) - ROM
    n = (L.object_end(p) - p) // 8
    return p, [struct.unpack_from('<BBHI', d, p + 8 * k) for k in range(n)]


def dialogue_texts(d):
    """text offsets used only by conversations (strings.txt leaves these out)"""
    uses = {}
    for i in range(N_SETS):
        for sp, nx, h, tp in read_set(d, i)[1]:
            if sp != END: uses[tp - ROM] = uses.get(tp - ROM, 0) + 1
    out = set()
    for o, n in uses.items():
        if d.count(struct.pack('<I', o + ROM)) == n: out.add(o)
    return out


def extract(d, out, reg, names):
    dd = os.path.join(out, 'dialogue'); os.makedirs(dd, exist_ok=True)
    for i in range(N_SETS):
        p, lines = read_set(d, i)
        x = ['# Conversation set %d (%s). "INDEX: SPEAKER > NEXT | text"; "end > NEXT" stops and resumes at NEXT next time.'
             % (i, L.name_at(p))]
        for k, (sp, nx, h, tp) in enumerate(lines):
            if sp == END: x.append('%d: end > %d' % (k, nx))
            else: x.append('%d: %s > %d | %s' % (k, names[sp] if sp < len(names) else sp, nx, esc(cstr(d, tp - ROM))))
        f = os.path.join(dd, 'set%02d.txt' % i)
        open(f, 'w', encoding='utf-8').write('\n'.join(x) + '\n')
        reg('dialogue:%02d' % i, f, kind='dialogue', set=i)


LINE = re.compile(r'^(\d+):\s*(\S+)\s*>\s*(\d+)\s*(?:\|\s?(.*))?$')


def build(d, a, path, ctx, names):
    i = a['set']; p, old = read_set(d, i)
    new = []
    for l in open(path, encoding='utf-8'):
        l = l.rstrip('\n')
        if not l.strip() or l.startswith('#'): continue
        m = LINE.match(l)
        if not m: raise SystemExit('%s: bad line: %s' % (path, l))
        k, who, nx, txt = int(m.group(1)), m.group(2), int(m.group(3)), m.group(4)
        if k != len(new): raise SystemExit('%s: line %d is out of order (expected %d)' % (path, k, len(new)))
        if who == 'end': new.append((END, nx, None))
        else:
            sp = names.index(who) if who in names else int(who, 0)
            if txt is None: raise SystemExit('%s: line %d needs "| text"' % (path, k))
            new.append((sp, nx, unesc(txt)))
    for k, (sp, nx, t) in enumerate(new):
        if nx >= len(new): raise SystemExit('%s: line %d: next %d does not exist' % (path, k, nx))
    if len(new) > 255: raise SystemExit('%s: at most 255 lines' % path)
    rows = []
    changed = len(new) != len(old)
    for k, (sp, nx, t) in enumerate(new):
        if sp == END:
            rows.append('\t.byte 0xFF, %d\n\t.2byte 0\n\t.4byte 0\n' % nx)
            changed |= k >= len(old) or old[k][:2] != (END, nx)
            continue
        lab = None
        if k < len(old) and old[k][0] != END and cstr(d, old[k][3] - ROM) == t:
            lab = L.name_at(old[k][3] - ROM)
        if lab is None:
            lab = ctx['new']('gConv%02d_Line%03d_Text' % (i, k), t.encode('latin-1') + b'\0')
            changed = True
        elif k >= len(old) or old[k][:2] != (sp, nx):
            changed = True
        rows.append('\t.byte %d, %d\n\t.2byte 0\n\t.4byte %s\n' % (sp, nx, lab))
    if not changed: return
    text = ''.join(rows)
    if len(new) <= len(old):
        ctx['put_s'](p, p + 8 * len(old), text + '\t.space %d\n' % (8 * (len(old) - len(new))), 8 * len(old), 'conv')
    else:
        lab = ctx['new_s']('gConv%02d' % i, text, 8 * len(new))
        ctx['put_s'](SETS + 4 * i, SETS + 4 * i + 4, '\t.4byte %s\n' % lab, 4, 'convptr')
