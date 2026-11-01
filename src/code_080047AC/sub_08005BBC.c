/* sub_08005BBC  (original: 0x08005BBC-0x08005BE2 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800ACFE();
extern int sub_08004E98();
extern int sub_08008CE8();
extern int volatile DAT_03000988;
extern undefined4 volatile DAT_03000864;


void sub_08005BBC(void)

{
  unsigned int __frame[18];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define auStack_48 ((undefined1 *)((char *)__frame + 0x0))
  sub_08008CE8(auStack_48,"You reached level %d!",DAT_03000988 + 1);
  sub_0800ACFE(6);
  sub_08004E98(&DAT_03000864,auStack_48);
  return;
}

