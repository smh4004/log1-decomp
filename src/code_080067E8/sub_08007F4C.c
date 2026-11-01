/* sub_08007F4C  (original: 0x08007F4C-0x08008016 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_0800BEEC();
extern int sub_08006294();
extern int sub_080062FC();
extern int sub_08002466();
extern int sub_0800BEB8();
extern undefined4 volatile DAT_03003b48;
extern undefined4 volatile DAT_03003b54;
extern undefined4 volatile DAT_030047f0;
extern undefined volatile gUnknown_086B6068;


void sub_08007F4C(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
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
    puVar1 = &DAT_030047f0;
    if (*(char *)(param_1 + 0xb) == '\x02') {
      puVar1 = &DAT_03003b54;
    }
    sub_080062FC(puVar1,param_1);
    sub_08006294(&DAT_03003b48,param_1);
  }
  iVar2 = *(int *)(param_1 + 0x274);
  if (param_2 == 6) {
    sub_0800BEB8(iVar2);
    sub_08002466(iVar2,0);
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
    sub_0800BEEC(iVar2);
    sub_0800ACFE(0x17);
    *(undefined2 *)(param_1 + 0x88) = 7;
  }
  else if ((*(int *)(*(int *)(*(int *)(iVar2 + 0x1c) + 0x28) +
                    *(int *)(&gUnknown_086B6068 + param_2 * 4) * 0x10) != 0) &&
          (*(int *)(*(int *)(iVar2 + 0x18) + *(int *)(&gUnknown_086B6068 + param_2 * 4) * 0x14) != 0
          )) {
    sub_08002466(iVar2);
  }
  return;
}

