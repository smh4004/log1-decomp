# Progress

| Part | State |
|---|---|
| Matching disassembly | done: `make compare` OK (SHA-1 `a3c8c767...`) |
| Byte map | done: `config/regions.yaml` |
| Relocatable source | done: shift test 37/37 (`docs/shifting.md`) |
| Ghidra reference C | done: all 865 functions (`ref/`) |
| C replacing assembly | 488 of 490 replaceable functions have C that compiles (23 hand-written). 181 verified + 107 tested (snapshot-equivalent in all 41 areas and from a late-game save, whole-game checked); 150 untested; 50 failing or blocklisted. `make decomp` / `make DECOMP=2` |
| Text | done: every pointed-to string; conversations as their own files |
| Conversations | done: 80 sets / 988 lines (speaker, next, text), lines can be added; checked in game |
| Story | done: 75 quests, 27 task/action types, every field named; add/remove/edit; checked in game |
| Sprites | done: 84 character sheets (all frames), checked in game |
| Sound | done: 20 samples (WAV in/out) |
| Music | done: 18 songs as tracker text, byte-exact round trip; checked with the mixer output |
| Movies | done: 3 FLI movies, frames as PNG, FLI encoder; checked in game |
| Compressed graphics | done: 182 BIOS blocks, decode + re-pack (Huffman / LZ77 / RLE / diff), drawn in their real layout and colours |
| Palettes | done: every image and area palette, as JASC-PAL files |
| Maps | done: all 42 areas as Tiled maps (3 tile layers, walkable and two other masks); copy-on-write for shared screens |
| Tables | enemy stats (34) and the player level table (25) as CSV, checked in game |
| Areas | characters, enemies, pickups, objects and trigger zones (warps, HP zones, events, messages) of all 42 areas; add/remove/move, new warps checked in game |

## Next steps
* Nothing the game reads is left unnamed; `bN`/`unusedN` fields are padding or never read by the code.
* C coverage of what the random routes can't reach (quest-dependent story events, the save chip, the ending): routes that play the story.
* Fix the 23 functions whose C differs on a snapshot, and re-examine the 22 blocklisted by the whole-game check (some may be timing, not behaviour).
