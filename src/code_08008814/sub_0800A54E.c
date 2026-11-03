/* sub_0800A54E  (original: 0x0800A54E-0x0800A5B8 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_0800A4C6();
extern int sub_0800A80E();
extern char volatile DAT_03003cfc;
extern short volatile DAT_03003d30;
extern ushort volatile DAT_03003d06;
extern ushort volatile DAT_03003d04;
extern undefined volatile DAT_0203f040;
extern undefined volatile DAT_03003f90;


void sub_0800A54E(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_03003cfc == '\x01') {
    iVar3 = (int)DAT_03003d30;
    puVar2 = &DAT_03003f90;
    while (uVar4 = (uint)DAT_03003d06, (int)uVar4 < iVar3) {
      if (uVar4 != 0) {
        iVar1 = 0;
        do {
          sub_0800A80E((int *)(&DAT_0203f040 + iVar1 * 0x40),(int)puVar2,uVar4);
          iVar1 = iVar1 + 1;
        } while (iVar1 < 0xf);
        puVar2 = puVar2 + (uint)DAT_03003d06 * 4;
        iVar3 = iVar3 - (uint)DAT_03003d06;
      }
      sub_0800A4C6();
      DAT_03003d06 = DAT_03003d04;
    }
    iVar1 = 0;
    do {
      sub_0800A80E((int *)(&DAT_0203f040 + iVar1 * 0x40),(int)puVar2,iVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xf);
    DAT_03003d06 = DAT_03003d06 - (short)iVar3;
  }
  return;
}

