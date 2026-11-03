/* sub_0800B3FC(obj): copies the type byte (+0x13) of obj's parent (obj+0x3c), sets obj's position (+0x20/+0x22)
   to the parent's position plus (x, y) from the 6-byte entry `type` of the ROM table at 0x08011E50
   (DAT_08011e50 = gUnknown_08011E44 + 0xc), and stores the low byte of the entry's third halfword at obj+0xc. r0 is left as obj. Hand-written: the `push {r3, r4, r5}` that
   only reserves a scratch slot made the pipeline treat it as variadic (it isn't). */
int sub_0800B3FC(int param_1)
{
  int parent = *(int *)(param_1 + 0x3c);
  byte type = *(byte *)(parent + 0x13);
  unsigned short *ent = (unsigned short *)((byte *)&DAT_08011e50 + type * 6);
  unsigned short x, y;
  *(byte *)(param_1 + 0x13) = type;
  x = *(unsigned short *)(parent + 0x20) + ent[0];
  y = *(unsigned short *)(parent + 0x22) + ent[1];
  *(uint *)(param_1 + 0x20) = (uint)x | ((uint)y << 16);
  *(byte *)(param_1 + 0xc) = (byte)ent[2];
  return param_1;
}
