/* sub_08008DBE  (original: 0x08008DBE-0x08008E06 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 69% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08008DBE(byte *param_1,short param_2)

{
  int iVar1;
  
  *(ushort *)(param_1 + *(short *)(param_1 + 10) * 2 + *(short *)(param_1 + 0xc) * 0x40 + 0x24) =
       (ushort)*param_1 * 0x1000 + param_2 + -0x1e;
  iVar1 = (*(ushort *)(param_1 + 10) + 1) * 0x10000;
  *(short *)(param_1 + 10) = (short)((uint)iVar1 >> 0x10);
  if ((int)*(short *)(param_1 + 6) <= iVar1 >> 0x10) {
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    iVar1 = *(int *)(param_1 + 0x18);
    *(int *)(param_1 + 0x18) = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      param_1[0x20] = 1;
      param_1[0x21] = 0;
      param_1[0x22] = 0;
      param_1[0x23] = 0;
    }
  }
  return;
}

