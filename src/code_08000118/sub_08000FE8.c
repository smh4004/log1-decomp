/* sub_08000FE8  (original: 0x08000FE8-0x08001008 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern int sub_08008D8A();
extern byte volatile REG_BLDY;


undefined4 sub_08000FE8(int param_1)
{
  undefined4 __r0 = (undefined4)param_1;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  byte bVar1;
  
  __r0 = (undefined4)sub_08008D8A(0x2029d94);
  if (*(char *)(param_1 + 4) != '\0') {
    bVar1 = *(char *)(param_1 + 4) - 1;
    *(byte *)(param_1 + 4) = bVar1;
    REG_BLDY = bVar1 >> 2;
  }
  return __r0;
  return __r0;
}
