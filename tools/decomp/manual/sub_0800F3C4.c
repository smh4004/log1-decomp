/* sub_0800F3C4(a, b): a[2..3] = (a[0] + b[0], a[1] + b[1]) as 16-bit halves, written as one word; returns that word
   (the original leaves it in r0). Hand-written: its `push {r3, r4}` (a scratch slot) made the pipeline treat it as
   variadic; it isn't. */
uint sub_0800F3C4(short *param_1, short *param_2)
{
  unsigned short x = (unsigned short)param_1[0] + (unsigned short)param_2[0];
  unsigned short y = (unsigned short)param_1[1] + (unsigned short)param_2[1];
  uint w = (uint)x | ((uint)y << 16);
  *(uint *)(param_1 + 2) = w;
  return w;
}
