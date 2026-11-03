/* sub_08001732  (original: 0x08001732-0x0800174A in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_0800324E();
extern uint volatile DAT_030007cc;


bool sub_08001732(int *param_1)

{
  bool bVar1;
  
  bVar1 = *param_1 != DAT_030007cc;
  if (bVar1) {
    sub_0800324E(DAT_030007cc);
  }
  return bVar1;
}

