/* sub_08005526  (original: 0x08005526-0x08005542 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 3/3 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080054AE();
extern undefined1 volatile DAT_03000028;


void sub_08005526(uint param_1)

{
  (&DAT_03000028)[(int)param_1 >> 3] =
       (byte)(1 << (param_1 & 7)) | (&DAT_03000028)[(int)param_1 >> 3];
  sub_080054AE();
  return;
}

