/* sub_0800BD8E  (original: 0x0800BD8E-0x0800BDB4 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int __16__rt_sdiv();


void sub_0800BD8E(int param_1)

{
  int iVar1;
  
  iVar1 = __16__rt_sdiv(*(uint *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58),
                        *(int *)(param_1 + 0x24) * (uint)*(byte *)(param_1 + 0x10));
  *(char *)(param_1 + 0x14) = (char)(iVar1 >> 1);
  if (2 < (iVar1 >> 1 & 0xffU)) {
    *(undefined1 *)(param_1 + 0x14) = 2;
  }
  return;
}

