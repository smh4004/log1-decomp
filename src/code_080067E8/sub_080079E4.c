/* sub_080079E4  (original: 0x080079E4-0x08007A4E in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 28% of instructions covered.
 */
#include "ghidra_types.h"


undefined4 sub_080079E4(int param_1,int *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_4 == 0) {
    uVar1 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0xc);
    if (iVar4 == *(int *)(param_3 + 0x20)) {
      uVar1 = 1;
      *param_2 = 1;
    }
    else if (param_4 == 1) {
      uVar1 = 0;
    }
    else if (iVar4 == *(int *)(param_4 * 0x14 + param_3 + 0xc)) {
      uVar1 = 1;
      *param_2 = param_4;
    }
    else {
      iVar3 = 1;
      while (iVar5 = param_4, param_4 = iVar3 + iVar5 >> 1, iVar3 != param_4) {
        iVar2 = *(int *)(param_4 * 0x14 + param_3 + 0xc);
        if (iVar4 == iVar2) {
          *param_2 = param_4;
          return 1;
        }
        if (iVar2 <= iVar4) {
          iVar3 = param_4;
          param_4 = iVar5;
        }
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

