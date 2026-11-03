/* sub_0800E27C  (original: 0x0800E27C-0x0800E32C in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int sub_0800E1FC();
extern int volatile DAT_03004810;
extern undefined volatile DAT_0d000000;

/* Ghidra's text, except the end: this library function returns with GCC's `pop {r1}; bx r1` (or r3), which Ghidra
   misread as a jump table. The value it "passed" to the jump is the return value in r0. */
undefined4 sub_0800E27C(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  unsigned int __frame[38];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_98 ((undefined1 *)((char *)__frame + 0x0))
#define auStack_96 ((ushort *)((char *)__frame + 0x2))
  param_1 = param_1 & 0xffff;
  if (param_1 < *(ushort *)(DAT_03004810 + 4)) {
    puVar5 = auStack_96 + *(byte *)(DAT_03004810 + 8);
    bVar1 = 0;
    if (*(byte *)(DAT_03004810 + 8) != 0) {
      do {
        *puVar5 = (ushort)param_1;
        puVar5 = puVar5 + -1;
        param_1 = param_1 >> 1;
        bVar1 = bVar1 + 1;
      } while (bVar1 < *(byte *)(DAT_03004810 + 8));
    }
    *puVar5 = 1;
    puVar5[-1] = 1;
    sub_0800E1FC(auStack_98,&DAT_0d000000,*(byte *)(DAT_03004810 + 8) + 3);
    sub_0800E1FC(&DAT_0d000000,auStack_98,0x44);
    puVar5 = auStack_96 + 3;
    puVar6 = (undefined2 *)(param_2 + 6);
    bVar1 = 0;
    do {
      uVar4 = 0;
      bVar2 = 0;
      do {
        uVar4 = (uVar4 << 0x11) >> 0x10 | *puVar5 & 1;
        puVar5 = puVar5 + 1;
        bVar2 = bVar2 + 1;
      } while (bVar2 < 0x10);
      *puVar6 = (short)uVar4;
      puVar6 = puVar6 + -1;
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80ff;
  }
  return uVar3;
}
