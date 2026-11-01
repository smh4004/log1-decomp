/* sub_0800C9A0  (original: 0x0800C9A0-0x0800C9B4 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_030043a0;


void sub_0800C9A0(int param_1)

{
  if ((DAT_030043a0 == param_1) && (*(char *)(param_1 + 0x10) == ' ')) {
    DAT_030043a0 = 0;
  }
  return;
}

