/* sub_08007352  (original: 0x08007352-0x08007416 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005CA8();
extern int volatile DAT_03000c18;


undefined4 sub_08007352(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(short *)(param_2 + 0x9a) == 1) ||
     ((*(char *)(param_2 + 10) == '\0' &&
      ((*(char *)(param_2 + 0xb) != '\x02' || (*(int *)(param_2 + 0x60) == 0)))))) {
    iVar3 = param_4;
    if (*(int *)(param_2 + 0x60) != 0) {
      iVar2 = sub_08005CA8(10000);
      if (iVar2 < 0x2329) {
        if (iVar2 < 0x1d4d) {
          if (iVar2 < 0x1389) {
            if (0x12c0 < iVar2) {
              return 0;
            }
          }
          else {
            iVar3 = 0;
            iVar2 = *(int *)(param_2 + 0x60) >> 2;
            if (iVar2 <= param_4) {
              iVar3 = param_4 - iVar2;
            }
          }
        }
        else {
          iVar3 = 0;
          iVar2 = *(int *)(param_2 + 0x60) >> 1;
          if (iVar2 <= param_4) {
            iVar3 = param_4 - iVar2;
          }
        }
      }
      else {
        iVar3 = 0;
        if (*(int *)(param_2 + 0x60) <= param_4) {
          iVar3 = param_4 - *(int *)(param_2 + 0x60);
        }
      }
    }
    if (iVar3 < *(int *)(param_2 + 0x4c)) {
      if (iVar3 == 0) {
        uVar1 = 0;
      }
      else if ((DAT_03000c18 == 0) || (*(short *)(param_2 + 0x9a) != 1)) {
        *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) - iVar3;
        uVar1 = 2;
      }
      else {
        uVar1 = 2;
      }
    }
    else if ((DAT_03000c18 == 0) || (*(short *)(param_2 + 0x9a) != 1)) {
      *(undefined4 *)(param_2 + 0x4c) = 0;
      *(undefined2 *)(param_2 + 0x9c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

