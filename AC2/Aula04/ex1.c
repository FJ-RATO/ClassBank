#include <detpic32.h>
#include "../util.h"
int main(void)
{
	LATDbits.LATD0 = 0;

	TRISDbits.TRISD0 = 0;
	while(1){
		delay(500);
		LATDbits.LATD0 = !LATDbits.LATD0;
	}
	return 0;
}