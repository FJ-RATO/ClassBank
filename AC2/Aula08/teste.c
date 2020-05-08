#import <detpic32.h>
#import "../util.h"
int main(void){
	printInt(20000000 / ((pow(4,2)) * 115200),10);
	printInt(20000000 / (16 * 115200),10); //valor esperado
}