/* sub_0800E0D4  (original: 0x0800E0D4-0x0800E0F8 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern short volatile DAT_03004646;
extern undefined1 volatile DAT_03004648;


void sub_0800E0D4(void)

{
  if ((DAT_03004646 != 0) && (DAT_03004646 = DAT_03004646 + -1, DAT_03004646 == 0)) {
    DAT_03004648 = 1;
  }
  return;
}

