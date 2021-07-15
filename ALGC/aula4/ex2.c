#include <stdio.h>
#include <assert.h>

int g_compare = 0;

int check(int* array, int n){
    assert(n > 2);
    int res = 0;

    for (int k = 2 ; k < n; k++){
        for(int j = 1 ; j < k; j++){
            for(int i = 0; i < j ; i++){
                g_compare++;
                if(array[k] == array[i] + array[j]){
                    res++;
                }
            }
        }
    }
    return res;
}

int main(void){
    int res;
    int test_1[] = {1,2,3,4,5,6,7,8,9,10};
    int test_2[] = {1,2,1,4,5,6,7,8,9,10};
    int test_3[] = {1,2,1,3,2,6,7,8,9,10};
    int test_4[] = {0,2,2,0,3,3,0,4,4,0};
    int test_5[] = {0,0,0,0,0,0,0,0,0,0};


    g_compare = 0;
    res = check(test_1,10);
    printf("result: %d | g_compare: %d \n",res,g_compare);
    
    g_compare = 0;
    res = check(test_2,10);
    printf("result: %d | g_compare: %d \n",res,g_compare);
    
    g_compare = 0;
    res = check(test_3,10);
    printf("result: %d | g_compare: %d \n",res,g_compare);

    g_compare = 0;
    res = check(test_4,10);
    printf("result: %d | g_compare: %d \n",res,g_compare);
    
    g_compare = 0;
    res = check(test_5,10);
    printf("result: %d | g_compare: %d \n",res,g_compare);
    
}