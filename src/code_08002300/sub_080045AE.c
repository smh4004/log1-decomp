/* sub_080045AE  (original: 0x080045AE-0x080045F8 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_explore.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"


void sub_080045AE(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = (uint)*(ushort *)(param_1 + 6);
  pbVar4 = *(byte **)(param_1 + 0x30);
  while (uVar6 != 0) {
    uVar6 = uVar6 - 1;
    uVar5 = (uint)*param_2;
    param_2 = param_2 + 1;
    while (uVar5 != 0) {
      uVar5 = uVar5 - 1;
      iVar2 = (int)(char)*param_2;
      pbVar3 = param_2 + 1;
      if (iVar2 < 0) {
        do {
          bVar1 = *pbVar3;
          pbVar3 = pbVar3 + 1;
          *pbVar4 = bVar1;
          pbVar4 = pbVar4 + 1;
          iVar2 = iVar2 + 1;
          param_2 = pbVar3;
        } while (iVar2 != 0);
      }
      else {
        bVar1 = *pbVar3;
        param_2 = param_2 + 2;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pbVar4 = bVar1;
          pbVar4 = pbVar4 + 1;
        }
      }
    }
  }
  return;
}

