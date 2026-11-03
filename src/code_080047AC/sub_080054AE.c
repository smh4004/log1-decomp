/* sub_080054AE  (original: 0x080054AE-0x08005526 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: cand-error, equal, inconclusive.
 */
#include "ghidra_types.h"
extern int sub_08004C5C();
extern int sub_08004D10();
extern int __call_via_r3();
extern int volatile DAT_0300087c;
extern undefined1 volatile DAT_03000038;
extern undefined4 volatile gUnknown_085439E0;


void sub_080054AE(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  do {
    iVar4 = (int)uVar3 >> 3;
    bVar1 = (byte)(1 << (uVar3 & 7));
    if (((&DAT_03000038)[iVar4] & bVar1) == 0) {
      iVar2 = sub_08004C5C((&gUnknown_085439E0)[uVar3]);
      if (iVar2 != 0) {
        (&DAT_03000038)[iVar4] = (&DAT_03000038)[iVar4] | bVar1;
        sub_08004D10((&gUnknown_085439E0)[uVar3]);
        iVar4 = 0;
        if (0 < DAT_0300087c) {
          do {
            iVar2 = __call_via_r3();
            if (iVar2 != 0) {
              return;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < DAT_0300087c);
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x4b);
  return;
}

