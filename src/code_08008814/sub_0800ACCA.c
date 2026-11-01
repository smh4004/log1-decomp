/* sub_0800ACCA  (original: 0x0800ACCA-0x0800ACFE in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined volatile DAT_0203f400;
extern undefined1 volatile DAT_0203f40c;
extern undefined1 volatile DAT_0203f410;
extern undefined1 volatile DAT_0203f411;
extern undefined4 volatile DAT_0203f424;
extern undefined4 volatile DAT_0203f42c;


undefined * sub_0800ACCA(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    if (((&DAT_0203f40c)[iVar1 * 0x40] & 1) == 0) {
      iVar2 = iVar1 * 0x40;
      (&DAT_0203f424)[iVar1 * 0x10] = param_1;
      (&DAT_0203f42c)[iVar1 * 0x10] = 0x4000;
      (&DAT_0203f410)[iVar2] = param_2;
      (&DAT_0203f411)[iVar2] = param_3;
      (&DAT_0203f40c)[iVar2] = 0x1f;
      return &DAT_0203f400 + iVar2;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  return (undefined *)0x0;
}

