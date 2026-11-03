/* sub_08000FA4  (original: 0x08000FA4-0x08000FE8 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern int sub_0800930A();
extern int sub_080090AE();
extern int sub_0800DCF0();
extern ushort volatile REG_BLDCNT;
extern ushort volatile DAT_02029d96;
extern byte volatile REG_BLDY;
extern ushort volatile DAT_02029d98;
extern ushort volatile DAT_02029d9a;
extern ushort volatile DAT_02029d9c;
extern undefined1 volatile DAT_02029d94;
extern undefined volatile DAT_0202addc;
extern undefined volatile DAT_0800fee4;


void sub_08000FA4(int param_1)

{
  sub_0800DCF0();
  DAT_02029d96 = 3;
  DAT_02029d98 = 4;
  DAT_02029d9a = 0x1b;
  DAT_02029d9c = 8;
  sub_0800930A(&DAT_02029d94,
               "Our story begins with our humble hero, Goku. It has been a long time since he has last seen his childhood friends, and so he has decided to meet with them at the house of his old Martial Arts master. Coming along with him is his young six-year old son, Gohan..."
              );
  sub_080090AE(&DAT_0202addc,(short *)&DAT_0800fee4);
  sub_08008D8A(0x202addc);
  REG_BLDY = 0x10;
  REG_BLDCNT = 0x88;
  *(undefined1 *)(param_1 + 4) = 0x40;
  return;
}

