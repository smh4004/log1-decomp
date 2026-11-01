/* sub_08004FFA  (original: 0x08004FFA-0x0800507A in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 95% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_02005040;


undefined4 sub_08004FFA(int param_1,short *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2[2] + 7 >> 3;
  iVar5 = (int)param_2[1] >> 3;
  iVar3 = param_2[3] + 7 >> 3;
  if (((((int)*param_2 >> 3 < 0) || (iVar5 < 0)) || (*(short *)(param_1 + 4) < iVar6)) ||
     (*(short *)(param_1 + 6) < iVar3)) {
    uVar1 = 0;
  }
  else {
    for (; iVar5 < iVar3; iVar5 = iVar5 + 1) {
      for (iVar2 = (int)*param_2 >> 3; iVar2 < iVar6; iVar2 = iVar2 + 1) {
        uVar4 = iVar5 * *(short *)(param_1 + 4) + iVar2;
        if (((uint)(byte)(&DAT_02005040)[((int)uVar4 >> 3) + param_3 * 0x1d4c] & 1 << (uVar4 & 7))
            == 0) {
          return 0;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}

