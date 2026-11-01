/* sub_08004AB2  (original: 0x08004AB2-0x08004B14 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08005BBC();
extern int sub_08005C32();
extern int sub_08005BFE();
extern int sub_08002FF6();
extern int sub_08008CE8();
extern int sub_08004E98();
extern int volatile DAT_030007d8;
extern int volatile DAT_030007b8;
extern undefined4 volatile DAT_03000864;


void sub_08004AB2(int param_1)

{
  int iVar1;
  int iVar2;
  unsigned int __frame[19];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_4c ((undefined1 *)((char *)__frame + 0x0))
  sub_08008CE8(auStack_4c,"You receive %d experience points!",*(undefined4 *)(param_1 + 4));
  sub_08004E98(&DAT_03000864,auStack_4c);
  DAT_030007d8 = DAT_030007d8 + *(int *)(param_1 + 4);
  iVar2 = *(int *)(DAT_030007b8 + 0x3c);
  iVar1 = *(int *)(iVar2 + 0x84) + *(int *)(param_1 + 4);
  *(int *)(iVar2 + 0x84) = iVar1;
  sub_08005C32(iVar1);
  iVar1 = sub_08005BFE(iVar2);
  if (iVar1 != 0) {
    sub_08005BBC();
    sub_08002FF6();
  }
  return;
}

