/* sub_0800A0E4  (original: 0x0800A0E4-0x0800A0F8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 88% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A0E4(undefined4 *param_1)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_1 + 0x12) + -1;
  *(char *)((int)param_1 + 0x12) = cVar1;
  if (cVar1 == '\0') {
    sub_08009A20(param_1);
  }
  return;
}

