/**
* main.c
*/
#include "F28x_Project.h"

void dis_wdg();
void cfg_clk();
void cfg_wdg();
void cfg_gpio();

void main(void)
{
DINT;
//init_proc();
dis_wdg();
cfg_clk();
cfg_wdg();
cfg_gpio();
EINT;
while(1){
EALLOW;
GpioDataRegs.GPATOGGLE.bit.GPIO31=1;

EDIS;

}
//return 0;
}
