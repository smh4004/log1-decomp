/* sub_0800453A  (original: 0x0800453A-0x080045AE in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes game output on tools/harness/decomp_explore.txt (found by gamebisect.py).
 */
#include "ghidra_types.h"


int sub_0800453A(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  
  pbVar4 = param_2 + 4;
  iVar2 = (uint)param_2[2] + (uint)param_2[3] * 0x100;
  pbVar7 = (byte *)(*(int *)(param_1 + 0x30) +
                   ((uint)*param_2 + (uint)param_2[1] * 0x100) * (uint)*(ushort *)(param_1 + 4));
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    uVar6 = (uint)*pbVar4;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar7;
    while (uVar6 != 0) {
      uVar6 = uVar6 - 1;
      pbVar3 = pbVar3 + *pbVar4;
      iVar8 = (int)(char)pbVar4[1];
      pbVar5 = pbVar4 + 2;
      if (iVar8 < 0) {
        bVar1 = *pbVar5;
        pbVar4 = pbVar4 + 3;
        while (iVar8 = iVar8 + 1, iVar8 != 1) {
          *pbVar3 = bVar1;
          pbVar3 = pbVar3 + 1;
        }
      }
      else {
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          *pbVar3 = bVar1;
          pbVar3 = pbVar3 + 1;
          iVar8 = iVar8 + -1;
          pbVar4 = pbVar5;
        } while (iVar8 != 0);
      }
    }
    pbVar7 = pbVar7 + *(ushort *)(param_1 + 4);
  }
  return param_1;
  return param_1;   /* ADS constructor: returns this */
}
