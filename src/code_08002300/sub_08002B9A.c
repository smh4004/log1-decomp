/* sub_08002B9A  (original: 0x08002B9A-0x08002BB0 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 50% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002466();


void sub_08002B9A(int param_1)

{
  if ((*(int *)(param_1 + 0x24) == 2) && (0xf < *(byte *)(param_1 + 0x10))) {
    sub_08002466(param_1,0);
  }
  return;
}

