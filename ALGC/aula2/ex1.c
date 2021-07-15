#include<stdio.h>
#include<stdlib.h>

unsigned int f1 (unsigned int n){
    unsigned int i,j,r = 0,ops = 0;
    for (i =1 ; i <= n ; i++){
        for (j = 1; j <= n ; j++){
            r += 1;
            ops++;
        }
    }
    printf("F1: %d\n",ops);
    return r;
}

unsigned int f2 (unsigned int n){
    unsigned int i, j, r = 0, ops = 0;
    for (i = 1; i <= n ; i++){
        for (j = 1; j <= i; j++){
            r += 1;
            ops++;
        }
    }
    printf("F2: %d\n",ops);
    return r;
}

unsigned int f3 (unsigned int n){
    unsigned int i,j,r = 0, ops = 0;
    for (i = 1; i <= n; i++){
        for (j = i ; j <= n ;j++){
            r += j;
            ops++;
        }
    }
    printf("F3: %d\n",ops);
    printf("F3 result: %u\n", r);
    return r;
}

unsigned int f4(unsigned int n){
    unsigned int i;
    unsigned int j;
    unsigned int r = 0;
    unsigned int ops = 0;
    for (i = 1; i <= n ; i++){
        for (j = i; j >= 1 ; j /= 10)
            r += i;
            ops++;
    }
    printf("F4: %d\n",ops);
    printf("F4 result: %u\n", r);
    return r;
}



int main(void){
    f4(15); 
    f4(2);
    f4(4);
    f4(8);
    f4(16);
    f4(32);
    f4(64);
    f4(1000);
    f4(2000);
}