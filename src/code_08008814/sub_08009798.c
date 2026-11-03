/* sub_08009798  (original: 0x08009798-0x080097C8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int * volatile DAT_03003b64;
extern byte volatile DAT_03003b60;
extern undefined volatile DAT_03003b70;


void sub_08009798(void)

{
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 4) + *DAT_03003b64));
  DAT_03003b60 = DAT_03003b60 - 1;
  DAT_03003b64 = *(int **)(&DAT_03003b70 + (uint)DAT_03003b60 * 4);
  __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0x14) + *DAT_03003b64));
  return;
}

