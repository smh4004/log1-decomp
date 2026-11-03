/* sub_0800A664  (original: 0x0800A664-0x0800A6B2 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_explore.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_0800DBF8();
extern ushort volatile DAT_03003d12;
extern ushort volatile DAT_03003d14;
extern ushort volatile DAT_03003d16;
extern byte volatile DAT_03003d10;
extern ushort volatile REG_KEYINPUT;
extern int volatile DAT_03003d18;
extern undefined volatile DAT_03003d1c;


void sub_0800A664(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = REG_KEYINPUT;
  uVar2 = ~uVar1;
  DAT_03003d14 = uVar2 & (uVar2 ^ DAT_03003d12);
  DAT_03003d16 = DAT_03003d12 & (uVar2 ^ DAT_03003d12);
  DAT_03003d12 = uVar2;
  if (DAT_03003d14 != 0) {
    uVar4 = (uint)DAT_03003d10;
    uVar3 = uVar4 + 1;
    DAT_03003d10 = (byte)uVar3;
    (&DAT_03003d1c)[uVar4] = (char)DAT_03003d14;
    if (7 < (uVar3 & 0xff)) {
      DAT_03003d10 = 0;
    }
  }
  if (((uVar1 & 0x30b) == 0) && (DAT_03003d18 != 0)) {
    sub_0800DBF8();
  }
  return;
}

