#!/bin/bash
# cc.sh OUT.o SRC.c [gcc flags...]: compile Thumb C the way the decomp build needs it.
# Modern GCC always returns through `pop {rN}; bx rN` on ARMv4T (interworking). When rN is r0, that destroys the
# value ADS code leaves in r0 for its caller (ADS returns with `pop {..., pc}`), so rewrite that epilogue to
# `pop {pc}`. Every caller of these functions is Thumb code, so this is safe; the original code does the same.
set -o pipefail
out=$1; src=$2; shift 2
arm-none-eabi-gcc "$@" -S -o - "$src" \
  | sed -E 'N;s/\tpop\t\{(r[0-3])\}\n\tbx\t\1/\tpop\t{pc}/;P;D' \
  | arm-none-eabi-as -mcpu=arm7tdmi -o "$out" -
