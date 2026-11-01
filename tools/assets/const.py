"""Game layout constants for the asset tools (Legacy of Goku II). One place to change when porting the tools.

All offsets are ROM file offsets (bus address - 0x08000000).
"""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'bfdis'))
from game import TEXT_END, IWRAM

ROM = 0x08000000
RODATA = (TEXT_END, IWRAM[0])        # uncompressed + compressed data between the code and the RW image
PALETTE = 0x3ECBA4                   # master palette: 512 x 24-bit RGB (BG 0-255, OBJ 256-511)
PAGE_TABLE = 0x4DF574                # global BG tile page table (pointers to WFZ pages of 256 8bpp tiles)
AREAS = (0x409368, 327, 56)          # area table: offset, count, record size
UI_PTRS = (0xE2840, 260)             # UI strings: pointer table, count (ASCII, 0-terminated)
UI_ENCODING = 'latin-1'
EXP = (0x1D9834, 50)                 # EXP needed for each level (u32, level 1 = 0)
CHARACTERS = (0x1D967C, 22, 20)      # playable/party character records (inferred)
STEP_TYPES = 0x3EC84C                # event step handlers (6 types)
OPCODES = 0x3B5C00                   # script VM opcode handlers (30)
NATIVES = (0x3B5D28, 145)            # script natives (getter table; 0-16 are also variables)
SETTERS = (0x3B5F70, 17)             # script variable setters


def isrodata(o): return RODATA[0] <= o < RODATA[1]


def ui_string(d, i):
    import struct
    if i >= UI_PTRS[1]: return ''
    o = struct.unpack_from('<I', d, UI_PTRS[0] + 4 * i)[0] - ROM
    e = d.index(b'\0', o)
    return d[o:e].decode(UI_ENCODING)
