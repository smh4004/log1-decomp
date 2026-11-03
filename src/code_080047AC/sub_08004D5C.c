/* sub_08004D5C  (original: 0x08004D5C-0x08004DAC in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800A5F6();
extern int sub_08009586();
extern undefined * volatile DAT_0202b610;
extern undefined volatile DAT_06000000;
extern undefined volatile DAT_0600f800;
extern undefined2 volatile REG_BG3CNT;
extern ushort volatile REG_BG0HOFS;
extern ushort volatile REG_BG0VOFS;
extern ushort volatile REG_BG1HOFS;
extern ushort volatile REG_BG1VOFS;
extern ushort volatile REG_BG2HOFS;
extern ushort volatile REG_BG2VOFS;
extern ushort volatile REG_BG3HOFS;
extern ushort volatile REG_BG3VOFS;
extern undefined volatile gUnknown_085C2204;
extern ushort volatile REG_BLDCNT;
extern undefined1 volatile REG_BLDY;
extern undefined2 volatile REG_DISPCNT;


void sub_08004D5C(int param_1)

{
  REG_DISPCNT = 0x800;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x88;
  REG_BLDY = 0x10;
  *(undefined2 *)(param_1 + 4) = 0;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586((undefined4 *)&gUnknown_085C2204,0x202b600,(int *)&DAT_06000000);
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  sub_0800A5F6(0x8592008);
  return;
}

