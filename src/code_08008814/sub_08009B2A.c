/* sub_08009B2A  (original: 0x08009B2A-0x08009BA6 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 52% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08009AD2();
extern int sub_08009AFE();
extern int sub_08009A20();


void sub_08009B2A(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 3) = *(char *)((int)param_1 + 0x1e);
  }
  bVar1 = *(byte *)(param_1 + 3);
  if ((bVar1 & 0xf) == 0) {
    *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
    param_1[5] = 0x8009aff;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    if (*(char *)((int)param_1 + 0xb) == '\x0f') {
      sub_08009AFE((int)param_1);
    }
  }
  else {
    uVar2 = ((uint)bVar1 << 0x18) >> 0x1c;
    if (uVar2 != 0) {
      if ((~(uint)bVar1 & 0xf) == 0) {
        *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
        sub_08009AFE((int)param_1);
      }
      else if (uVar2 == 0xf) {
        *(byte *)((int)param_1 + 0xb) = bVar1 & 0xf;
        sub_08009AD2((int)param_1);
        return;
      }
      return;
    }
    *(undefined1 *)((int)param_1 + 0xb) = *(undefined1 *)(param_1 + 3);
    param_1[5] = 0x8009ad3;
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    if (*(char *)((int)param_1 + 0xb) == '\x0f') {
      sub_08009AD2((int)param_1);
      return;
    }
  }
  return;
}

