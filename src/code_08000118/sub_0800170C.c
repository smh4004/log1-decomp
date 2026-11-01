/* sub_0800170C  (original: 0x0800170C-0x08001730 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800324E();
extern int volatile DAT_030007d0;
extern int volatile DAT_030007cc;


undefined4 sub_0800170C(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_030007d0 == DAT_030007cc) {
    uVar1 = 0;
  }
  else {
    iVar2 = DAT_030007d0 + (DAT_030007cc >> 2);
    if (DAT_030007cc < iVar2) {
      iVar2 = DAT_030007cc;
    }
    sub_0800324E(iVar2);
    uVar1 = 1;
  }
  return uVar1;
}

