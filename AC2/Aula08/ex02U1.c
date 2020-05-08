#include <detpic32.h>
#include "../util.h"

int main(void){
	config_UART1(600,'O',2);
	while(1){
		put_char('+');
		delay(1000);
	}
}
