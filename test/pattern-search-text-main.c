#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include <string.h>
#include <stdlib.h>
//#include <malloc.h>
#include <stdio.h>

#include "itec-lib/patternsearch.h"

    

static void test_pattern_search_all(void **state)
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


static void test_pattern_search_all_empty_pattern(void **state)
{
    char text[] = "ottos mops trotzt\n ottotto: fort mops fort\n ... Ernst Jandl"; 
    char pattern[] = "";

    int refbitmap[59] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //typ :int *

    const int text_length = strlen(text);
    int *bitmap = malloc(text_length * sizeof(int)); //dynamische speicher alloc auf dem heap muss wieder freigegeben werden
    
    assert_non_null(bitmap);

    pattern_search_all(pattern, text, bitmap);

    for (size_t i = 0; i < text_length; i++)
    {
        printf("index: %i - %i <-> %i)\n", i, bitmap[i], refbitmap[i]);
        assert_int_equal(bitmap[i],refbitmap[i]);
    }

    free(bitmap); //Freigabe des Speichers
}


static void test_pattern_search(void **state)
{
    char text[] = "ottos mops trotzt\n ottotto: fort mops fort\n ... Ernst Jandl"; 
    char pattern[] = "mops";

    int ret = pattern_search(pattern, text);

    assert_int_equal(ret,6);
}

static void test_pattern_all_empty_text(void **state)
{
    char text[] = ""; 
    char pattern[] = "otto";

    int bitmap[] = {0}; //typ :int *

    assert_non_null(bitmap);

    pattern_search_all(pattern, text, bitmap);

    assert_int_equal(bitmap[0],0);
}


static void test_pattern_empty_text(void **state)
{
    char text[] = ""; 
    char pattern[] = "otto";

    int ret = pattern_search(pattern, text);

    assert_int_equal(ret,-1);
}

static void test_pattern_empty_pattern(void **state)
{
    char text[] = "ottos mops trotzt\n ottotto: fort mops fort\n ... Ernst Jandl"; 
    
    char pattern[] = "";

    int ret = pattern_search(pattern, text);

    assert_int_equal(ret, -1);
}


int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_pattern_search_all),
        cmocka_unit_test(test_pattern_all_empty_text),
        cmocka_unit_test(test_pattern_empty_text),
        cmocka_unit_test(test_pattern_search),
        cmocka_unit_test(test_pattern_empty_pattern),
        cmocka_unit_test(test_pattern_search_all_empty_pattern)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}