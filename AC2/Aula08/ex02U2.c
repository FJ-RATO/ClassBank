#include <detpic32.h>
#include "../util.h"

void putc(char byte2send){
	while(U2STAbits.UTXBF == 1)
		;
	U2TXREG = byte2send;
}

int main(void){
	while(1){
		putc('+');
		delay(1000);
	}
}