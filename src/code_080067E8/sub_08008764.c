/* sub_08008764  (original: 0x08008764-0x080087A0 in asm/code_080067E8.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 100% of instructions covered.
 */
#include "ghidra_types.h"
extern undefined4 volatile DAT_03003b40;
extern undefined4 volatile DAT_03003b44;
extern undefined volatile DAT_03003b38;
extern undefined volatile DAT_03003b3c;
#define _DAT_03003b40 (*(undefined4 volatile *)0x03003B40)
#define _DAT_03003b44 (*(undefined4 volatile *)0x03003B44)
#define _DAT_03003b38 (*(undefined4 volatile *)0x03003B38)
#define _DAT_03003b3c (*(undefined4 volatile *)0x03003B3C)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08008764(undefined4 param_1)

{
  undefined4 local_10;
  undefined2 local_c;
  undefined2 uStack_a;
  
  _DAT_03003b40 = 0;
  local_c = (short)param_1;
  uStack_a = (short)((uint)param_1 >> 0x10);
  local_10 = CONCAT22(uStack_a << 3,local_c << 3);
  _DAT_03003b44 = local_10;
  _DAT_03003b38 = 0;
  _DAT_03003b3c = param_1;
  return;
}

