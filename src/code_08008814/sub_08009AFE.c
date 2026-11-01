/* sub_08009AFE  (original: 0x08009AFE-0x08009B2A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"


void sub_08009AFE(int param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 8) = (char)((uint)iVar1 >> 0x18);
  if (0x3f < iVar1 >> 0x18) {
    *(undefined1 *)(param_1 + 8) = 0x40;
    *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) & 0xfc;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined1 *)(iVar1 + 0x10) = *(undefined1 *)(param_1 + 8);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  return;
}

