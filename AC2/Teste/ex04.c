#include <detpic32.h>

void delay(unsigned int ms){
	for(;ms > 0; ms--){
		resetCoreTimer();
		while(readCoreTimer() < PBCLK/1000);
	}
}

void send2displays(unsigned char value){
	static const char display7Scodes[] = {0x3F,0x06,0x5B,0x79,0x74,0x6D,0x6F,0x38,0x7F,0x7C,0x7E,0x67,0X0F,0x73,0x4F,0x4E};
	static char flag = 1;
	int dl = value & 0x0F;
	int dh = value >> 4;
	if(flag){
		LATB = (LATB & 0x00FF) | (display7Scodes[dl] << 8);
		LATDbits.LATD5 = 1;
		LATDbits.LATD6 = 0;
	}
	else{
		LATB = (LATB & 0x00FF) | (display7Scodes[dh] << 8);
		LATDbits.LATD5 = 0;
		LATDbits.LATD6 = 1;
	}
	flag = !flag;
}

int main(void){
	//led config
	TRISE = TRISE & 0xFFF0;

	//display config
	LATB = LATB & 0x00FF;
	TRISB = TRISB & 0x00FF;
	LATD = LATD & 0xFF9F;
	TRISD = TRISD & 0xFF9F;

	char c, tecla;

	c = getChar();

	while(1){
		delay(5);
		if((tecla = inkey()) != 0)
			c = tecla;
		switch(c){ //getchar é bloqueante

			case '0':
			LATEbits.LATE0 = 1;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 0;
			send2displays(0);
			break;

			case '1':
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 1;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 0;
			send2displays(1);
			break;

			case '2':
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 1;
			LATEbits.LATE3 = 0;
			send2displays(2);
			break;

			case '3':
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 1;
			send2displays(3);
			break;

			default:
			LATEbits.LATE0 = 1;
			LATEbits.LATE1 = 1;
			LATEbits.LATE2 = 1;
			LATEbits.LATE3 = 1;
			
			
			int i = 0;
			while(i++ < 200){
				send2displays(0xFF);
				delay(5);
			}
			LATEbits.LATE0 = 0;
			LATEbits.LATE1 = 0;
			LATEbits.LATE2 = 0;
			LATEbits.LATE3 = 0;
			
			LATDbits.LATD5 = 0;
			LATDbits.LATD6 = 0;
			c = getChar();
			break;

		}
	}
}

