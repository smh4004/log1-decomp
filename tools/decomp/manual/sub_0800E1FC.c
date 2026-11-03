/* Ghidra's text, except the return value: this library function ends with GCC's `pop {r0}; bx r0`, so it returns
   with its own return address in r0 (Ghidra's in_lr). */
undefined4 sub_0800E1FC(undefined4 param_1,undefined4 param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar2 = REG_IME;
  REG_IME = 0;
  uVar1 = REG_WAITCNT;
  REG_WAITCNT = uVar1 & 0xf8ff | *(ushort *)(DAT_03004810 + 6);
  REG_DMA3SAD = param_1;
  REG_DMA3DAD = param_2;
  Ram040000dc = param_3 & 0xffff | 0x80000000;
  uVar1 = DAT_040000de;
  while ((uVar1 & 0x8000) != 0) {
    uVar1 = DAT_040000de;
  }
  REG_IME = uVar2;
  return (undefined4)__builtin_return_address(0);
}
