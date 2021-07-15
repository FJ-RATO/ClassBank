#include <stdio.h>
#include "elapsed_time.h"

typedef unsigned long long u64;

u64 P_rec(unsigned int n){
    if(n == 0){
        return (u64)0;
    }
    if(n == 1){
        return (u64)1;
    }
    return (u64)3 * P(n-1) + (u64)2* P(n-2);
}

u64 P_it(unsigned int n){
    if(n == 0){
        return (u64)0;
    }
    if(n == 1){
        return (u64)1;
    }
    

}

int main(void){
    (void)elapsed_time();
   
    for(int i = 0; i < 39; i++){
        printf("%lld\n",P_rec(i));
    }
    
    double timer = elapsed_time();
    printf("%f",timer);

    (void)elapsed_time();

    for(int i = 0; i < 39; i++){
        printf("%lld\n",P_it(i));
    }

}

