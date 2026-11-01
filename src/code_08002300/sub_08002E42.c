/* sub_08002E42  (original: 0x08002E42-0x08002E80 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;


void sub_08002E42(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  local_8 = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
  uVar1 = local_8;
  local_8 = CONCAT22((DAT_030007c2 >> 4) + 8,(DAT_030007c0 >> 4) + 0x10);
  *param_1 = uVar1;
  param_1[1] = local_8;
  return;
}

