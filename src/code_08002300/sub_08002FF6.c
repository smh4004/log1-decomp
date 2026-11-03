/* sub_08002FF6  (original: 0x08002FF6-0x0800301C in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08005C7A();
extern int volatile DAT_030007b8;
extern undefined4 volatile DAT_030007d8;
extern undefined4 volatile DAT_030007cc;
extern undefined4 volatile DAT_030007c4;
extern undefined4 volatile DAT_030007d0;
extern undefined4 volatile DAT_030007c8;
extern byte volatile DAT_030007ac;


void sub_08002FF6(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_030007b8 + 0x3c);
  DAT_030007d8 = *(undefined4 *)(iVar1 + 0x84);
  DAT_030007cc = *(undefined4 *)(iVar1 + 0x50);
  DAT_030007c4 = *(undefined4 *)(iVar1 + 0x58);
  DAT_030007d0 = *(undefined4 *)(iVar1 + 0x4c);
  DAT_030007c8 = *(undefined4 *)(iVar1 + 0x54);
  DAT_030007ac = sub_08005C7A();
  return;
}

