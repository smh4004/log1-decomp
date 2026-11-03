/* sub_0800A9CC  (original: 0x0800A9CC-0x0800A9F6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined1 volatile DAT_03003d2c;
extern undefined1 volatile DAT_0203f04c;
extern undefined1 volatile DAT_0203f070;


void sub_0800A9CC(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  DAT_03003d2c = param_1;
  do {
    iVar2 = iVar1 * 0x40;
    (&DAT_0203f070)[iVar2] = param_1;
    iVar1 = iVar1 + 1;
    (&DAT_0203f04c)[iVar2] = (&DAT_0203f04c)[iVar2] | 0x10;
  } while (iVar1 < 0xf);
  return;
}

