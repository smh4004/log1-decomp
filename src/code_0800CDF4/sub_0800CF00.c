/* sub_0800CF00  (original: 0x0800CF00-0x0800CF10 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


bool sub_0800CF00(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  return iVar1 == 0;
}

