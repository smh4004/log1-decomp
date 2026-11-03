/* sub_080026DE  (original: 0x080026DE-0x080026F2 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002666();
extern undefined4 volatile DAT_03000994;


void sub_080026DE(int param_1)

{
  (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
       (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + -1;
  sub_08002666(param_1);
  return;
}

