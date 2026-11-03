/* sub_0800DA86  (original: 0x0800DA86-0x0800DAA0 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009744();
extern byte volatile DAT_03003b60;
extern undefined4 volatile DAT_030005e0;


void sub_0800DA86(void)

{
  DAT_03003b60 = 0;
  sub_08009744(&DAT_030005e0);
  return;
}

