/* sub_08004DAC  (original: 0x08004DAC-0x08004DC6 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined1 volatile REG_BLDY;


void sub_08004DAC(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(param_1 + 4);
  if (uVar1 < 0x40) {
    REG_BLDY = (char)((int)(0x40 - uVar1) >> 2);
    return;
  }
  REG_BLDY = (char)((int)(uVar1 - 0x40) >> 2);
  return;
}

