/* sub_0800E812  (original: 0x0800E812-0x0800E86A in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800E7C4();
extern int sub_0800E8EE();
extern int sub_0800E95C();
extern int sub_0800E8E4();
extern int sub_0800E98C();
extern int sub_0800E880();


void sub_0800E812(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(uint *)((char *)__frame + 0x0))
  local_18 = param_4;
  iVar1 = sub_0800E8EE(0);
  if (param_2 < param_1 + iVar1) {
    iVar2 = sub_0800E98C(iVar1,&local_18);
    if (iVar2 == 0) {
      sub_0800E880(9,0);
    }
    if (local_18 != param_2) {
      param_1 = local_18;
    }
    param_2 = local_18 + iVar2;
  }
  iVar2 = sub_0800E7C4();
  *(uint *)(iVar2 + 8) = param_1;
  uVar3 = param_1 + iVar1;
  sub_0800E8E4(param_1);
  if (param_2 != uVar3) {
    sub_0800E95C(*(undefined4 *)(iVar2 + 8),uVar3,param_2 - uVar3);
  }
  return;
}

