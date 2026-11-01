/* sub_08009A20  (original: 0x08009A20-0x08009AA2 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: equal, r0-void.
 */
#include "ghidra_types.h"
extern undefined volatile gUnknown_08591E4C;
extern undefined volatile gUnknown_080116C8;


void sub_08009A20(undefined4 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if ((bVar1 & 0x11) == 0) {
    if ((bVar1 & 0x44) != 0) {
      *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_1 + 7);
      iVar3 = param_1[8];
      *(undefined1 *)(iVar3 + 0x10) = *(undefined1 *)(param_1 + 7);
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x10;
    }
  }
  else if (*(byte *)((int)param_1 + 0x1a) == 0xff) {
    *(byte *)(param_1[8] + 0xc) = *(byte *)(param_1[8] + 0xc) & 0xfe;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) & 0xfb;
  }
  else {
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_1 + 7);
    uVar4 = *(undefined4 *)(&gUnknown_080116C8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4);
    *param_1 = uVar4;
    *(undefined1 *)((int)param_1 + 10) = 4;
    iVar3 = param_1[8];
    if ((int)((uint)bVar1 << 0x1a) < 0) {
      uVar2 = *(undefined1 *)(param_1 + 2);
      *(undefined4 *)(iVar3 + 0x2c) = uVar4;
      *(undefined1 *)(iVar3 + 0x10) = uVar2;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x17;
    }
    else {
      bVar1 = *(byte *)((int)param_1 + 0x1b);
      uVar2 = *(undefined1 *)(param_1 + 2);
      *(undefined4 *)(iVar3 + 0x2c) = uVar4;
      *(undefined **)(iVar3 + 0x24) = &gUnknown_08591E4C + (uint)bVar1 * 0xc;
      *(undefined1 *)(iVar3 + 0x10) = uVar2;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x1f;
    }
  }
  return;
}

