#include <stdio.h>  //printf
#include <math.h> // methode exp
#include <time.h> //c_clock for time measurement

int main(){

    clock_t start = clock();

    for (size_t i = 0; i < 1000000; i++)
    {
        i = i+1;
        int j = exp(i)/exp(i);
        //printf("%i ", i);
    }

    clock_t end = clock();
    double elapsed_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Runtime: %.2f milliseconds\n", elapsed_time);
}