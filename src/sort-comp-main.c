#include <time.h> //c_clock for time measurement
#include <stdio.h>  //printf
#include <string.h> // Include for memcpy

#include "itec-lib/itec.h" //print_array
#include "itec-lib/mergesort.h" //mergesort
#include "itec-lib/quicksort.h" //quicksort


int main(){
    int arr[] = {5,6,3,2,7,8,2,3,5,8,9};
    int length = sizeof(arr) / sizeof(arr[0]);

    //copy array for the second algorithm.
    int arr_cpy[length];

    memcpy(arr_cpy, arr, sizeof(arr));


    printf("Initialized array of length %i: \n", length);
    printf_array(length, arr);

    clock_t start = clock();
    mergeSort(arr,0,length-1);
    clock_t end = clock();

    printf("MergeSort result: \n");
    printf_elapsed_time(end, start);
    printf_array(length, arr);

    start = clock();
    quickSort(arr_cpy,0,length-1);
    end = clock();

    printf("quicksort result: \n");
    printf_elapsed_time(end, start);
    printf_array(length, arr_cpy);
}

