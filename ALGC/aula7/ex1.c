#include<stdio.h>
#include<assert.h>

unsigned int g_counter = 0;

int f (int input){
    
    if(input <= 2){
        return 1;
    }
    else{
        unsigned int sum = 0;
        unsigned int res = f(input - 1) + f(input - 2);
        for(int k = 0; k <= (input-3); k++){
            sum += f(k) * f(input - 3 - k);
        }
        res = res + sum;
        return res;
    }
}

int f_dinamic(int n, int* array){

}

int main(){
    for(int i; i<26;i++){
        printf("%d \n",f(i));
    }

}