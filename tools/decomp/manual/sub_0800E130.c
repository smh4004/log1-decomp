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
