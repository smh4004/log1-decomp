/* sub_08009AA2  (original: 0x08009AA2-0x08009AB4 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009A20();
extern byte volatile DAT_03003d00;


void sub_08009AA2(undefined4 *param_1)

{
  sub_08009A20(param_1);
  DAT_03003d00 = *(undefined1 *)((int)param_1 + 0x1e);
  return;
}

