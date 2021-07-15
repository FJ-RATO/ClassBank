#include<stdio.h>

int main (int argc, char* argv[]){//argc = numero de argumentos | argv = argumentos
    //char name[50];
    
    puts ("Hello World!"); //apenas para strings
    //printf("Name?\n");

    if((argc == 1) || (argc > 3)){
        printf("Incorrect number of arguments, must be 2");
    }
    else{
    //fgets(name,50,stdin); //ler do teclado
    printf( "hello %s %s ! \n", argv[1], argv[2]);
    }
    return 0;
}