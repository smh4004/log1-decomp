/* sub_08000386  (original: 0x08000386-0x080003B4 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined1 volatile REG_BLDY;


void sub_08000386(int param_1)

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

