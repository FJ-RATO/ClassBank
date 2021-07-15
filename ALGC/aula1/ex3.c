#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (void){
    int count = 10;
    char number[10];
    float square;
    printf("Insert number of lines");
    fgets(number,5,stdin);
    count = atoi(number);
    for (size_t i = 0; i < count; i++){
        square = sqrt(i);
        printf ("|%d|%4.3f| \n", i,square);
    }
    
}