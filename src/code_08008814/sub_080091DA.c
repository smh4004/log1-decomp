/* sub_080091DA  (original: 0x080091DA-0x080092A4 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_080091DA(byte *param_1,short *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar4 = ((int)param_2[2] - (int)*param_2) + -2;
  uVar1 = (ushort)*param_1 << 0xc;
  iVar2 = param_2[1] + 1;
  iVar3 = *param_2 * 2 + param_2[1] * 0x40;
  *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 100;
  puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      *puVar5 = uVar1 | 0x66;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  *puVar5 = uVar1 | 0x464;
  if (iVar2 < param_2[3] + -1) {
    do {
      iVar3 = iVar2 * 0x40;
      iVar2 = iVar2 + 1;
      iVar3 = *param_2 * 2 + iVar3;
      *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 0x67;
      *(ushort *)(param_1 + iVar4 * 2 + iVar3 + 0x26) = uVar1 | 0x467;
    } while (iVar2 < param_2[3] + -1);
  }
  iVar3 = *param_2 * 2 + iVar2 * 0x40;
  *(ushort *)(param_1 + iVar3 + 0x24) = uVar1 | 0x65;
  puVar5 = (ushort *)(param_1 + iVar3 + 0x26);
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      *puVar5 = uVar1 | 0x866;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  *puVar5 = uVar1 | 0x465;
  return;
}

