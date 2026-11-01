/* sub_0800324E  (original: 0x0800324E-0x08003284 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002466();
extern int volatile DAT_030007b8;
extern uint volatile DAT_030007d0;
extern uint volatile DAT_030007cc;


void sub_0800324E(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_030007b8 + 0x3c);
  if (DAT_030007d0 != 0) {
    if ((int)param_1 < 1) {
      sub_08002466(DAT_030007b8,2,DAT_030007b8,param_4,param_4);
      *(undefined2 *)(iVar1 + 0x9c) = 0;
      DAT_030007d0 = 0;
    }
    else {
      DAT_030007d0 = param_1;
      if (DAT_030007cc < param_1) {
        DAT_030007d0 = DAT_030007cc;
      }
    }
  }
  *(uint *)(iVar1 + 0x4c) = DAT_030007d0;
  return;
}

