/* sub_0800A182  (original: 0x0800A182-0x0800A1EE in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009AFE();
extern undefined volatile gUnknown_08011928;


void sub_0800A182(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = (uint)*(ushort *)(&gUnknown_08011928 + (uint)*(byte *)((int)param_1 + 0xd) * 2) * *param_1
          >> 0xe;
  *param_1 = uVar3;
  uVar1 = param_1[8];
  *(uint *)(uVar1 + 0x2c) = uVar3;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 2;
  uVar1 = param_1[1];
  puVar4 = param_1 + 2;
  if (*param_1 < uVar1) {
    *param_1 = uVar1;
    uVar3 = param_1[8];
    *(uint *)(uVar3 + 0x2c) = uVar1;
    *(byte *)(uVar3 + 0xc) = *(byte *)(uVar3 + 0xc) | 2;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xf7;
    param_1[5] = 0x8009aff;
    sub_08009AFE((int)param_1);
    return;
  }
  iVar2 = ((uint)(byte)*puVar4 + (uint)*(byte *)((int)param_1 + 0xb)) * 0x1000000;
  *(byte *)puVar4 = (byte)((uint)iVar2 >> 0x18);
  if (0x3f < iVar2 >> 0x18) {
    *(byte *)puVar4 = 0x40;
    param_1[5] = 0x8009cc3;
  }
  uVar1 = param_1[8];
  *(byte *)(uVar1 + 0x10) = (byte)*puVar4;
  *(byte *)(uVar1 + 0xc) = *(byte *)(uVar1 + 0xc) | 0x10;
  return;
}

