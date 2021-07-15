#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double Convert(double degree){
    double pi = 3.14;
    return(degree* (pi/180));
}

void print_table(double low, double high, double interval){
    
    //file pointer
    FILE *file;
    //open file in write mode
    file =fopen("ex4.txt","w");
    
    int interval_d = interval;
    int degree = low;
    low = Convert(low);
    high = Convert(high);
    interval = Convert(interval);

    for (double i = low; i < high; i = i + interval){
        double s = sin(i);
        double c = cos(i);

        fprintf(file,"%dº | sin(%4.3f) | cos(%4.3f) \n",degree,s,c);
        printf("%dº | sin(%4.3f) | cos(%4.3f) \n",degree,s,c);
        degree = degree + interval_d;
    }

    fclose(file);
    
}


int main (void){
    
    double low;
    double high;
    double interval;
    char aux[10];

    printf("Insert low value:\n");
    fgets(aux,10,stdin);
    low = atof(aux);

    printf("Insert high value:\n");
    fgets(aux,10,stdin);
    high = atof(aux);

    printf("Insert interval value:\n");
    fgets(aux,10,stdin);
    interval = atoi(aux);

    print_table(low,high,interval);

}

