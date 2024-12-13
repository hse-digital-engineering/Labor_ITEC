
#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include <string.h>
#include "itec-lib/editdistance.h"

static void test_editdistance(void **state)
{

    char* source = "berlin";
    char* target = "bern";

    int n = strlen(source), m = strlen(target);

    int dist = editDistance(source, target, n, m);
    
    assert_int_equal(dist, 2);
}

static void test_editdistance_ZeroLengthInput(void **state)
{

    char* source = "berlin";
    char* target = "";

    int n = strlen(source), m = strlen(target);

    int dist = editDistance(source, target, n, m);

    assert_int_equal(dist, 6);

    dist = editDistance(target, source, m, n);

    assert_int_equal(dist, 6);


}


int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_editdistance),
        cmocka_unit_test(test_editdistance_ZeroLengthInput)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}