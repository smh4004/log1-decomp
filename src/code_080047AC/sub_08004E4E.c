/* sub_08004E4E  (original: 0x08004E4E-0x08004E76 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 22/22 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_080090AE();
extern int sub_08008D14();
extern undefined1 volatile DAT_02029d94;
extern undefined volatile gUnknown_0801146E;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_08004E4E(void)

{
  sub_08008D14(&DAT_02029d94);
  sub_080090AE(&DAT_02029d94,(short *)&gUnknown_0801146E);
  REG_DMA3SAD = 0x85c386a;
  REG_DMA3DAD = 0x5000002;
  Ram040000dc = 0xf;
  DAT_040000de = 0x8000;
  return;
}

