/* sub_08000FE8  (original: 0x08000FE8-0x08001008 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern undefined1 volatile DAT_02029d94;
extern undefined1 volatile REG_BLDY;


void sub_08000FE8(int param_1)

{
  byte bVar1;
  
  sub_08008D8A(&DAT_02029d94);
  if (*(char *)(param_1 + 4) != '\0') {
    bVar1 = *(char *)(param_1 + 4) - 1;
    *(byte *)(param_1 + 4) = bVar1;
    REG_BLDY = bVar1 >> 2;
  }
  return;
}

