/* sub_08002716  (original: 0x08002716-0x0800279E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_030047ec;
extern undefined4 volatile DAT_03000614;
extern undefined1 volatile DAT_030007a0;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


undefined4 sub_08002716(int param_1)
{
  undefined4 __r0 = (undefined4)param_1;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (((&DAT_030007a0)[(int)uVar2 >> 3] & (byte)(1 << (uVar2 & 7))) == 0) {
      (&DAT_030007a0)[(int)uVar2 >> 3] = (&DAT_030007a0)[(int)uVar2 >> 3] | (byte)(1 << (uVar2 & 7))
      ;
      param_1 = uVar2 * 0x40 + 0x2003840;
      break;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x60);
  piVar1 = &DAT_03000614 + DAT_03000610;
  DAT_03000610 = DAT_03000610 + 1;
  *piVar1 = param_1;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = param_1;
  Ram040000dc = 0x10;
  DAT_040000de = 0x8500;
  *(undefined4 *)(param_1 + 0x38) = 0x8002553;
  *(undefined1 *)(param_1 + 0x15) = 0xff;
  return __r0;
  return __r0;
}
