#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include <string.h>

#include "itec-lib/quicksort.h"
#include "itec-lib/mergesort.h"

static void quick_sort_deals_with_zero_input(void **state)
{
    int arr[] = {};
    int length = 0;

    quickSort(arr,0,length-1);
}

static void quick_sort_deals_with_input_length_1(void **state)
{
    int arr[] = {1};
    int length = 1;

    int result = 1;

    quickSort(arr,0,length-1);

    assert_int_equal(arr[0], result);
}

static void quick_sort_array_with_same_numbers(void **state)
{
    int arr[] = {5,6,3,2,7,8,2,3,5,8,9};
    int length = sizeof(arr) / sizeof(arr[0]);

    //copy array for the second algorithm.
    int arr_sorted[] = {2, 2, 3, 3, 5, 5, 6, 7, 8, 8, 9};

    quickSort(arr,0,length-1);
    
    for (size_t i = 0; i < length; i++)
    {
        assert_int_equal(arr[i],arr_sorted[i]);
    }
}

static void merge_sort_deals_with_zero_input(void **state)
{
    int arr[] = {};
    int length = 0;

    mergeSort(arr,0,length-1);
}

static void merge_sort_deals_with_input_length_1(void **state)
{
    int arr[] = {1};
    int length = 1;

    int result = 1;

    mergeSort(arr,0,length-1);

    assert_int_equal(arr[0], result);
}

static void merge_sort_array_with_same_numbers(void **state)
{
    int arr[] = {5,6,3,2,7,8,2,3,5,8,9};
    int length = sizeof(arr) / sizeof(arr[0]);

    //copy array for the second algorithm.
    int arr_sorted[] = {2, 2, 3, 3, 5, 5, 6, 7, 8, 8, 9};

    mergeSort(arr,0,length-1);
    
    for (size_t i = 0; i < length; i++)
    {
        assert_int_equal(arr[i],arr_sorted[i]);
    }
}


int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(quick_sort_deals_with_zero_input),
        cmocka_unit_test(quick_sort_array_with_same_numbers),
        cmocka_unit_test(quick_sort_deals_with_input_length_1),
        cmocka_unit_test(merge_sort_array_with_same_numbers),
        cmocka_unit_test(merge_sort_array_with_same_numbers),
        cmocka_unit_test(merge_sort_deals_with_input_length_1),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}