/* sub_08006D70  (original: 0x08006D70-0x08006D90 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __16__rt_sdiv();
extern int volatile DAT_03000c1c;


void sub_08006D70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x58) >> 6;
  if (*(short *)(param_1 + 0x9a) == 1) {
    iVar1 = __16__rt_sdiv(3,*(undefined4 *)(param_1 + 0x50),param_3,param_4,param_4);
    DAT_03000c1c = iVar1 + 1;
  }
  return;
}

