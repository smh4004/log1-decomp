/* sub_08009EDA  (original: 0x08009EDA-0x08009F70 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; not reached by the capture routes (compiles; unverified).
 */
#include "ghidra_types.h"
extern int sub_08009DB0();
extern int sub_08009AD2();
extern int sub_08009AFE();
extern int sub_08009A20();


void sub_08009EDA(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  sub_08009A20(param_1);
  if (*(char *)((int)param_1 + 0x1e) != '\0') {
    *(char *)(param_1 + 3) = *(char *)((int)param_1 + 0x1e);
  }
  if ((int)((uint)*(byte *)((int)param_1 + 10) << 0x1d) < 0) {
    if ((*(byte *)(param_1 + 6) & 0x11) != 0) {
      *(undefined1 *)((int)param_1 + 0x11) = 0;
    }
    bVar1 = *(byte *)(param_1 + 3);
    if ((bVar1 & 0xf) == 0) {
      *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
      param_1[5] = 0x8009ead;
      if (*(char *)((int)param_1 + 0xb) == '\x0f') {
        sub_08009AFE((int)param_1);
      }
    }
    else {
      uVar2 = ((uint)bVar1 << 0x18) >> 0x1c;
      if (uVar2 == 0) {
        *(char *)((int)param_1 + 0xb) = (char)param_1[3];
        param_1[5] = 0x8009e7f;
        if (*(char *)((int)param_1 + 0xb) == '\x0f') {
          sub_08009AD2((int)param_1);
        }
      }
      else if ((~(uint)bVar1 & 0xf) == 0) {
        *(byte *)((int)param_1 + 0xb) = bVar1 >> 4;
        sub_08009AFE((int)param_1);
        param_1[5] = 0x8009db1;
      }
      else if (uVar2 == 0xf) {
        *(byte *)((int)param_1 + 0xb) = bVar1 & 0xf;
        sub_08009AD2((int)param_1);
        param_1[5] = 0x8009db1;
      }
    }
    *(byte *)((int)param_1 + 10) = *(byte *)((int)param_1 + 10) | 1;
    sub_08009DB0(param_1);
  }
  return;
}

