/* sub_0800A5C0  (original: 0x0800A5C0-0x0800A5F6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 12/12 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_0203ee24;
extern undefined1 volatile DAT_0203ee2e;
extern undefined1 volatile DAT_0203ee3c;
extern undefined1 volatile DAT_0203ee43;
extern undefined4 volatile DAT_0203ee44;
extern undefined volatile DAT_0203f040;
extern undefined1 volatile DAT_0203f04c;
extern undefined4 volatile DAT_0203f068;


void sub_0800A5C0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = iVar1 * 0x24;
    (&DAT_0203ee2e)[iVar3] = 0;
    (&DAT_0203ee43)[iVar3] = 0;
    (&DAT_0203ee3c)[iVar3] = 0;
    (&DAT_0203ee44)[iVar1 * 9] = &DAT_0203f040 + iVar1 * 0x40;
    (&DAT_0203f04c)[iVar1 * 0x40] = 0;
    iVar2 = iVar1 + 1;
    (&DAT_0203f068)[iVar1 * 0x10] = &DAT_0203ee24 + iVar3;
    iVar1 = iVar2;
  } while (iVar2 < 0xf);
  return;
}

