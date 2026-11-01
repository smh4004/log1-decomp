/* sub_0800F540  (original: 0x0800F540-0x0800F56E in asm/code_0800F31C.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"


int sub_0800F540(short *param_1,short *param_2)

{
  return (int)(short)(*param_1 - *param_2) * (int)(short)(*param_1 - *param_2) +
         (int)(short)(param_1[1] - param_2[1]) * (int)(short)(param_1[1] - param_2[1]);
}

