/* sub_0800F478  (original: 0x0800F478-0x0800F4DA in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


void sub_0800F478(int param_1,undefined4 param_2)

{
  undefined4 local_20;
  undefined2 local_18;
  undefined2 uStack_16;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  local_18 = (short)param_2;
  uStack_16 = (short)((uint)param_2 >> 0x10);
  local_20 = CONCAT22(uStack_16 << 4,local_18 << 4);
  *(undefined4 *)(param_1 + 0x1c) = local_20;
  *(ushort *)(param_1 + 0x24) = (ushort)*(byte *)(param_1 + 0x20) + *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x26) = (ushort)*(byte *)(param_1 + 0x21) + *(short *)(param_1 + 0x1a);
  *(ushort *)(param_1 + 0x28) =
       (ushort)*(byte *)(param_1 + 0x20) + (ushort)*(byte *)(param_1 + 0x22) +
       *(short *)(param_1 + 0x18);
  *(ushort *)(param_1 + 0x2a) =
       (ushort)*(byte *)(param_1 + 0x21) + (ushort)*(byte *)(param_1 + 0x23) +
       *(short *)(param_1 + 0x1a);
  return;
}

