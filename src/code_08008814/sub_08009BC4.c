/* sub_08009BC4  (original: 0x08009BC4-0x08009C34 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 47% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009A20();
extern undefined volatile DAT_08011b28;
extern undefined volatile gUnknown_08011BA8;


void sub_08009BC4(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    uVar1 = (uint)*(byte *)((int)param_1 + 0xd);
    uVar2 = (uVar1 << 0x18) >> 0x1c;
    if (uVar2 != 0xf) {
      if (uVar2 == 0xe) {
        uVar1 = (uint)*(ushort *)(&DAT_08011b28 + ((uVar1 << 0x1c) >> 0x1b)) * *param_1 >> 0x10;
        *param_1 = uVar1;
        uVar2 = param_1[8];
        *(uint *)(uVar2 + 0x2c) = uVar1;
        *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
        return;
      }
      param_1[5] = 0x8009ba7;
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
      return;
    }
    uVar1 = (uint)*(ushort *)(&gUnknown_08011BA8 + ((uVar1 << 0x1c) >> 0x1b)) * *param_1 >> 0x10;
    *param_1 = uVar1;
    uVar2 = param_1[8];
    *(uint *)(uVar2 + 0x2c) = uVar1;
    *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 2;
  }
  return;
}

