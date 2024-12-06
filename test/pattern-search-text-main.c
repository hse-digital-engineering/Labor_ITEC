#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include <string.h>
#include <malloc.h>
#include "itec-lib/patternsearch.h"

static void test_pattern_all(void **state)
{
    char text[] = "ottos mops trotzt\n ottotto: fort mops fort\n ... Ernst Jandl"; 
    char pattern[] = "otto";

    int refbitmap[59] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int *bitmap; //typ :int *

    int text_length = strlen(text);
    bitmap = malloc(text_length * sizeof(int)); //dynamische speicher alloc auf dem heap muss wieder freigegeben werden
    
    assert_non_null(bitmap);

    pattern_search_all(pattern, text, bitmap);

    for (size_t i = 0; i < text_length; i++)
    {
        assert_int_equal(bitmap[i],refbitmap[i]);
    }

    free(bitmap); //Freigabe des Speichers
    
}


int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_pattern_all)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}