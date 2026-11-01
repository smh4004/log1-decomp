/* sub_08001D52  (original: 0x08001D52-0x08001DA0 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 3/3 snapshots, 56% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_08009798();
extern ushort volatile DAT_03003d12;
extern ushort volatile DAT_03003d14;
extern undefined2 volatile REG_BG0HOFS;
extern undefined2 volatile REG_BG0VOFS;
extern undefined2 volatile REG_DISPCNT;


undefined4 sub_08001D52(int param_1)

{
  if ((int)((uint)DAT_03003d12 << 0x18) < 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  else if (-1 < (int)((uint)DAT_03003d12 << 0x19)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  if (((DAT_03003d14 & 1) != 0) || ((int)((uint)DAT_03003d14 << 0x1e) < 0)) {
    sub_0800ACFE(0);
    REG_DISPCNT = 0x1f00;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    sub_08009798();
  }
  return 0;
}

