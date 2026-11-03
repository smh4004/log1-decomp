/* sub_0800ACFE  (original: 0x0800ACFE-0x0800AD3A in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 83% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_0203f400;
extern undefined1 volatile DAT_0203f40c;
extern undefined1 volatile DAT_0203f410;
extern undefined1 volatile DAT_0203f411;
extern undefined4 volatile DAT_0203f424;
extern undefined4 volatile DAT_0203f42c;
extern undefined volatile gUnknown_085C0B0C;


undefined * sub_0800ACFE(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    if (((&DAT_0203f40c)[iVar1 * 0x40] & 1) == 0) {
      iVar2 = iVar1 * 0x40;
      (&DAT_0203f42c)[iVar1 * 0x10] = 0x4000;
      (&DAT_0203f424)[iVar1 * 0x10] = &gUnknown_085C0B0C + param_1 * 0xc;
      (&DAT_0203f410)[iVar2] = 0x40;
      (&DAT_0203f411)[iVar2] = 0;
      (&DAT_0203f40c)[iVar2] = 0x1f;
      return &DAT_0203f400 + iVar2;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return (undefined *)0x0;
}

