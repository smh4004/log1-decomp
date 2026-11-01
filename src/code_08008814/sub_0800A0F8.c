/* sub_0800A0F8  (original: 0x0800A0F8-0x0800A10E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800A0F8(int param_1)

{
  *(undefined1 *)(param_1 + 0x12) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined4 *)(param_1 + 0x14) = 0x800a0e5;
  *(byte *)(param_1 + 10) = (*(byte *)(param_1 + 10) & 0xfc) + 2;
  return;
}

