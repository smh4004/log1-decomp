/* sub_08003232  (original: 0x08003232-0x0800324E in asm/code_08002300.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: r0-void.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_030007c0;
#define _DAT_030007c0 (*(undefined4 volatile *)0x030007C0)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sub_08003232(short *param_1)
{
  undefined4 __r0 = (undefined4)param_1;   /* what the original leaves in r0 (see autodecomp.py fixvoid) */
  undefined4 local_4;
  
  local_4 = CONCAT22(param_1[1] << 4,*param_1 << 4);
  _DAT_030007c0 = local_4;
  return __r0;
  return __r0;
}
