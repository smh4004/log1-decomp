/* sub_08000F58  (original: 0x08000F58-0x08000F6C in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_08000F58(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    __call_via_r1(piVar1,(undefined *)(*(int *)(*piVar1 + 0x10) + *piVar1));
  }
  return;
}

