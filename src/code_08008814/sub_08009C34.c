/* sub_08009C34  (original: 0x08009C34-0x08009C52 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined volatile gUnknown_08011928;


void sub_08009C34(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(&gUnknown_08011928 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0xe;
  *param_1 = uVar2;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar2;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  return;
}

