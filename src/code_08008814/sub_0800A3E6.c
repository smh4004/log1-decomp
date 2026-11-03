/* sub_0800A3E6  (original: 0x0800A3E6-0x0800A4C6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 96% of instructions covered.
 */
#include "ghidra_types.h"
extern byte volatile DAT_03003cfd;
extern byte volatile DAT_03003cfe;
extern ushort volatile DAT_03003d02;
extern int * volatile DAT_03003d08;
extern byte * volatile DAT_03003d0c;
extern undefined1 volatile DAT_0203ee3c;
extern undefined volatile DAT_0203ee3d;
extern undefined2 volatile DAT_08142386;


undefined4 sub_0800A3E6(void)
{
  undefined4 __r0 = 0;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  DAT_03003cfd = DAT_03003cfd + 1;
  if (DAT_03003cfe <= DAT_03003cfd) {
    iVar4 = (DAT_03003d02 + 1) * 0x10000;
    DAT_03003d02 = (ushort)((uint)iVar4 >> 0x10);
    if (*(char *)(DAT_03003d08[1] + (iVar4 >> 0x10)) == -1) {
      DAT_03003d02 = 0;
    }
    pbVar3 = *(byte **)(*DAT_03003d08 +
                       (uint)*(byte *)(DAT_03003d08[1] + (int)(short)DAT_03003d02) * 4);
    DAT_03003cfd = 0;
    DAT_03003cfe = *pbVar3;
    DAT_03003d0c = pbVar3 + 1;
  }
  iVar4 = 0;
  do {
    iVar5 = iVar4 * 0x24;
    iVar4 = iVar4 + 1;
    (&DAT_0203ee3c)[iVar5] = 0;
  } while (iVar4 < 0xf);
  while( true ) {
    pbVar3 = DAT_03003d0c;
    bVar1 = *DAT_03003d0c;
    DAT_03003d0c = DAT_03003d0c + 1;
    if (bVar1 == 0) break;
    iVar4 = ((bVar1 & 0xf) - 1) * 0x24;
    uVar2 = (uint)(bVar1 >> 4);
    if (uVar2 == 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = pbVar3 + 2;
      (&DAT_0203ee3d)[iVar4] = bVar1;
      (&DAT_0203ee3c)[iVar4] = bVar1;
    }
    else if (uVar2 == 1) {
      (&DAT_0203ee3c)[iVar4] = (&DAT_0203ee3d)[iVar4];
    }
    else {
      (&DAT_0203ee3c)[iVar4] = *(undefined1 *)((int)&DAT_08142386 + uVar2);
    }
    uVar2 = (uint)(byte)(&DAT_0203ee3c)[iVar4];
    if ((int)(uVar2 << 0x1f) < 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee3e) = bVar1;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee3f) = bVar1;
    }
    if ((int)(uVar2 << 0x1d) < 0) {
      bVar1 = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee40) = bVar1;
    }
    if ((int)(uVar2 << 0x1c) < 0) {
      pbVar3 = DAT_03003d0c + 1;
      *(byte *)(iVar4 + 0x203ee41) = *DAT_03003d0c;
      DAT_03003d0c = DAT_03003d0c + 2;
      *(byte *)(iVar4 + 0x203ee42) = *pbVar3;
    }
  }
  return __r0;
  return __r0;
}
