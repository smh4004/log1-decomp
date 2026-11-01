/* sub_080012EC  (original: 0x080012EC-0x08001390 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int __call_via_r1();
extern int sub_080009B8();
extern int sub_080098F8();
extern int sub_08008D3A();
extern int sub_08009586();
extern undefined2 volatile REG_BG0CNT;
extern undefined2 volatile REG_BG1CNT;
extern undefined2 volatile gUnknown_08142380;
extern undefined * volatile DAT_0202b610;
extern undefined2 volatile REG_BG2CNT;
extern undefined1 volatile DAT_02029d94;
extern undefined2 volatile REG_BG3CNT;
extern undefined volatile DAT_0202a5b8;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_0202b600;
extern undefined2 volatile REG_BG1HOFS;
extern undefined volatile DAT_0600c000;
extern undefined2 volatile REG_BG1VOFS;
extern undefined volatile DAT_0600e000;
extern undefined2 volatile REG_BG2HOFS;
extern undefined volatile DAT_0600e800;
extern undefined2 volatile REG_BG2VOFS;
extern undefined volatile DAT_0600f000;
extern undefined2 volatile REG_BG3HOFS;
extern undefined volatile DAT_0600f800;
extern undefined2 volatile REG_BG3VOFS;
extern undefined2 volatile REG_BLDCNT;
extern undefined1 volatile REG_BLDALPHA;
extern undefined1 volatile DAT_04000053;
extern undefined volatile gUnknown_081B3514;
extern undefined2 volatile REG_DISPCNT;


void sub_080012EC(int *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  REG_DISPCNT = 0x80;
  REG_BG0CNT = 0x1c0f;
  REG_BG1CNT = 0x1d0f;
  REG_BG2CNT = 0x1e0f;
  REG_BG3CNT = 0x1f83;
  REG_BLDCNT = 0x844;
  REG_BLDALPHA = 0x10;
  DAT_04000053 = 0xc;
  sub_080098F8();
  DAT_0202b610 = &DAT_0600f800;
  sub_08009586(&gUnknown_081B3514,&DAT_0202b600,0x6000000);
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202a5b8,&DAT_0600e800,&DAT_0600c000,0xe,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_080009B8(0,1);
  __call_via_r1(param_1,*(int *)(*param_1 + 0x14) + *param_1);
  REG_DISPCNT = 0x1f00;
  REG_BG1HOFS = 0;
  REG_BG1VOFS = 0;
  REG_BG2HOFS = 0;
  REG_BG2VOFS = 0;
  REG_BG3HOFS = 0;
  REG_BG3VOFS = 0;
  return;
}

