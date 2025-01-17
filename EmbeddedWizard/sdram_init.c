/*
 * Copyright 2018 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define __var unsigned int
__var __readMemory32(__var addr, char * notuse)
{
    return *(volatile __var*)addr;
}
void __writeMemory32(__var value, __var addr, char * notuse)
{
    *(volatile __var*)addr = value;
}
void SDRAM_WaitIpCmdDone(void)
{
  __var reg;
  do
  {
    reg = __readMemory32(0x400D403C, "Memory");
  }while((reg & 0x3) == 0);
  
  __writeMemory32(0x00000003, 0x400D403C, "Memory");    // clear IPCMDERR and IPCMDDONE bits  
}

void EnableOSC400M(void)
{
    __var reg;
    __var val;
    // CTRL1: power down
    reg = 0x40C84050;
    val = __readMemory32(reg, "Memory");
    val &= ~0x1;
    __writeMemory32(val, reg, "Memory");
    // CTRL2: enable clock
    reg = 0x40C84060;
    val = __readMemory32(reg, "Memory");
    val |= 0x1;
    __writeMemory32(val, reg, "Memory");
}

void EnableOSC24M(void)
{
    __var reg;
    __var val;

    reg = 0x40C84020;
    val = __readMemory32(reg, "Memory");
    if ((val & 0x10) == 0)
    {
        val = 0x14; // OSC_EN and LP_EN
        __writeMemory32(val, reg, "Memory");
        val = __readMemory32(reg, "Memory");
        while ((val & 0x80000000) == 0);
    }
}
void __delay(__var loop)
{
    for(int i=0; i<loop; i++)
    {
        // asm("nop");
        for(int j=0; j<1000; j++)
            ;
    }
}

void EnablePllLdo(void)
{
    __var reg;
    __var val;
    
    // CTRL_AI_CTRL
    reg = 0x40C84820; 
    __writeMemory32(0, reg, "Memory");
    // CTRL_AI_WDATA
    reg = 0x40C84830; 
    __writeMemory32(0x105, reg, "Memory");
    // PMU_LDO_PLL
    reg = 0x40C84500;
    val = __readMemory32(reg, "Memory");
    val |= 0x10000;
    __writeMemory32(val, reg, "Memory");
    __delay(100);

    // PMU_POWER_DETECT_CTRL
    reg = 0x40C84580;
    __writeMemory32(0x100, reg, "Memory");
    __delay(1);
    
    // PMU_REF_CTRL
    reg = 0x40C84570;
    __writeMemory32(0x10, reg, "Memory");
}

void SetSemcClock(void)
{
    __var reg;
    __var val;

    EnableOSC400M();
    // Set SEMC root clock
    reg = 0x40CC0200;
    // Use OSC400M and divided by 3
    //val = 0x202; //108MHz
    val = 0x602; //198MHz
    
    __writeMemory32(val, reg, "Memory");
}
 
void _clock_init(void)
{
    SetSemcClock();
}

void _sdr_Init(void)
{
  // Config IOMUX
  __writeMemory32(0x00000000, 0x400E8010, "Memory");
  __writeMemory32(0x00000000, 0x400E8014, "Memory"); 
  __writeMemory32(0x00000000, 0x400E8018, "Memory");
  __writeMemory32(0x00000000, 0x400E801C, "Memory");
  __writeMemory32(0x00000000, 0x400E8020, "Memory");
  __writeMemory32(0x00000000, 0x400E8024, "Memory");
  __writeMemory32(0x00000000, 0x400E8028, "Memory");
  __writeMemory32(0x00000000, 0x400E802C, "Memory");
  __writeMemory32(0x00000000, 0x400E8030, "Memory");
  __writeMemory32(0x00000000, 0x400E8034, "Memory");
  __writeMemory32(0x00000000, 0x400E8038, "Memory");
  __writeMemory32(0x00000000, 0x400E803C, "Memory");
  __writeMemory32(0x00000000, 0x400E8040, "Memory");
  __writeMemory32(0x00000000, 0x400E8044, "Memory");
  __writeMemory32(0x00000000, 0x400E8048, "Memory");
  __writeMemory32(0x00000000, 0x400E804C, "Memory");
  __writeMemory32(0x00000000, 0x400E8050, "Memory");
  __writeMemory32(0x00000000, 0x400E8054, "Memory");
  __writeMemory32(0x00000000, 0x400E8058, "Memory");
  __writeMemory32(0x00000000, 0x400E805C, "Memory");
  __writeMemory32(0x00000000, 0x400E8060, "Memory");
  __writeMemory32(0x00000000, 0x400E8064, "Memory");
  __writeMemory32(0x00000000, 0x400E8068, "Memory");
  __writeMemory32(0x00000000, 0x400E806C, "Memory");
  __writeMemory32(0x00000000, 0x400E8070, "Memory");
  __writeMemory32(0x00000000, 0x400E8074, "Memory");
  __writeMemory32(0x00000000, 0x400E8078, "Memory");
  __writeMemory32(0x00000000, 0x400E807C, "Memory");
  __writeMemory32(0x00000000, 0x400E8080, "Memory");
  __writeMemory32(0x00000000, 0x400E8084, "Memory");
  __writeMemory32(0x00000000, 0x400E8088, "Memory");
  __writeMemory32(0x00000000, 0x400E808C, "Memory");
  __writeMemory32(0x00000000, 0x400E8090, "Memory");
  __writeMemory32(0x00000000, 0x400E8094, "Memory");
  __writeMemory32(0x00000000, 0x400E8098, "Memory");
  __writeMemory32(0x00000000, 0x400E809C, "Memory");
  __writeMemory32(0x00000000, 0x400E80A0, "Memory");
  __writeMemory32(0x00000000, 0x400E80A4, "Memory");
  __writeMemory32(0x00000000, 0x400E80A8, "Memory");
  __writeMemory32(0x00000010, 0x400E80AC, "Memory"); // EMC_39, DQS PIN, enable SION
  __writeMemory32(0x00000000, 0x400E80B0, "Memory");
  __writeMemory32(0x00000000, 0x400E80B4, "Memory");
  __writeMemory32(0x00000000, 0x400E80B8, "Memory");
  __writeMemory32(0x00000000, 0x400E80BC, "Memory");
  __writeMemory32(0x00000000, 0x400E80C0, "Memory");
  __writeMemory32(0x00000000, 0x400E80C4, "Memory");
  __writeMemory32(0x00000000, 0x400E80C8, "Memory");
  __writeMemory32(0x00000000, 0x400E80CC, "Memory");
  __writeMemory32(0x00000000, 0x400E80D0, "Memory");
  __writeMemory32(0x00000000, 0x400E80D4, "Memory");
  __writeMemory32(0x00000000, 0x400E80D8, "Memory");
  __writeMemory32(0x00000000, 0x400E80DC, "Memory");
  __writeMemory32(0x00000000, 0x400E80E0, "Memory");
  __writeMemory32(0x00000000, 0x400E80E4, "Memory");
  __writeMemory32(0x00000000, 0x400E80E8, "Memory");
  __writeMemory32(0x00000000, 0x400E80EC, "Memory");
  __writeMemory32(0x00000000, 0x400E80F0, "Memory");
  __writeMemory32(0x00000000, 0x400E80F4, "Memory");
  __writeMemory32(0x00000000, 0x400E80F8, "Memory");
  __writeMemory32(0x00000000, 0x400E80FC, "Memory");
  __writeMemory32(0x00000000, 0x400E8100, "Memory");
  __writeMemory32(0x00000000, 0x400E8104, "Memory");
  __writeMemory32(0x00000000, 0x400E8108, "Memory");

  // PAD ctrl
  // PDRV = 1b (normal); PULL = 10b (PD)
  __writeMemory32(0x00000008, 0x400E8254, "Memory"); 
  __writeMemory32(0x00000008, 0x400E8258, "Memory");
  __writeMemory32(0x00000008, 0x400E825C, "Memory");
  __writeMemory32(0x00000008, 0x400E8260, "Memory");
  __writeMemory32(0x00000008, 0x400E8264, "Memory");
  __writeMemory32(0x00000008, 0x400E8268, "Memory");
  __writeMemory32(0x00000008, 0x400E826C, "Memory");
  __writeMemory32(0x00000008, 0x400E8270, "Memory");
  __writeMemory32(0x00000008, 0x400E8274, "Memory");
  __writeMemory32(0x00000008, 0x400E8278, "Memory");
  __writeMemory32(0x00000008, 0x400E827C, "Memory");
  __writeMemory32(0x00000008, 0x400E8280, "Memory");
  __writeMemory32(0x00000008, 0x400E8284, "Memory");
  __writeMemory32(0x00000008, 0x400E8288, "Memory");
  __writeMemory32(0x00000008, 0x400E828C, "Memory");
  __writeMemory32(0x00000008, 0x400E8290, "Memory");
  __writeMemory32(0x00000008, 0x400E8294, "Memory");
  __writeMemory32(0x00000008, 0x400E8298, "Memory");
  __writeMemory32(0x00000008, 0x400E829C, "Memory");
  __writeMemory32(0x00000008, 0x400E82A0, "Memory");
  __writeMemory32(0x00000008, 0x400E82A4, "Memory");
  __writeMemory32(0x00000008, 0x400E82A8, "Memory");
  __writeMemory32(0x00000008, 0x400E82AC, "Memory");
  __writeMemory32(0x00000008, 0x400E82B0, "Memory");
  __writeMemory32(0x00000008, 0x400E82B4, "Memory");
  __writeMemory32(0x00000008, 0x400E82B8, "Memory");
  __writeMemory32(0x00000008, 0x400E82BC, "Memory");
  __writeMemory32(0x00000008, 0x400E82C0, "Memory");
  __writeMemory32(0x00000008, 0x400E82C4, "Memory");
  __writeMemory32(0x00000008, 0x400E82C8, "Memory");
  __writeMemory32(0x00000008, 0x400E82CC, "Memory");
  __writeMemory32(0x00000008, 0x400E82D0, "Memory");
  __writeMemory32(0x00000008, 0x400E82D4, "Memory");
  __writeMemory32(0x00000008, 0x400E82D8, "Memory");
  __writeMemory32(0x00000008, 0x400E82DC, "Memory");
  __writeMemory32(0x00000008, 0x400E82E0, "Memory");
  __writeMemory32(0x00000008, 0x400E82E4, "Memory");
  __writeMemory32(0x00000008, 0x400E82E8, "Memory");
  __writeMemory32(0x00000008, 0x400E82EC, "Memory");
  __writeMemory32(0x00000008, 0x400E82F0, "Memory");
  __writeMemory32(0x00000008, 0x400E82F4, "Memory");
  __writeMemory32(0x00000008, 0x400E82F8, "Memory");
  __writeMemory32(0x00000008, 0x400E82FC, "Memory");
  __writeMemory32(0x00000008, 0x400E8300, "Memory");
  __writeMemory32(0x00000008, 0x400E8304, "Memory");
  __writeMemory32(0x00000008, 0x400E8308, "Memory");
  __writeMemory32(0x00000008, 0x400E830C, "Memory");
  __writeMemory32(0x00000008, 0x400E8310, "Memory");
  __writeMemory32(0x00000008, 0x400E8314, "Memory");
  __writeMemory32(0x00000008, 0x400E8318, "Memory");
  __writeMemory32(0x00000008, 0x400E831C, "Memory");
  __writeMemory32(0x00000008, 0x400E8320, "Memory");
  __writeMemory32(0x00000008, 0x400E8324, "Memory");
  __writeMemory32(0x00000008, 0x400E8328, "Memory");
  __writeMemory32(0x00000008, 0x400E832C, "Memory");
  __writeMemory32(0x00000008, 0x400E8330, "Memory");
  __writeMemory32(0x00000008, 0x400E8334, "Memory");
  __writeMemory32(0x00000008, 0x400E8338, "Memory");
  __writeMemory32(0x00000008, 0x400E833C, "Memory");
  __writeMemory32(0x00000008, 0x400E8400, "Memory");
  __writeMemory32(0x00000008, 0x400E8404, "Memory");
  __writeMemory32(0x00000008, 0x400E8408, "Memory");
  __writeMemory32(0x00000008, 0x400E840C, "Memory");

  // Config SDR Controller Registers/
  __writeMemory32(0x10000004, 0x400d4000, "Memory"); // MCR
  __writeMemory32(0x00030524, 0x400d4008, "Memory"); // BMCR0
  __writeMemory32(0x06030524, 0x400d400C, "Memory"); // BMCR1
  __writeMemory32(0x80000019, 0x400d4010, "Memory"); // BR0, 16MB
                                 
  __writeMemory32(0x00000F32, 0x400d4040, "Memory"); // SDRAMCR0, 32bit
  __writeMemory32(0x00772A22, 0x400d4044, "Memory"); // SDRAMCR1
  __writeMemory32(0x00010A0D, 0x400d4048, "Memory"); // SDRAMCR2
  __writeMemory32(0x21210408, 0x400d404C, "Memory"); // SDRAMCR3
                                 
  __writeMemory32(0x80000000, 0x400d4090, "Memory"); // IPCR0
  __writeMemory32(0x00000002, 0x400d4094, "Memory"); // IPCR1
  __writeMemory32(0x00000000, 0x400d4098, "Memory"); // IPCR2
                                 
  __writeMemory32(0xA55A000F, 0x400d409C, "Memory"); // IPCMD, SD_CC_IPREA
  SDRAM_WaitIpCmdDone();         
  __writeMemory32(0xA55A000C, 0x400d409C, "Memory"); // SD_CC_IAF
  SDRAM_WaitIpCmdDone();         
  __writeMemory32(0xA55A000C, 0x400d409C, "Memory"); // SD_CC_IAF
  SDRAM_WaitIpCmdDone();         
  __writeMemory32(0x00000033, 0x400d40A0, "Memory"); // IPTXDAT
  __writeMemory32(0xA55A000A, 0x400d409C, "Memory"); // SD_CC_IMS
  SDRAM_WaitIpCmdDone();         
                                 
  __writeMemory32(0x21210409, 0x400d404C, "Memory"); // enable sdram self refresh after initialization done.
}

void boot_sdram_config(void)
{
    //return;
    _clock_init();
    _sdr_Init();
}


