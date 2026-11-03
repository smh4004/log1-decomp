/* sub_0800A092  (original: 0x0800A092-0x0800A0B6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 38% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800A092(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x12) + -1;
  *(char *)(param_1 + 0x12) = cVar1;
  if (cVar1 == '\0') {
    *(byte *)(*(int *)(param_1 + 0x20) + 0xc) = *(byte *)(*(int *)(param_1 + 0x20) + 0xc) | 5;
    *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0xe) & 0xf;
    *(undefined1 *)(param_1 + 10) = 4;
  }
  return;
}

