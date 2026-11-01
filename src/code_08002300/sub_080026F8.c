/* sub_080026F8  (original: 0x080026F8-0x08002716 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_03000614;


void sub_080026F8(void)

{
  int iVar1;
  
  for (iVar1 = DAT_03000610 + -1; -1 < iVar1; iVar1 = iVar1 + -1) {
    __call_via_r1((&DAT_03000614)[iVar1],
                  *(undefined4 *)(*(int *)((&DAT_03000614)[iVar1] + 0x34) + 4));
  }
  return;
}

