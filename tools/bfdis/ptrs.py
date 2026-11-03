#!/usr/bin/env python3
"""Pointer classification for .rodata (Phase 2).

A 4-byte-aligned word in uncompressed .rodata whose value lies in the ROM image is a pointer *candidate*.
Candidates are accepted when the evidence is strong; the rest are written to config/ptr_ambiguous.txt
and stay raw numbers (they will NOT follow if data moves).

Accepted:
  wfz        target is the first byte of a WFZ container
  func       odd value, target-1 is a traced Thumb function (or even value at an ARM function)
  code       target is also referenced from a code literal pool
  label      target is a code-area label (instruction, pool, vtable, data label)
  table      target in uncompressed .rodata, even, word sits in a pointer run (another candidate within 8 bytes)
             or in a regular-stride array, or the target is pointed to at least twice
Rejected (ambiguous):
  target inside a WFZ container (compressed bytes cannot be addressed), odd non-function targets,
  isolated words with a single reference.
"""
import struct, collections, bisect, re

ROM = 0x08000000
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from game import SOUND_LO, SOUND_HI, NOPTR, PALETTE_FILTER, ISOLATED_REFCOUNT, STRING_TABLES, PTR_TABLES   # uncompressed sound region (samples + sequences); no-pointer ranges


def classify(d, db, blocks, text_end, ro_lo, ro_hi, image_end):
    wstart = {o for o, s, e, t in blocks}
    bs = sorted((o, e) for o, s, e, t in blocks)
    starts = [b[0] for b in bs]

    def in_wfz(t):
        i = bisect.bisect_right(starts, t) - 1
        return i >= 0 and bs[i][0] < t < bs[i][1]

    inwfz = bytearray(len(d))
    for o, e in bs: inwfz[o:e] = b'\x01' * (e - o)
    funcs = db['funcs']
    insn = db['insn']
    pool_targets = set()
    for la in db['pool']:
        o = la - ROM if la >= ROM else db['iwram'][0] + la - db['iwram'][1]
        w = struct.unpack_from('<I', d, o)[0]
        if ROM <= w < ROM + image_end: pool_targets.add(w & ~1)
    code_labels = set(db['pool']) | set(db['labels']) | set(ROM + e for e in db['vt_ents'])
    vt_bases = set(db['vt_bases'])

    def smooth(w):
        # byte tables (sine curves, offsets, palettes) produce words like 0x08090908 / 0x08080404: every byte
        # within 8 of its neighbour. Real pointers like that are rare; keep them only with strong evidence.
        b = [(w >> s) & 0xFF for s in (0, 8, 16, 24)]
        return max(abs(b[i] - b[i + 1]) for i in range(3)) <= 8

    def pcmlike(o, W=48):
        # 8-bit signed audio: consecutive bytes change slowly and are rarely 00/FF. Tables of pointers or
        # records have large byte-to-byte jumps (xx xx xx 08) or many zero bytes.
        s = d[o - W:o] + d[o + 4:o + 4 + W]
        sb = [x - 256 if x > 127 else x for x in s]
        dl = [abs(sb[i + 1] - sb[i]) for i in range(len(sb) - 1) if i != W - 1]
        nz = sum(1 for x in s if x not in (0, 0xFF))
        return sum(dl) / len(dl) < 20 and nz > 0.7 * len(s)

    def palettelike(o):
        # 16-colour palettes (BGR555): the aligned 32-byte block holds 16 halfwords with bit 15 clear, and most of its
        # words are not ROM-pointer shaped (a grey 0x0842 in the high half makes a word look like 0x0842xxxx)
        b = o & ~31
        if re.search(rb'[ -~]{6}', d[b:b + 32]): return False          # text, not colours
        hw = struct.unpack_from('<16H', d, b)
        if any(h & 0x8000 for h in hw): return False
        ws = struct.unpack_from('<8I', d, b)
        big = sum(1 for h in hw if h >= 0x400)          # colours, not small record fields
        return sum(1 for w in ws if ROM <= w < ROM + image_end) <= 2 and big >= 11 and len(set(hw)) >= 8

    # words that are pointers to known Thumb functions: a pointer to a run of them points to a method table
    fptr = set()
    for o in range(ro_lo, ro_hi, 4):
        w = struct.unpack_from('<I', d, o)[0]
        if w & 1 and (w - 1) in funcs and funcs[w - 1] == 't' and not inwfz[o]: fptr.add(o)

    def methods_at(t):
        return sum(1 for k in range(0, 16, 4) if (t + k) in fptr) >= 2

    def ptrtable_at(t):
        """t starts a run of at least two pointer-looking words (an array of pointers)"""
        if not ro_lo <= t < ro_hi - 8 or t % 4: return False
        a, b = struct.unpack_from('<II', d, t)
        return all(ROM <= x < ROM + image_end and x & 3 != 3 for x in (a, b)) and not inwfz[t]

    def object_at(t):
        """t holds a method table (vtable-like) or starts with a pointer to one (a C++/C object stored in ROM)"""
        if methods_at(t): return True
        if not ro_lo <= t < ro_hi - 4 or t % 4: return False
        v = struct.unpack_from('<I', d, t)[0]
        return ROM <= v < ROM + image_end and v % 4 == 0 and methods_at(v - ROM)

    def cstring_at(t):
        # start of a C string: after a NUL (or 4-aligned), at least 3 printable characters with letters, then NUL
        if not (ro_lo <= t < ro_hi) or (t % 4 and d[t - 1] != 0): return False
        m = re.match(rb'[ -~\n]{3,}\x00', d[t:t + 512])
        return bool(m) and re.search(rb'[A-Za-z]{2}', m.group()) is not None

    acc, amb = {}, {}
    cand = {}
    forced = {s + k * st + f for s, n, st, f in PTR_TABLES for k in range(n)}
    for o in range(ro_lo, ro_hi, 4):
        if inwfz[o]: continue
        w = struct.unpack_from('<I', d, o)[0]
        if o in forced and ROM <= w < ROM + image_end:
            acc[o] = (w, 'config'); continue
        if ROM <= w < ROM + image_end:
            if any(lo <= o < hi for lo, hi in NOPTR):
                amb[o] = (w, 'noptr'); continue
            if w % 4 == 0 and object_at(w - ROM):
                cand[o] = w; continue                  # pointer to an object or its method table: never data
            if PALETTE_FILTER and (w - ROM) not in wstart and (w & ~1) not in pool_targets and palettelike(o):
                amb[o] = (w, 'palette'); continue
            if (w - ROM) not in wstart and pcmlike(o):
                amb[o] = (w, 'pcm'); continue
            if smooth(w) and not ((w - ROM) in wstart or (w & ~1) in pool_targets or (w - 1) in funcs):
                amb[o] = (w, 'bytepattern'); continue
            cand[o] = w
    refcount = collections.Counter(cand.values())
    odd = []
    isolated = []
    for o, w in cand.items():
        t = w - ROM
        # dialogue step record {u16 id, u8 type=5, u8 speaker, u32 textref}: a packed text ref
        # (bank | off<<6 | len<<21) with len 64..67 looks exactly like a ROM pointer
        if d[o - 2] == 5 and d[o - 1] != 0x08 and (w & 0x3F) < 7 and struct.unpack_from('<H', d, o - 4)[0] < 0x400:
            amb[o] = (w, 'textref'); continue
        if t in wstart and w % 2 == 0: acc[o] = (w, 'wfz'); continue
        if w & 1 and (w - 1) in funcs and funcs[w - 1] == 't': acc[o] = (w, 'func'); continue
        if w % 4 == 0 and w in funcs and funcs[w] == 'a': acc[o] = (w, 'func'); continue
        if in_wfz(t): amb[o] = (w, 'inside_wfz'); continue
        if w & 1 and (w - 1) in insn and insn[w - 1][0] == 't':
            # odd value at a Thumb instruction that is not a known function start: a new entry point only when
            # it sits in a pointer run or is referenced twice; one isolated hit in a blob is noise
            if refcount[w] >= 2 or any((o + k) in cand for k in (-12, -8, -4, 4, 8, 12)):
                acc[o] = (w, 'func')
            else:
                amb[o] = (w, 'func_weak')
            continue
        if w & 1: odd.append(o); continue
        if w in pool_targets: acc[o] = (w, 'code'); continue
        if t < text_end:
            # plain instruction addresses are not evidence (0x08000800 is also two halfwords 0x0800)
            if t in vt_bases or (w in code_labels and w not in insn): acc[o] = (w, 'label')
            else: amb[o] = (w, 'text_unlabeled')
            continue
        neighbour = any((o + k) in cand for k in (-8, -4, 4, 8))
        stride = False
        if not neighbour:
            for s in range(12, 260, 4):
                if (o - s) in cand and (o + s) in cand or (o + s) in cand and (o + 2 * s) in cand \
                        or (o - s) in cand and (o - 2 * s) in cand:
                    stride = True; break
        # without a neighbouring pointer the evidence is weak: also require an aligned target that is either
        # close by (same asset bank) or pointed to several times
        if STRING_TABLES and (neighbour or stride or any((o + k) in cand for k in (-16, -12, 12, 16))) and cstring_at(t):
            acc[o] = (w, 'strtable'); continue
        weak_ok = w % 4 == 0 and (abs(t - o) < 0x80000 or w in pool_targets or object_at(t) or ptrtable_at(t)
                                  or (ISOLATED_REFCOUNT and refcount[w] >= ISOLATED_REFCOUNT))
        if neighbour or (stride or refcount[w] >= 2) and weak_ok:
            acc[o] = (w, 'table')
        else:
            isolated.append(o)
    # isolated words: accept when they sit at the start of an object that something points to
    # (e.g. a font header {glyph ptr, 0, 0, ram ptr} referenced from code). Noise in big blobs is far from labels.
    obj_starts = sorted(set(w2 - ROM for w2 in pool_targets) | set(w2 - ROM for (w2, k2) in acc.values()))
    for o in isolated:
        w = cand[o]
        i = bisect.bisect_right(obj_starts, o) - 1
        tset = getattr(classify, '_tset', None)
        if tset is None or tset[0] is not obj_starts: tset = classify._tset = (obj_starts, set(obj_starts))
        if i >= 0 and o - obj_starts[i] < 0x20 and ((w - ROM) in tset[1] or abs(w - ROM - o) < 0x10000):   # and the target is a known object or close by
            acc[o] = (w, 'struct')
        elif w % 4 == 0 and object_at(w - ROM):           # pointer to an object / its method table
            acc[o] = (w, 'methods')
        elif w % 4 == 0 and ptrtable_at(w - ROM):         # pointer to an array of pointers
            acc[o] = (w, 'ptrarray')
        elif 4 <= w - ROM - o <= 16:                      # points just past itself (record + inline data): never chance
            acc[o] = (w, 'inline')
        else:
            amb[o] = (w, 'isolated')
    # odd targets (byte streams such as scripts): accept only next to a strongly-typed pointer
    for o in odd:
        w = cand[o]
        strong = any(acc.get(o + k, (0, ''))[1] in ('func', 'wfz', 'code', 'label') for k in (-8, -4, 4, 8))
        run = any((o + k) in cand and cand[o + k] & 1 and abs(cand[o + k] - w) < 0x8000 for k in (-8, -4, 4, 8))
        if not run:      # regular-stride array of records (e.g. 12-byte sound sample headers)
            for st in range(8, 68, 4):
                hits = sum(1 for m in (-2, -1, 1, 2) if (o + m * st) in cand and abs(cand[o + m * st] - w) < 0x100000)
                if hits >= 2: run = True; break
        bytepat = (w >> 16) & 0xFF == 0x08 and (w & 0xFF) == (w >> 8) & 0xFF      # e.g. 01 01 08 08: byte fields
        if STRING_TABLES and not bytepat and cstring_at(w - ROM) and any((o + k) in cand for k in (-16, -12, -8, -4, 4, 8, 12, 16)):
            acc[o] = (w, 'strtable'); continue
        if w - ROM >= text_end and (strong or run) and not bytepat:
            acc[o] = (w, 'table_odd')
        else:
            amb[o] = (w, 'odd')
    # words inside byte-stream objects (objects whose start is not 4-aligned: sound sequences, scripts)
    # are data, not pointers -- unless the evidence is strong (wfz/func/code).
    starts = sorted(set((w2 & ~0) - ROM for (w2, k2) in acc.values() if k2 not in ('func',)) | set(w2 - ROM for w2 in pool_targets))
    for o in list(acc):
        w, k = acc[o]
        if k in ('wfz', 'func', 'code', 'config'): continue
        i = bisect.bisect_right(starts, o) - 1
        if i < 0 or starts[i] % 2 == 0 or o - starts[i] >= 0x1000: continue   # only odd-start objects
        if not (SOUND_LO <= starts[i] < SOUND_HI): continue       # observed only for sound sequences
        # a regular array of pointers (same field in fixed-size records) is real even inside such a region
        if any((o + m * st) in acc and (o + 2 * m * st) in acc for st in range(4, 68, 4) for m in (-1, 1)): continue
        del acc[o]; amb[o] = (w, 'in_bytestream')
    return acc, amb
