/* sub_08007F4C  (original: 0x08007F4C-0x08008016 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 14% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080062FC();
extern int sub_0800BEEC();
extern int sub_0800ACFE();
extern int sub_08006294();
extern int sub_0800BEB8();
extern int sub_08002466();
extern undefined4 volatile DAT_03003b48;
extern undefined4 volatile DAT_03003b54;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_086B6068;


void sub_08007F4C(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((uint)*(byte *)(param_1 + 9) == (param_2 & 0xff)) {
    if (param_2 != 6) {
      return;
    }
  }
  else {
    if (3 < *(byte *)(param_1 + 9)) {
      *(undefined1 *)(param_1 + 10) = 0x2d;
    }
    *(char *)(param_1 + 9) = (char)param_2;
  }
  if ((param_2 == 7) && (*(short *)(param_1 + 0x9a) == 2)) {
    piVar1 = &DAT_030047f0;
    if (*(char *)(param_1 + 0xb) == '\x02') {
      piVar1 = &DAT_03003b54;
    }
    sub_080062FC(piVar1,param_1);
    sub_08006294(&DAT_03003b48,param_1);
  }
  iVar3 = *(int *)(param_1 + 0x274);
  if (param_2 == 6) {
    sub_0800BEB8(iVar3);
    sub_08002466(iVar3,0);
    if (*(byte *)(param_1 + 9) != 0) {
      if (3 < *(byte *)(param_1 + 9)) {
        *(undefined1 *)(param_1 + 10) = 0x2d;
      }
      *(undefined1 *)(param_1 + 9) = 0;
    }
    if (*(short *)(param_1 + 0x9a) == 2) {
      *(undefined1 *)(param_1 + 10) = 0x14;
      *(undefined2 *)(param_1 + 0x14) = 0x50;
    }
  }
  else if (param_2 == 7) {
    sub_0800BEEC(iVar3);
    sub_0800ACFE(0x17);
    *(undefined2 *)(param_1 + 0x88) = 7;
  }
  else {
    iVar2 = *(int *)(&gUnknown_086B6068 + param_2 * 4);
    if ((*(int *)(*(int *)(*(int *)(iVar3 + 0x1c) + 0x28) + iVar2 * 0x10) != 0) &&
       (*(int *)(*(int *)(iVar3 + 0x18) + iVar2 * 0x14) != 0)) {
      sub_08002466(iVar3,iVar2);
    }
  }
  return;
}

