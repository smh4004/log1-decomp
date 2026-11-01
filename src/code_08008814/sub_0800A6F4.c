/* sub_0800A6F4  (original: 0x0800A6F4-0x0800A714 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern uint volatile DAT_03003d24;
extern uint volatile DAT_03003d28;


int sub_0800A6F4(void)

{
  DAT_03003d24 = DAT_03003d24 + 0x2cbbc71 ^ DAT_03003d28;
  DAT_03003d28 = (DAT_03003d28 >> 0x1d | DAT_03003d28 << 3) + 0x632d80f ^ DAT_03003d24;
  return DAT_03003d24 * DAT_03003d28;
}

