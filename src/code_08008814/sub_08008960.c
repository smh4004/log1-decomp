/* sub_08008960  (original: 0x08008960-0x08008984 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern short volatile DAT_030047e8;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern undefined2 volatile DAT_040000de;
extern undefined volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined4 volatile *)0x040000DC)


void sub_08008960(byte *param_1,int param_2,int param_3,int param_4)

{
  DAT_030047e8 = (ushort)*param_1 << 0xc;
  REG_DMA3SAD = 0x30047e8;
  REG_DMA3DAD = param_1 + 0x24;
  Ram040000dc = 0x400;
  DAT_040000de = 0x8100;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 4);
  return;
}

