/* sub_08000732  (original: 0x08000732-0x08000784 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; BLOCKED: passes the snapshot tests but changes the game on tools/harness/decomp_route.txt before its timing horizon (gamebisect.py).
 */
#include "ghidra_types.h"
extern int volatile DAT_03004390;
extern byte volatile DAT_02029b94;
extern undefined4 volatile DAT_02029b98;
extern undefined4 volatile DAT_03000024;
extern undefined4 volatile DAT_03000020;
#define _DAT_02029b94 (*(undefined1 volatile *)0x02029B94)
#define _DAT_03000020 (*(undefined4 volatile *)0x03000020)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000732(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 4;
  param_1[2] = 8;
  param_1[3] = 0;
  if (DAT_03004390 != 0) {
    if (((_DAT_02029b94 & 0xff ^ (_DAT_02029b94 >> 8 & 0xff ^ 3) << 2 ^
          (_DAT_02029b94 >> 0x10 & 0xff ^ 3) << 6 ^ 1) & 0xff) != _DAT_02029b94 >> 0x18) {
      _DAT_02029b94 = 0x80400;
    }
    DAT_03000024 = DAT_02029b98;
    _DAT_03000020 = _DAT_02029b94;
  }
  return;
}

