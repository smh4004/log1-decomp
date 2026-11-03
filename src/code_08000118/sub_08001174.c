/* sub_08001174  (original: 0x08001174-0x08001208 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_080095FE();
extern int sub_08008D14();
extern int sub_080098F8();
extern int sub_0800106C();
extern int sub_080095DC();
extern undefined2 volatile REG_BG0CNT;
extern undefined * volatile DAT_02029da4;
extern undefined2 volatile REG_BG1CNT;
extern ushort volatile DAT_02029d96;
extern undefined2 volatile REG_BG2CNT;
extern undefined2 volatile REG_BG3CNT;
extern ushort volatile DAT_02029d98;
extern ushort volatile DAT_02029d9a;
extern ushort volatile REG_BG1HOFS;
extern ushort volatile REG_BG1VOFS;
extern ushort volatile DAT_02029d9c;
extern ushort volatile REG_BG2HOFS;
extern byte volatile DAT_02029d94;
extern ushort volatile REG_BG2VOFS;
extern undefined * volatile DAT_0202a5c8;
extern ushort volatile REG_BG3HOFS;
extern undefined * volatile DAT_0202adec;
extern ushort volatile REG_BG3VOFS;
extern undefined * volatile DAT_0202b610;
extern ushort volatile DAT_03000608;
extern ushort volatile DAT_0300060a;
extern undefined volatile DAT_0600e000;
extern undefined volatile DAT_0600e800;
extern ushort volatile REG_BLDCNT;
extern undefined volatile DAT_0600f000;
extern undefined volatile DAT_0600f800;
extern undefined4 volatile REG_DMA3SAD;
extern undefined2 volatile REG_DISPCNT;


undefined4 sub_08001174(undefined4 param_1)
{
  undefined4 __r0 = (undefined4)param_1;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  int iVar1;
  
  REG_DISPCNT = 0x80;
  __r0 = (undefined4)sub_080098F8();
  iVar1 = sub_080095DC(0x85c31ec);
  __r0 = (undefined4)sub_080095FE(&REG_DMA3SAD,0x6000000,iVar1,0x1240);
  __r0 = (undefined4)sub_0800106C(param_1);
  REG_BG0CNT = 0x1c00;
  REG_BG1CNT = 0x1d81;
  REG_BG2CNT = 0x1e83;
  REG_BG3CNT = 0x1f83;
  DAT_02029da4 = &DAT_0600e000;
  DAT_02029d96 = 0;
  DAT_02029d98 = 0;
  DAT_02029d9a = 0x1e;
  DAT_02029d9c = 0x14;
  DAT_02029d94 = 0;
  __r0 = (undefined4)sub_08008D14(&DAT_02029d94);
  DAT_0202a5c8 = &DAT_0600e800;
  DAT_0202adec = &DAT_0600f000;
  DAT_0202b610 = &DAT_0600f800;
  REG_BLDCNT = 0;
  REG_DISPCNT = 8000;
  REG_BG1HOFS = DAT_03000608;
  REG_BG1VOFS = DAT_0300060a;
  REG_BG2HOFS = DAT_03000608;
  REG_BG2VOFS = DAT_0300060a;
  REG_BG3HOFS = DAT_03000608;
  REG_BG3VOFS = DAT_0300060a;
  return __r0;
  return __r0;
}
