/* sub_08004774  (original: 0x08004774-0x08004794 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern ushort volatile DAT_030047e8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08004774(int param_1)

{
  DAT_030047e8 = 0;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = *(undefined4 *)(param_1 + 0x30);
  Ram040000dc = (short)((uint)*(ushort *)(param_1 + 6) * (uint)*(ushort *)(param_1 + 4) >> 1);
  DAT_040000de = 0x8100;
  return;
}

