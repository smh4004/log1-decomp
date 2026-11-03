# Modding toolkit: technical reference

```sh
make extract          # baserom.gba -> assets/ (git-ignored; never commit or share it)
#   ...edit files under assets/...
make modern           # -> log1_modern.gba, built from your edits
make patch            # -> log1_modern.bps (share this)
make verify-mods      # self-test
```
**The step-by-step user guide is `USER_README.md`.**

| What | Files | Tool |
|---|---|---|
| Conversations (80 sets, 988 lines: speaker, next line, text) | `assets/dialogue/setNN.txt` | `tools/assets/dialogue.py` |
| The story: 75 quests, their tasks and their results | `assets/story/quests.json` | `tools/assets/quests.py` |
| Character sprite sheets (84 characters, 19 rows x 4 directions) | `assets/sprites/NAME.png` | `tools/assets/sprites.py` |
| Instrument and sound samples (20) | `assets/sound/sampleNN.wav`, `samples.json` | `tools/assets/sound.py` |
| Music: 18 songs as tracker text (tempo, order, patterns, notes, effects) | `assets/music/songNN.txt` | `tools/assets/music.py` |
| The 3 intro movies (FLI files and PNG frames) | `assets/movies/movieN.fli`, `movieN/frameNNN.png` | `tools/assets/movies.py` |
| All other text the game points to: story, menus, names | `assets/text/strings.txt` | `tools/assets/assets.py` |
| Graphics and other packed data (182 BIOS-compressed blocks), drawn in their real colours | `assets/gfx/blocks/LABEL.bin` + `LABEL.png` | `tools/assets/assets.py`, `bios.py`, `gfxinfo.py` |
| Palettes (every one those images and the areas use) | `assets/palettes/LABEL.pal` | `assets.py` |
| The 42 area maps (3 tile layers + walkable/mask layers) | `assets/maps/areaNN.tmx` (Tiled) | `tools/assets/maps.py` |
| Enemy stats, player level table | `assets/tables/enemies.csv`, `levels.csv` | `tools/assets/tables.py` |
| What is in each area: characters, enemies, pickups, objects, warps and other trigger zones | `assets/areas/areaNN.json` | `tools/assets/areas.py` |

## Text
`strings.txt` lists every labelled object in `.rodata` that starts with a C string (at least 3 printable characters,
with letters). Labels exist where something points, so this covers dialogue (records `{u8 speaker, u8 id, u16, ptr}`
point at each line), the opening story, menus and names. A string that fits is written in place; a longer one rewrites
its object and moves it to the appendix at the end of the data, and every pointer to it follows.

## Conversations
`gConversationSets` (0x0815BF28) points to 80 arrays of 8-byte lines `{u8 speaker, u8 next, u16 0, u32 text}`. The
player of a conversation (0x080051D0) starts at an entry line and follows `next` until a line with speaker 0xFF; that
line's `next` becomes the entry for the next time, which is how characters say something new the second time. Speakers
are character sprite sets (their face is drawn). Characters name a set in their area `param`; kind 1 keeps the entry per
set, kind 0 per character (initial entry = the actor's `entry`); conversation triggers give set and entry; story scripts
move entries (0x0800536C). Each set file lists its lines; lines can be added at the end and any speaker, next or text
changed. Changed text becomes a new string; the array is rewritten in place, or moved and its table entry repointed if
it grows. `make verify-mods` plays Krillin's first conversation with a rewritten and an added line.

Texts that only conversations point to are no longer in `strings.txt` (one place to edit each text).

## Quests (the story)
The story is data. `gQuestTable` (0x085439E0) points to 75 quest records `{name, task count, tasks, action count,
actions}`; tasks and actions are small C++ objects `{vtable, fields}` whose vtable is their type (27 types, listed with
their fields in `tools/assets/quests.py`). The game sends events to every task: 0 = talked to a character (its sprite
set), 1 = a quest object was used, 2 = an enemy died, 3 = a conversation reached an entry, 4 = a quest was done
(`sub_08005478`). A task that matches sets its bit; a quest whose tasks are all set is done, its actions run in order
(EXP, pickups, conversations, warps, conversation entries for next time, walkable areas, music...), and event 4 goes
out. Area actors hide or appear by quest: their `flag` is an index into `quest_of_flag` (0x08543988).

`quests.json` keeps each object's `label`; fields edit in place; lists of tasks and actions can be reordered, cut or
extended, and new objects of any type are created (list moved if it grows, count patched). `make verify-mods` turns
quest 1 into "pick up the magazine" with an extra `give_exp` of 1234 and checks in the emulator that it completes and
the EXP arrives.

## Sprite sheets
`gCharacterTable` (0x085C0C80, 84 records, chosen per sprite set through the byte table 0x0815A709) holds each
character's palette and a table of 76 frame records (19 rows x 4 facing directions). A frame record gives size, OAM
shape, a mirror flag and a pointer to uncompressed 4 bpp tiles (0x086B6AC0-0x087A6..). The sheet shows every frame in
its cell (mirrored ones mirrored); edits are written back into the frames (unmirrored), in place, so frame sizes are
fixed. Frames shared between cells or characters are written once; conflicting edits stop the build. The 19 rows are
animation frames in the game's order (standing, walking, ... per character); not every character uses every row.

## Sound samples
`gSampleTable` (0x08591E4C) has 20 records {-> 8-bit signed PCM, loop flag, loop start, length, rate in Hz}. They are
exported as WAV and imported from any 8/16-bit mono or stereo WAV; the rate comes from the file, a longer sample is
moved to the appendix and its pointer follows. `make verify-mods` replaces a sample the title music uses with a longer
tone and checks that the music player points into the new data. The 18 music tracks follow (next section).

## Music
`gTrackTable` (0x08591F3C) has 18 songs `{-> pattern pointer list, -> order list, tempo | speed << 8}`; the order
list, the patterns and the pointer list lie in that order. Patterns are Webfoot's packed tracker rows: per row,
tokens `channel+1 | mask kind << 4` (kind 0 = new mask byte, 1 = the channel's last mask, 2-15 = a 14-byte global mask
dictionary at 0x08142388), then the note / sample / volume / effect bytes the mask asks for; mask bits 0x10-0x80 replay
the channel's previous value. Effects use Impulse Tracker numbering. The layout and row encoding were worked out with
help from [webfootaudioengine](https://github.com/ghxstboyy/webfootaudioengine) (it converts Webfoot songs to and from
`.it` modules); `music.py` is a separate implementation. All 282 patterns decode and re-encode to the original bytes.
`songNN.txt` lists each row's channel cells (`CHANNEL NOTE SAMPLE VOLUME EFFECT`, `=` = repeat). A changed song is
re-encoded and moved to the appendix (its descriptor's pointers follow). `make verify-mods` records the mixer buffer
(0x0203F800) at the title: the title song re-encoded and moved gives identical audio for 60 buffers, transposed it
doesn't.

For `.it` work (OpenMPT), webfootaudioengine reads and writes LoG1 songs directly in a ROM; use it on a built
`log1_modern.gba` as the last step (its changes are not in this source tree).

## Movies
The three movies (0x081CA168, 0x08337248 = the one at boot, 0x084E4F44) are standard Autodesk FLI animations, 120x80,
8 bpp, played by `sub_080045F8` (chunks 4, 7, 11, 12, 13, 15, 16; the 0xF100 prefix chunk is skipped). They are exported
as `.fli` (any FLI player or converter, e.g. ffmpeg, reads them) and as PNG frames. A replaced `.fli` is used as is;
changed frames are re-encoded (256-colour palette chunk on change, then line delta or byte run). A movie that grows is
added at the end and only the pointer to it changes (bytes inside the old movie that other data happens to point at stay
put). `make verify-mods` re-encodes the boot movie from its frames (it decodes to the same frames, and the boot looks
the same; a few sampled screens can be a VBlank early or late because decode time depends on the encoding) and checks
that edited frames show.

These two tables showed a gap in relocation: four sample pointers were plain numbers. `config/game.json` can now list
known pointer tables (`ptr_tables`: start, count, stride, field); the sample/track table is listed there (9,436
pointers, shift test still 37/37).

## Compressed blocks
The game unpacks graphics with `Decompress(src, flags)` (0x08009524), which chains the BIOS decoders: Huffman (swi 0x13),
then LZ77 (swi 0x11), then run-length (swi 0x14), then the 16-bit (swi 0x18) or 8-bit (swi 0x16) difference filter, as
selected by the flags (bits 4 to 0). `tools/bfdis/lz.py` finds every word-aligned
stream that a ROM word points to and decodes the chain to find each block's stages. Extract writes the fully decoded
bytes (`.bin`) and an indexed PNG drawn the way the game draws the block (`tools/assets/gfxinfo.py`):

| Layout | Blocks | Picture |
|---|---|---|
| `portrait` | 67 dialogue faces (512 bytes) | 32x32, 4x4 tiles of 4 bpp, 16 colours |
| `screen8` / `bitmap8` | 21 full screens (38,400 bytes: title, logos, story pictures) | 240x160, 8 bpp tiles (30x20) or a mode 4 bitmap, 256 colours |
| `tiles8` | 90 area tile sets and extra tile blocks | 8 bpp tiles, 16 per row, the area's 256 colours |
| `tiles4` | 4 others (the font, an unused block) | 4 bpp tiles, 16 per row |

The palette comes from the image header {u32 palette, u32 data, u32 flags} that the game passes to the loader; most
images keep it right before their data, full-screen pictures are listed in tables of such triples (0x085C219C), and area
tiles use their area's palette. The PNG's colour indexes are what is stored, so draw with the PNG's own palette (an RGB
image is mapped to the nearest palette colour). To change colours, edit the palette file. On build an edited block is re-packed with the same stages by `tools/assets/bios.py`
(Huffman always with 4-bit symbols, which the BIOS accepts and which always fits its tree format; difference filters
included) and moved to the
appendix if it grew. Verified in the emulator by `make verify-mods` (the title logo).

Caveat: a block's stages are inferred from the stream headers (0x24/0x28 Huffman, 0x10 LZ77, 0x30 RLE). If decoded data
happens to start with one of those bytes, an extra stage may be assumed; compare with the call site's flags if a
re-packed block looks wrong.

## Palettes
`assets/palettes/LABEL.pal` is a JASC-PAL text file (Tiled, GIMP, Aseprite and most pixel editors read it): one "R G B"
line (0-255) per colour, 16 or 256 colours, converted to and from the GBA's 15-bit colour (5 bits per channel; bit 15
is kept). The file keeps its number of colours; it is written back in place, so every image that uses it changes.

## Maps
Format and rules are in the docstring of `tools/assets/maps.py`. In short: `gAreaTable` (0x081C7C48, pointer list at
0x081CA09C) has 42 records; an area is a grid of 30x20-tile screens on three 8 bpp BG layers, plus three 1-bit-per-tile
masks (the first is where the player can walk). Its tiles are the area tile set at slot 146 and extra tile blocks from
slot 346 (slots 0-145 hold the text font). Each `areaNN.tmx` has layers `bg3 (bottom)`, `bg2`, `bg1 (top)` (tile gid =
slot + 1, with Tiled's flip flags) and `walkable`, `flyable`, `shots` (the red flag tile = set; flying mode and ki blasts use the latter two). Edited screens used once
are rewritten in place; screens shared with another place (14 are) and empty screens that get tiles become new objects,
and only that layer and position's pointer changes. Map sizes can't change. What stands in an area is in `areas/`
(next section); the record's `+0x18` byte table picks the extra tile block for each screen (`screen_tiles`).

## Areas: characters, enemies, warps
Field-by-field format in the docstring of `tools/assets/areas.py`. Each area record's `+0x14` points to an info block
that the area loader (0x08001FA8, also what warps call) walks: music track, tile animation (`sub_08005B38`), a list of actors (12 bytes: position, sprite set, show-if story
flag, kind 2 = enemy, otherwise a character and what they say), pickups (8 bytes, `sub_0800D1A0`), objects (8 bytes,
`sub_0800697E`), and a list of pointers to trigger zones: rectangles with a callback (warp `sub_0800356C`: area and
position; HP zone `sub_080042B4`: HP change per second; conversation `sub_080061B0`; message `sub_080061D0`). Enemy
actors use the enemy table row whose sprite set they name (the wolf sprite gives row 2, `wolf`).

Build rules: lists that change are rewritten (moved to the appendix if they grow; their count is patched); trigger
records are edited in place (not their callback); new warps, HP zones and conversations become new records and the
area's trigger list is rewritten. `make verify-mods` checks in the emulator that an added wolf appears with the HP from
`enemies.csv` and that an added warp zone takes Goku from Kame House to the forest.

## Tables
`tools/assets/tables.py` documents the fields. `enemies.csv` is `gEnemyTable` (0x086B6094, 34 entries of 0x40 bytes,
read by the enemy constructor 0x08006D90): exp, hp, defense (subtracted in full, by half or by a quarter from each hit,
0x08007352), power and 17 AI values (idle mode, reaction, courage, group, sight, home/goto points, speed; read by `sub_0800755A`). `levels.csv` is the player's level table (0x080114A8, 25 rows):
EXP needed, max HP, power and the ki counter. Both are written in place and checked in game by `make verify-mods` (max HP of the player; HP of an
added wolf).

## How it fits together
Same as the sequels: `assets.py extract` writes the files and `assets/manifest.json` (SHA-1 per file); `assets.py build`
turns changed files into overrides, `tools/assets/apply.py` splices them into a copy of `data/*.s`, and the normal
build links `log1_modern.gba`. This works because every pointer in the data is a symbol (`docs/shifting.md`).

## Not covered yet
The area `+0x18` byte table, what the 17 enemy AI values do,  (speaker/next fields), sprite sheets, music and the
movie codec. The data is all reachable
from the disassembly (`data/*.s`), and the code that reads it is in `ref/` and `src/`.
