/* sub_08009CC2  (original: 0x08009CC2-0x08009D00 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile gUnknown_08011BA8;


void sub_08009CC2(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(&gUnknown_08011BA8 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0x10;
  *param_1 = uVar2;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar2;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  if (*param_1 < uVar1) {
    *param_1 = uVar1;
    uVar2 = param_1[8];
    *(uint *)(uVar2 + 0x2c) = uVar1;
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf4;
  }
  return;
}

