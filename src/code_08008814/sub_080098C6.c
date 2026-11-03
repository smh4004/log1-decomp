/* sub_080098C6  (original: 0x080098C6-0x080098DE in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


undefined4 sub_080098C6(void)
{
  undefined4 __r0 = 0;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  REG_DMA3SAD = 0x202be24;
  REG_DMA3DAD = 0x7000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8400;
  return __r0;
  return __r0;
}
