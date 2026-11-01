#!/usr/bin/env python3
"""Sanity check for the equivalence tester: mutate accepted, fully covered functions and confirm the tester rejects them.
usage: mutation_check.py [N]"""
import sys, os, json, glob, random, pickle, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import autodecomp as A
N = int(sys.argv[1]) if len(sys.argv) > 1 else 25
st = json.load(open(A.B + '/status.json'))
db = pickle.load(open('.analysis/analysis.pickle', 'rb')); ins = sorted(db['insn'])
F = A.load_funcs()
acc = [(n, v) for n, v in st.items() if v['status'] == 'accepted' and v.get('coverage', 0) >= 1.0]
random.seed(5); random.shuffle(acc)
det = tot = 0
for n, v in acc:
    if tot >= N: break
    src = open('%s/tu/%s.c' % (A.B, n)).read()
    i = src.index('\n\n'); head, body = src[:i], src[i:]
    for a, b in (('+ 1', '+ 2'), ('- 1', '- 2'), (' + 4', ' + 8'), ('<', '<='), ('!= 0', '== 0'), ('== 0', '!= 0'), ('= 1;', '= 2;'), ('= 0;', '= 3;')):
        if a in body: m = head + body.replace(a, b, 1); break
    else: continue
    open('%s/tu/%s.c' % (A.B, n), 'w').write(m)
    try:
        if A.compile_one(n)[1]:
            snaps = sorted(glob.glob('%s/%08X_*.snap' % (A.SNAPDIR, v['addr'])))
            void = (F[n].get('sig') or '').startswith('void ')
            r = A.test_one((n, v['addr'], snaps, v['end'], bisect.bisect_left(ins, v['end']) - bisect.bisect_left(ins, v['addr']), void))[1]
            tot += 1; d = any(x not in ('equal', 'equal-r0dead', 'inconclusive') for x in r); det += d
            print('%-16s %-6s -> %-6s %-40s %s' % (n, a, b, r, 'DETECTED' if d else 'missed'))
    finally:
        open('%s/tu/%s.c' % (A.B, n), 'w').write(src); A.compile_one(n)
print('mutants detected: %d of %d' % (det, tot))
