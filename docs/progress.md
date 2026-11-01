# Progress

| Part | State |
|---|---|
| Matching disassembly | done: `make compare` OK (SHA-1 `18e0715d...`) |
| Byte map | done: `config/regions.yaml`, 100% of the ROM classified |
| Relocatable source | done: shift test 37/37 at 0x100 and 0x2000 (`docs/shifting.md`) |
| Ghidra reference C | done: all 2,424 functions (`ref/`) |
| C replacing assembly | 177 verified + 90 tested (of 1,486 replaceable); `make decomp` plays the smoke and long routes identically |
| Event scripts | done: 291 lists, 1,811 steps decompile and recompile byte for byte; steps can be added, removed, grown |
| Script natives | 125 of 145 named (`config/script_natives.txt`) |
| Text | UI strings (260); all dialogue through the event files |
| Maps, tiles, sprites, palette | done (336 maps, 168 tile pages, 6,014 sprite images) |
| Tables | areas, items, enemies, enemy placement, EXP |

## Next steps
* Capture routes deeper into the game (beyond the opening areas) so more C moves from *untested* to *tested*/*verified*;
  bisect the *tested* tier on the exploration route (`tools/decomp/gamebisect.py config/decomp_tested.txt tools/harness/decomp_explore.txt`).
* Name the remaining 20 natives and confirm the "(guess)" ones.
* Actor lists of areas (NPCs, objects, triggers): the format around `sub_0800D624`/`sub_0800D7E0` records is partly known.
* Character records (0x081D967C) and the player stat growth tables.
* 16-colour and multi-part sprites in the sprite exporter.
