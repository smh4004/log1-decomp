/* sub_08002B70  (original: 0x08002B70-0x08002B8C in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08000F8C();
extern undefined4 volatile DAT_030000ec;
extern undefined4 volatile DAT_0300010c;
extern undefined4 volatile DAT_0300085c;


void sub_08002B70(int param_1)

{
  if (*(int *)(param_1 + 0x24) == 0x80) {
    sub_08000F8C(&DAT_030000ec,&DAT_0300085c,&DAT_0300010c);
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return;
}

