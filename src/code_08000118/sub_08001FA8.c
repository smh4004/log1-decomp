/* sub_08001FA8  (original: 0x08001FA8-0x08002134 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 86% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08003232();
extern int sub_0800697E();
extern int sub_08003120();
extern int sub_080058D6();
extern int sub_0800A62C();
extern int sub_08002328();
extern int sub_08004F56();
extern int sub_0800F36C();
extern int sub_08009744();
extern int sub_0800428E();
extern int sub_080031E2();
extern int sub_0800D1A0();
extern int sub_080053F0();
extern int sub_0800252E();
extern byte volatile DAT_0300004c;
extern undefined4 volatile DAT_03000048;
extern int volatile DAT_030005fc;
extern undefined4 * volatile DAT_03000600;
extern byte * volatile DAT_03000604;
extern undefined4 volatile DAT_030005f0;
extern undefined4 volatile DAT_030005f4;
extern short volatile DAT_030005f6;
extern short volatile DAT_030005f8;
extern undefined * volatile DAT_030046b4;
extern undefined4 volatile DAT_030047f4;
extern undefined4 volatile DAT_030047f8;
extern undefined4 volatile DAT_030047f0;
extern undefined4 volatile DAT_03003b4c;
extern undefined4 volatile DAT_03003b50;
extern undefined4 volatile DAT_03003b48;
extern undefined4 volatile DAT_03003b58;
extern undefined4 volatile DAT_03003b5c;
extern undefined4 volatile DAT_03003b54;
extern undefined * volatile gUnknown_081CA09C;
extern int volatile DAT_030007b8;
extern short volatile DAT_03000608;
extern short volatile DAT_0300060a;
extern short volatile DAT_030005fa;
extern short volatile DAT_0300060c;
extern short volatile DAT_0300060e;
extern byte volatile DAT_03003b60;
extern undefined volatile DAT_02013224;
extern undefined4 volatile DAT_0300010c;
extern undefined volatile gUnknown_08591F3C;
#define _DAT_030005f0 (*(undefined4 volatile *)0x030005F0)
#define _DAT_030005f8 (*(undefined4 volatile *)0x030005F8)
#define _DAT_030005f4 (*(undefined4 volatile *)0x030005F4)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08001FA8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  unsigned int __frame[11];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_2c (*(short *)((char *)__frame + 0x0))
#define local_2a (*(undefined2 *)((char *)__frame + 0x2))
#define local_28 (*(short *)((char *)__frame + 0x4))
#define sStack_26 (*(short *)((char *)__frame + 0x6))
#define local_24 (*(undefined2 *)((char *)__frame + 0x8))
#define local_22 (*(undefined2 *)((char *)__frame + 0xa))
#define local_20 (*(short *)((char *)__frame + 0xc))
#define local_1e (*(undefined2 *)((char *)__frame + 0xe))
#define local_1c (*(undefined2 *)((char *)__frame + 0x10))
#define local_1a (*(undefined2 *)((char *)__frame + 0x12))
#define local_18 (*(undefined4 *)((char *)__frame + 0x14))
  DAT_0300004c = (undefined1)param_1;
  DAT_03000048 = *param_2;
  sub_080031E2();
  DAT_03000600 = (undefined4 *)(&gUnknown_081CA09C)[param_1];
  DAT_03000604 = (byte *)DAT_03000600[5];
  _DAT_030005f0 = *DAT_03000600;
  uVar1 = DAT_03000600[1];
  DAT_030005f4 = (short)uVar1;
  DAT_030005f6 = (short)((uint)uVar1 >> 0x10);
  local_18 = CONCAT22(DAT_030005f6 << 3,DAT_030005f4 << 3);
  _DAT_030005f8 = local_18;
  _DAT_030005f4 = uVar1;
  DAT_030005fc = param_1;
  sub_0800252E();
  DAT_030046b4 = &DAT_02013224;
  DAT_030047f4 = 0;
  DAT_030047f8 = 0;
  DAT_030047f0 = 0;
  DAT_03003b4c = 0;
  DAT_03003b50 = 0;
  DAT_03003b48 = 0;
  DAT_03003b58 = 0;
  DAT_03003b5c = 0;
  DAT_03003b54 = 0;
  sub_0800428E(0x3003b54);
  iVar2 = sub_08003232((short *)param_2);
  sub_08003120(iVar2);
  sub_08004F56((int)DAT_03000600);
  if (*DAT_03000604 != 0xffffffff) {
    sub_0800A62C((int)(&gUnknown_08591F3C + (uint)*DAT_03000604 * 0xc));
  }
  iVar2 = 0;
  if (0 < *(int *)(DAT_03000604 + 8)) {
    do {
      sub_080058D6((undefined2 *)(*(int *)(DAT_03000604 + 0xc) + iVar2 * 0xc));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(DAT_03000604 + 8));
  }
  iVar2 = 0;
  if (0 < *(int *)(DAT_03000604 + 0x10)) {
    do {
      puVar3 = (undefined4 *)(*(int *)(DAT_03000604 + 0x14) + iVar2 * 8);
      sub_0800D1A0(puVar3[1],puVar3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(DAT_03000604 + 0x10));
  }
  iVar2 = 0;
  if (0 < *(int *)(DAT_03000604 + 0x20)) {
    do {
      sub_0800697E((ushort *)(*(int *)(DAT_03000604 + 0x24) + iVar2 * 8));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(DAT_03000604 + 0x20));
  }
  sub_08002328((undefined4 *)&local_2c,DAT_030007b8);
  local_20 = local_2c;
  local_1e = local_2a;
  local_1c = local_28;
  local_1a = sStack_26;
  uVar1 = sub_0800F36C(&local_20);
  local_24 = 0x78;
  local_22 = 0x50;
  (*(undefined2 *)((char *)&local_18 + 0)) = (short)uVar1;
  (*(undefined2 *)((char *)&local_18 + 2)) = (short)((uint)uVar1 >> 0x10);
  local_28 = (short)local_18 + -0x78;
  sStack_26 = (*(undefined2 *)((char *)&local_18 + 2)) + -0x50;
  DAT_03000608 = local_28;
  if (local_28 < 0) {
    DAT_03000608 = 0;
  }
  DAT_0300060a = sStack_26;
  if (sStack_26 < 0) {
    DAT_0300060a = 0;
  }
  if (DAT_030005f8 + -0xf0 < (int)DAT_03000608) {
    DAT_03000608 = (short)(DAT_030005f8 + -0xf0);
  }
  if (DAT_030005fa + -0xa0 < (int)DAT_0300060a) {
    DAT_0300060a = (short)(DAT_030005fa + -0xa0);
  }
  DAT_0300060c = DAT_03000608 + 0xf0;
  DAT_0300060e = DAT_0300060a + 0xa0;
  local_18 = uVar1;
  sub_080053F0();
  DAT_03003b60 = 0;
  sub_08009744(&DAT_0300010c);
  return;
}

