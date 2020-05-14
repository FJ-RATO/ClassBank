#include <detpic32.h>
#include "../util.h"

void UART2Interrupts(void){

	IEC1bits.U2RXIE = 1;    //receivever
	IEC1bits.U2TXIE = 0;   //transmiter
	IEC1bits.U2EIE = 1;   //enable error
	IPC8bits.U2AIP = 3;  //priority
}

int main(void){
	config_UART2(115200,'N',1);
	UART1Interrupts();
	EnableInterrupts();
	while(1);
}

void _int_(24) isr_uart1(void){
	put_char(U1RXREG);
	IFS1bits.U2RXIF = 0;	
}