#include <detpic32.h>

int main(void){
	TRISEbits.TRISE0 = 0;
	TRISEbits.TRISE1 = 0;
	TRISEbits.TRISE2 = 0;
	TRISEbits.TRISE3 = 0;
	//ou então TRISE = TRISE & 0xFFF0;

	TRISBbits.TRISB0 = 1;
	TRISBbits.TRISB1 = 1;
	TRISBbits.TRISB2 = 1;
	TRISBbits.TRISB3 = 1;
	// ou então TRISB = TRISB & 0x000F;

	while(1){
		LATEbits.LATE0 = PORTBbits.RB0;
		LATEbits.LATE1 = PORTBbits.RB1;
		LATEbits.LATE2 = PORTBbits.RB2;
		LATEbits.LATE3 = PORTBbits.RB3; // PORT USA A NUMENCLATURA ANTIGA WHY??????
	}
}
