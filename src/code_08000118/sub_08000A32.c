/* sub_08000A32  (original: 0x08000A32-0x08000A58 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080098C6();
extern uint * volatile DAT_030000d4;


void sub_08000A32(int param_1,int param_2)

{
  *DAT_030000d4 =
       ((uint)(param_1 << 0x1a) >> 0x17) << 0x10 |
       (uint)(param_2 << 0x1b) >> 0x18 | *DAT_030000d4 & 0xfe00ff00;
  sub_080098C6();
  return;
}

