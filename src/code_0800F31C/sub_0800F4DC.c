/* sub_0800F4DC  (original: 0x0800F4DC-0x0800F53E in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


void sub_0800F4DC(int param_1)

{
  undefined4 local_14;
  
  local_14 = CONCAT22(*(short *)(param_1 + 0x1e) >> 4,*(short *)(param_1 + 0x1c) >> 4);
  *(undefined4 *)(param_1 + 0x18) = local_14;
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

