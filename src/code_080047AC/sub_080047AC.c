/* sub_080047AC  (original: 0x080047AC-0x08004832 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: orig-error.
 */
#include "ghidra_types.h"
extern int sub_080098F8();
extern undefined2 volatile DAT_04000020;
extern undefined2 volatile DAT_04000022;
extern ushort volatile DAT_03000828;
extern undefined2 volatile DAT_04000024;
extern undefined2 volatile DAT_04000026;
extern ushort volatile DAT_0300082a;
extern undefined4 volatile DAT_04000028;
extern undefined1 volatile DAT_00004000;
extern undefined1 volatile DAT_00004001;
extern undefined4 * volatile DAT_0300000b;
extern undefined4 volatile DAT_03000104;
extern undefined4 volatile DAT_0400002c;
extern undefined2 volatile REG_BLDCNT;
extern undefined2 volatile REG_DISPCNT;


void sub_080047AC(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  sub_080098F8();
  REG_DISPCNT = 0x404;
  *(undefined1 *)(param_1 + 8) = 0;
  DAT_04000028 = 0;
  DAT_0400002c = 0;
  DAT_04000020 = (short)((uint)DAT_03000828 * 0x112 >> 8);
  DAT_04000022 = 0;
  DAT_04000024 = 0;
  DAT_04000026 = (short)((uint)DAT_0300082a * 0x19a >> 8);
  REG_BLDCNT = 0;
  iVar1 = 0;
  while( true ) {
    uVar2 = iVar1 * 0x3e ^ 0x9c;
    uVar3 = iVar1 * 0xe3 + 0x25;
    if ((uVar2 & 0xff) != uVar2) {
      return;
    }
    if (uVar3 != (uVar3 & 0xff)) break;
    iVar1 = iVar1 + 1;
    if (4 < iVar1) {
      DAT_0300000b = &DAT_03000104;
      return;
    }
  }
  return;
}

