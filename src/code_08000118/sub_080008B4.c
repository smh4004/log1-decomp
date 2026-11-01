/* sub_080008B4  (original: 0x080008B4-0x0800091C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E4F8();
extern int sub_0800B368();
extern undefined1 volatile DAT_030007b0;
extern undefined2 volatile DAT_030007b2;
extern undefined4 volatile DAT_030007e0;
extern undefined4 volatile DAT_030007d8;
extern int volatile DAT_03000044;
extern int volatile DAT_03003b6c;
extern undefined1 volatile DAT_03000028;
extern undefined4 volatile DAT_02029b9c;
extern undefined1 volatile DAT_02029ba0;
extern undefined volatile DAT_02029bbc;


void sub_080008B4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0xa5) = DAT_030007b0;
  iVar4 = param_2 * 0xac;
  *(char *)(param_1 + 0xa6) = (char)DAT_030007b2;
  *(char *)(param_1 + 0xa4) = (char)DAT_030007e0;
  *(undefined4 *)(param_1 + 0xa0) = DAT_030007d8;
  sub_0800E4F8(&DAT_02029ba0 + iVar4,&DAT_03000028,0xa7);
  *(int *)(&DAT_02029bbc + iVar4) = DAT_03000044 + DAT_03003b6c;
  uVar1 = 0;
  uVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = (uVar1 >> 0x1d | uVar1 << 3) + (uint)DAT_03000028 + 1;
    uVar3 = uVar3 ^ uVar1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xa8);
  (&DAT_02029b9c)[param_2 * 0x2b] = uVar3;
  sub_0800B368(&DAT_02029b9c + param_2 * 0x2b,iVar4 + 0x2029c48);
  return;
}

