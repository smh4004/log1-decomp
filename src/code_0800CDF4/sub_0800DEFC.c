/* sub_0800DEFC  (original: 0x0800DEFC-0x0800DF14 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009328();
extern int volatile DAT_02029da8;
extern undefined1 volatile DAT_02029d94;


bool sub_0800DEFC(void)

{
  sub_08009328(&DAT_02029d94,0);
  return DAT_02029da8 == 0;
}

