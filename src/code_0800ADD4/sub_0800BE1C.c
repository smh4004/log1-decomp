/* sub_0800BE1C  (original: 0x0800BE1C-0x0800BE32 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();


void sub_0800BE1C(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ((*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x18)) + *(int *)(param_1 + 0x2c));
  *(undefined4 **)(param_1 + 0x30) = puVar1;
  __call_via_r1(param_1,(undefined *)*puVar1);
  return;
}

