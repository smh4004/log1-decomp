/* sub_0800B4FA  (original: 0x0800B4FA-0x0800B554 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 30% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800B436();
extern int sub_08002466();
extern undefined volatile gUnknown_086B3AD4;
extern ushort volatile DAT_03003d12;
extern undefined volatile gUnknown_086B3C50;
extern undefined volatile gUnknown_086B3AA8;


void sub_0800B4FA(int param_1)

{
  if ((int)((uint)DAT_03003d12 << 0x1e) < 0) {
    sub_0800B436(param_1,*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x3c) + 0x58) + 0xf >> 4);
  }
  else {
    *(undefined1 *)(param_1 + 0x16) = 0;
    if (*(int *)(param_1 + 0x24) < 0x49) {
      if (*(int *)(param_1 + 0x24) < 0x15) {
        *(undefined **)(param_1 + 0x1c) = &gUnknown_086B3C50;
        *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 5;
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + 5;
      }
      else {
        *(undefined **)(param_1 + 0x1c) = &gUnknown_086B3AD4;
        *(short *)(param_1 + 0x20) = *(short *)(param_1 + 0x20) + 4;
        *(short *)(param_1 + 0x22) = *(short *)(param_1 + 0x22) + 4;
      }
    }
    else {
      *(undefined **)(param_1 + 0x1c) = &gUnknown_086B3AA8;
    }
    sub_08002466(param_1,1);
  }
  return;
}

