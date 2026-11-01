# User guide: making mods for Dragon Ball Z: The Legacy of Goku II

This guide covers changing the game's text, cutscenes, items, enemies, maps, graphics and balance, building a playable ROM,
and sharing it as a patch. You don't need to know assembly or C: you edit text files, spreadsheets (CSV) and images, and
run two commands.

For the technical reference behind each tool, see `docs/modding.md`. For how the disassembly and decompilation work, see `README.md`.

---

## Contents
1. [Setup (once)](#setup)
2. [The edit loop](#loop)
3. [Finding what you want to change](#finding)
4. [Recipes](#recipes)
   * [Text: dialogue, menus, names](#text)
   * [Cutscenes and NPC talk](#cutscenes)
   * [Scripting reference](#scripting)
   * [Items](#items)
   * [Enemies: stats and placement](#enemies)
   * [Leveling (EXP curve)](#exp)
   * [Maps: layout, tiles, collision](#maps)
   * [Graphics: tiles, sprites, colours](#graphics)
   * [Areas and music](#areas)
5. [Rules and limits](#limits)
6. [Testing](#testing)
7. [Sharing your mod](#sharing)
8. [Troubleshooting](#trouble)
9. [Reference: files, numbers, addresses](#reference)

---

<a name="setup"></a>
## 1. Setup (once)
You need a Linux shell. Windows users can use WSL (Ubuntu); macOS works with Homebrew equivalents.
```sh
sudo apt-get install git make python3 python3-pip gcc gcc-arm-none-eabi binutils-arm-none-eabi libmgba-dev libpng-dev zlib1g-dev
pip install --break-system-packages capstone numpy pillow unicorn
git clone https://github.com/smh4004/log2-decomp && cd log2-decomp
cp /path/to/your/Legacy_of_Goku_II_USA.gba baserom.gba     # your own dump, USA version
make && make compare                                      # must print: log2.gba: OK
```
`baserom.gba` must be the USA ROM with SHA-1 `18e0715dec419f3501c301511530d2edcd590f8b` (the stand-alone cartridge, not the
"2 Games in 1" compilation). If `make compare` doesn't print OK, you have a different dump and nothing else will work reliably.

<a name="loop"></a>
## 2. The edit loop
```sh
make extract        # once: unpacks the game into assets/ (about 8,300 files)
# ... edit files in assets/ ...
make modern         # builds log2_modern.gba from your edits (a few seconds)
# play log2_modern.gba in any GBA emulator (mGBA recommended)
make patch          # when you're ready to share: log2_modern.bps
```
* Only files you changed are rebuilt. With no changes, `make modern` produces the original ROM exactly.
* Edits can make things **bigger**: longer text, more cutscene steps, bigger scripts. The build moves grown data to free space
  at the end of the data area and fixes every pointer to it.
* To undo everything, delete `assets/` and run `make extract` again. To undo one file, copy it from a fresh extract.
* **Keep your edited files somewhere safe** (a private git repo or a backup). **Never publish `assets/` or any ROM**: they
  contain the game's copyrighted data. Publish the `.bps` patch.

<a name="finding"></a>
## 3. Finding what you want to change
| You want to change | Look in |
|---|---|
| a line someone says, a sign, a narration box | `grep -rl "words from the line" assets/scripts/` (dialogue lives inside the event files) |
| a menu word, item name, area name, technique description | `assets/text/ui_strings.txt` |
| what happens in a cutscene or when you talk to someone | the `.evt` file that contains the dialogue (same grep) |
| an item's name, icon, how many you can carry, what using it does | `assets/tables/items.csv` |
| enemy HP, attack, defence, EXP | `assets/tables/enemies.csv` |
| where enemies stand | `assets/tables/spawns.csv` (`_area` column says which map) |
| how much EXP each level needs | `assets/tables/exp.csv` |
| a map's layout or collision | `assets/maps/wWW_aAA_<Area name>/` (`assets/maps/index.csv` lists all of them) |
| background tiles | `assets/gfx/tiles/page_NNN.png` |
| character / NPC / enemy sprites | `assets/gfx/sprites/<animation>/*.png` |
| colours | `assets/palette/master.txt` |
| area music, area names | `assets/tables/areas.csv` |

Who is speaking: `assets/scripts/SPEAKERS.txt` lists every speaker id with sample lines.

<a name="recipes"></a>
## 4. Recipes

<a name="text"></a>
### Text: dialogue, menus, names
**Dialogue** is part of the event files (next section): edit the quoted text of a `say` / `zsay` step.
```
step 6 say 0x01 "#I won't let you down."
```
* Any length. Text that grows moves automatically.
* `\x0b` starts a new page of the text box. `\n` is a line break, `\"` a quote, `\\` a backslash.
* The first characters are box/portrait codes, keep them: `@^` = narration box with no portrait, `#` = normal box with the
  speaker's portrait, `!` = alternative box style (see existing lines for examples).
* `say` text is stored as plain bytes; `zsay` text is stored compressed. Both behave the same for you; the build re-compresses `zsay`.

**Menus, item names, area names**: `assets/text/ui_strings.txt`, one string per line: `index<TAB>text`. `{0A}` is a line
break; `%d` / `%s` are numbers/names filled in by the game, keep them. Keep the index.

<a name="cutscenes"></a>
### Cutscenes and NPC talk (`assets/scripts/*.evt`)
Every event list (a cutscene, a conversation, a sign, a trigger) is one file named after its address, e.g.
`gUnknown_083B6EC8.evt` (Gohan training Trunks at the start). A list is a sequence of **steps** that the game runs in order:
```
step 1 code
    call join_party(3)
    call wait(60)
    pushn 0, 2
    call face
    end
step 2 zsay 0x01 "#TRUNKS: This isn't fair. Gohan, why are the Androids doing this?\x0bAll those innocent people..."
step 3 code
    pushn 54, 3
    call face
    end
```
Step kinds:
| Kind | Meaning |
|---|---|
| `code` | script bytecode (see the scripting reference), ends with `end` |
| `say SPEAKER "text"` | a text box (plain text) |
| `zsay SPEAKER "text"` | a text box (stored compressed) |
| `sayf SPEAKER LABEL` + code | a text box whose `%d`/`%s` are filled by the code below it; LABEL is the format string object |
| `zsayf SPEAKER LABEL "format"` | the same, with the format text inline and the argument code at LABEL |
| `goto LABEL` | continue with another event list |
| `raw TYPE bytes` / `ref LABEL` | kept as is (unknown kind / step shared with another list) |

You can **edit**, **delete**, **reorder** and **add** steps. For a new step write `step auto ...`:
```
step 2 zsay 0x01 "#TRUNKS: ..."
step auto say 0x39 "#GOHAN: A brand new line."
step 3 code
```
In lists numbered 1, 2, 3... (almost all) the build renumbers the steps by position, because the game finds the next step by
its number. The number you write only tells the build which original step a line came from.

<a name="scripting"></a>
### Scripting reference
The script language is a small stack machine (full description at the top of `tools/scripts/l2script.py`).
```
push 5            ; push a byte (0-255)
push.v -300       ; push any number
pushn 1, 2, 300   ; push several numbers
call wait(60)     ; = push 60 ; call wait   (arguments are pushed in order)
call give_item    ; call with the arguments already on the stack
set reg0          ; pop into a variable;  inc/dec/preinc/postinc/predec/postdec VAR
add sub mul div neg and or eq ne gt ge lt le pop
jz L1 / jmp L1    ; forward jumps only (at most 255 bytes); jz pops the condition
loop_begin / loop L1   ; repeat a block: push the count, loop_begin, ..., loop L1 (backward, at most 255 bytes)
end
L1:               ; label
```
Natives (the game functions a script can call) are named in `config/script_natives.txt` (125 of 145; the rest show as `0xNN`).
`docs/script_natives.md` shows each one's code. The most useful:
| Native | Arguments (pushed order) | Effect |
|---|---|---|
| `wait` | frames | pause the event |
| `get_flag` / `set_flag` / `clear_flag` | flag | story flags (saved) |
| `give_item` / `take_item` / `item_count` | item (row of items.csv) | inventory |
| `give_exp` | amount | EXP for the current character (level-up included) |
| `join_party` / `leave_party` | character (0 Gohan, 1 Piccolo, 2 Vegeta, 3 Trunks, 4 Goku) | party |
| `learn_skill` | character, skill | unlock a technique |
| `play_music` / `play_sfx` | track / sound | audio |
| `fade_out` / `fade_in` | frames | screen fades |
| `warp` | world, area, 0, x, y | move the player to another map (no fade) |
| `teleport` | world, area, 0, x, y | the same with the teleport effect |
| `walk_to` | actor, x, y | move an actor (0 = player) |
| `face` | actor, direction | turn an actor |
| `random` | n | push a random number 0..n-1 |
Variables: `reg0`-`reg3` (free registers), `arg0`-`arg3`, `map_world`, `map_area`, `cur_char`, `hp`, `max_hp`, `ki`, `max_ki`.

Example: a code step that heals you fully and gives a Senzu Bean, only the first time it runs (story flag 200 remembers it):
```
step 1 code
    call get_flag(200)
    jz L1
    end
L1:
    push 200
    call set_flag
    push.v 999
    set hp
    call give_item(0)
    end
```

<a name="items"></a>
### Items (`assets/tables/items.csv`)
One row per item (50 rows). `name`/`desc` are indexes into `ui_strings.txt` (the `_name_text` column shows the text; change
the text in `ui_strings.txt`). `max_count` = how many you can carry. `on_use` = what using it does (the existing handlers:
STR/POW/END capsules, heal, energy). `icon`/`icon2` = sprite images.

<a name="enemies"></a>
### Enemies: stats and placement
**Stats** (`assets/tables/enemies.csv`, 109 enemy types; `_placed` = how many are placed in the world):
| Column | Meaning |
|---|---|
| `hp` | hit points (also the size of its health bar) |
| `exp` | EXP for defeating it (above 5, the game scales it to your level) |
| `str` / `pow` / `end` | melee attack / energy attack / defence |
| `phys_taken` / `ki_taken` | damage it takes from melee / energy attacks, 128 = 100% (256 = double, 64 = half) |
| `character` | which sprite set it uses |
| `behaviour` | its AI (copy another enemy's value to swap behaviour) |
Verified in the emulator: an enemy's HP in RAM is the `hp` value from this table.

**Placement** (`assets/tables/spawns.csv`, 666 placed enemies): `enemy` = row of enemies.csv, `x`/`y` = position in map
pixels, `_area` = which map. Change `enemy` to put a different enemy there, `x`/`y` to move it. Rows can't be added or
removed yet.

<a name="exp"></a>
### Leveling (EXP curve) (`assets/tables/exp.csv`)
50 rows: the total EXP needed to reach each level (level 1 = 0). Keep the values increasing.

<a name="maps"></a>
### Maps: layout, tiles, collision (`assets/maps/<map>/`)
Each map folder has:
* `L<k>.csv`: background layer k as a grid of 8x8 cells. Each cell is a hex number: bits 0-9 = tile slot (a line of
  `tiles.txt`), bit 10 (`400`) = flip horizontally, bit 11 (`800`) = flip vertically. The grid size is fixed.
* `tiles.txt`: the map's tile list (`page:tile` hex, strictly increasing). Add a line to use another tile from the tile pages.
* `floor.png` / `area.png`: 256x256 collision masks, one pixel per 8x8 cell: where you can walk / the play area.
`make extract` with `python3 tools/assets/assets.py extract --previews` also writes `L<k>.png` previews (slow).

<a name="graphics"></a>
### Graphics: tiles, sprites, colours
* **Tile pages** `assets/gfx/tiles/page_NNN.png`: 16 tiles per row, 256 colours of the BG palette. Edit in any editor; keep
  the image size. Colours are matched to the palette.
* **Sprites** `assets/gfx/sprites/<animation>/*.png`: one PNG per frame image (256 colours, OBJ palette, index 0 = transparent).
  Keep the size.
* **Palette** `assets/palette/master.txt`: 512 lines `R G B` (0-255). Lines 0-255 = backgrounds, 256-511 = sprites.

<a name="areas"></a>
### Areas and music (`assets/tables/areas.csv`)
327 areas (`world`, `area` = the numbers `warp` uses). `name` = area name string, `music` = song number (or a label: a small
script that picks the song, e.g. by story flag), `scene` = the map. Swap `music` values to change an area's song.

<a name="limits"></a>
## 5. Rules and limits
* Tables keep their row count; maps keep their layer size; images keep their size.
* Jumps in scripts reach at most 255 bytes (split long blocks into steps).
* A few objects are reached by the code as "address + offset" (`config/pinned.txt`); they can be edited but not enlarged.
  The build stops with a clear message if you try.
* 16-colour sprites and multi-part sprites aren't exported yet.
* Names in `config/script_natives.txt` marked "(guess)" are inferred; test what you use.

<a name="testing"></a>
## 6. Testing
* Play `log2_modern.gba` in mGBA.
* `make verify-mods` runs the toolkit's self-test (rebuilds the original, round-trips every event, applies demo edits and
  checks them in a headless emulator).
* `python3 tools/assets/demo_edits.py` (on a fresh extract) shows one edit of each kind; read it as an example.
* Headless harness: `tools/harness/harness log2_modern.gba tools/harness/smoke.txt outdir` plays a scripted route and saves
  screenshots (commands are listed at the top of `tools/harness/harness.c`).

<a name="sharing"></a>
## 7. Sharing your mod
```sh
make patch          # -> log2_modern.bps
```
Players apply `log2_modern.bps` to their own Legacy of Goku II (USA) ROM with any BPS patcher (Floating IPS, Rom Patcher JS)
or `python3 tools/bps.py apply original.gba log2_modern.bps out.gba`. Never share the ROM or `assets/`.

<a name="trouble"></a>
## 8. Troubleshooting
| Problem | Fix |
|---|---|
| `make compare` fails | wrong dump: check the SHA-1 |
| `ValueError: line N: ...` from `make modern` | the message names the file and line: a typo in an `.evt` file, a missing label, a jump too far |
| `must keep N rows` | a CSV lost or gained rows |
| the game hangs after an edit | undo the last edit; check scripts end with `end` and jumps land where you meant |
| text overflows the box | add `\x0b` page breaks |

<a name="reference"></a>
## 9. Reference: files, numbers, addresses
| Thing | Count | Address |
|---|---|---|
| event lists / steps | 291 / 1,811 | found by scanning |
| UI strings | 260 | 0x080E2840 |
| areas | 327 x 56 bytes | 0x08409368 |
| items | 50 x 56 bytes | 0x086ADE24 |
| enemy types | 109 x 24 bytes | 0x086D56AC |
| placed enemies | 666 x 28 bytes | records starting with 0x0800E77F |
| EXP table | 50 x u32 | 0x081D9834 |
| master palette | 512 x RGB | 0x083ECBA4 |
| maps | 336 | `assets/maps/index.csv` |
| tile pages | 168 | table 0x084DF574 |
| sprite animations / images | 689 / 6,014 | found by scanning |
| script natives | 145 (125 named) | 0x083B5D28 |
