#!/usr/bin/env python3
"""Legacy of Goku II script bytecode: disassembler and assembler.

The VM (ScriptVM_Run, 0x080092E4) is a stack machine, an older version of the Buu's Fury one.
Opcodes (gScriptOpcodeFuncs, 0x083B5C00, 30 entries; 0x11 is a null entry that ends the script):
  00 push u8            01 push varint         02 call native[u8]     03 set var[u8] = pop
  04 and  05 or  06 neg  07 add  08 sub  09 mul  0A div   (no mod: that is 0x1E in Buu's Fury)
  0B eq   0C ne  0D gt   0E ge   0F lt   10 le
  11 end                12 jmp u8              13 jz u8 (pops)        14 pop
  15 inc var  16 preinc var (push new)  17 postinc var (push old)
  18 dec var  19 predec var             1A postdec var
  1B loop_begin (pops count)            1C loop u16 (back)     1D pushn u8 n, n varints
Jump offsets are one unsigned byte, relative to the byte after the offset (jmp/jz forward only, loop backward only).
Varint: 7-bit groups, most significant first, bit 7 = more; the decoded value's low bit is the sign.
"Vars" are natives 0-17 used as getter (native table) and setter (gScriptSetterFuncs, 0x083B5F70) pairs. Natives: gScriptNativeFuncs, 0x083B5D28.

Text syntax (one instruction per line, `;` comments, `name:` labels):
  push 5 / push.v -3 / pushn 1, -2, 300 / call 0x88 / call wait(30) / set 3 / inc 3 ...
  jmp L1 / jz L1 / loop L1 / end / raw 01 02 ...
`call NAME(a, b)` is shorthand for `push a; push b; call NAME` (u8 pushes); names come from config/script_natives.txt.
"""
import os, re

OPS = {0x04: 'and', 0x05: 'or', 0x06: 'neg', 0x07: 'add', 0x08: 'sub', 0x09: 'mul', 0x0A: 'div',
       0x0B: 'eq', 0x0C: 'ne', 0x0D: 'gt', 0x0E: 'ge', 0x0F: 'lt', 0x10: 'le', 0x11: 'end', 0x14: 'pop',
       0x1B: 'loop_begin'}
VAROPS = {0x03: 'set', 0x15: 'inc', 0x16: 'preinc', 0x17: 'postinc', 0x18: 'dec', 0x19: 'predec', 0x1A: 'postdec'}
JUMPS = {0x12: 'jmp', 0x13: 'jz', 0x1C: 'loop'}
BYNAME = {v: k for k, v in list(OPS.items()) + list(VAROPS.items()) + list(JUMPS.items())}

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..'))


def load_names():
    """config/script_natives.txt: `id name [comment]` (id in hex or decimal). Also used for var names."""
    names = {}
    p = os.path.join(ROOT, 'config', 'script_natives.txt')
    if os.path.exists(p):
        for l in open(p):
            l = l.split('#')[0].split()
            if len(l) >= 2: names[int(l[0], 0)] = l[1]
    return names


def enc_varint(v):
    s = (abs(v) << 1) | (1 if v < 0 else 0)
    groups = []
    while True:
        groups.append(s & 0x7F); s >>= 7
        if not s: break
    groups.reverse()
    return bytes([g | 0x80 for g in groups[:-1]] + [groups[-1]])


def dec_varint(b, p):
    v = 0; start = p
    while True:
        c = b[p]; p += 1
        v = v * 128 + (c & 0x7F)
        if not c & 0x80: break
    r = v >> 1
    if v & 1: r = -r
    return r, p, b[start:p]


class BadCode(Exception):
    pass


def decode(b, start=0, stop_at_end=True):
    """Linear decode -> list of (offset, opcode, operand, raw bytes). Stops after `end` (and any jump targets
    beyond it are followed so the whole reachable body is covered)."""
    out = []; p = start; targets = set(); limit = len(b)
    seen_end = False
    while p < limit:
        if seen_end and stop_at_end and not any(t >= p for t in targets): break
        o = p; op = b[p]; p += 1
        if op == 0x00:
            arg = b[p]; p += 1
        elif op == 0x01:
            arg, p, _ = dec_varint(b, p)
        elif op in (0x02,) or op in VAROPS:
            arg = b[p]; p += 1
        elif op in JUMPS:
            off = b[p]; p += 1
            arg = p - off if op == 0x1C else p + off
            targets.add(arg)
        elif op == 0x1D:
            n = b[p]; p += 1; arg = []
            for _ in range(n):
                v, p, _ = dec_varint(b, p); arg.append(v)
        elif op in OPS:
            arg = None
        else:
            raise BadCode('bad opcode 0x%02X at +%d' % (op, o - start))
        if p > limit: raise BadCode('truncated')
        out.append((o, op, arg, bytes(b[o:p])))
        if op == 0x11: seen_end = True
    if not seen_end and stop_at_end: raise BadCode('no end')
    for t in targets:
        if not any(x[0] == t for x in out) and t != p: raise BadCode('jump into the middle of an instruction')
    return out, p


def canonical(op, arg, raw):
    """True when re-encoding (op, arg) gives raw (so the text form round-trips)."""
    return encode_one(op, arg, 0, {}) == raw if op not in JUMPS else True


def encode_one(op, arg, here, labels):
    if op == 0x00: return bytes([0, arg & 0xFF])
    if op == 0x01: return b'\x01' + enc_varint(arg)
    if op == 0x02 or op in VAROPS: return bytes([op, arg])
    if op == 0x1D: return bytes([0x1D, len(arg)]) + b''.join(enc_varint(v) for v in arg)
    if op in JUMPS:
        t = labels[arg] if isinstance(arg, str) else arg
        f = here + 2
        off = (f - t) if op == 0x1C else (t - f)
        if not 0 <= off < 0x100: raise ValueError('%s target out of range (u8, %s only)' % (JUMPS[op], 'backward' if op == 0x1C else 'forward'))
        return bytes([op, off])
    return bytes([op])


def disasm(b, start=0, names=None, base=0, stop=None):
    """Bytecode -> text. With `stop`, everything up to `stop` is included (code after `end`, e.g. in compressed
    steps; whatever doesn't decode is kept as `raw`)."""
    names = names if names is not None else load_names()
    ins, endp = decode(b, start)
    tail = b''
    if stop is not None and endp < stop:
        try:
            more, e2 = decode(b[:stop], endp, stop_at_end=False)
            ins += more; endp = e2
        except (BadCode, IndexError):
            pass
        tail = bytes(b[endp:stop])
    targets = sorted({a for _, op, a, _ in ins if op in JUMPS})
    lab = {t: 'L%d' % (i + 1) for i, t in enumerate(targets)}
    lines = []
    i = 0
    while i < len(ins):
        o, op, arg, raw = ins[i]
        if o in lab: lines.append('%s:' % lab[o])
        if not canonical(op, arg, raw):
            lines.append('    raw %s' % raw.hex(' ')); i += 1; continue
        if op == 0x00:
            # fold u8 pushes directly followed by a call into call arguments (byte-identical shorthand)
            j = i
            while j < len(ins) and ins[j][1] == 0x00 and (j == i or ins[j][0] not in lab) and canonical(*ins[j][1:]): j += 1
            if j < len(ins) and ins[j][1] == 0x02 and ins[j][0] not in lab and j > i:
                args = ', '.join(str(x[2]) for x in ins[i:j])
                n = ins[j][2]
                lines.append('    call %s(%s)' % (names.get(n, '0x%02X' % n), args))
                i = j + 1; continue
            lines.append('    push %d' % arg)
        elif op == 0x01: lines.append('    push.v %d' % arg)
        elif op == 0x02: lines.append('    call %s' % names.get(arg, '0x%02X' % arg))
        elif op in VAROPS: lines.append('    %s %s' % (VAROPS[op], names.get(arg, '0x%02X' % arg)))
        elif op in JUMPS: lines.append('    %s %s' % (JUMPS[op], lab[arg]))
        elif op == 0x1D: lines.append('    pushn %s' % ', '.join(str(v) for v in arg))
        else: lines.append('    %s' % OPS[op])
        i += 1
    if endp in lab: lines.append('%s:' % lab[endp])
    for k in range(0, len(tail), 16): lines.append('    raw %s' % tail[k:k + 16].hex(' '))
    return '\n'.join(lines) + '\n', endp + len(tail)


def _num(s, names):
    s = s.strip()
    if s in names: return names[s]
    return int(s, 0)


def asm(text, names=None):
    """Text -> bytecode (two passes for labels)."""
    names = names if names is not None else load_names()
    rev = {v: k for k, v in names.items()}
    prog = []
    for ln, l in enumerate(text.split('\n'), 1):
        l = l.split(';')[0].strip()
        if not l: continue
        m = re.match(r'^(\w+):$', l)
        if m: prog.append(('label', m.group(1), ln)); continue
        m = re.match(r'^call\s+([\w.]+)\s*\((.*)\)$', l)
        if m:
            for a in [x for x in m.group(2).split(',') if x.strip()]:
                prog.append(((0x00, _num(a, {})), None, ln))
            prog.append(((0x02, _num(m.group(1), rev)), None, ln)); continue
        parts = l.split(None, 1); mn = parts[0]; rest = parts[1] if len(parts) > 1 else ''
        try:
            if mn == 'push': prog.append(((0x00, int(rest, 0)), None, ln))
            elif mn == 'push.v': prog.append(((0x01, int(rest, 0)), None, ln))
            elif mn == 'pushn': prog.append(((0x1D, [int(x, 0) for x in rest.split(',')]), None, ln))
            elif mn == 'call': prog.append(((0x02, _num(rest, rev)), None, ln))
            elif mn in BYNAME and BYNAME[mn] in VAROPS: prog.append(((BYNAME[mn], _num(rest, rev)), None, ln))
            elif mn in BYNAME and BYNAME[mn] in JUMPS: prog.append(((BYNAME[mn], rest.strip()), None, ln))
            elif mn in BYNAME: prog.append(((BYNAME[mn], None), None, ln))
            elif mn == 'raw': prog.append((('raw', bytes.fromhex(rest.replace(' ', ''))), None, ln))
            else: raise ValueError('unknown instruction %r' % mn)
        except ValueError as e:
            raise ValueError('line %d: %s' % (ln, e))
    # pass 1: sizes (jumps are always 2 bytes)
    labels = {}; pos = 0
    for item, lab, ln in prog:
        if item == 'label': labels[lab] = pos; continue
        if item[0] == 'raw': pos += len(item[1])
        elif item[0] in JUMPS: pos += 2
        else: pos += len(encode_one(item[0], item[1], 0, {}))
    out = bytearray()
    for item, lab, ln in prog:
        if item == 'label': continue
        if item[0] == 'raw': out += item[1]; continue
        if item[0] in JUMPS and item[1] not in labels: raise ValueError('line %d: unknown label %s' % (ln, item[1]))
        out += encode_one(item[0], item[1], len(out), labels)
    return bytes(out)
