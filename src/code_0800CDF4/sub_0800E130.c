/* sub_0800E130  (original: 0x0800E130-0x0800E1B8 in asm/code_0800CDF4.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern ushort volatile DAT_03004650;
extern undefined2 * volatile DAT_0300464c;
extern sbyte volatile DAT_03004644;
extern byte volatile DAT_03004648;
extern ushort volatile DAT_03004646;
extern undefined2 volatile REG_IE;
extern ushort volatile REG_IF;
extern ushort volatile REG_IME;

/* Ghidra's text, except the return value: this library function ends with GCC's `pop {r0}; bx r0`, so it returns
   with its own return address in r0 (Ghidra's in_lr). */
undefined4 sub_0800E130(undefined2 *param_1)

{
  ushort uVar1;
  
  DAT_03004650 = REG_IME;
  REG_IME = 0;
  DAT_0300464c[1] = 0;
  REG_IF = (short)(8 << DAT_03004644);
  uVar1 = REG_IE;
  REG_IE = uVar1 | (ushort)(8 << DAT_03004644);
  DAT_03004648 = 0;
  DAT_03004646 = *param_1;
  *DAT_0300464c = param_1[1];
  DAT_0300464c[1] = param_1[2];
  REG_IME = 1;
  return (undefined4)__builtin_return_address(0);
}
