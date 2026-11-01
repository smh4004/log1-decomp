/* sub_08004FD8  (original: 0x08004FD8-0x08004FF6 in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined volatile DAT_02005040;


undefined4 sub_08004FD8(undefined4 param_1,uint param_2,int param_3)

{
  if (((uint)(byte)(&DAT_02005040)[param_3 * 0x1d4c + ((int)param_2 >> 3)] & 1 << (param_2 & 7)) !=
      0) {
    return 1;
  }
  return 0;
}

