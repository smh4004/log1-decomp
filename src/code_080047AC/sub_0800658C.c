/* sub_0800658C  (original: 0x0800658C-0x0800660A in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 68% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08002E42();
extern int sub_0800A714();
extern int sub_0800236E();
extern int sub_08002910();
extern int sub_0800507A();
extern int volatile DAT_03000600;


void sub_0800658C(int param_1)

{
  undefined1 uVar1;
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(short *)((char *)__frame + 0x0))
#define local_16 (*(short *)((char *)__frame + 0x2))
#define local_14 (*(short *)((char *)__frame + 0x4))
#define local_12 (*(short *)((char *)__frame + 0x6))
#define local_10 (*(short *)((char *)__frame + 0x8))
#define local_e (*(short *)((char *)__frame + 0xa))
#define local_c (*(short *)((char *)__frame + 0xc))
#define local_a (*(short *)((char *)__frame + 0xe))
  sub_08002910(param_1);
  uVar1 = sub_0800A714(0x80);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  sub_0800236E((undefined4 *)&local_18,param_1);
  local_10 = local_18;
  local_e = local_16;
  local_c = local_14;
  local_a = local_12;
  sub_08002E42((undefined4 *)&local_18);
  if ((((local_14 <= local_10) || (local_c <= local_18)) || (local_12 <= local_e)) ||
     (local_a <= local_16)) {
    sub_0800236E((undefined4 *)&local_18,param_1);
    sub_0800507A(DAT_03000600,&local_18,0,0);
  }
  return;
}

