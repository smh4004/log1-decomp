# Progress

| Part | State |
|---|---|
| Matching disassembly | done: `make compare` OK (SHA-1 `a3c8c767...`) |
| Byte map | done: `config/regions.yaml` |
| Relocatable source | done: shift test 37/37 (`docs/shifting.md`) |
| Ghidra reference C | done: all 865 functions (`ref/`) |
| C replacing assembly | 58 verified (+47 tested, experimental) of 490 replaceable; `make decomp` plays all three routes identically |
| Text | done: every pointed-to string (977) |
| Compressed graphics | done: 182 BIOS blocks, decode + re-pack (Huffman / LZ77 / RLE / diff), drawn in their real layout and colours |
| Palettes | done: every image and area palette, as JASC-PAL files |
| Maps | done: all 42 areas as Tiled maps (3 tile layers, walkable and two other masks); copy-on-write for shared screens |
| Tables | enemy stats (34) and the player level table (25) as CSV, checked in game |
| Areas | characters, enemies, pickups, objects and trigger zones (warps, HP zones, events, messages) of all 42 areas; add/remove/move, new warps checked in game |

## Next steps
* The area record's +0x18 byte table, the dialogue record format, sprite sheets, music.
* Name the 17 enemy AI values and the actor/trigger fields kept as raw numbers (b10, b11, b13, mode).
* Capture routes beyond Kame House for more C coverage; bisect the tested tier.
