/* sub_0800B716  (original: 0x0800B716-0x0800B758 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 50% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800B436();
extern int sub_08002466();
extern int sub_0800ACFE();
extern ushort volatile DAT_03003d12;


void sub_0800B716(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x3c);
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(iVar1 + 0x58) + 0xf >> 4);
    return;
  }
  if (*(int *)(param_1 + 0x24) * 2 < *(int *)(iVar1 + 0x58)) {
    iVar1 = 8;
  }
  else {
    iVar1 = 0xc;
  }
  sub_0800ACFE(iVar1);
  *(undefined1 *)(param_1 + 0x16) = 0;
  sub_08002466(param_1,1);
  return;
}

