/* sub_08003750  (original: 0x08003750-0x080037F6 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08005EA6();
extern int sub_08002486();
extern int sub_080095DC();
extern uint volatile DAT_030007ec;
extern int volatile DAT_030007e8;
extern undefined4 volatile DAT_03000994;
extern undefined * volatile PTR_sub_08002910_1_08010868;
extern undefined volatile gUnknown_0815A709;
extern undefined * volatile gUnknown_085C0C80;
extern undefined * volatile gUnknown_0815A4E8;


void sub_08003750(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  int *piVar6;
  
  if (DAT_030007ec != 0) {
    uVar2 = (uint)*(byte *)(*(int *)(param_1 + 0x10) + 0xd);
    (&DAT_03000994)[uVar2 * 2] = (&DAT_03000994)[uVar2 * 2] + -1;
  }
  piVar6 = (int *)(&gUnknown_0815A4E8)[*(byte *)(param_1 + 4)];
  if (piVar6 == (int *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
  }
  else {
    uVar1 = sub_08005EA6(*piVar6);
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0xd) = uVar1;
    uVar3 = sub_080095DC((int)piVar6);
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = uVar3;
  }
  DAT_030007ec = (uint)(piVar6 != (int *)0x0);
  uVar2 = 0;
  if ((*(char *)(param_1 + 8) == '\x01') || (*(char *)(param_1 + 8) == '\x02')) {
    uVar2 = (uint)*(byte *)(param_1 + 6);
  }
  if (DAT_030007e8 != 0) {
    uVar4 = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0xd);
    (&DAT_03000994)[uVar4 * 2] = (&DAT_03000994)[uVar4 * 2] + -1;
  }
  DAT_030007e8 = 0;
  puVar5 = (&gUnknown_085C0C80)[(byte)(&gUnknown_0815A709)[*(byte *)(param_1 + 4)]];
  if (((puVar5 != (undefined *)0x0) && (*(int *)(*(int *)(puVar5 + 0x28) + uVar2 * 0x10) != 0)) &&
     ((&PTR_sub_08002910_1_08010868)[uVar2 * 5] != (undefined *)0x0)) {
    sub_08002486(*(int *)(param_1 + 0xc),(int)puVar5,&PTR_sub_08002910_1_08010868,uVar2);
    DAT_030007e8 = 1;
  }
  return;
}

