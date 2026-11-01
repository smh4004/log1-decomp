/* Linker script for Dragon Ball Z: The Legacy of Goku (USA) disassembly. */
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY
{
    ROM   (rx)  : ORIGIN = 0x08000000, LENGTH = 32M
    IWRAM (rwx) : ORIGIN = 0x03000000, LENGTH = 32K
}

SECTIONS
{
    .text :
    {
        build/asm/header.o(.text);
        INCLUDE "build/code_objs.ld"
    } > ROM

    .rodata :
    {
        INCLUDE "build/data_objs.ld"
    } > ROM

    /* RW image: copied to 0x03000000 by crt0 (DMA3 from __iwram_lma, 0xE7F bytes). */
    .iwram :
    {
        __iwram_start = .;
        build/asm/iwram.o(.text);
        __iwram_end = .;
    } > IWRAM AT > ROM
    __iwram_lma = LOADADDR(.iwram);

    /* make decomp: C functions go into the free space after the RW image, so no original byte moves.
       (Their old assembly is replaced by padding of the same size; see docs/decomp.md.) */
    .decomp ALIGN(LOADADDR(.iwram) + SIZEOF(.iwram), 4) :
    {
        INCLUDE "build/src_objs.ld"
        *libgcc.a:*(.text*)
    } > ROM

    /DISCARD/ : { *(.ARM.attributes) *(.comment) }
}
