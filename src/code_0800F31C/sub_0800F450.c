/* sub_0800F450  (original: 0x0800F450-0x0800F476 in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


undefined4 sub_0800F450(int param_1)

{
  undefined4 local_4;
  
  (*(undefined2 *)((char *)&local_4 + 0)) = (short)*(undefined4 *)(param_1 + 0x18);
  (*(undefined2 *)((char *)&local_4 + 2)) = (short)((uint)*(undefined4 *)(param_1 + 0x18) >> 0x10);
  local_4 = CONCAT22((*(undefined2 *)((char *)&local_4 + 2)) + (ushort)(*(byte *)(param_1 + 0x23) >> 1),
                     (short)local_4 + (ushort)(*(byte *)(param_1 + 0x22) >> 1));
  return local_4;
}

