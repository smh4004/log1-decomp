/* sub_080031FA  (original: 0x080031FA-0x08003232 in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800507A();
extern int sub_08002486();
extern int sub_0800236E();
extern undefined * volatile gUnknown_085C2614;
extern char volatile DAT_030007b0;
extern int volatile DAT_030007bc;
extern int volatile DAT_03000600;


void sub_080031FA(void)

{
  unsigned int __frame[5];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define asStack_14 ((short *)((char *)__frame + 0x0))
  if (DAT_030007b0 != '\0') {
    sub_08002486(DAT_030007bc,*(int *)(DAT_030007bc + 0x1c),&gUnknown_085C2614,0);
    sub_0800236E((undefined4 *)asStack_14,DAT_030007bc);
    sub_0800507A(DAT_03000600,asStack_14,1,0);
    DAT_030007b0 = '\0';
    DAT_030007bc = 0;
  }
  return;
}

