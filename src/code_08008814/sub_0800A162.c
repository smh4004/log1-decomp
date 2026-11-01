/* sub_0800A162  (original: 0x0800A162-0x0800A17E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: equal, r0-void.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A162(int param_1)

{
  int iVar1;
  
  sub_08009A20();
  *(undefined1 *)(param_1 + 9) = *(undefined1 *)(param_1 + 0x1e);
  iVar1 = *(int *)(param_1 + 0x20);
  *(undefined1 *)(iVar1 + 0x11) = *(undefined1 *)(param_1 + 0x1e);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  return;
}

