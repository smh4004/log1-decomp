/* sub_080024B8  (original: 0x080024B8-0x0800252E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08005EA6();
extern int __call_via_r1();
extern int sub_0800BEA8();
extern undefined4 volatile DAT_03000994;


void sub_080024B8(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = sub_0800BEA8();
  uVar4 = *(byte *)(param_1 + 0xd) & 0xf;
  if (iVar2 != 0) {
    uVar4 = (uint)(*(byte *)(param_1 + 0xd) >> 4);
  }
  (&DAT_03000994)[uVar4 * 2] = (&DAT_03000994)[uVar4 * 2] + -1;
  if (param_3 == 0) {
    param_3 = *(int *)(param_1 + 0x18);
  }
  *(int *)(param_1 + 0x1c) = param_2;
  *(int *)(param_1 + 0x18) = param_3;
  uVar1 = sub_08005EA6(*(undefined4 *)(param_2 + 0x24));
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0x1c) + 0x28) + param_4 * 0x10;
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0x18) + param_4 * 0x14);
  *(undefined4 **)(param_1 + 0x34) = puVar3;
  __call_via_r1(param_1,*puVar3);
  if (iVar2 != 0) {
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + 1;
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | *(byte *)(param_1 + 0xd) << 4;
  }
  return;
}

