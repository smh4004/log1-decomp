/* sub_08009486  (original: 0x08009486-0x080094B8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008E06();


void sub_08009486(int *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *param_1) {
    do {
      pbVar2 = (byte *)param_1[iVar3 + 1];
      bVar1 = pbVar2[1];
      *(ushort *)(param_2 + 10) = (ushort)*pbVar2;
      *(ushort *)(param_2 + 0xc) = (ushort)bVar1;
      sub_08008E06(param_2,*(byte **)(pbVar2 + 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  return;
}

