/* sub_08005E4C  (original: 0x08005E4C-0x08005E62 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 50% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002466();


void sub_08005E4C(int param_1)

{
  if ((*(int *)(param_1 + 0x24) == 2) && (0xf < *(byte *)(param_1 + 0x10))) {
    sub_08002466(param_1,0);
  }
  return;
}

