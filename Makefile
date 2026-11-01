# Dragon Ball Z: The Legacy of Goku (USA) -- matching disassembly
#   make               build log1.gba from asm/ + data/ (+ baserom.gba)
#   make compare       check the SHA-1 against the original ROM
#   make SHIFT=0x100   relocation test build (log1_shift.gba): padding after crt0 moves everything
#   make extract       baserom.gba -> assets/ (editable events and text, palette, tables, maps, tiles, sprites)
#   make modern        build log1_modern.gba from assets/ (edited assets recompressed; non-matching)
#   make shift-test    build + headless comparison of SHIFT build vs matching build
#   make patch         log1_modern.bps from your edits;  make verify-mods: toolkit self-test
PREFIX  ?= arm-none-eabi-
AS      := $(PREFIX)as
LD      := $(PREFIX)ld
OBJCOPY := $(PREFIX)objcopy
PYTHON  ?= python3

SHIFT   ?= 0
MODERN  ?= 0
DECOMP  ?= 0
DATADIR := data
CC_ARM  := arm-none-eabi-gcc
CFLAGS  := -mthumb -mcpu=arm7tdmi -O2 -std=gnu11 -ffreestanding -fsigned-char -fno-builtin -fno-strict-aliasing \
           -fwrapv -fno-delete-null-pointer-checks -fno-common -w -Iinclude -ffunction-sections -fdata-sections
LIBGCC  := $(shell $(CC_ARM) -mthumb -mcpu=arm7tdmi -print-libgcc-file-name)
ifneq ($(DECOMP),0)
# DECOMP_DIR lets several decomp builds run side by side (tools/decomp/gamebisect.py)
DECOMP_DIR ?= build_decomp
ROM     := $(patsubst build_%,log1_%,$(DECOMP_DIR)).gba
BUILD   := $(DECOMP_DIR)
# DECOMP=1 verified C only, DECOMP=2 + tested, DECOMP=3 + untested (experimental)
TIERS   := verified $(if $(filter 2 3,$(DECOMP)),tested) $(if $(filter 3,$(DECOMP)),untested)
ifdef DECOMP_LIST
CSRC    := $(shell cat $(DECOMP_LIST))
TIERS   :=
else
CSRC    := $(foreach t,$(TIERS),$(shell cat config/decomp_$(t).txt))
endif
COBJS   := $(CSRC:%=$(BUILD)/src/%.o)
ASFLAGS_EXTRA := --defsym DECOMP_BUILD=1 -I $(BUILD)
else ifneq ($(MODERN),0)
ROM     := log1_modern.gba
BUILD   := build_modern
DATADIR := build_modern/src
else ifneq ($(SHIFT),0)
ROM     := log1_shift.gba
BUILD   := build_shift
else
ROM     := log1.gba
BUILD   := build
endif
ELF     := $(ROM:.gba=.elf)
ASFLAGS := -mcpu=arm7tdmi -mthumb-interwork -I . --defsym SHIFT=$(SHIFT) $(ASFLAGS_EXTRA)

CODE    := $(shell cat config/code_files.txt)
DATA    := $(shell cat config/data_files.txt)
ifneq ($(MODERN),0)
DATA    += rodata_appendix
endif
OBJS    := $(BUILD)/asm/header.o $(CODE:%=$(BUILD)/asm/%.o) $(BUILD)/asm/iwram.o $(DATA:%=$(BUILD)/data/%.o)
ifneq ($(SHIFT),0)
OBJS    += $(BUILD)/asm/shift.o
endif

.PHONY: FORCE all compare clean harness shift-test extract modern modern-rom decomp patch verify-mods
all: $(ROM)

compare: $(ROM)
	@sha1sum -c log1.sha1

$(BUILD)/asm/%.o: asm/%.s asm/macros.inc baserom.gba $(if $(COBJS),$(BUILD)/decomp_defs.inc)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD)/src/%.o: src/%.c include/ghidra_types.h tools/decomp/cc.sh
	@mkdir -p $(dir $@)
	tools/decomp/cc.sh $@.tmp $< $(CFLAGS)
	@# the assembly keeps NAME at the original address as a long jump to NAME__c (docs/decomp.md)
	$(OBJCOPY) --redefine-sym $(notdir $*)=$(notdir $*)__c $@.tmp $@ && rm $@.tmp

# rewritten on every run, but only touched when the function list changes (so asm is reassembled exactly then)
$(BUILD)/decomp_defs.inc: FORCE
	@mkdir -p $(BUILD)
	@echo '$(notdir $(CSRC))' | tr ' ' '\n' | grep . | sed 's/.*/\t.set DECOMP_&, 1/' > $@.tmp
	@cmp -s $@.tmp $@ && rm $@.tmp || mv $@.tmp $@

$(BUILD)/src_objs.ld: FORCE
	@mkdir -p $(BUILD)
	@echo '$(COBJS)' | tr ' ' '\n' | grep . | sed 's/.*/&(.text* .rodata*);/' > $@.tmp
	@cmp -s $@.tmp $@ && rm $@.tmp || mv $@.tmp $@

FORCE:

$(BUILD)/data/%.o: $(DATADIR)/%.s baserom.gba
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD)/code_objs.ld: config/code_files.txt
	@mkdir -p $(BUILD)
	sed 's|.*|$(BUILD)/asm/&.o(.text);|' $< > $@
ifneq ($(SHIFT),0)
	sed -i '1a $(BUILD)/asm/shift.o(.text);' $@
endif

$(BUILD)/data_objs.ld: config/data_files.txt
	@mkdir -p $(BUILD)
	sed 's|.*|$(BUILD)/data/&.o(.rodata);|' $< > $@
ifneq ($(MODERN),0)
	echo '$(BUILD)/data/rodata_appendix.o(.rodata);' >> $@
endif

$(BUILD)/ld_script.ld: ld_script.ld
	@mkdir -p $(BUILD)
	sed 's|build/|$(BUILD)/|g' $< > $@

$(ELF): $(OBJS) $(COBJS) $(BUILD)/ld_script.ld $(BUILD)/code_objs.ld $(BUILD)/data_objs.ld $(BUILD)/src_objs.ld
	$(LD) -T $(BUILD)/ld_script.ld -Map $(BUILD)/log1.map -o $@ $(OBJS) $(COBJS) $(if $(COBJS),src/absolute.ld $(LIBGCC))

$(ROM): $(ELF)
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x08800000 $< $@

# ---- assets / modern build
assets/manifest.json: baserom.gba
	$(PYTHON) tools/assets/assets.py extract

extract: assets/manifest.json

modern: assets/manifest.json
	$(PYTHON) tools/assets/assets.py build
	$(PYTHON) tools/assets/apply.py build_modern/overrides/overrides.json data build_modern/src
	$(MAKE) MODERN=1 modern-rom

modern-rom: $(ROM)

# share a hack: log1_modern.bps (apply it to an original Legacy of Goku (USA) ROM)
patch: modern
	$(PYTHON) tools/bps.py make baserom.gba log1_modern.gba log1_modern.bps

# end-to-end check of the modding toolkit (demo edits in the emulator)
verify-mods:
	$(PYTHON) tools/assets/verify_mods.py

# ---- tools
harness: tools/harness/harness
tools/harness/harness: tools/harness/harness.c
	$(CC) -O2 -o $@ $< -lmgba -lpng -lz

shift-test:
	tools/harness/shift_test.sh $(if $(filter-out 0,$(SHIFT)),$(SHIFT),0x100)

decomp:
	$(MAKE) DECOMP=$(if $(filter-out 0,$(DECOMP)),$(DECOMP),1) log1_decomp.gba

clean:
	rm -rf build build_decomp build_decomp_w* log1_decomp_w*.* build_shift build_modern *.gba.tmp log1.elf log1_shift.* log1_modern.* log1.gba tools/harness/harness
