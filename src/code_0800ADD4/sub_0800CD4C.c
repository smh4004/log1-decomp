/* sub_0800CD4C  (original: 0x0800CD4C-0x0800CD80 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern ushort volatile DAT_030047e8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800CD4C(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x1e;
  REG_DMA3SAD = 0x5000000;
  REG_DMA3DAD = param_1 + 8;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8000;
  DAT_030047e8 = 0xffff;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x200;
  DAT_040000de = 0x8100;
  return;
}

