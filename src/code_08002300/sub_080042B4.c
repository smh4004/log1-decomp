/* sub_080042B4  (original: 0x080042B4-0x080042F4 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800324E();
extern int sub_08003550();
extern int volatile DAT_03000814;
extern int volatile DAT_03003b6c;
extern int volatile DAT_030007d0;


undefined4 sub_080042B4(int param_1)

{
  if (DAT_03000814 < DAT_03003b6c + -0x3c) {
    DAT_03000814 = DAT_03003b6c;
    if ((DAT_030007d0 != 0) &&
       (sub_0800324E(DAT_030007d0 + *(int *)(param_1 + 0x10)), *(int *)(param_1 + 0x10) < 0)) {
      sub_08003550();
    }
  }
  return 0;
}

