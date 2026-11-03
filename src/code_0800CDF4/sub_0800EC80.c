/* sub_0800EC80  (original: 0x0800EC80-0x0800EC90 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_0300000b;
extern undefined volatile _0800F180;
#define ram0x0300000c (*(undefined4 volatile *)0x0300000C)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800EC80(void)

{
  ram0x0300000c = &_0800F180;
  return;
}

