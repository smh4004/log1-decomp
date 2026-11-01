/* sub_0800A9A2  (original: 0x0800A9A2-0x0800A9CC in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 5/5 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined1 volatile DAT_03003d2d;
extern undefined1 volatile DAT_0203f40c;
extern undefined1 volatile DAT_0203f430;


void sub_0800A9A2(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  DAT_03003d2d = param_1;
  do {
    iVar2 = iVar1 * 0x40;
    (&DAT_0203f430)[iVar2] = param_1;
    iVar1 = iVar1 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] | 0x10;
  } while (iVar1 < 0x10);
  return;
}

