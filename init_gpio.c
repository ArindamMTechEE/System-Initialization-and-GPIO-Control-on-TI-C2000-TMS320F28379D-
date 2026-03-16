#include "F28x_Project.h"

void cfg_gpio(void){
EALLOW;

GpioCtrlRegs.GPAMUX2.bit.GPIO31=0;
GpioCtrlRegs.GPADIR.bit.GPIO31=1;
EDIS;
}
