#include <detpic32.h>
#include "../util.h"

int main(void){

	LATB = LATB & 0x00FF;
	TRISB = TRISB & 0x00FF;
	LATD = LATD & 0xFF9F;
	TRISD = TRISD & 0xFF9F;
	LATDbits.LATD5 = 1;
	LATDbits.LATD6 = 0;

	while(1){
		switch(getChar()){
		
			case 'a':
			LATB = (LATB & 0x00FF ) | 0x0100 ;
			break;
			
			case 'b':
			LATB = (LATB & 0x00FF ) | 0x0200 ;
			break;

			case 'c':
			LATB = (LATB & 0x00FF ) | 0x0400 ;
			break;

			case 'd':
			LATB = (LATB & 0x00FF ) | 0x0800 ;
			break;

			case 'e':
			LATB = (LATB & 0x00FF ) | 0x1000 ;
			break;

			case 'f':
			LATB = (LATB & 0x00FF ) | 0x2000 ;
			break;

			case 'g':
			LATB = (LATB & 0x00FF ) | 0x4000 ;
			break;

			case 's':
			LATDbits.LATD5 = !LATDbits.LATD5;
			LATDbits.LATD6 = !LATDbits.LATD6;
			break;

			default:
			LATB = (LATB & 0x00FF ) | 0xFF00 ;
			break;
		}
		
		
	}
}