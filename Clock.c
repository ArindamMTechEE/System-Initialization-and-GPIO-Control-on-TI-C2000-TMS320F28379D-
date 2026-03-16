#include "F28x_Project.h"

void sys_clk(void)
{
    Uint16 i;

    DINT;   // Mask CPU interrupts

    /* -------- CLOCK: 120 MHz -------- */
    EALLOW;

    ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 1;  // External clock
    ClkCfgRegs.SYSPLLCTL1.bit.PLLEN = 0;         // Bypass PLL
    ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 0;

    ClkCfgRegs.SYSPLLMULT.bit.IMULT = 12;
    ClkCfgRegs.SYSPLLMULT.bit.FMULT = 0;

    for(i = 0; i < 5; i++)
    {
        ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 1;
       while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS != 1);
    }

    ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV = 0; // 120 MHz

    /* -------- PIE -------- */
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
    PieCtrlRegs.PIEACK.all = 0xFFFF;

    IER = 0x0000;
    IFR = 0x0000;

    EDIS;

    EINT;   // Enable CPU interrupts
}
