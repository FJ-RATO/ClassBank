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
//using UART1

void config_UART1(int baudrate, char paridade, int stop){

	if((baudrate < 600) || (baudrate > 115200) || ((paridade != 'N') && (paridade != 'E') && (paridade != 'O')) || ((stop != 1)&& (stop != 2)) ){
		//change to default
		U1BRG =( 20000000 / (16 * 115200)); 
		U1MODEbits.PDSEL = 0;
		U1MODEbits.STSEL = 0;
	}

	else{
		U1BRG =( 20000000 / (16 * baudrate)); 
		
		if(paridade == 'N'){
			U1MODEbits.PDSEL = 0;
		}
		else if(paridade == 'E'){
			U1MODEbits.PDSEL = 1;
		}
		else if(paridade == 'O'){
			U1MODEbits.PDSEL = 2;
		}

		if(stop == 1){
			U1MODEbits.STSEL = 0;
		}
		else if(stop == 2){
			U1MODEbits.STSEL = 1;
		}
	}
}

void put_char(char byte2send){
	while(U1STAbits.UTXBF == 1)
		;
	U1TXREG = byte2send;
}

void put_string(char *str){
	for(;*str != '\0'; str++){
		put_char(*str);
	}
}
