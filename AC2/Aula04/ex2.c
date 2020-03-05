#include <detpic32.h>
#include "../util.h"

int main(void){

	LATE = LATE & 0xFFF0;
	TRISE = TRISE & 0xFFF0;

	int counter = 0;

	while(1){
		delay(500);
		LATE = (LATE & 0xFFF0) | counter;
		counter ++;
		if(counter > 15){
			counter = 0;
		}
	}
	return 0;
}