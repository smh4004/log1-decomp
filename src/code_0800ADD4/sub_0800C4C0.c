/* sub_0800C4C0  (original: 0x0800C4C0-0x0800C5CE in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_080085A0();
extern int sub_0800236E();
extern int sub_08002466();
extern int sub_08006F1A();
extern int sub_08002E42();
extern int sub_0800507A();
extern undefined4 volatile DAT_030043a4;
extern int volatile DAT_030043a0;
extern undefined4 volatile DAT_030043a8;
extern short volatile DAT_030005f8;
extern short volatile DAT_030005fa;
extern ushort volatile DAT_0300444a;
extern ushort volatile DAT_030043f6;
extern ushort volatile DAT_0300444c;
extern ushort volatile DAT_030043f8;
extern undefined4 volatile DAT_030043e4;
extern undefined4 volatile DAT_03004458;
extern undefined4 volatile DAT_0300445c;
extern ushort volatile DAT_030043c6;
extern int volatile DAT_03004428;
extern int volatile DAT_0300442c;
extern ushort volatile DAT_03004430;
extern ushort volatile DAT_03004432;
extern int volatile DAT_03004624;
extern int volatile DAT_03000600;
#define _DAT_03004430 (*(undefined2 volatile *)0x03004430)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_0800C4C0(int param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_20 (*(undefined4 *)((char *)__frame + 0x0))
#define local_1c (*(undefined4 *)((char *)__frame + 0x4))
#define local_18 (*(undefined4 *)((char *)__frame + 0x8))
  DAT_030043a8 = *param_3;
  if ((short)DAT_030043a8 < 0) {
    DAT_030043a8 = DAT_030043a8 & 0xffff0000;
  }
  if ((int)DAT_030043a8 < 0) {
    DAT_030043a8 = DAT_030043a8 & 0xffff;
  }
  uVar1 = **(undefined4 **)(param_1 + 0x1c);
  (*(undefined2 *)((char *)&local_1c + 0)) = (short)uVar1;
  (*(undefined2 *)((char *)&local_1c + 0)) = DAT_030005f8 - (short)local_1c;
  (*(undefined2 *)((char *)&local_1c + 2)) = (short)((uint)uVar1 >> 0x10);
  (*(undefined2 *)((char *)&local_1c + 2)) = DAT_030005fa - (*(undefined2 *)((char *)&local_1c + 2));
  local_20 = CONCAT22((*(undefined2 *)((char *)&local_1c + 2)),(short)local_1c);
  local_18 = local_20;
  if ((short)local_1c < (short)DAT_030043a8) {
    DAT_030043a8 = CONCAT22((*(undefined2 *)((char *)&DAT_030043a8 + 2)),(short)local_1c);
  }
  if ((*(undefined2 *)((char *)&local_1c + 2)) < (*(undefined2 *)((char *)&DAT_030043a8 + 2))) {
    DAT_030043a8 = CONCAT22((*(undefined2 *)((char *)&local_1c + 2)),(short)DAT_030043a8);
  }
  DAT_0300444a = 1;
  DAT_030043f6 = 0;
  DAT_0300444c = 1;
  DAT_030043f8 = 0xc;
  DAT_030043e4 = 4;
  DAT_03004458 = 0;
  DAT_0300445c = 0;
  DAT_030043c6 = 0x8001;
  DAT_03004428 = (int)*(short *)(param_1 + 0x20) >> 3;
  DAT_0300442c = (int)*(short *)(param_1 + 0x22) >> 3;
  _DAT_03004430 = 0;
  DAT_03004432 = 0;
  DAT_030043a0 = param_1;
  DAT_030043a4 = param_2;
  DAT_03004624 = param_1;
  local_1c = uVar1;
  sub_080085A0(0x30043b0,(short *)(param_1 + 0x20));
  sub_0800236E(&local_20,param_1);
  sub_0800507A(DAT_03000600,(short *)&local_20,1,0);
  sub_08002E42(&local_20);
  sub_0800507A(DAT_03000600,(short *)&local_20,1,0);
  local_20 = CONCAT22((*(undefined2 *)((char *)&DAT_030043a8 + 2)) >> 3,(short)DAT_030043a8 >> 3);
  local_1c = local_20;
  sub_08006F1A(0x30043b0,(short *)&local_1c,0);
  sub_08002466(param_1,1);
  return;
}

