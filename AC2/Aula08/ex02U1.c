#include <detpic32.h>
#include "../util.h"

int main(void){
	config_UART1(99999999,'O',2); //feeding wrong data to trigger default mode
	while(1){
		put_char('+');
		delay(1000);
	}
}
