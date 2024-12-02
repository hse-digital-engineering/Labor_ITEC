
#include <stdlib.h>
#include <stdio.h>  //printf

#include "itec.h" 

void swap(int* i, int *j){
    int tmp = *i;
    *i = *j;
    *j = tmp;
}


void printf_array(int length, int *arr)
{
    printf("\t array = ("); // kein new line, damit wir das Array in eine Zeile schreiben können
    for (int i = 0; i < length; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf(")\n"); //new line um die Zeile abzuschließten
}

void printf_elapsed_time(clock_t end, clock_t start)
{
    double elapsed_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("\tRuntime: %.2f milliseconds\n", elapsed_time);
}


