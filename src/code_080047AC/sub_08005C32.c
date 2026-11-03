/* sub_08005C32  (original: 0x08005C32-0x08005C5C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int volatile DAT_03000984;
extern int volatile DAT_03000988;
extern undefined volatile gUnknown_080114A8;


void sub_08005C32(int param_1)

{
  DAT_03000984 = param_1;
  DAT_03000988 = 0;
  while( true ) {
    if ((param_1 < *(int *)(&gUnknown_080114A8 + DAT_03000988 * 0x10)) ||
       (*(int *)(&gUnknown_080114A8 + DAT_03000988 * 0x10) == 0)) break;
    DAT_03000988 = DAT_03000988 + 1;
  }
  DAT_03000988 = DAT_03000988 + -1;
  return;
}

