#include "Delay.h"


void delay_us(int x){
    delay_cycles(x * CPUCLK_FREQ /1000000);
}

void delay_ms(int x){
    delay_cycles(x * CPUCLK_FREQ /1000);
}
