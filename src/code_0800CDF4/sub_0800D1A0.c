/* sub_0800D1A0  (original: 0x0800D1A0-0x0800D1CE in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002300();
extern int sub_0800AEC6();
extern int sub_0800507A();
extern undefined4 volatile DAT_03000600;


void sub_0800D1A0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  unsigned int __frame[4];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_10 ((undefined1 *)((char *)__frame + 0x0))
  iVar1 = sub_0800AEC6(param_2,param_1);
  *(undefined4 *)(iVar1 + 0x38) = 0x800d03d;
  *(undefined4 *)(iVar1 + 0x3c) = param_1;
  sub_08002300(auStack_10);
  sub_0800507A(DAT_03000600,auStack_10,0,0);
  return;
}

