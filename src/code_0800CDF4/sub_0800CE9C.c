/* sub_0800CE9C  (original: 0x0800CE9C-0x0800CF00 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_explore.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800CE9C(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  unsigned int __frame[260];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_410 ((ushort *)((char *)__frame + 0x0))
  iVar4 = *(int *)(param_1 + 4) * 0x400;
  iVar1 = 0;
  do {
    uVar3 = (uint)*(ushort *)(iVar1 * 2 + param_1 + 8);
    iVar2 = iVar1 + 1;
    local_410[iVar1] =
         (ushort)(((int)(iVar4 * ((uVar3 << 0x11) >> 0x1b)) >> 0x10) << 10) |
         (ushort)(iVar4 * (uVar3 & 0x1f) >> 0x10) |
         (ushort)(((int)(iVar4 * ((uVar3 << 0x16) >> 0x1b)) >> 0x10) << 5);
    iVar1 = iVar2;
  } while (iVar2 < 0x200);
  REG_DMA3SAD = local_410;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  return;
}

