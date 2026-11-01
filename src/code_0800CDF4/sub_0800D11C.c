/* sub_0800D11C  (original: 0x0800D11C-0x0800D19C in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002300();
extern int sub_08002E42();
extern int sub_0800245A();
extern int sub_0800507A();
extern undefined4 volatile DAT_03000600;
extern undefined * volatile gUnknown_08011E00;


void sub_0800D11C(int param_1)

{
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(short *)((char *)__frame + 0x0))
#define sStack_16 (*(short *)((char *)__frame + 0x2))
#define sStack_14 (*(short *)((char *)__frame + 0x4))
#define sStack_12 (*(short *)((char *)__frame + 0x6))
#define sStack_10 (*(short *)((char *)__frame + 0x8))
#define sStack_e (*(short *)((char *)__frame + 0xa))
#define sStack_c (*(short *)((char *)__frame + 0xc))
#define sStack_a (*(short *)((char *)__frame + 0xe))
  if (*(int *)(param_1 + 0x24) == 0) {
    sub_08002E42(&local_18);
    sub_08002300(&sStack_10,param_1);
    if ((((local_18 < sStack_c) && (sStack_10 < sStack_14)) && (sStack_16 < sStack_a)) &&
       (sStack_e < sStack_12)) {
      *(undefined4 *)(param_1 + 0x24) = 900;
    }
    else {
      sub_0800245A(param_1,&gUnknown_08011E00);
      *(undefined4 *)(param_1 + 0x38) = 0x800d03d;
      sub_08002300(&sStack_10,param_1);
      sub_0800507A(DAT_03000600,&sStack_10,0,0);
    }
  }
  else {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  }
  return;
}

