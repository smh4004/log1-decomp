/* sub_08009766  (original: 0x08009766-0x08009798 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_0800AB3E();
extern int __call_via_r1();
extern int WaitForVBlank();
extern int sub_0800A664();
extern int * volatile DAT_03003b64;


void sub_08009766(void)

{
  int iVar1;
  
  do {
    __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 8) + *DAT_03003b64));
    sub_0800AB3E();
    WaitForVBlank(1);
    sub_0800A664();
    iVar1 = __call_via_r1(DAT_03003b64,(undefined *)(*(int *)(*DAT_03003b64 + 0xc) + *DAT_03003b64))
    ;
  } while (iVar1 == 0);
  return;
}

