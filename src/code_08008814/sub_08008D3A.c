/* sub_08008D3A  (original: 0x08008D3A-0x08008D8A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080095DC();
extern int sub_08008D14();
extern undefined2 volatile DAT_05000000;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08008D3A(byte *param_1,undefined4 param_2,undefined4 param_3,byte param_4,
                 undefined2 *param_5)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *param_1 = param_4;
  *(undefined2 *)(param_1 + 2) = *param_5;
  *(undefined2 *)(param_1 + 4) = param_5[1];
  *(undefined2 *)(param_1 + 6) = param_5[2];
  *(undefined2 *)(param_1 + 8) = param_5[3];
  REG_DMA3SAD = 0x815b928;
  REG_DMA3DAD = &DAT_05000000 + (uint)*param_1 * 0x10;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8000;
  uVar1 = sub_080095DC(0x815b2f0);
  REG_DMA3SAD = uVar1;
  REG_DMA3DAD = param_3;
  Ram040000dc = 0x690;
  DAT_040000de = 0x8000;
  sub_08008D14(param_1);
  return;
}

