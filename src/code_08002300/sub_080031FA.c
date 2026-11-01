/* sub_080031FA  (original: 0x080031FA-0x08003232 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002486();
extern int sub_0800236E();
extern int sub_0800507A();
extern undefined * volatile gUnknown_085C2614;
extern char volatile DAT_030007b0;
extern int volatile DAT_030007bc;
extern undefined4 volatile DAT_03000600;


void sub_080031FA(void)

{
  unsigned int __frame[5];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_14 ((undefined1 *)((char *)__frame + 0x0))
  if (DAT_030007b0 != '\0') {
    sub_08002486(DAT_030007bc,*(undefined4 *)(DAT_030007bc + 0x1c),&gUnknown_085C2614,0);
    sub_0800236E(auStack_14,DAT_030007bc);
    sub_0800507A(DAT_03000600,auStack_14,1,0);
    DAT_030007b0 = '\0';
    DAT_030007bc = 0;
  }
  return;
}

