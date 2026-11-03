/* sub_0800A162  (original: 0x0800A162-0x0800A17E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A162(undefined4 *param_1)

{
  int iVar1;
  
  sub_08009A20(param_1);
  *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)param_1 + 0x1e);
  iVar1 = param_1[8];
  *(undefined1 *)(iVar1 + 0x11) = *(undefined1 *)((int)param_1 + 0x1e);
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  return;
}

