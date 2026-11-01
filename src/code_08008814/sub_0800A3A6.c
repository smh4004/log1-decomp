/* sub_0800A3A6  (original: 0x0800A3A6-0x0800A3E6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 67% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern undefined * volatile gUnknown_08166734;


void sub_0800A3A6(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = *(byte *)((int)param_1 + 10) >> 2;
  *(byte *)((int)param_1 + 10) = bVar1 << 2;
  if ((int)((uint)bVar1 << 0x1f) < 0) {
    iVar3 = param_1[8];
    if (*(int *)(iVar3 + 0x2c) != *param_1) {
      *(int *)(iVar3 + 0x2c) = *param_1;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 2;
    }
  }
  if (*(byte *)(param_1 + 6) != 0) {
    uVar2 = (uint)*(byte *)((int)param_1 + 0x1d);
    if ((*(byte *)(param_1 + 6) & 0x88) == 0) {
      uVar2 = 0;
    }
    __call_via_r1(param_1,(&gUnknown_08166734)[uVar2],&gUnknown_08166734,0x88,param_4);
  }
  return;
}

