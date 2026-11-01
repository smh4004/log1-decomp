#!/bin/sh
# Relocation test: build a SHIFT=n ROM, run the same input script on it and on the matching ROM,
# and compare per-checkpoint frame hashes. Usage: tools/harness/shift_test.sh [shift] [script]
set -e
SHIFT=${1:-0x100}
SCRIPT=${2:-tools/harness/long.txt}
make -s harness
make -s
make -s SHIFT=$SHIFT
O=build_shift/test; rm -rf $O; mkdir -p $O/base $O/shift
tools/harness/harness log1.gba $SCRIPT $O/base > $O/base.log
tools/harness/harness log1_shift.gba $SCRIPT $O/shift > $O/shift.log
paste $O/base.log $O/shift.log | awk '/^shot/ { n++; if ($6 == $12) same++; else { diff++; print "DIFF", $2 } }
  END { printf "checkpoints %d, identical %d, different %d\n", n, same, diff }'
