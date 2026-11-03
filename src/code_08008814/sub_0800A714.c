/* sub_0800A714  (original: 0x0800A714-0x0800A724 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800A6F4();


uint sub_0800A714(int param_1)

{
  uint uVar1;
  
  uVar1 = sub_0800A6F4();
  return param_1 * (uVar1 >> 0x10) >> 0x10;
}

