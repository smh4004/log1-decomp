/* sub_0800E408  (original: 0x0800E408-0x0800E45E in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E27C();
extern int volatile DAT_03004810;

/* Ghidra's text, except the end: this library function returns with GCC's `pop {r1}; bx r1` (or r3), which Ghidra
   misread as a jump table. The value it "passed" to the jump is the return value in r0. */
undefined4 sub_0800E408(ushort param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  short *psVar4;
  undefined4 uVar5;
  unsigned int __frame[5];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_14 ((short *)((char *)__frame + 0x0))
  psVar4 = asStack_14;
  uVar5 = 0;
  if (param_1 < *(ushort *)(DAT_03004810 + 4)) {
    sub_0800E27C(param_1,asStack_14);
    bVar3 = 0;
    do {
      sVar1 = *param_2;
      sVar2 = *psVar4;
      psVar4 = psVar4 + 1;
      param_2 = param_2 + 1;
      if (sVar1 != sVar2) {
        uVar5 = 0x8000;
        break;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 4);
  }
  else {
    uVar5 = 0x80ff;
  }
  return uVar5;
}
