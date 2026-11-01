#!/usr/bin/env python3
"""End-to-end check of the modding toolkit (needs baserom.gba and the harness, about 2 minutes):
  1. fresh `make extract` + `make modern` with no edits -> byte-identical ROM
  2. event round trip (tools/scripts/roundtrip.py)
  3. demo_edits.py + `make modern`, then in the emulator (tools/harness/intro_test.txt):
     - the rewritten compressed narration is decompressed into RAM and shown
     - the new plain-text lines are in the ROM, and the screens that show them differ from the original game
     - the game still plays the whole smoke route (title -> intro -> walking -> menu) without leaving valid memory
Exits non-zero on any failure."""
import os, sys, subprocess, shutil, hashlib
os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
ok = True


def run(cmd):
    r = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    if r.returncode: print(r.stdout[-2000:], r.stderr[-2000:]); sys.exit('FAILED: ' + cmd)
    return r.stdout


def check(name, cond):
    global ok
    print('%-66s %s' % (name, 'ok' if cond else 'FAILED')); ok &= bool(cond)


def shots(rom, route, out):
    shutil.rmtree(out, ignore_errors=True); os.makedirs(out)
    return {l.split()[1]: l.split()[5] for l in run('tools/harness/harness %s %s %s' % (rom, route, out)).split('\n')
            if l.startswith('shot')}


shutil.rmtree('assets', ignore_errors=True); shutil.rmtree('build_modern', ignore_errors=True)
run('make -s harness && make -s && make -s extract && make -s modern')
sha = lambda p: hashlib.sha1(open(p, 'rb').read()).hexdigest()
check('unedited assets rebuild the original ROM', sha('log1_modern.gba') == sha('baserom.gba'))
check('all event steps reassemble (round trip)', 'OK' in run('python3 tools/scripts/roundtrip.py'))
ref = shots('log1.gba', 'tools/harness/intro_test.txt', 'build_modern/verify_ref')
run('python3 tools/assets/demo_edits.py && make -s modern')
new = shots('log1_modern.gba', 'tools/harness/intro_test.txt', 'build_modern/verify')
rom = open('log1_modern.gba', 'rb').read()
ew = open('build_modern/verify/n4_ew.bin', 'rb').read()
check('rewritten compressed narration is decompressed into RAM', b'Compressed text is recompressed on build.' in ew)
check('rewritten plain-text narration is in the ROM', b'rewritten with the script compiler!' in rom)
check('inserted event step is in the ROM', b'This line is a new step added to the event list.' in rom)
check('edited UI string is in the ROM', b'Outside Pepper Town (Legacy of Goku 4 edit)' in rom)
check('narration screens differ from the original game', all(new.get(k) != ref.get(k) for k in ('n3', 'n4', 'n6')))
out = run('(echo "guardon 08800000"; cat tools/harness/smoke.txt) > build_modern/smoke_guard.txt && '
          'tools/harness/harness log1_modern.gba build_modern/smoke_guard.txt build_modern/verify_smoke')
check('edited ROM plays the smoke route without a crash', 'bad pc' not in out and 's21_menu' in out)
print('ALL OK' if ok else 'SOME CHECKS FAILED'); sys.exit(0 if ok else 1)
