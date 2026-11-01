// Pre-script for Ghidra headless: add GBA RAM/IO memory blocks and name the I/O registers.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;

public class AddGbaMemory extends GhidraScript {
    void block(String name, long start, long len, boolean vol) throws Exception {
        Address a = toAddr(start);
        if (currentProgram.getMemory().getBlock(a) != null) return;
        MemoryBlock b = currentProgram.getMemory().createUninitializedBlock(name, a, len, false);
        b.setRead(true); b.setWrite(true); b.setVolatile(vol);
    }
    void reg(long a, String n) throws Exception {
        createLabel(toAddr(a), n, true, SourceType.IMPORTED);
    }
    public void run() throws Exception {
        block("EWRAM", 0x02000000L, 0x40000, false);
        // IWRAM after the RW image (LoG1 has no RW image in IWRAM: the whole block is RAM)
        block("IWRAM_BSS", 0x03000000L, 0x8000, false);
        block("IO", 0x04000000L, 0x400, true);
        block("PALRAM", 0x05000000L, 0x400, false);
        block("VRAM", 0x06000000L, 0x18000, false);
        block("OAM", 0x07000000L, 0x400, false);
        String[][] r = {{"04000000","REG_DISPCNT"},{"04000004","REG_DISPSTAT"},{"04000006","REG_VCOUNT"},
          {"04000008","REG_BG0CNT"},{"0400000A","REG_BG1CNT"},{"0400000C","REG_BG2CNT"},{"0400000E","REG_BG3CNT"},
          {"04000010","REG_BG0HOFS"},{"04000012","REG_BG0VOFS"},{"04000014","REG_BG1HOFS"},{"04000016","REG_BG1VOFS"},
          {"04000018","REG_BG2HOFS"},{"0400001A","REG_BG2VOFS"},{"0400001C","REG_BG3HOFS"},{"0400001E","REG_BG3VOFS"},
          {"04000040","REG_WIN0H"},{"04000048","REG_WININ"},{"0400004A","REG_WINOUT"},{"0400004C","REG_MOSAIC"},
          {"04000050","REG_BLDCNT"},{"04000052","REG_BLDALPHA"},{"04000054","REG_BLDY"},
          {"04000080","REG_SOUNDCNT_L"},{"04000082","REG_SOUNDCNT_H"},{"04000084","REG_SOUNDCNT_X"},
          {"040000A0","REG_FIFO_A"},{"040000A4","REG_FIFO_B"},
          {"040000B0","REG_DMA0SAD"},{"040000BC","REG_DMA1SAD"},{"040000C0","REG_DMA1DAD"},{"040000C4","REG_DMA1CNT"},
          {"040000C8","REG_DMA2SAD"},{"040000D4","REG_DMA3SAD"},{"040000D8","REG_DMA3DAD"},{"040000DC","REG_DMA3CNT"},
          {"04000100","REG_TM0CNT"},{"04000104","REG_TM1CNT"},{"04000108","REG_TM2CNT"},{"0400010C","REG_TM3CNT"},
          {"04000130","REG_KEYINPUT"},{"04000132","REG_KEYCNT"},
          {"04000200","REG_IE"},{"04000202","REG_IF"},{"04000204","REG_WAITCNT"},{"04000208","REG_IME"}};
        for (String[] e : r) reg(Long.parseLong(e[0], 16), e[1]);
    }
}
