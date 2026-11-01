/* sub_0800E0F8  (original: 0x0800E0F8-0x0800E130 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 5/5 snapshots, 36% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined2 volatile REG_TM0CNT;
extern byte volatile DAT_03004644;
extern undefined2 * volatile DAT_0300464c;
extern int sub_0800E0D4();


bool sub_0800E0F8(byte param_1,undefined4 *param_2)

{
  if (3 >= param_1) {
    DAT_0300464c = &REG_TM0CNT + (uint)param_1 * 2;
    DAT_03004644 = param_1;
    *param_2 = sub_0800E0D4;
  }
  return 3 < param_1;
}

