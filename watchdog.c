#include "F28x_Project.h"

void watchdog_disable(void)
{
    EALLOW;
    WdRegs.WDCR.all = 0x0068;   // Disable watchdog
    EDIS;
}
