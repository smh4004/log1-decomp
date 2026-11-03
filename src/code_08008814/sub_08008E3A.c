/* sub_08008E3A  (original: 0x08008E3A-0x08009064 in asm/code_08008814.s)
 * Ghidra decompilation, compiled with GCC; equivalent on 30/30 snapshots, 25% of instructions covered.
 */
#include "ghidra_types.h"
extern int sub_08008E06();
extern int sub_08008DBE();
extern int sub_0800E748();

/* sub_08008E3A(win, fmt, ...): printf-style text output into a text window `win`. Plain characters go through
   sub_08008DBE(win, c); '\n' moves to the start of the next line (+0xa = +0x2, ++(+0xc)) and decrements the
   line budget at +0x18, setting +0x20 to 1 when it reaches 0. Conversions (after '%'):
     digits '1'..'8' accumulate a width (width*10 + d; note '9' is NOT a digit and is skipped like any unknown
     character), '0' sets the pad character to '0' (default ' '), '%' prints '%',
     c: one char, d: signed decimal (digits via sub_0800E748 = divmod by 10), x: hex (uppercase), p: hex with
     width 8 / pad '0', s: string (NULL -> "<null>"; with a width, at most `width` chars), P: a packed
     (short x, short y) word printed as "(%d, %d)", B: two packed words printed as "{%d,%d | %d,%d}".
   Number digits are produced in reverse into a small buffer, padded on the left up to the width, then output.
   Returns what the original leaves in r0: the pointer to the terminating NUL, or 0 if the string ends right
   after a '%' sequence. Hand-written because it is variadic (push {r0-r3}, then walks the arguments on the
   stack) and Ghidra's C loses the stack arguments and the r1 operands. */

typedef unsigned long long divmod10_t;   /* sub_0800E748 returns quotient in r0, remainder in r1 */

int sub_08008E3A(int win, const char *fmt, ...)
{
  __builtin_va_list ap;
  const unsigned char *p = (const unsigned char *)fmt;
  /* the original's buffer is 12 bytes in its frame; widths > 12 overrun its own locals there */
  unsigned char buf[128];
  int width, n;
  unsigned int pad, c;

  __builtin_va_start(ap, fmt);
  for (;; p++) {
    c = *p;
    if (c == 0) return (int)p;
    if (c == '\n') {
      *(unsigned short *)(win + 0xa) = *(unsigned short *)(win + 2);
      *(unsigned short *)(win + 0xc) = *(unsigned short *)(win + 0xc) + 1;
      if (--*(int *)(win + 0x18) == 0) *(int *)(win + 0x20) = 1;
      continue;
    }
    if (c != '%') {
      sub_08008DBE(win, c);
      continue;
    }
    width = 0;
    pad = ' ';
    for (;;) {
      c = *++p;
      if (c == 0) return 0;
      if (c >= '1' && c <= '8') { width = width * 10 + (int)c - '0'; continue; }
      if (c == '0') { pad = '0'; continue; }
      if (c == '%') { sub_08008DBE(win, '%'); break; }
      if (c == 'c') { sub_08008DBE(win, __builtin_va_arg(ap, int)); break; }
      if (c == 'd') {
        int v = __builtin_va_arg(ap, int);
        int neg = 0;
        if (v < 0) { neg = 1; v = -v; }
        n = 0;
        while (v >= 10) {
          divmod10_t qr = ((divmod10_t (*)(int))sub_0800E748)(v);
          buf[n++] = (unsigned char)((unsigned int)(qr >> 32) + '0');
          v = (int)(unsigned int)qr;
        }
        buf[n++] = (unsigned char)(v + '0');
        if (neg) buf[n++] = '-';
        if (width != 0 && n < width) {
          do buf[n++] = (unsigned char)pad; while (n < width);
        }
        while (n != 0) { n--; sub_08008DBE(win, buf[n]); }
        break;
      }
      if (c == 'x' || c == 'p') {
        unsigned int v;
        if (c == 'p') { width = 8; pad = '0'; }
        v = __builtin_va_arg(ap, unsigned int);
        n = 0;
        do { buf[n++] = "0123456789ABCDEF"[v & 0xf]; v >>= 4; } while (v != 0);
        if (width != 0 && n < width) {
          do buf[n++] = (unsigned char)pad; while (n < width);
        }
        while (n != 0) { n--; sub_08008DBE(win, buf[n]); }
        break;
      }
      if (c == 's') {
        const unsigned char *s = __builtin_va_arg(ap, const unsigned char *);
        if (width == 0) {
          sub_08008E06(win, s ? (const char *)s : "<null>");
        } else if (s == 0) {
          sub_08008E06(win, "<null>");
        } else {
          unsigned int w = (unsigned int)width;
          while (*s != 0 && w-- != 0) { sub_08008DBE(win, *s); s++; }
        }
        break;
      }
      if (c == 'P') {
        unsigned int v = __builtin_va_arg(ap, unsigned int);
        sub_08008E3A(win, "(%d, %d)", (int)(short)v, (int)(short)(v >> 16));
        break;
      }
      if (c == 'B') {
        unsigned int a = __builtin_va_arg(ap, unsigned int);
        unsigned int b = __builtin_va_arg(ap, unsigned int);
        sub_08008E3A(win, "{%d,%d | %d,%d}", (int)(short)a, (int)(short)(a >> 16),
                     (int)(short)b, (int)(short)(b >> 16));
        break;
      }
      /* anything else: skipped, keep scanning the conversion */
    }
  }
}
