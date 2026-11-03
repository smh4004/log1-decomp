/* sub_0800AB1A  (original: 0x0800AB1A-0x0800AB3E in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int WaitForVBlank();
extern undefined2 volatile DAT_040000d2;
extern ushort volatile DAT_04000102;
extern ushort volatile REG_SOUNDCNT_X;
extern undefined2 volatile DAT_040000c6;
extern ushort volatile REG_IE;


void sub_0800AB1A(void)

{
  ushort uVar1;
  
  uVar1 = REG_IE;
  REG_IE = uVar1 | 0x400;
  WaitForVBlank(0x400);
  DAT_04000102 = 0;
  DAT_040000c6 = 0;
  DAT_040000d2 = 0;
  REG_SOUNDCNT_X = 0;
  return;
}

