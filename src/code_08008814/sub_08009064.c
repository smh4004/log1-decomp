/* sub_08009064  (original: 0x08009064-0x080090AE in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 56% of instructions covered.
 */
#include "ghidra_types.h"


void sub_08009064(byte *param_1,byte *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  
  uVar2 = *(undefined2 *)(param_1 + 10);
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    if (bVar1 == 10) {
      *(undefined2 *)(param_1 + 10) = uVar2;
      *(ushort *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1U & 0x1f;
    }
    else {
      *(ushort *)(param_1 + *(short *)(param_1 + 10) * 2 + *(short *)(param_1 + 0xc) * 0x40 + 0x24)
           = (ushort)bVar1 + (ushort)*param_1 * 0x1000 + -0x1e;
      *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + 1;
    }
    param_2 = param_2 + 1;
  }
  return;
}

