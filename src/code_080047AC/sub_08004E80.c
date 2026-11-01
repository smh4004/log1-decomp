/* sub_08004E80  (original: 0x08004E80-0x08004E98 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 9/9 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009328();
extern int volatile DAT_02029da8;
extern undefined1 volatile DAT_02029d94;


bool sub_08004E80(void)

{
  sub_08009328(&DAT_02029d94,0x8004e3d);
  return DAT_02029da8 == 0;
}

