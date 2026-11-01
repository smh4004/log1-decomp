/* sub_080092A4  (original: 0x080092A4-0x080092CA in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 15/15 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"


int sub_080092A4(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  sVar4 = 0;
  iVar2 = 0;
  do {
    iVar1 = 0;
    sVar3 = sVar4;
    do {
      iVar5 = iVar1 * 2;
      sVar4 = sVar3 + 1;
      iVar1 = iVar1 + 1;
      *(short *)(iVar2 * 0x40 + param_1 + iVar5 + 0x24) = sVar3;
      sVar3 = sVar4;
    } while (iVar1 < 0x1e);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  return param_1;
  return param_1;   /* ADS constructor: returns this */
}
