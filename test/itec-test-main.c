#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include "itec-lib/itec.h"

static void test_swap(void **state)
{
    int i = 3;
    int j = 2;

    swap(i,j);

    assert_int_equal(i, 2);
    assert_int_equal(j, 3);
}


int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_swap)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}