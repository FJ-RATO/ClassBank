#include <detpic32.h>
#include "../util.h"

void UART1Interrupts(void){

	IEC0bits.U1RXIE = 1;    //receivever
	IEC0bits.U1TXIE = 0;   //transmiter
	IEC0bits.U1EIE = 1;   //enable error
	IPC6bits.U1AIP = 3;  //priority
}

int main(void){
	config_UART1(115200,'N',1);
	UART1Interrupts();
	EnableInterrupts();
	while(1);
}

void _int_(24) isr_uart1(void){
	put_char(U1RXREG);
	IFS0bits.U1RXIF = 0;	
}