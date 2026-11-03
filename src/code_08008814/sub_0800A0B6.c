/* sub_0800A0B6  (original: 0x0800A0B6-0x0800A0E0 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009A20();


void sub_0800A0B6(undefined4 *param_1)

{
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xe) = *(char *)((int)param_1 + 0x1e);
  }
  param_1[5] = 0x800a093;
  *(byte *)((int)param_1 + 0x12) = *(byte *)((int)param_1 + 0xe) & 0xf;
  *(byte *)((int)param_1 + 10) = (*(byte *)((int)param_1 + 10) & 0xfc) + 2;
  return;
}

