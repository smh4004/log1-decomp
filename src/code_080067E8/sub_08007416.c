/* sub_08007416  (original: 0x08007416-0x0800755A in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 81% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005CA8();
extern int sub_08005BFE();
extern int sub_0800ACFE();
extern int sub_08007352();
extern int sub_08005BBC();
extern int sub_08007F4C();
extern int sub_0800BEB8();
extern int sub_08005C32();
extern int volatile DAT_03003b6c;
extern int volatile DAT_03000c1c;


void sub_08007416(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uStack_18;
  
  if (*(short *)(param_2 + 0x14) == 0) {
    if (*(short *)(param_1 + 0x9c) == 0) {
      *(undefined4 *)(param_1 + 600) = 0;
      if (*(int *)(param_2 + 0x25c) == param_1) {
        *(undefined4 *)(param_2 + 0x25c) = 0;
      }
    }
    else if (*(short *)(param_2 + 0x9c) == 0) {
      *(undefined4 *)(param_2 + 600) = 0;
      if (*(int *)(param_1 + 0x25c) == param_2) {
        *(undefined4 *)(param_1 + 0x25c) = 0;
      }
    }
    else {
      uStack_18 = param_4;
      if (*(short *)(param_1 + 0x9a) == 2) {
        if (param_3 == 0) {
          sub_08007F4C(param_1,5);
        }
        *(undefined4 *)(param_1 + 0xa8) = 0;
        if (DAT_03000c1c < param_4) {
          uStack_18 = DAT_03000c1c;
        }
      }
      else {
        sVar1 = sub_08005CA8(900);
        *(short *)(param_2 + 0x1e) = sVar1 + 900;
      }
      *(int *)(param_1 + 600) = param_2;
      *(int *)(param_2 + 0x25c) = param_1;
      iVar2 = sub_08007352(param_1,param_2,param_3,uStack_18);
      if (iVar2 == 2) {
        if (*(short *)(param_2 + 0x9a) == 2) {
          iVar2 = 0x1c;
          if (param_3 != 0) {
            iVar2 = 0x16;
          }
          sub_0800ACFE(iVar2);
        }
        else {
          sub_0800ACFE(0x14);
        }
        sub_08007F4C(param_2,6);
      }
      else if (iVar2 == 1) {
        *(undefined4 *)(param_1 + 600) = 0;
        if (*(int *)(param_1 + 0x25c) == param_2) {
          *(undefined4 *)(param_1 + 0x25c) = 0;
        }
        *(undefined4 *)(param_2 + 0x25c) = 0;
        *(undefined4 *)(param_2 + 600) = 0;
        sub_08007F4C(param_2,7);
        if (*(short *)(param_1 + 0x9a) == 1) {
          iVar2 = *(int *)(param_1 + 0x84) + *(int *)(param_2 + 0x84);
          *(int *)(param_1 + 0x84) = iVar2;
          sub_08005C32(iVar2);
          iVar2 = sub_08005BFE(param_1);
          if (iVar2 != 0) {
            sub_08005BBC();
          }
        }
      }
      else {
        if (*(int *)(param_2 + 0x18) < DAT_03003b6c) {
          sub_0800ACFE(0x1d);
          *(int *)(param_2 + 0x18) = DAT_03003b6c + 0x14;
        }
        sub_0800BEB8(*(int *)(param_2 + 0x274));
      }
    }
  }
  else {
    if (*(int *)(param_2 + 0x18) < DAT_03003b6c) {
      sub_0800ACFE(0x1d);
      *(int *)(param_2 + 0x18) = DAT_03003b6c + 0x14;
    }
    sub_0800BEB8(*(int *)(param_2 + 0x274));
  }
  return;
}

