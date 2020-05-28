#include <detpic32.h>

void delay(unsigned int ms){
	for(;ms > 0; ms--){
		resetCoreTimer();
		while(readCoreTimer() < PBCLK/1000);
	}
}

int main(void){
	TRISEbits.TRISE0 = 0;
	TRISEbits.TRISE1 = 0;
	TRISEbits.TRISE2 = 0;
	TRISEbits.TRISE3 = 0;

	while(1){
		switch(getChar()){ //ex de polling

			case '0':
			LATEbits.LATE0 = 1;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 0;
			break;

			case '1':
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 1;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 0;
			break;

			case '2':
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 1;
			LATEbits.LATE3 = 0;
			break;

			case '3':
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 1;
			break;

			default:
			LATEbits.LATE0 = 1;
			LATEbits.LATE1 = 1;
			LATEbits.LATE2 = 1;
			LATEbits.LATE3 = 1;
			delay(1000);
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 0;
		}
	}
}

