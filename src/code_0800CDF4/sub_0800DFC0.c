/* sub_0800DFC0  (original: 0x0800DFC0-0x0800DFEE in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 47% of instructions covered.
 */
#include "ghidra_types.h"
extern byte volatile REG_BLDY;


void sub_0800DFC0(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 4);
  if (uVar1 < 0x20) {
    REG_BLDY = (char)(uVar1 * -0x8000 + 0x100000 >> 0x10);
    return;
  }
  if (uVar1 < 0xd4) {
    REG_BLDY = 0;
    return;
  }
  REG_BLDY = (char)(uVar1 * 0x8000 + -0x6a0000 >> 0x10);
  return;
}

