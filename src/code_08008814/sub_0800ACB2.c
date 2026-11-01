/* sub_0800ACB2  (original: 0x0800ACB2-0x0800ACCA in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined1 volatile DAT_0203f40c;


void sub_0800ACB2(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 * 0x40;
    iVar1 = iVar1 + 1;
    (&DAT_0203f40c)[iVar2] = (&DAT_0203f40c)[iVar2] & 0xfe;
  } while (iVar1 < 0x10);
  return;
}

