/* sub_08004832  (original: 0x08004832-0x080048FA in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_warp.txt (41 areas) before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_080045F8();
extern ushort volatile DAT_03000832;
extern ushort volatile DAT_03000830;
extern short volatile DAT_03000840;
extern ushort volatile DAT_0300082a;
extern ushort volatile DAT_03000828;
extern undefined4 volatile DAT_0202c224;
extern undefined volatile DAT_02035824;
extern undefined1 volatile DAT_02035825;
extern undefined volatile DAT_02035826;
extern undefined volatile DAT_0600a000;
extern undefined2 volatile REG_DISPCNT;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08004832(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  unsigned int __frame[133];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_214 ((ushort *)((char *)__frame + 0x0))
  if ((DAT_03000832 < DAT_03000830) && (iVar2 = sub_080045F8(0x3000824,0), iVar2 != 0)) {
    if (DAT_03000840 != 0) {
      iVar2 = 0;
      do {
        iVar1 = iVar2 * 3;
        iVar3 = iVar2 + 1;
        local_214[iVar2] =
             (ushort)((byte)(&DAT_02035826)[iVar1] >> 3) << 10 |
             (ushort)((byte)(&DAT_02035824)[iVar1] >> 3) |
             (ushort)((byte)(&DAT_02035825)[iVar1] >> 3) << 5;
        iVar2 = iVar3;
      } while (iVar3 < 0x100);
      REG_DMA3SAD = local_214;
      REG_DMA3DAD = 0x5000000;
      Ram040000dc = 0x100;
      DAT_040000de = 0x8000;
    }
    if (*(char *)(param_1 + 8) == '\0') {
      puVar4 = &DAT_0600a000;
    }
    else {
      puVar4 = (undefined *)0x6000000;
    }
    iVar2 = 0;
    if (DAT_0300082a != 0) {
      do {
        REG_DMA3SAD = (undefined4 *)((int)&DAT_0202c224 + iVar2 * (uint)DAT_03000828);
        REG_DMA3DAD = puVar4 + iVar2 * 0xf0;
        Ram040000dc = DAT_03000828 >> 1;
        DAT_040000de = 0x8000;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)DAT_0300082a);
    }
    if (*(char *)(param_1 + 8) == '\0') {
      REG_DISPCNT = 0x414;
    }
    else {
      REG_DISPCNT = 0x404;
    }
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) ^ 1;
  }
  return;
}

