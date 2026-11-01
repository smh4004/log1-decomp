#!/usr/bin/env python3
"""Self-test: export every event list, then (1) compile it back unedited (must give no overrides) and (2) re-encode
every step from its text (must give the original bytes; compressed text and pointer steps are compared by content)."""
import sys, os, struct, tempfile, collections
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [HERE, os.path.join(HERE, '..', 'assets'), os.path.join(HERE, '..', 'wfz')]
os.chdir(os.path.join(HERE, '..', '..'))
import events as E, l2script as B
d = open('baserom.gba', 'rb').read()
banks = None
lists = E.find_lists(d); names = B.load_names()
owner = {}
for o, it, tm in lists:
    for t in it: owner.setdefault(t, o)
tmp = tempfile.mkdtemp(); bad = 0; kinds = collections.Counter()
for o, it, tm in lists:
    txt = E.export_list(d, o, it, tm, banks, names, owner)
    if E.compile_list(d, o, it, tm, txt, names, lambda s: 1 / 0, tmp, 't'):
        bad += 1; print('unedited list produced overrides:', hex(o))
    for s, t in zip(E.parse_evt(txt), it):
        kinds[s['kind']] += 1
        if s['kind'] != 'ref':
            data = E.step_bytes(s, names, None)
            if not E.same_step(d, t, s, data): bad += 1; print('mismatch', hex(t), s['kind'])
print('%d lists, %d steps %s: %s' % (len(lists), sum(len(i) for _, i, _ in lists), dict(kinds), 'OK' if not bad else '%d FAILURES' % bad))
sys.exit(1 if bad else 0)
