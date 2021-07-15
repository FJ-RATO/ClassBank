#include <stdio.h>
#include <assert.h>

int g_counter = 0;

float r(float* input,int size){ //find r
    g_counter++;
    return input[1] / input[0];
}

int check(float r, float* input, int size){
    assert(size > 2);
    for(int i = 2; i < size; i++){
        g_counter++;
        float first = input[i-1];
        float next = input[i];
        if((r*first) != next){
            return 0;
        }
    }
    return 1;
}

int main(void){

    float reason;
    int progression;



    g_counter = 0;
    float test0[] = {1,2,3,4,5,6,7,8,9,10};
    reason = r(test0,10);
    progression = check(reason,test0,10);
    printf("test0 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float big[] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
    reason = r(big,20);
    progression = check(reason,test0,20);
    printf("big is progression: %i\nWith %i operationsn\n", progression, g_counter);

    g_counter = 0;
    float test1[] = {1,2,4,4,5,6,7,8,9,10};
    reason = r(test1,10);
    progression = check(reason,test1,10);
    printf("test1 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test2[] = {1,2,4,8,5,6,7,8,9,10};
    reason = r(test2,10);
    progression = check(reason,test2,10);
    printf("test2 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test3[] = {1,2,4,8,16,6,7,8,9,10};
    reason = r(test3,10);
    progression = check(reason,test3,10);
    printf("test3 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test4[] = {1,2,4,8,16,32,7,8,9,10};
    reason = r(test4,10);
    progression = check(reason,test4,10);
    printf("test4 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test5[] = {1,2,4,8,16,32,64,8,9,10};
    reason = r(test5,10);
    progression = check(reason,test5,10);
    printf("test5 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test6[] = {1,2,4,8,16,32,64,128,9,10};
    reason = r(test6,10);
    progression = check(reason,test6,10);
    printf("test6 is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test7[] = {1,2,4,8,16,32,64,128,256,10};
    reason = r(test7,10);
    progression = check(reason,test7,10);
    printf("test is progression: %i\nWith %i operations\n", progression, g_counter);

    g_counter = 0;
    float test8[] = {1,2,4,8,16,32,64,128,256,512};
    reason = r(test8,10);
    progression = check(reason,test8,10);
    printf("test8 is progression: %i\nWith %i operations\n", progression, g_counter);

}