/* sub_08006244  (original: 0x08006244-0x08006256 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 2/10 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005526();
extern int sub_080060A0();


undefined4 sub_08006244(int param_1)

{
  sub_080060A0(param_1);
  sub_08005526((uint)*(byte *)(param_1 + 0xd));
  return 1;
}

