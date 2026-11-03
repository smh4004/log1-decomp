/* sub_08009744  (original: 0x08009744-0x08009766 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int * volatile DAT_03003b64;


void sub_08009744(int *param_1)

{
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 4) + *DAT_03003b64));
  __call_via_r1(param_1,(undefined *)(*(int *)*param_1 + *param_1));
  DAT_03003b64 = param_1;
  return;
}

