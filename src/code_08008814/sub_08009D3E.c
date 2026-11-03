/* sub_08009D3E  (original: 0x08009D3E-0x08009DB0 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 87% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined volatile gUnknown_080116C8;


void sub_08009D3E(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0x1e);
  }
  bVar1 = *(byte *)((int)param_1 + 10);
  if (-1 < (int)((uint)bVar1 << 0x1d)) {
    return;
  }
  if ((param_1[6] & 0x11) == 0) {
    if (-1 < (int)((uint)bVar1 << 0x1c)) goto _08009D94;
  }
  else {
    if (*(byte *)((int)param_1 + 0x1a) == 0xff) goto _08009D94;
    param_1[1] = *(uint *)(&gUnknown_080116C8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4);
    *(byte *)((int)param_1 + 10) = bVar1 | 8;
  }
  if (*param_1 < param_1[1]) {
    param_1[5] = 0x8009d01;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  }
  else {
    param_1[5] = 0x8009cc3;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  }
_08009D94:
  if ((param_1[6] & 0x44) != 0) {
    *(char *)(param_1 + 2) = (char)param_1[7];
    uVar2 = param_1[8];
    *(char *)(uVar2 + 0x10) = (char)param_1[2];
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 0x10;
  }
  return;
}

