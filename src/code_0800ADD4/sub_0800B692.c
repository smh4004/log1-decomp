/* sub_0800B692  (original: 0x0800B692-0x0800B6D6 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_080087A0();
extern int __16__rt_sdiv();
extern int volatile DAT_03003b6c;
extern int volatile DAT_030007e4;


void sub_0800B692(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 0x3c);
  sub_0800ACFE(10);
  iVar1 = *(int *)(iVar2 + 0x58);
  if (iVar1 < *(int *)(param_1 + 0x24)) {
    *(int *)(param_1 + 0x24) = iVar1;
  }
  iVar1 = __16__rt_sdiv(*(undefined4 *)(iVar2 + 0x58),*(int *)(param_1 + 0x24) * 300);
  sub_080087A0(iVar1 + 0x3c);
  DAT_030007e4 = iVar1 + 0x3c + DAT_03003b6c + 0x3c;
  return;
}

