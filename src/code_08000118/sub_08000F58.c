/* sub_08000F58  (original: 0x08000F58-0x08000F6C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 55% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_08000F58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(*piVar1 + 0x10);
    __call_via_r1(piVar1,iVar2 + *piVar1,iVar2,param_4,param_4);
  }
  return;
}

