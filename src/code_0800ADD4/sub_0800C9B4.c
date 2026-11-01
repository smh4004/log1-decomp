/* sub_0800C9B4  (original: 0x0800C9B4-0x0800C9DA in asm/code_0800ADD4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int volatile DAT_030043a0;


void sub_0800C9B4(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10) + '\x01';
  *(char *)(param_1 + 0x10) = cVar1;
  if ((DAT_030043a0 != param_1) && (DAT_030043a0 != 0)) {
    *(char *)(param_1 + 0x12) = '\x01' - ((char)(cVar1 * ' ') >> 7);
    return;
  }
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}

