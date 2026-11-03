/* sub_08001E90  (original: 0x08001E90-0x08001F04 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_0800946E();
extern int sub_08009586();
extern int sub_08008D3A();
extern int sub_080098F8();
extern undefined2 volatile REG_BG0CNT;
extern undefined * volatile DAT_0202b610;
extern undefined2 volatile gUnknown_08142380;
extern int volatile DAT_03003b6c;
extern int volatile DAT_030005ec;
extern undefined2 volatile REG_BG3CNT;
extern undefined1 volatile DAT_02029d94;
extern ushort volatile REG_BG0HOFS;
extern undefined volatile DAT_06000000;
extern ushort volatile REG_BG0VOFS;
extern undefined volatile DAT_0600c000;
extern ushort volatile REG_BG1HOFS;
extern undefined volatile DAT_0600e000;
extern ushort volatile REG_BG1VOFS;
extern undefined volatile DAT_0600f800;
extern ushort volatile REG_BG2HOFS;
extern ushort volatile REG_BG2VOFS;
extern undefined volatile gUnknown_0801082C;
extern ushort volatile REG_BG3HOFS;
extern ushort volatile REG_BG3VOFS;
extern ushort volatile REG_BLDCNT;
extern undefined volatile gUnknown_0819BCDC;
extern undefined2 volatile REG_DISPCNT;


void sub_08001E90(void)

{
  sub_080098F8();
  REG_DISPCNT = 0x900;
  REG_BG0CNT = 0x1c0f;
  REG_BG3CNT = 0x1f83;
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586((undefined4 *)&gUnknown_0819BCDC,0x202b600,(int *)&DAT_06000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_0800946E(&gUnknown_0801082C,&DAT_02029d94);
  sub_08008D8A(0x2029d94);
  REG_BG0HOFS = 0;
  REG_BG0VOFS = 0;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  REG_BLDCNT = 0;
  DAT_030005ec = DAT_03003b6c + 0x708;
  return;
}

