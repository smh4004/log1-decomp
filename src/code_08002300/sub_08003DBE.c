/* sub_08003DBE  (original: 0x08003DBE-0x08003E02 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 53% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800245A();
extern int sub_08003524();
extern ushort volatile DAT_03003d14;
extern int volatile DAT_030007dc;
extern ushort volatile DAT_03003d12;
extern undefined4 volatile DAT_03000994;
extern undefined * volatile gUnknown_08011438;


void sub_08003DBE(int param_1)

{
  if ((int)((uint)DAT_03003d14 << 0x16) < 0) {
    sub_08003524();
  }
  if ((DAT_030007dc != 0) || ((int)((uint)DAT_03003d12 << 0x1d) < 0)) {
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + -1;
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0x14) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0x14) * 2] + -1;
    sub_0800245A(param_1,&gUnknown_08011438);
  }
  return;
}

