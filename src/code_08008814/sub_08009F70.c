/* sub_08009F70  (original: 0x08009F70-0x0800A068 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009AD2();
extern int sub_08009AFE();
extern undefined volatile DAT_08011df4;
extern undefined volatile gUnknown_080116C8;
extern undefined volatile gUnknown_08011DE8;


void sub_08009F70(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 3) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    iVar3 = 0;
    if ((param_1[6] & 0x44) != 0) {
      *(char *)(param_1 + 2) = (char)param_1[7];
      uVar2 = param_1[8];
      *(char *)(uVar2 + 0x10) = (char)param_1[2];
      *(byte *)(uVar2 + 0xc) = *(byte *)(uVar2 + 0xc) | 0x10;
    }
    bVar1 = (byte)param_1[3];
    if ((bVar1 & 0xf) == 0) {
      *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
      iVar3 = 1;
      if (*(char *)((int)param_1 + 0xb) == '\x0f') {
        sub_08009AFE((int)param_1);
      }
    }
    else {
      uVar2 = ((uint)bVar1 << 0x18) >> 0x1c;
      if (uVar2 == 0) {
        iVar3 = 2;
        *(char *)((int)param_1 + 0xb) = (char)param_1[3];
        if (*(char *)((int)param_1 + 0xb) == '\x0f') {
          sub_08009AD2((int)param_1);
        }
      }
      else if ((~(uint)bVar1 & 0xf) == 0) {
        *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
        sub_08009AFE((int)param_1);
      }
      else if (uVar2 == 0xf) {
        *(byte *)((int)param_1 + 0xb) = bVar1 & 0xf;
        sub_08009AD2((int)param_1);
      }
    }
    if ((param_1[6] & 0x11) == 0) {
      bVar1 = *(byte *)((int)param_1 + 10);
      if ((-1 < (int)((uint)bVar1 << 0x1c)) && (iVar3 != 0)) {
        if (iVar3 == 1) {
          param_1[5] = 0x8009aff;
          *(byte *)((int)param_1 + 10) = bVar1 | 1;
        }
        else if (iVar3 == 2) {
          param_1[5] = 0x8009ad3;
          *(byte *)((int)param_1 + 10) = bVar1 | 1;
        }
      }
    }
    else {
      if (*(byte *)((int)param_1 + 0x1a) == 0xff) {
        return;
      }
      param_1[1] = *(uint *)(&gUnknown_080116C8 + (uint)*(byte *)((int)param_1 + 0x1a) * 4);
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 8;
    }
    if (param_1[1] <= *param_1) {
      param_1[5] = *(uint *)(&DAT_08011df4 + iVar3 * 4);
      *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
      return;
    }
    param_1[5] = *(uint *)(&gUnknown_08011DE8 + iVar3 * 4);
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
  }
  return;
}

