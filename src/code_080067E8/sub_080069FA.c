/* sub_080069FA  (original: 0x080069FA-0x08006A52 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002466();
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;


void sub_080069FA(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(short)((DAT_030007c0 >> 4) - *(short *)(param_1 + 0x20));
  iVar2 = (int)(short)((DAT_030007c2 >> 4) - *(short *)(param_1 + 0x22));
  if (0x100 < iVar1 * iVar1 + iVar2 * iVar2) {
    sub_08002466(param_1,1);
  }
  return;
}

