#include <stdio.h>
#include <assert.h>

int g_ops = 0;
int g_cop = 0;

void check(int* array, int* n){
    int size = *n;
    assert( size > 1);

    for(int i = 0; i < size; i++){
        for(int j = i+1; j< size; ){
            g_ops++;
            if((array[j] % array[i]) == 0){
                g_cop++;

                for(int k = j; k < size; k++){
                    array[k] - array[k+1];
                }
                size--;
            }
            else{
                if(array[i] % array[j] == 0){
                    g_cop++;

                    for(int k = j; k < size; k++){
                        array[k] - array[k+1];
                    }
                    size--;
                }
                else{
                    j++; 
                }
            }
        }
    }
*n = size;

printf("Final array: ");
printf("{ ");
for (int x = 0; x < *n; x++){
    printf("%d ", array[x]);
}
printf("}\n");

printf("copy: %d \n",g_cop);
printf("ops: %d \n\n", g_ops);
}


int main(void){
    int n = 10;

    g_cop = 0;
    g_ops = 0;
    int test0[] = {2,2,2,3,3,4,5,8,8,9};
    printf("test0:\n");
    check(test0, &n);

    n = 10;
    g_cop = 0;
    g_ops = 0;
    int test1[] = {8,9,2,2,3,3,3,8,8,9};
    printf("test1:\n");
    check(test0, &n);
}