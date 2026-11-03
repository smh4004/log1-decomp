/* sub_0800996E  (original: 0x0800996E-0x080099B6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030047ec;
extern undefined * volatile DAT_03007ffc;
extern undefined volatile DAT_03003bc0;
extern ushort volatile REG_IE;
extern ushort volatile REG_IME;
extern undefined4 volatile REG_DMA3SAD;
extern undefined2 volatile REG_DISPSTAT;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)


void sub_0800996E(void)

{
  REG_DMA3SAD = 0x8000138;
  REG_DMA3DAD = 0x3003bc0;
  Ram040000dc = 0x4f;
  DAT_040000de = 0x8400;
  DAT_030047ec = 0x800996d;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3003b88;
  Ram040000dc = 0xe;
  DAT_040000de = 0x8500;
  DAT_03007ffc = &DAT_03003bc0;
  REG_IE = 0x2000;
  REG_IME = 1;
  REG_DISPSTAT = 8;
  return;
}

