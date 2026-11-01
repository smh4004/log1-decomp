/* sub_08004D5C  (original: 0x08004D5C-0x08004DAC in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009586();
extern int sub_0800A5F6();
extern undefined * volatile DAT_0202b610;
extern undefined volatile DAT_0202b600;
extern undefined volatile DAT_0600f800;
extern undefined2 volatile REG_BG3CNT;
extern undefined2 volatile REG_BG0HOFS;
extern undefined2 volatile REG_BG0VOFS;
extern undefined2 volatile REG_BG1HOFS;
extern undefined2 volatile REG_BG1VOFS;
extern undefined2 volatile REG_BG2HOFS;
extern undefined2 volatile REG_BG2VOFS;
extern undefined2 volatile REG_BG3HOFS;
extern undefined2 volatile REG_BG3VOFS;
extern undefined volatile gUnknown_085C2204;
extern undefined2 volatile REG_BLDCNT;
extern undefined volatile gUnknown_08592008;
extern undefined1 volatile REG_BLDY;
extern undefined2 volatile REG_DISPCNT;


void sub_08004D5C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  REG_DISPCNT = 0x800;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x88;
  REG_BLDY = 0x10;
  *(undefined2 *)(param_1 + 4) = 0;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586(&gUnknown_085C2204,&DAT_0202b600,0x6000000,param_4,param_4);
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  sub_0800A5F6(&gUnknown_08592008);
  return;
}

