/* sub_080037F6  (original: 0x080037F6-0x08003880 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_08005EA6();
extern int sub_0800245A();
extern int sub_080090AE();
extern int sub_08002716();
extern int sub_08003750();
extern int sub_08008D14();
extern int sub_0800252E();
extern undefined4 volatile DAT_030007ec;
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_08010858;
extern undefined volatile DAT_08010860;
extern undefined * volatile PTR_sub_080035B0_1_080109bc;
extern undefined * volatile gUnknown_08011480;
extern undefined * volatile gUnknown_0815A4E8;


void sub_080037F6(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  
  DAT_030007ec = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  sub_08008D14(&DAT_0202a5b8);
  sub_080090AE(&DAT_0202a5b8,(short *)&DAT_08010858);
  sub_080090AE(&DAT_0202a5b8,(short *)&DAT_08010860);
  sub_08008D8A(0x202a5b8);
  iVar2 = sub_0800252E();
  iVar2 = sub_08002716(iVar2);
  *(int *)(param_1 + 0xc) = iVar2;
  iVar2 = sub_08002716(iVar2);
  *(int *)(param_1 + 0x10) = iVar2;
  uVar3 = sub_08002716(iVar2);
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  puVar4 = *(undefined2 **)(param_1 + 0x10);
  *puVar4 = 200;
  puVar4[1] = 8;
  sub_0800245A(*(int *)(param_1 + 0x10),&gUnknown_08011480);
  uVar1 = sub_08005EA6(*(int *)(&gUnknown_0815A4E8)[*(byte *)(param_1 + 4)]);
  *(undefined1 *)(*(int *)(param_1 + 0x10) + 0xd) = uVar1;
  uVar1 = sub_08005EA6(0x80109d0);
  *(undefined1 *)(*(int *)(param_1 + 0x14) + 0xd) = uVar1;
  sub_0800245A(*(int *)(param_1 + 0x14),&PTR_sub_080035B0_1_080109bc);
  sub_08003750(param_1);
  return;
}

