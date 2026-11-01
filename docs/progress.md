# Progress

| Part | State |
|---|---|
| Matching disassembly | done: `make compare` OK (SHA-1 `a3c8c767...`) |
| Byte map | done: `config/regions.yaml` |
| Relocatable source | done: shift test 37/37 (`docs/shifting.md`) |
| Ghidra reference C | done: all 865 functions (`ref/`) |
| C replacing assembly | 58 verified (+47 tested, experimental) of 490 replaceable; `make decomp` plays all three routes identically |
| Text | done: every pointed-to string (977) |
| Compressed graphics | done: 182 BIOS blocks, decode + re-pack (Huffman / LZ77 / RLE) |

## Next steps
* Palettes (to give the tile sheets real colours), maps, the dialogue record format, music.
* Capture routes beyond Kame House for more C coverage; bisect the tested tier.
