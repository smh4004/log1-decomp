/* sub_08004112  (original: 0x08004112-0x0800413E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 57% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800245A();
extern int volatile DAT_030007dc;
extern ushort volatile DAT_03003d12;
extern undefined4 volatile DAT_03000994;
extern undefined * volatile PTR_sub_08003D94_1_08011424;


void sub_08004112(int param_1)

{
  if ((DAT_030007dc != 1) && (-1 < (int)((uint)DAT_03003d12 << 0x1d))) {
    (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)(param_1 + 0xd) * 2] + -1;
    sub_0800245A(param_1,&PTR_sub_08003D94_1_08011424);
  }
  return;
}

