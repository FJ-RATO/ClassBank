#include <stdio.h>
#include <assert.h>

typedef unsigned int uint;
int g_counter = 0;

uint t1(uint n){
    assert(n >= 0);
    g_counter++; //number of fucntion calls
    if(n == 0){
        return 0;
    }
    else{
        return t1(n/4) + n;
    }
}

uint t2(uint n){
    assert(n >= 0);
    g_counter++; //number of fucntion calls
    if(n < 4){
        return n;
    }
    else{
        return t2(n/4) + t2((n+3)/4) + n;
    }
}

uint t3(uint n){
    assert(n >= 0);
    g_counter++; //number of fucntion calls
    if(n < 4){
        return n;
    }
    if((n%4) == 0){
        return 2 * t3(n/4) + n;
    }
    else{
        return t3(n/4) + t3((n+3)/4) + n;
    }
}

int main(void){
    int res;
    printf("\n\n=== T1 RESULTS ===\n");
    for(int i = 0; i < 29; i++){
        g_counter = 0;
        res = t1(i);
        printf("Test n = %d | Result = %d | calls = %d \n",i,res,g_counter);
    }
    printf("\n\n=== T2 RESULTS ===\n");
    for(int i = 0; i < 29; i++){
        g_counter = 0;
        res = t2(i);
        printf("Test n = %d | Result = %d | calls = %d \n",i,res,g_counter);
    }
    printf("\n\n=== T3 RESULTS ===\n");
    for(int i = 0; i < 29; i++){
        g_counter = 0;
        res = t3(i);
        printf("Test n = %d | Result = %d | calls = %d \n",i,res,g_counter);
    }

}