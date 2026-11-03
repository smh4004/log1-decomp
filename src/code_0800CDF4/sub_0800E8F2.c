/* sub_0800E8F2  (original: 0x0800E8F2-0x0800E95A in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E7D8();


uint * sub_0800E8F2(uint *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  uVar4 = param_2 + 4;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  uVar4 = uVar4 + 7 & 0xfffffff8;
  if (param_2 - 1U < uVar4) {
    do {
      puVar3 = (uint *)param_1[1];
      puVar2 = param_1;
      while (puVar1 = puVar3, puVar1 != (uint *)0x0) {
        if (uVar4 <= *puVar1) {
          if (*puVar1 < uVar4 + 8) {
            puVar2[1] = puVar1[1];
          }
          else {
            piVar6 = (int *)((int)puVar1 + uVar4);
            piVar6[1] = puVar1[1];
            *piVar6 = *puVar1 - uVar4;
            puVar2[1] = (uint)piVar6;
            *puVar1 = uVar4;
          }
          return puVar1 + 1;
        }
        puVar2 = puVar1;
        puVar3 = (uint *)puVar1[1];
      }
      iVar5 = sub_0800E7D8((int *)param_1,uVar4);
    } while (iVar5 != 0);
  }
  return (uint *)0x0;
}

