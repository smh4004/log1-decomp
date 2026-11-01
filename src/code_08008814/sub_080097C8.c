/* sub_080097C8  (original: 0x080097C8-0x080097F8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 2/11 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern byte volatile DAT_03003b60;
extern int * volatile DAT_03003b64;
extern undefined volatile DAT_03003b70;


void sub_080097C8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_03003b64;
  uVar2 = (uint)DAT_03003b60;
  DAT_03003b60 = DAT_03003b60 + 1;
  *(int **)(&DAT_03003b70 + uVar2 * 4) = DAT_03003b64;
  iVar3 = *piVar1;
  iVar4 = *(int *)(iVar3 + 4);
  __call_via_r1(piVar1,iVar4 + iVar3,iVar4,param_4,param_4);
  __call_via_r1(param_1,*(int *)*param_1 + *param_1);
  DAT_03003b64 = param_1;
  return;
}

