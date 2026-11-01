"""Game layout constants for the asset tools (Legacy of Goku). All offsets are ROM file offsets."""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'bfdis'))
from game import TEXT_END, IWRAM

ROM = 0x08000000
RODATA = (TEXT_END, IWRAM[0])        # data between the code and the end of the ROM image
DECOMPRESS = 0x08009524              # Decompress(src, flags): bit4 Huffman, bit3 LZ77, bit2 RLE


def isrodata(o): return RODATA[0] <= o < RODATA[1]
