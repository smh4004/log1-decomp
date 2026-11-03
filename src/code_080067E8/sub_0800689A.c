/* sub_0800689A  (original: 0x0800689A-0x0800697E in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 60% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002300();
extern int sub_0800994C();
extern int sub_0800ACFE();
extern int sub_0800286A();
extern int sub_08003398();
extern int sub_080028C4();
extern int sub_0800507A();
extern int volatile DAT_03000600;


undefined4 sub_0800689A(int param_1,int param_2,short *param_3)

{
  undefined4 uVar1;
  unsigned int __frame[8];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_20 ((short *)((char *)__frame + 0x0))
#define sStack_1c (*(short *)((char *)__frame + 0x4))
#define sStack_1a (*(short *)((char *)__frame + 0x6))
#define sStack_18 (*(short *)((char *)__frame + 0x8))
#define sStack_16 (*(short *)((char *)__frame + 0xa))
#define sStack_14 (*(short *)((char *)__frame + 0xc))
#define sStack_12 (*(short *)((char *)__frame + 0xe))
#define sStack_10 (*(short *)((char *)__frame + 0x10))
#define sStack_e (*(short *)((char *)__frame + 0x12))
  if (param_2 == 1) {
    if (*(int *)(param_3 + 6) != 0) {
      return 0;
    }
    sub_08002300((undefined4 *)&sStack_1c,param_1);
    sStack_14 = sStack_1c;
    sStack_12 = sStack_1a;
    if (((sStack_1c < param_3[2]) && (*param_3 < sStack_18)) &&
       ((sStack_1a < param_3[3] && (param_3[1] < sStack_16)))) {
      sub_0800507A(DAT_03000600,&sStack_14,1,0);
      sub_080028C4(param_1);
      sub_0800ACFE(0x16);
      sub_0800286A(6,0);
      return 1;
    }
  }
  else if (param_2 == 0) {
    sub_08002300((undefined4 *)asStack_20,param_1);
    sub_0800994C(&sStack_18,asStack_20,2);
    uVar1 = sub_08003398();
    sStack_10 = (short)uVar1;
    if ((((sStack_18 <= sStack_10) && (sStack_10 < sStack_14)) &&
        (sStack_e = (short)((uint)uVar1 >> 0x10), sStack_16 <= sStack_e)) && (sStack_e < sStack_12))
    {
      return 1;
    }
  }
  return 0;
}

