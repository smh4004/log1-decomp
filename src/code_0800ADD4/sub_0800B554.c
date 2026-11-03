/* sub_0800B554  (original: 0x0800B554-0x0800B5A2 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int __16__rt_sdiv();
extern undefined volatile DAT_08011e6a;
extern undefined volatile DAT_08011e6c;
extern undefined volatile DAT_08011e6e;
extern undefined volatile gUnknown_08011E68;


void sub_0800B554(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x12) = 0;
  iVar2 = (uint)*(byte *)(param_1 + 0x13) * 8;
  *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + *(short *)(&gUnknown_08011E68 + iVar2);
  *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + *(short *)(&DAT_08011e6a + iVar2);
  iVar2 = (uint)*(byte *)(param_1 + 0x13) * 8;
  *(undefined2 *)(param_1 + 0x28) = *(undefined2 *)(&DAT_08011e6c + iVar2);
  *(undefined2 *)(param_1 + 0x2a) = *(undefined2 *)(&DAT_08011e6e + iVar2);
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x24) = 2;
  sub_0800ACFE(3);
  uVar1 = __16__rt_sdiv(3,*(uint *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x50));
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  return;
}

