/* sub_0800C20A  (original: 0x0800C20A-0x0800C232 in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800C188();
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_03000614;


void sub_0800C20A(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 4) = 0;
  iVar1 = DAT_03000610;
  iVar2 = 0;
  if (0 < DAT_03000610) {
    do {
      sub_0800C188(param_1,(&DAT_03000614)[iVar2]);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

