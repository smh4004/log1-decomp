/* sub_08002134  (original: 0x08002134-0x080022A4 in asm/code_08000118.s)
 * Ghidra decompilation, compiled with GCC; NOT equivalent: mem@03000000, r0.
 */
#include "ghidra_types.h"
extern int sub_0800F36C();
extern undefined4 volatile DAT_03000608;
extern short volatile DAT_0300060a;
extern short volatile DAT_030005f8;
extern short volatile DAT_030005fa;
extern short volatile DAT_0300060c;
extern short volatile DAT_0300060e;


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool sub_08002134(short *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short local_18;
  short sStack_16;
  short local_14;
  short sStack_12;
  short local_10;
  short sStack_e;
  
  uVar1 = sub_0800F36C(&DAT_03000608);
  uVar2 = sub_0800F36C(param_1);
  local_18 = (short)uVar2;
  local_10 = (short)uVar1;
  sStack_e = (short)((uint)uVar1 >> 0x10);
  local_14 = local_18 - local_10;
  sStack_16 = (short)((uint)uVar2 >> 0x10);
  sStack_12 = sStack_16 - sStack_e;
  if (local_14 < 1) {
    if (local_14 < 0) {
      local_14 = local_14 + 0x10;
      if (local_14 < -8) {
        local_14 = -8;
      }
      else if (0 < local_14) {
        local_14 = 0;
      }
    }
  }
  else {
    local_14 = local_14 + -0x10;
    if (local_14 < 9) {
      if (local_14 < 0) {
        local_14 = 0;
      }
    }
    else {
      local_14 = 8;
    }
  }
  if (sStack_12 < 1) {
    if (sStack_12 < 0) {
      sStack_12 = sStack_12 + 0x10;
      if (sStack_12 < -8) {
        sStack_12 = -8;
      }
      else if (0 < sStack_12) {
        sStack_12 = 0;
      }
    }
  }
  else {
    sStack_12 = sStack_12 + -0x10;
    if (sStack_12 < 9) {
      if (sStack_12 < 0) {
        sStack_12 = 0;
      }
    }
    else {
      sStack_12 = 8;
    }
  }
  DAT_03000608 = local_10 + local_14 + -0x78;
  DAT_0300060a = sStack_e + sStack_12 + -0x50;
  if (DAT_03000608 < 0) {
    DAT_03000608 = 0;
    local_14 = 0;
  }
  if (DAT_0300060a < 0) {
    DAT_0300060a = 0;
    sStack_12 = 0;
  }
  if (DAT_030005f8 + -0xf0 < (int)DAT_03000608) {
    DAT_03000608 = (short)(DAT_030005f8 + -0xf0);
    local_14 = 0;
  }
  if (DAT_030005fa + -0xa0 < (int)DAT_0300060a) {
    DAT_0300060a = (short)(DAT_030005fa + -0xa0);
    sStack_12 = 0;
  }
  DAT_0300060c = DAT_03000608 + 0xf0;
  DAT_0300060e = DAT_0300060a + 0xa0;
  return local_14 != 0 || sStack_12 != 0;
}

