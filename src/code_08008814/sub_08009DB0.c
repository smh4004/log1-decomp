/* sub_08009DB0  (original: 0x08009DB0-0x08009DF4 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined volatile DAT_080118a8;
extern undefined volatile DAT_08011b28;
extern undefined volatile gUnknown_08011DA8;


undefined4 sub_08009DB0(int *param_1)
{
  undefined4 __r0 = (undefined4)param_1;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(byte *)((int)param_1 + 0x11) + (uint)*(byte *)((int)param_1 + 0xf) & 0x3f;
  *(char *)((int)param_1 + 0x11) = (char)uVar1;
  iVar2 = (int)((int)(char)(&gUnknown_08011DA8)[uVar1] * (uint)*(byte *)(param_1 + 4)) >> 6;
  if (iVar2 < 0) {
    uVar1 = (uint)*(ushort *)(&DAT_08011b28 + iVar2 * -2) * *param_1 >> 0x10;
  }
  else {
    uVar1 = (uint)*(ushort *)(&DAT_080118a8 + iVar2 * 2) * *param_1 >> 0xf;
  }
  iVar2 = param_1[8];
  *(uint *)(iVar2 + 0x2c) = uVar1;
  *(byte *)(iVar2 + 0xc) = *(byte *)(iVar2 + 0xc) | 2;
  return __r0;
  return __r0;
}
