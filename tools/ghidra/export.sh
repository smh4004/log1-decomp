#!/bin/sh
# Re-export Ghidra output from an analysed project.
# usage: tools/ghidra/export.sh GHIDRA_DIR PROJECT_DIR PROJECT_NAME
# Writes .analysis/ghidra/{functions.jsonl, c/*.c, c/index.tsv} (derived from the ROM: git-ignored).
# First-time project setup is in docs/decomp.md (import log1.elf as ARM v4T LE, run AddGbaMemory.java, auto-analyse).
set -e
G=$1; P=$2; N=$3
OUT=.analysis/ghidra; mkdir -p $OUT
ls asm/code_*.s | sed 's/.*code_\([0-9A-F]*\)\.s/\1/' | sort > $OUT/starts.txt
python3 - $OUT <<'PY'
import sys
o = sys.argv[1]; s = [l.strip() for l in open(o + '/starts.txt')]
with open(o + '/ranges.txt', 'w') as f:
    for i, a in enumerate(s):
        e = s[i + 1] if i + 1 < len(s) else '0800FE40'
        f.write('code_%s %s %s\n' % (a, a, e))
PY
"$G/support/analyzeHeadless" "$P" "$N" -process -noanalysis -readOnly -scriptPath tools/ghidra \
    -postScript ExportFunctions.java "$PWD/$OUT/functions.jsonl" \
    -postScript ExportDecomp.java "$PWD/$OUT/c" "$PWD/$OUT/ranges.txt"
