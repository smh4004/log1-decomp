/* sub_08002810  (original: 0x08002810-0x0800283C in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_03000610;
extern undefined4 volatile DAT_03000614;


undefined4 sub_08002810(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_03000610) {
    do {
      if (*(byte *)((&DAT_03000614)[iVar1] + 0x15) == param_1) {
        return (&DAT_03000614)[iVar1];
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_03000610);
  }
  return 0;
}

