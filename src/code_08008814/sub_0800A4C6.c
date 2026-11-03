/* sub_0800A4C6  (original: 0x0800A4C6-0x0800A530 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_0800A748();
extern int sub_0800A3E6();
extern int __call_via_r1();
extern int sub_0800A3A6();
extern char volatile DAT_03003cff;
extern char volatile DAT_03003d00;
extern undefined volatile DAT_0203ee24;
extern undefined1 volatile DAT_0203ee2e;
extern undefined volatile DAT_0203f040;


void sub_0800A4C6(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  DAT_03003cff = DAT_03003cff + -1;
  if (DAT_03003cff == '\0') {
    sub_0800A3E6();
    iVar3 = 0;
    do {
      sub_0800A3A6((int *)(&DAT_0203ee24 + iVar3 * 0x24));
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
    DAT_03003cff = DAT_03003d00;
  }
  else {
    iVar3 = 0;
    do {
      iVar2 = iVar3 * 0x24;
      bVar1 = (&DAT_0203ee2e)[iVar2];
      if (((bVar1 & 3) != 0) && (((bVar1 & 3) != 1 || ((int)((uint)bVar1 << 0x1d) < 0)))) {
        __call_via_r1(&DAT_0203ee24 + iVar2,*(undefined **)(iVar2 + 0x203ee38));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
  }
  iVar3 = 0;
  do {
    sub_0800A748((undefined4 *)(&DAT_0203f040 + iVar3 * 0x40));
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xf);
  return;
}

