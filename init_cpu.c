#include "F28x_Project.h"
void dis_wdg(void){
EALLOW;
WdRegs.SCSR.bit.WDOVERRIDE=1;
WdRegs.WDCR.bit.WDDIS=1;
EDIS;
}
void cfg_clk(void){
EALLOW;
ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL = 1;//external clock as source for the oscillator
ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN=0;// by pass the pll
ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV=0;
ClkCfgRegs.SYSPLLMULT.bit.IMULT=12;
ClkCfgRegs.SYSPLLMULT.bit.FMULT=0;
int i;
for(i=0;i<5;i++){
ClkCfgRegs.SYSPLLCTL1.bit.PLLEN=1;
while(ClkCfgRegs.SYSPLLSTS.bit.LOCKS!=1){

}
}
ClkCfgRegs.SYSPLLCTL1.bit.PLLCLKEN = 1;

//ClkCfgRegs.SYSPLLCLT1.bit.PLLCLKEN=1;
EDIS;
}
void cfg_wdg(void){
EALLOW;
WdRegs.WDCR.bit.WDPS=2;
WdRegs.WDKEY.bit.WDKEY=0x55;
WdRegs.WDKEY.bit.WDKEY=0xAA;
WdRegs.WDCR.bit.WDDIS=0;
EDIS;
}
