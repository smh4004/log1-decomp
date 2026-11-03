/* sub_080042F4  (original: 0x080042F4-0x080043AC in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 85% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800E640();
extern ushort volatile DAT_030047e8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


undefined4 sub_080042F4(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x1c;
  DAT_040000de = 0x8100;
  if ((param_3 == 1) || (param_3 == 2)) {
    if ((*(short *)(param_2 + 4) == -0x50ef) || (*(short *)(param_2 + 4) == -0x50ee)) {
      uVar1 = *(ushort *)(param_2 + 8);
      *(ushort *)(param_1 + 4) = uVar1;
      uVar2 = *(ushort *)(param_2 + 10);
      *(ushort *)(param_1 + 6) = uVar2;
      *(uint *)(param_1 + 8) = (uint)uVar2 * (uint)uVar1;
      *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 6);
      if (*(short *)(param_2 + 4) == -0x50ef) {
        *(undefined2 *)(param_1 + 0x10) = 1;
      }
      else {
        *(undefined2 *)(param_1 + 0x10) = 2;
      }
      *(undefined2 *)(param_1 + 0x12) = 8;
      if (*(short *)(param_1 + 0x10) == 1) {
        uVar5 = 1000;
        if (*(ushort *)(param_2 + 0x10) != 0) {
          uVar5 = (uint)*(ushort *)(param_2 + 0x10) * 1000;
        }
        uVar3 = sub_0800E640(0x46,uVar5);
        *(undefined4 *)(param_1 + 0x14) = uVar3;
      }
      else {
        *(uint *)(param_1 + 0x14) = (uint)*(ushort *)(param_2 + 0x10);
      }
      iVar4 = param_2 + 0x80;
      *(int *)(param_1 + 0x34) = iVar4;
      *(int *)(param_1 + 0x24) = iVar4;
      *(int *)(param_1 + 0x28) = iVar4;
      *(int *)(param_1 + 0x2c) = iVar4;
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

