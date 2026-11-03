/* sub_08009586  (original: 0x08009586-0x080095D0 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800AB3E();
extern int sub_08008D8A();
extern int sub_08009626();
extern int sub_080092A4();
extern int Decompress();
extern int WaitForVBlank();
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08009586(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = Decompress((undefined4 *)param_1[1],(uint)*(byte *)(param_1 + 2));
  sub_080092A4(param_2);
  sub_0800AB3E();
  WaitForVBlank(1);
  REG_DMA3SAD = *param_1;
  REG_DMA3DAD = 0x5000000;
  Ram040000dc = 0x100;
  DAT_040000de = 0x8000;
  sub_08009626(&REG_DMA3SAD,(int)param_3,iVar1,0x9600);
  sub_08008D8A(param_2);
  return;
}

