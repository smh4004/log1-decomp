/* sub_0800DCF0  (original: 0x0800DCF0-0x0800DDC4 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_080098F8();
extern int sub_08008D8A();
extern int sub_0800A6F4();
extern int sub_080092A4();
extern int sub_08008D3A();
extern int sub_08009680();
extern undefined2 volatile REG_BG0CNT;
extern undefined2 volatile DAT_05000000;
extern undefined2 volatile gUnknown_08142380;
extern undefined2 volatile DAT_05000004;
extern undefined2 volatile REG_BG2CNT;
extern undefined volatile DAT_02020202;
extern undefined2 volatile REG_BG3CNT;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_0202b600;
extern undefined4 volatile DAT_0202c224;
extern undefined volatile DAT_02035824;
extern undefined2 volatile DAT_0203582a;
extern undefined2 volatile DAT_05000006;
extern undefined volatile DAT_0600c000;
extern undefined volatile DAT_0600e000;
extern undefined volatile DAT_0600f000;
extern undefined volatile DAT_0600f800;
extern undefined2 volatile REG_DISPCNT;
extern undefined4 volatile REG_DMA3SAD;


void sub_0800DCF0(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  REG_DISPCNT = 0x80;
  sub_080098F8();
  sub_08008D3A(&DAT_02029d94,&DAT_0600e000,&DAT_0600c000,0xf,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202addc,&DAT_0600f000,0x6000000,1,&gUnknown_08142380);
  sub_08008D3A(&DAT_0202b600,&DAT_0600f800,0x6000000,0,&gUnknown_08142380);
  DAT_05000000 = 0;
  DAT_05000004 = 0;
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    (&DAT_05000006)[iVar3] = ((short)iVar3 * -2 + 0x1f) * 0x421;
    iVar3 = iVar2;
  } while (iVar2 < 8);
  sub_08009680(&REG_DMA3SAD,0x6000000,&DAT_02020202,0x9600);
  sub_080092A4(&DAT_0202b600);
  sub_08008D8A(&DAT_0202b600);
  REG_BG0CNT = 0x1c0c;
  iVar3 = 0;
  REG_BG2CNT = 0x1e0c;
  REG_BG3CNT = 0x1f80;
  REG_DISPCNT = 0xd20;
  do {
    uVar1 = sub_0800A6F4();
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(&DAT_02035824 + iVar2) = uVar1;
  } while (iVar3 < 400);
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 1;
    (&DAT_0203582a)[iVar3 * 4] = 0;
    iVar3 = iVar2;
  } while (iVar2 < 100);
  sub_08009680(&REG_DMA3SAD,&DAT_0202c224,&DAT_02020202,0x9600);
  return;
}

