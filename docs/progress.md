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
| Tables | enemy stats (34) and the player level table (25) as CSV |

## Next steps
* Area exits/objects and enemy placement (area record +0x14/+0x18), the dialogue record format, sprite sheets, music.
* Name the 17 enemy AI values; a route that reaches an enemy, to check enemy-table edits in game.
* Capture routes beyond Kame House for more C coverage; bisect the tested tier.
