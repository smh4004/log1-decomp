/* sub_0800FE0C  (original: 0x0800FE0C-0x0800FE40 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 7/7 snapshots, 92% of instructions covered.
 */
#include "ghidra_types.h"


int * sub_0800FE0C(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      if (param_1[iVar1 * 6 + 1] == *param_2) {
        return param_1 + iVar1 * 6 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  return (int *)0x0;
}

