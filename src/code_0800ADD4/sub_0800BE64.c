/* sub_0800BE64  (original: 0x0800BE64-0x0800BEA8 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_0800BE32();
extern int sub_08002466();
extern int sub_08002450();
extern byte volatile DAT_03004394;
extern undefined4 volatile DAT_03000994;


void sub_0800BE64(int param_1)

{
  uint uVar1;
  
  sub_0800BE32();
  uVar1 = *(int *)(param_1 + 0x28) - 1;
  *(uint *)(param_1 + 0x28) = uVar1;
  if ((uVar1 & 0xf) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    (&DAT_03000994)[(uint)DAT_03004394 * 2] = (&DAT_03000994)[(uint)DAT_03004394 * 2] + -1;
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) >> 4;
    sub_08002450(param_1);
    if ((uVar1 & 0x10) != 0) {
      sub_08002466(param_1,2);
    }
  }
  return;
}

