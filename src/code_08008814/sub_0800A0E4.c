/* sub_0800A0E4  (original: 0x0800A0E4-0x0800A0F8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A0E4(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x12) + -1;
  *(char *)(param_1 + 0x12) = cVar1;
  if (cVar1 == '\0') {
    sub_08009A20();
  }
  return;
}

