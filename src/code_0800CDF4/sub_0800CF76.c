/* sub_0800CF76  (original: 0x0800CF76-0x0800CF8E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 83% of instructions covered.
 */
#include "ghidra_types.h"
extern ushort volatile DAT_03003d14;


undefined4 sub_0800CF76(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if ((iVar1 != 0) && ((DAT_03003d14 & 1) == 0)) {
    return 0;
  }
  return 1;
}

