#!/bin/sh
# Create and analyse the Ghidra project used by the decomp pipeline (one time, about 10-20 minutes).
# usage: tools/ghidra/setup.sh GHIDRA_DIR PROJECT_DIR PROJECT_NAME      (needs `make` first: imports log1.elf)
set -e
G=$1; P=$2; N=$3
mkdir -p "$P"
python3 tools/ghidra/veneer_sigs.py > /dev/null
# all labels are global symbols in the build (so the decomp build can reference them); make the local-label ones local again
# (_08XXXXXX) or Ghidra would start a function at every branch target
arm-none-eabi-objcopy --wildcard --localize-symbol='_0[0-9A-F]*' log1.elf .analysis/ghidra/log1_ghidra.elf
"$G/support/analyzeHeadless" "$P" "$N" -import log1.elf -processor ARM:LE:32:v4t -overwrite \
    -scriptPath tools/ghidra -preScript AddGbaMemory.java
# separate run without auto-analysis: otherwise the analyzers react to the fix-ups and re-mark the veneers noreturn
"$G/support/analyzeHeadless" "$P" "$N" -process -noanalysis \
    -scriptPath tools/ghidra -postScript FixFlow.java "$PWD/.analysis/ghidra/veneer_sigs.txt"
