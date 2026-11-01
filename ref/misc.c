/* Ghidra reference decompilation of misc (read-only; see docs/decomp.md). */
#include "ghidra_types.h"

/* RomHeader @ 0x08000000 */

void RomHeader(void)

{
  do {
    DAT_03000004 = 0;
    DAT_03007ffc = IntrMain;
    AgbMain();
  } while( true );
}


/* _start @ 0x080000C0 */

void _start(void)

{
  do {
    DAT_03000004 = 0;
    DAT_03007ffc = IntrMain;
    AgbMain();
  } while( true );
}


