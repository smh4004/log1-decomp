/* sub_080051D0  (original: 0x080051D0-0x0800536C in asm/code_080047AC.s)
 * Ghidra decompilation, compiled with GCC; snapshots inconclusive (BIOS call or fault before return).
 */
#include "ghidra_types.h"
extern int sub_08005478();
extern int sub_08005EA6();
extern int sub_0800245A();
extern int sub_08002556();
extern int sub_0800930A();
extern int sub_08002716();
extern int sub_080097F8();
extern int sub_08008D8A();
extern int sub_0800994C();
extern int sub_08002896();
extern int sub_080090AE();
extern int sub_08002666();
extern int sub_080095DC();
extern int sub_08008D14();
extern short volatile DAT_030007c0;
extern short volatile DAT_030007c2;
extern short volatile DAT_0300060a;
extern ushort volatile DAT_03000874;
extern ushort volatile DAT_0300086c;
extern short volatile DAT_02029d96;
extern short volatile DAT_02029d98;
extern short volatile DAT_02029d9a;
extern short volatile DAT_02029d9c;
extern undefined1 volatile DAT_02029d94;
extern undefined4 volatile DAT_03000868;
extern undefined * volatile gUnknown_0815A4E8;
extern undefined4 volatile DAT_03000994;
extern short volatile UNK_0300086e;
extern short volatile UNK_03000870;
extern short volatile UNK_03000872;
extern short volatile UNK_03000876;
extern short volatile UNK_03000878;
extern short volatile UNK_0300087a;
extern undefined * volatile gUnknown_0815BF28;
extern undefined4 volatile REG_DMA3SAD;
extern undefined4 volatile REG_DMA3DAD;
extern ushort volatile DAT_040000de;
extern undefined * volatile gUnknown_08011480;
extern ushort volatile REG_DMA3CNT;
#define Ram040000dc (*(undefined2 volatile *)0x040000DC)
#define sRam0300086e (*(short volatile *)0x0300086E)
#define sRam03000876 (*(short volatile *)0x03000876)
#define _DAT_03000874 (*(undefined2 volatile *)0x03000874)
#define _DAT_0300086c (*(undefined2 volatile *)0x0300086C)
#define sRam0300087a (*(short volatile *)0x0300087A)
#define sRam03000878 (*(short volatile *)0x03000878)
#define sRam03000870 (*(short volatile *)0x03000870)
#define sRam03000872 (*(short volatile *)0x03000872)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_080051D0(int param_1,byte *param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *piVar5;
  unsigned int __frame[11];   /* stack slots at their original offsets (see autodecomp.stack_frame) */
#define uStack_2c (*(undefined4 *)((char *)__frame + 0x0))
#define uStack_28 (*(undefined4 *)((char *)__frame + 0x4))
#define local_24 ((undefined1 *)((char *)__frame + 0x8))
#define local_22 (*(ushort *)((char *)__frame + 0xa))
#define local_20 (*(undefined * *)((char *)__frame + 0xc))
#define iStack_1c (*(int *)((char *)__frame + 0x10))
#define local_18 (*(byte * *)((char *)__frame + 0x14))
  local_20 = (&gUnknown_0815BF28)[param_1];
  local_24[0] = (undefined1)param_1;
  local_22 = (ushort)*param_2;
  REG_DMA3SAD = 0x85c386a;
  REG_DMA3DAD = 0x5000002;
  Ram040000dc = 0xf;
  DAT_040000de = 0x8000;
  iStack_1c = param_1;
  local_18 = param_2;
  while( true ) {
    pcVar4 = local_20 + (uint)*local_18 * 8;
    *local_18 = pcVar4[1];
    if (*pcVar4 == -1) break;
    uStack_2c = CONCAT22(DAT_030007c2 >> 4,DAT_030007c0 >> 4);
    uStack_28 = uStack_2c;
    if ((int)(DAT_030007c2 >> 4) - (int)DAT_0300060a < 0x41) {
      sRam0300086e = 0xd;
    }
    else {
      sRam0300086e = 3;
    }
    sRam03000876 = sRam0300086e;
    if ((*pcVar4 == '4') || (*pcVar4 == 'b')) {
      _DAT_03000874 = 2;
      _DAT_0300086c = 8;
    }
    else {
      _DAT_03000874 = 0x18;
      _DAT_0300086c = 3;
    }
    DAT_02029d9a = _DAT_0300086c + 0x13;
    DAT_02029d9c = sRam0300086e + 4;
    sRam0300087a = sRam0300086e + 4;
    sRam03000878 = _DAT_03000874 + 4;
    DAT_02029d96 = _DAT_0300086c;
    DAT_02029d98 = sRam0300086e;
    sRam03000870 = DAT_02029d9a;
    sRam03000872 = DAT_02029d9c;
    sub_08008D14(&DAT_02029d94);
    sub_0800930A(&DAT_02029d94,*(undefined4 *)(pcVar4 + 4));
    sub_0800994C((short *)&uStack_2c,(short *)&DAT_0300086c,1);
    _DAT_0300086c = (short)uStack_2c;
    sRam0300086e = (*(undefined2 *)((char *)&uStack_2c + 2));
    sRam03000870 = (undefined2)uStack_28;
    sRam03000872 = (*(undefined2 *)((char *)&uStack_28 + 2));
    piVar5 = (int *)(&gUnknown_0815A4E8)[*pcVar4];
    puVar2 = (undefined4 *)sub_08002716(*pcVar4 * 4);
    uVar1 = sub_08005EA6(*piVar5);
    *(undefined1 *)((int)puVar2 + 0xd) = uVar1;
    uStack_28 = CONCAT22(sRam03000876 << 3,_DAT_03000874 << 3);
    *puVar2 = uStack_28;
    *(undefined1 *)(puVar2 + 3) = 0;
    uVar3 = sub_080095DC((int)piVar5);
    puVar2[2] = uVar3;
    sub_0800245A((int)puVar2,&gUnknown_08011480);
    sub_08002556(0,1);
    sub_08008D14(&DAT_02029d94);
    sub_080090AE(&DAT_02029d94,(short *)&DAT_0300086c);
    sub_080090AE(&DAT_02029d94,(short *)&DAT_03000874);
    sub_080097F8(&DAT_03000868);
    DAT_02029d96 = 0;
    DAT_02029d98 = 0;
    DAT_02029d9a = 0x1e;
    DAT_02029d9c = 0x14;
    (&DAT_03000994)[(uint)*(byte *)((int)puVar2 + 0xd) * 2] =
         (&DAT_03000994)[(uint)*(byte *)((int)puVar2 + 0xd) * 2] + -1;
    sub_08002666((int)puVar2);
    sub_08002556(0,1);
    sub_08002896();
  }
  sub_08008D14(&DAT_02029d94);
  sub_08008D8A(0x2029d94);
  sub_08005478(3,local_24);
  return;
}

