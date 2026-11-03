/* sub_0800E090  (original: 0x0800E090-0x0800E0D4 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 52% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined * volatile DAT_03004810;
extern undefined volatile gUnknown_087A63A8;
extern undefined volatile gUnknown_087A639C;


undefined4 sub_0800E090(short param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 4) {
    DAT_03004810 = &gUnknown_087A639C;
  }
  else if (param_1 == 0x40) {
    DAT_03004810 = &gUnknown_087A63A8;
  }
  else {
    DAT_03004810 = &gUnknown_087A639C;
    uVar1 = 1;
  }
  return uVar1;
}

