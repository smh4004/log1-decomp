/* sub_08001A8C  (original: 0x08001A8C-0x08001A9E in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 3/3 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_08001A8C(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 1) = 0;
  iVar1 = *(int *)(*param_1 + 0x14);
  __call_via_r1(param_1,iVar1 + *param_1,iVar1,param_4,param_4);
  return;
}

