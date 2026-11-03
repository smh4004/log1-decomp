/* sub_0800BDC0  (original: 0x0800BDC0-0x0800BDD6 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 90% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080028C4();


void sub_0800BDC0(int param_1)

{
  byte bVar1;
  
  bVar1 = *(char *)(param_1 + 0x10) + 1;
  *(byte *)(param_1 + 0x10) = bVar1;
  if (7 < bVar1) {
    sub_080028C4(param_1);
  }
  return;
}

