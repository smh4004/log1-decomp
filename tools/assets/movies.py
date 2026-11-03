"""The intro movies as FLI files and PNG frames (used by assets.py). Legacy of Goku.

The three movies are Autodesk FLI animations (type 0xAF11, 120x80, 8 bits per pixel) stored as they are; the player
(sub_080045F8) understands the FLI/FLC chunks 4 (256-colour palette), 11 (64-level palette), 12 (line delta),
7 (word delta), 15 (byte run), 13 (black) and 16 (raw copy).

assets/movies/movieN.fli          the movie file (any FLI/FLC player or converter reads it)
assets/movies/movieN/frameNNN.png one indexed PNG per frame, in that frame's palette
Edit either:
  * a replacement movieN.fli (120x80, 8 bpp, FLI or FLC) is used as it is;
  * changed frame PNGs are re-encoded into FLI (256-colour palette chunks when the palette changes, then the smaller of
    byte run or line delta); you can also add or delete frame files (keep the numbering continuous).
A movie that grows is placed at the end of the data and only the game's pointer to it changes.
"""
import os, struct, glob
import numpy as np

ROM = 0x08000000
W, H = 120, 80
# movie start (ROM offset) and the ROM offset of the word that points to it
MOVIES = [(0x1CA168, None), (0x337248, None), (0x4E4F44, None)]


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def movie_refs(d):
    out = []
    for o, _ in MOVIES:
        p = struct.pack('<I', o + ROM); r = d.find(p)
        while r % 4: r = d.find(p, r + 1)
        out.append((o, r))
    return out


def decode(fli):
    """-> list of (frame index array HxW, palette 256x3 0-255)"""
    size, typ, nframes, w, h = struct.unpack_from('<IHHHH', fli, 0)
    if typ not in (0xAF11, 0xAF12) or (w, h) != (W, H): raise ValueError('not a 120x80 FLI/FLC')
    six = typ == 0xAF11
    pix = np.zeros((h, w), np.uint8); pal = np.zeros((256, 3), np.uint8)
    out = []; p = 128
    for f in range(nframes):
        fsize, magic, nch = struct.unpack_from('<IHH', fli, p)
        if magic == 0xF100: p += fsize; fsize, magic, nch = struct.unpack_from('<IHH', fli, p)
        if magic != 0xF1FA: raise ValueError('frame %d: bad magic' % f)
        c = p + 16
        for _ in range(nch):
            csize, ctype = struct.unpack_from('<IH', fli, c); b = c + 6
            if ctype in (4, 11):
                n = struct.unpack_from('<H', fli, b)[0]; q = b + 2; idx = 0
                for _ in range(n):
                    idx += fli[q]; cnt = fli[q + 1] or 256; q += 2
                    for _ in range(cnt):
                        v = np.frombuffer(fli[q:q + 3], np.uint8)
                        pal[idx] = (v << 2) if ctype == 11 else v; idx += 1; q += 3
            elif ctype == 15:
                q = b
                for y in range(h):
                    q += 1; x = 0
                    while x < w:
                        k = struct.unpack_from('b', fli, q)[0]; q += 1
                        if k < 0: pix[y, x:x - k] = np.frombuffer(fli[q:q - k], np.uint8); q -= k; x -= k
                        else: pix[y, x:x + k] = fli[q]; q += 1; x += k
            elif ctype == 12:
                y, n = struct.unpack_from('<HH', fli, b); q = b + 4
                for _ in range(n):
                    pk = fli[q]; q += 1; x = 0
                    for _ in range(pk):
                        x += fli[q]; k = struct.unpack_from('b', fli, q + 1)[0]; q += 2
                        if k < 0: pix[y, x:x - k] = fli[q]; q += 1; x -= k
                        else: pix[y, x:x + k] = np.frombuffer(fli[q:q + k], np.uint8); q += k; x += k
                    y += 1
            elif ctype == 7:
                n = struct.unpack_from('<H', fli, b)[0]; q = b + 2; y = 0
                for _ in range(n):
                    while True:
                        wd = struct.unpack_from('<h', fli, q)[0]; q += 2
                        if (wd & 0xC000) == 0xC000: y -= wd
                        elif wd & 0x8000: pix[y, w - 1] = wd & 0xFF
                        else: break
                    x = 0
                    for _ in range(wd):
                        x += fli[q]; k = struct.unpack_from('b', fli, q + 1)[0]; q += 2
                        if k < 0:
                            pair = fli[q:q + 2]; q += 2
                            for _ in range(-k): pix[y, x:x + 2] = np.frombuffer(pair, np.uint8); x += 2
                        else:
                            pix[y, x:x + 2 * k] = np.frombuffer(fli[q:q + 2 * k], np.uint8); q += 2 * k; x += 2 * k
                    y += 1
            elif ctype == 13: pix[:] = 0
            elif ctype == 16: pix[:] = np.frombuffer(fli[b:b + w * h], np.uint8).reshape(h, w)
            c += csize
        out.append((pix.copy(), pal.copy()))
        p += fsize
    return out


def brun(img):
    out = bytearray()
    for row in img:
        line = bytearray(); x = 0; n = 0; row = bytes(row)
        while x < W:
            r = 1
            while x + r < W and r < 127 and row[x + r] == row[x]: r += 1
            if r >= 3:
                line += struct.pack('b', r) + row[x:x + 1]; x += r
            else:
                s = x
                while x < W and x - s < 127 and not (x + 2 < W and row[x] == row[x + 1] == row[x + 2]): x += 1
                line += struct.pack('b', -(x - s)) + row[s:x]
            n += 1
        out += bytes([min(n, 255)]) + line
    return bytes(out)


def lc(prev, img):
    rows = [y for y in range(H) if not np.array_equal(prev[y], img[y])]
    if not rows: return None
    y0, y1 = rows[0], rows[-1]
    out = bytearray(struct.pack('<HH', y0, y1 - y0 + 1))
    for y in range(y0, y1 + 1):
        a, b = bytes(prev[y]), bytes(img[y]); pk = bytearray(); np_ = 0; x = 0; last = 0
        while x < W:
            if a[x] == b[x]: x += 1; continue
            s = x
            while x < W and x - s < 127 and (a[x] != b[x] or (x + 1 < W and a[x + 1] != b[x + 1])): x += 1
            skip = s - last
            while skip > 255:            # long skip: an empty copy packet
                pk += bytes([255, 0]); skip -= 255; np_ += 1
            pk += bytes([skip]) + struct.pack('b', x - s) + b[s:x]; np_ += 1; last = x
        out += bytes([np_]) + pk
    return bytes(out)


def chunk(t, data):
    data = data + bytes(len(data) & 1)
    return struct.pack('<IH', 6 + len(data), t) + data


def encode(frames, speed=7):
    """frames: list of (index array, palette 256x3 0-255) -> FLI bytes (with the ring frame)"""
    body = bytearray(); prev = np.zeros((H, W), np.uint8); prevpal = None
    seq = list(frames) + [frames[0]]
    for i, (img, pal) in enumerate(seq):
        chunks = []
        pal8 = np.asarray(pal, np.uint8)
        if prevpal is None or not np.array_equal(pal8, prevpal):
            chunks.append(chunk(4, struct.pack('<H', 1) + bytes([0, 0]) + pal8.tobytes()))
            prevpal = pal8
        img = np.asarray(img, np.uint8)
        if i == 0: chunks.append(chunk(15, brun(img)))
        else:
            d1 = lc(prev, img); b1 = brun(img)
            if d1 is not None: chunks.append(chunk(12, d1) if len(d1) < len(b1) else chunk(15, b1))
        fr = b''.join(chunks)
        body += struct.pack('<IHH8x', 16 + len(fr), 0xF1FA, len(chunks)) + fr
        prev = img
    hdr = struct.pack('<IHHHHHHI', 128 + len(body), 0xAF11, len(frames), W, H, 8, 0, speed) + bytes(108)
    return hdr + bytes(body)


def extract(d, out, reg):
    from PIL import Image
    md = os.path.join(out, 'movies'); os.makedirs(md, exist_ok=True)
    for i, (o, ref) in enumerate(movie_refs(d)):
        size = u32(d, o); fli = d[o:o + size]
        p = os.path.join(md, 'movie%d.fli' % (i + 1)); open(p, 'wb').write(fli)
        fd = os.path.join(md, 'movie%d' % (i + 1)); os.makedirs(fd, exist_ok=True)
        files = []
        for k, (img, pal) in enumerate(decode(fli)):
            f = os.path.join(fd, 'frame%03d.png' % k)
            im = Image.fromarray(img, 'P'); im.putpalette(pal.reshape(-1).tolist()); im.save(f); files.append(f)
        reg('movie:%d' % (i + 1), p, kind='movie', movie=i, start=o, ref=ref,
            frames=[[os.path.relpath(f, out), __import__('hashlib').sha1(open(f, 'rb').read()).hexdigest()] for f in files])


def build(d, a, path, ctx, src):
    from PIL import Image
    import hashlib
    o, ref = a['start'], a['ref']; size = u32(d, o)
    fli = open(path, 'rb').read()
    fd = os.path.join(os.path.dirname(path), 'movie%d' % (a['movie'] + 1))
    files = sorted(glob.glob(os.path.join(fd, 'frame*.png')))
    changed_frames = [os.path.relpath(f, src) for f in files] != [x[0] for x in a['frames']] or any(
        hashlib.sha1(open(f, 'rb').read()).hexdigest() != h for f, (_, h) in zip(files, a['frames']))
    if fli == d[o:o + size] and changed_frames:
        frames = []
        for f in files:
            im = Image.open(f)
            if im.mode != 'P' or im.size != (W, H): raise SystemExit('%s: must be a 120x80 indexed PNG' % f)
            pal = np.array((im.getpalette() + [0] * 768)[:768], np.uint8).reshape(256, 3)
            frames.append((np.array(im, np.uint8), pal))
        fli = encode(frames, struct.unpack_from('<I', d, o + 16)[0])
    if fli == d[o:o + size]: return
    decode(fli)                              # validate
    if len(fli) <= size:
        ctx['put'](o, o + len(fli), fli, 'movie')
    else:
        lab = ctx['new']('gMovie%d' % (a['movie'] + 1), fli)
        ctx['put_s'](ref, ref + 4, '\t.4byte %s\n' % lab, 4, 'movieptr')
