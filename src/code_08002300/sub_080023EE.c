/* sub_080023EE  (original: 0x080023EE-0x0800241E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08004FFA();
extern undefined4 volatile DAT_03000600;


void sub_080023EE(int param_1,short *param_2)

{
  unsigned int __frame[5];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_14 (*(undefined4 *)((char *)__frame + 0x0))
#define local_10 (*(undefined4 *)((char *)__frame + 0x4))
#define local_c (*(undefined4 *)((char *)__frame + 0x8))
  local_14 = CONCAT22(param_2[1] + (*(short **)(param_1 + 0x1c))[1],
                      *param_2 + **(short **)(param_1 + 0x1c));
  local_10 = *(undefined4 *)param_2;
  local_c = local_14;
  sub_08004FFA(DAT_03000600,&local_10);
  return;
}

