/* sub_0800BCA0  (original: 0x0800BCA0-0x0800BCD8 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_08011ee8;
extern undefined volatile gUnknown_08011E88;
extern undefined volatile DAT_08011eea;


void sub_0800BCA0(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 8;
  *(undefined2 *)(param_1 + 6) = 8;
  iVar1 = (uint)*(byte *)(param_1 + 0x13) * 4;
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(&DAT_08011ee8 + iVar1);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(&DAT_08011eea + iVar1);
  *(undefined **)(param_1 + 0x28) = &gUnknown_08011E88 + (uint)*(byte *)(param_1 + 0x13) * 8;
  return;
}

