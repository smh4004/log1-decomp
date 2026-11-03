/* sub_08004466  (original: 0x08004466-0x0800453A in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_08004466(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  
  pbVar8 = *(byte **)(param_1 + 0x30);
  iVar5 = (uint)*param_2 + (uint)param_2[1] * 0x100;
  pbVar4 = param_2 + 2;
  while (iVar5 = iVar5 + -1, iVar5 != -1) {
    iVar6 = (uint)*pbVar4 + (uint)pbVar4[1] * 0x100;
    pbVar3 = pbVar4;
    while( true ) {
      iVar9 = iVar6 * 0x10000 >> 0x10;
      pbVar4 = pbVar3 + 2;
      pbVar7 = pbVar8;
      if ((uint)(iVar9 << 0x10) >> 0x1e == 0) break;
      if ((uint)(iVar9 << 0x10) >> 0x1e == 3) {
        pbVar8 = pbVar8 + -(iVar9 * (uint)*(ushort *)(param_1 + 4));
      }
      else if (iVar9 < 0) {
        pbVar8[*(ushort *)(param_1 + 4) - 1] = (byte)((uint)(iVar6 * 0x10000) >> 0x10);
      }
      iVar6 = (uint)*pbVar4 + (uint)pbVar3[3] * 0x100;
      pbVar3 = pbVar4;
    }
    while (iVar9 != 0) {
      iVar9 = (iVar9 + -1) * 0x10000 >> 0x10;
      pbVar7 = pbVar7 + *pbVar4;
      iVar6 = (int)(char)pbVar4[1];
      pbVar3 = pbVar4 + 2;
      if (iVar6 < 0) {
        bVar1 = pbVar4[2];
        bVar2 = pbVar4[3];
        pbVar4 = pbVar4 + 4;
        while (iVar6 = iVar6 + 1, iVar6 != 1) {
          *pbVar7 = bVar1;
          pbVar7[1] = bVar2;
          pbVar7 = pbVar7 + 2;
        }
      }
      else {
        for (; pbVar4 = pbVar3, iVar6 != 0; iVar6 = iVar6 + -1) {
          *pbVar7 = *pbVar4;
          pbVar7[1] = pbVar4[1];
          pbVar7 = pbVar7 + 2;
          pbVar3 = pbVar4 + 2;
        }
      }
    }
    pbVar8 = pbVar8 + *(ushort *)(param_1 + 4);
  }
  return;
}

