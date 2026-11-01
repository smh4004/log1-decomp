/* sub_0800640C  (original: 0x0800640C-0x0800647C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08006330();
extern int sub_0800245A();
extern int sub_08002716();
extern int sub_08000954();
extern undefined volatile DAT_03000070;
extern undefined * volatile gUnknown_08011648;


void sub_0800640C(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  
  iVar1 = sub_08002716();
  local_18 = CONCAT22((short)(*(short *)(param_1 + 10) + *(short *)(param_1 + 0xe)) >> 1,
                      (short)(*(short *)(param_1 + 8) + *(short *)(param_1 + 0xc)) >> 1);
  *(undefined4 *)(iVar1 + 0x20) = local_18;
  *(int *)(iVar1 + 0x3c) = param_1;
  iVar2 = sub_08000954(param_1);
  if (iVar2 == 0) {
    sub_0800245A(iVar1,&gUnknown_08011648);
    *(undefined4 *)(iVar1 + 0x38) = 0x800636d;
  }
  else {
    sub_08006330(iVar1,(&DAT_03000070)[*(byte *)(param_1 + 7)]);
  }
  return;
}

