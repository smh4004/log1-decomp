/* sub_0800C2B2  (original: 0x0800C2B2-0x0800C306 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800FE0C();
extern int sub_080028C4();
extern int __16__rt_sdiv();
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800C2B2(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  unsigned int __frame[3];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_c (*(int *)((char *)__frame + 0x0))
  if (*(char *)(param_2 + 0x15) != -1) {
    piVar1 = (int *)(param_1 + 4);
    local_c = param_2;
    iVar2 = sub_0800FE0C(piVar1,&local_c);
    iVar2 = __16__rt_sdiv(0x18,iVar2 - (param_1 + 8));
    iVar3 = *piVar1;
    *piVar1 = iVar3 + -1;
    iVar3 = (iVar3 + -1) - iVar2;
    if (iVar3 != 0) {
      REG_DMA3SAD = piVar1 + iVar2 * 6 + 7;
      REG_DMA3DAD = piVar1 + iVar2 * 6 + 1;
      Ram040000dc = (short)((uint)(iVar3 * 0x18) >> 2);
      DAT_040000de = 0x8400;
    }
    sub_080028C4(local_c);
  }
  return;
}

