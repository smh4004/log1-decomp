/* sub_0800CD80  (original: 0x0800CD80-0x0800CDAE in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


bool sub_0800CD80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0xf) {
    REG_DMA3SAD = param_1 + 8;
    REG_DMA3DAD = 0x5000000;
    Ram040000dc = 0x200;
    DAT_040000de = 0x8000;
  }
  return *(int *)(param_1 + 4) == 0;
}

