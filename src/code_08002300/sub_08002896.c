/* sub_08002896  (original: 0x08002896-0x080028C4 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_080098C6();
extern int volatile DAT_03000798;
extern ushort volatile DAT_0300079e;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


undefined4 sub_08002896(void)
{
  undefined4 __r0 = 0;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  __r0 = (undefined4)sub_080098C6();
  if (DAT_03000798 + 0xfdff4fdcU != 0) {
    REG_DMA3SAD = 0x200b024;
    REG_DMA3DAD = (uint)DAT_0300079e * 0x20 + 0x6010000;
    Ram040000dc = (short)(DAT_03000798 + 0xfdff4fdcU >> 2);
    DAT_040000de = 0x8400;
  }
  return __r0;
  return __r0;
}
