/* sub_080096CC  (original: 0x080096CC-0x08009744 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_080098F8();
extern int sub_0800A9F6();
extern int sub_0800B2DE();
extern int sub_0800E4B0();
extern int sub_0800996E();
extern int sub_0800E4DC();
extern byte volatile DAT_03003b60;
extern undefined4 volatile DAT_030047ec;
extern undefined4 * volatile DAT_03003b64;
extern undefined4 volatile DAT_03003b8b;
extern undefined4 volatile DAT_03003b68;
extern ushort volatile REG_IE;
extern ushort volatile REG_WAITCNT;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern undefined2 volatile DAT_040000de;
extern undefined volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined4 volatile *)0x040000DC)


int sub_080096CC(int param_1)

{
  ushort uVar1;
  
  if ((param_1 == 0) && (param_1 = sub_0800E4DC(1), param_1 == 0)) {
    return 0;
  }
  DAT_03003b60 = 0;
  REG_WAITCNT = 0x4014;
  DAT_030047ec = 0;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x2000000;
  Ram040000dc = 0;
  DAT_040000de = 0x8500;
  REG_DMA3SAD = 0x30047ec;
  REG_DMA3DAD = 0x3000000;
  Ram040000dc = 0x1f80;
  DAT_040000de = 0x8500;
  sub_080098F8();
  sub_0800E4B0();
  sub_0800996E();
  sub_0800B2DE();
  sub_0800A9F6(14000);
  DAT_03003b64 = &DAT_03003b68;
  DAT_03003b8b = 0x80096b5;
  uVar1 = REG_IE;
  REG_IE = uVar1 | 1;
  return param_1;
}

