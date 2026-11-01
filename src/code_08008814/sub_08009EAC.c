/* sub_08009EAC  (original: 0x08009EAC-0x08009EDA in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009DB0();


void sub_08009EAC(int param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 8) = (char)((uint)iVar1 >> 0x18);
  if (0x3f < iVar1 >> 0x18) {
    *(undefined1 *)(param_1 + 8) = 0x40;
    *(undefined4 *)(param_1 + 0x14) = 0x8009db1;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined1 *)(iVar1 + 0x10) = *(undefined1 *)(param_1 + 8);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  sub_08009DB0();
  return;
}

