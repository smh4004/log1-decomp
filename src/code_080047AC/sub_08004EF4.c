/* sub_08004EF4  (original: 0x08004EF4-0x08004F56 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 34% of instructions covered.
 */
#include "ghidra_types.h"


char sub_08004EF4(short *param_1,short *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = (int)param_2[1];
  iVar5 = (int)*param_1;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar3 = iVar5 * iVar2 + (int)*param_2;
  cVar1 = *(char *)(iVar4 + iVar3);
  if (cVar1 == '\0') {
    if ((int)*param_2 < iVar5 + -1) {
      cVar1 = *(char *)(iVar4 + iVar3 + 1);
      if (cVar1 == '\0') {
        if (iVar2 < param_1[1] + -1) {
          cVar1 = *(char *)(iVar4 + iVar5 + iVar3);
          if (cVar1 == '\0') {
            cVar1 = *(char *)(iVar4 + iVar5 + iVar3 + 1);
          }
        }
        else {
          cVar1 = '\0';
        }
      }
    }
    else if (iVar2 < param_1[1] + -1) {
      cVar1 = *(char *)(iVar4 + iVar5 + iVar3);
    }
    else {
      cVar1 = '\0';
    }
  }
  return cVar1;
}

