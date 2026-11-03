/* sub_08009E7E  (original: 0x08009E7E-0x08009EAC in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009DB0();


void sub_08009E7E(int *param_1)

{
  int iVar1;
  
  iVar1 = ((uint)*(byte *)(param_1 + 2) - (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(char *)(param_1 + 2) = (char)((uint)iVar1 >> 0x18);
  if (iVar1 >> 0x18 < 1) {
    *(undefined1 *)(param_1 + 2) = 0;
    param_1[5] = 0x8009db1;
  }
  iVar1 = param_1[8];
  *(char *)(iVar1 + 0x10) = (char)param_1[2];
  *(byte *)(iVar1 + 0xc) = *(byte *)(iVar1 + 0xc) | 0x10;
  sub_08009DB0(param_1);
  return;
}

