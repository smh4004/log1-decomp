/* sub_08006530  (original: 0x08006530-0x0800658C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800AEC6();
extern int sub_080060E6();
extern int sub_0800507A();
extern int volatile DAT_030005fc;
extern undefined4 volatile DAT_03000600;


void sub_08006530(int param_1)

{
  unsigned int __frame[6];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define local_18 (*(undefined4 *)((char *)__frame + 0x0))
#define local_10 (*(undefined4 *)((char *)__frame + 0x8))
  if (*(char *)(param_1 + 4) == DAT_030005fc) {
    local_18 = CONCAT22(*(short *)(param_1 + 0xe) + 8,*(short *)(param_1 + 0xc) + 0xf);
    local_10 = local_18;
    sub_0800AEC6(&local_10,*(undefined1 *)(param_1 + 5));
    sub_0800507A(DAT_03000600,param_1 + 0xc,1,0);
    sub_080060E6(param_1 + 8);
  }
  return;
}

