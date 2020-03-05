#include <detpic32.h>

void delay(unsigned int ms){
	for(;ms > 0; ms--){
		resetCoreTimer();
		while(readCoreTimer() < PBCLK/1000);
	}
}