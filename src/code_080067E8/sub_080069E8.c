/* sub_080069E8  (original: 0x080069E8-0x080069FA in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08002910();
extern int sub_0800A714();


void sub_080069E8(int param_1)

{
  undefined1 uVar1;
  
  sub_08002910();
  uVar1 = sub_0800A714(0x80);
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  return;
}

