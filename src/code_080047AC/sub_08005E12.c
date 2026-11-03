/* sub_08005E12  (original: 0x08005E12-0x08005E24 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 10/10 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002930();
extern int sub_08005478();


void sub_08005E12(int param_1)

{
  sub_08002930(param_1);
  sub_08005478(1,(uint)*(byte *)(param_1 + 0x15));
  return;
}

