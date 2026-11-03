/* sub_0800E1B8  (original: 0x0800E1B8-0x0800E1FC in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern undefined2 * volatile DAT_0300464c;
extern sbyte volatile DAT_03004644;
extern ushort volatile DAT_03004650;
extern ushort volatile REG_IE;
extern ushort volatile REG_IME;


void sub_0800E1B8(void)

{
  ushort uVar1;
  
  REG_IME = 0;
  *DAT_0300464c = 0;
  DAT_0300464c[1] = 0;
  uVar1 = REG_IE;
  REG_IE = uVar1 & ~(ushort)(8 << DAT_03004644);
  REG_IME = DAT_03004650;
  return;
}

