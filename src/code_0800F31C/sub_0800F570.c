/* sub_0800F570  (original: 0x0800F570-0x0800F588 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


int sub_0800F570(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1 - param_3;
  iVar3 = -iVar1;
  if (-1 < iVar1) {
    iVar3 = iVar1;
  }
  iVar2 = param_2 - param_4;
  iVar1 = -iVar2;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  return iVar3 + iVar1;
}

