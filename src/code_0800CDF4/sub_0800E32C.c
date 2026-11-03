/* sub_0800E32C  (original: 0x0800E32C-0x0800E408 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E130();
extern int sub_0800E1FC();
extern int sub_0800E1B8();
extern int volatile DAT_03004810;
extern undefined volatile DAT_0d000000;
extern char volatile DAT_03004648;
extern undefined volatile gUnknown_087A63B4;
#define _DAT_0d000000 (*(undefined4 volatile *)0x0D000000)

/* Ghidra's text, except the end: this library function returns with GCC's `pop {r1}; bx r1` (or r3), which Ghidra
   misread as a jump table. The value it "passed" to the jump is the return value in r0. */
undefined4 sub_0800E32C(uint param_1,ushort *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  unsigned int __frame[44];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_b0 ((undefined1 *)((char *)__frame + 0x0))
#define auStack_2e ((undefined2 *)((char *)__frame + 0x82))
  param_1 = param_1 & 0xffff;
  if (param_1 < *(ushort *)(DAT_03004810 + 4)) {
    bVar2 = *(byte *)(DAT_03004810 + 8);
    auStack_2e[bVar2 + 1] = 0;
    puVar5 = auStack_2e + bVar2;
    bVar2 = 0;
    do {
      uVar4 = (uint)*param_2;
      param_2 = param_2 + 1;
      bVar1 = 0;
      do {
        *puVar5 = (short)uVar4;
        puVar5 = puVar5 + -1;
        uVar4 = uVar4 >> 1;
        bVar1 = bVar1 + 1;
      } while (bVar1 < 0x10);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 4);
    for (bVar2 = 0; bVar2 < *(byte *)(DAT_03004810 + 8); bVar2 = bVar2 + 1) {
      *puVar5 = (short)param_1;
      puVar5 = puVar5 + -1;
      param_1 = param_1 >> 1;
    }
    *puVar5 = 0;
    puVar5[-1] = 1;
    sub_0800E1FC(auStack_b0,&DAT_0d000000,*(byte *)(DAT_03004810 + 8) + 0x43);
    sub_0800E130(&gUnknown_087A63B4);
    uVar3 = 0;
    do {
      if ((_DAT_0d000000 & 1) != 0) goto _0800E3EA;
    } while (DAT_03004648 == '\0');
    if ((_DAT_0d000000 & 1) == 0) {
      uVar3 = 0xc001;
    }
_0800E3EA:
    sub_0800E1B8();
  }
  else {
    uVar3 = 0x80ff;
  }
  return uVar3;
}
