/* sub_08000784  (original: 0x08000784-0x080007D2 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 2/2 snapshots, 42% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_0800B316();
extern byte volatile DAT_02029b94;
extern byte volatile DAT_03000020;
extern byte volatile DAT_02029b95;
extern byte volatile DAT_03000021;
extern byte volatile DAT_02029b96;
extern byte volatile DAT_03000022;
extern undefined4 volatile DAT_03000024;
extern undefined4 volatile DAT_02029b98;
extern undefined4 volatile DAT_02029b9c;
#define _DAT_02029b94 (*(undefined1 volatile *)0x02029B94)
#define _DAT_03000020 (*(undefined1 volatile *)0x03000020)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_08000784(void)

{
  byte bVar1;
  uint uVar2;
  
  if ((((_DAT_02029b94 & 0xff) != (_DAT_03000020 & 0xff)) || (DAT_02029b95 != DAT_03000021)) ||
     (DAT_02029b96 != DAT_03000022)) {
    uVar2 = (uint)DAT_03000022;
    bVar1 = DAT_03000020 ^ (byte)((DAT_03000021 ^ 3) << 2);
    _DAT_03000020 = CONCAT13(bVar1 ^ (byte)((uVar2 ^ 3) << 6),_DAT_03000020) ^ 0x1000000;
    DAT_02029b98 = DAT_03000024;
    _DAT_02029b94 = _DAT_03000020;
    sub_0800B316(&DAT_02029b94,(undefined1 *)&DAT_02029b9c);
  }
  return;
}

