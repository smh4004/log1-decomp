/* sub_0800B2DE  (original: 0x0800B2DE-0x0800B316 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_0800E27C();
extern int sub_0800E0F8();
extern int sub_0800E090();
extern undefined4 volatile DAT_03004390;
extern undefined volatile DAT_02029b94;
extern undefined volatile DAT_03003ba0;


void sub_0800B2DE(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = sub_0800E090(4);
  if (iVar1 == 0) {
    sub_0800E0F8(6,&DAT_03003ba0);
    uVar2 = 0;
    do {
      sub_0800E27C(uVar2 & 0xffff,&DAT_02029b94 + uVar2 * 8);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x40);
    DAT_03004390 = 1;
    return;
  }
  DAT_03004390 = 0;
  return;
}

