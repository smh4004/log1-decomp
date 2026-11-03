"""Instrument and sound samples as WAV files (used by assets.py). Legacy of Goku.

gSampleTable (0x08591E4C): 20 records {u32 -> 8-bit signed PCM, u16 loop (0 = none, 1/3 = loops), u16 loop start,
u16 length, u16 sample rate (Hz)}; the music track table follows (gTrackTable 0x08591F3C, 18 x {-> pattern list,
-> order list, u8 tempo, u8}; its pattern format is not decoded yet).

assets/sound/sampleNN.wav   mono 8-bit WAV at the sample's own rate
assets/sound/samples.json   loop, loop_start (in samples) and rate for each
A replacement WAV can be any length and rate (mono or stereo, 8 or 16 bit; stereo is mixed down). The length and rate
in the record follow the file (rate from the WAV header); a longer sample is moved to the end of the data.
"""
import os, json, struct, wave
import numpy as np
import labels as L

ROM = 0x08000000
SAMPLES, N_SAMPLES, REC = 0x591E4C, 20, 12


def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def read(d, k):
    p, loop, ls, ln, rate = struct.unpack_from('<IHHHH', d, SAMPLES + REC * k)
    return p - ROM, loop, ls, ln, rate


def extract(d, out, reg):
    sd = os.path.join(out, 'sound'); os.makedirs(sd, exist_ok=True)
    meta = []
    for k in range(N_SAMPLES):
        o, loop, ls, ln, rate = read(d, k)
        pcm = (np.frombuffer(d[o:o + ln], np.int8).astype(np.int16) + 128).astype(np.uint8)
        p = os.path.join(sd, 'sample%02d.wav' % k)
        with wave.open(p, 'wb') as w:
            w.setnchannels(1); w.setsampwidth(1); w.setframerate(rate); w.writeframes(pcm.tobytes())
        reg('sample:%02d' % k, p, kind='sample', sample=k)
        meta.append(dict(sample=k, loop=loop, loop_start=ls, rate=rate, length=ln))
    p = os.path.join(sd, 'samples.json')
    open(p, 'w').write('[\n' + ',\n'.join(' ' + json.dumps(m) for m in meta) + '\n]\n')
    reg('samples', p, kind='samples')


def read_wav(path):
    with wave.open(path, 'rb') as w:
        ch, sw, rate, n = w.getnchannels(), w.getsampwidth(), w.getframerate(), w.getnframes()
        raw = w.readframes(n)
    if sw == 1: a = np.frombuffer(raw, np.uint8).astype(np.int32) - 128
    elif sw == 2: a = np.frombuffer(raw, '<i2').astype(np.int32) >> 8
    else: raise SystemExit('%s: use 8- or 16-bit WAV' % path)
    a = a.reshape(-1, ch).mean(axis=1).round().astype(np.int32)
    return np.clip(a, -128, 127).astype(np.int8).tobytes(), rate


def build(d, a, path, ctx, src):
    """sample WAVs and samples.json are applied together (both are read here, once)"""
    if ctx.get('samples_done'): return
    ctx['samples_done'] = True
    sd = os.path.dirname(path)
    meta = {m['sample']: m for m in json.load(open(os.path.join(sd, 'samples.json')))}
    for k in range(N_SAMPLES):
        o, loop, ls, ln, rate = read(d, k)
        data, wrate = read_wav(os.path.join(sd, 'sample%02d.wav' % k))
        m = meta.get(k, {})
        nloop, nls = m.get('loop', loop), m.get('loop_start', ls)
        nrate = wrate if data != d[o:o + ln] else m.get('rate', rate)
        if len(data) > 0xFFFF: raise SystemExit('sample%02d.wav: at most 65535 samples' % k)
        rec = SAMPLES + REC * k
        if data != d[o:o + ln]:
            if len(data) <= ln:
                ctx['put'](o, o + ln, data + bytes(ln - len(data)), 'pcm')
            else:
                lab = ctx['new']('gSample%02d' % k, data)
                ctx['put_s'](rec, rec + 4, '\t.4byte %s\n' % lab, 4, 'pcmptr')
        hdr = struct.pack('<HHHH', nloop, nls, len(data), nrate)
        if hdr != d[rec + 4:rec + 12]: ctx['put'](rec + 4, rec + 12, hdr, 'pcmhdr')
