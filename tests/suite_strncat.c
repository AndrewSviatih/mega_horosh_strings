#include "s21_tests.h"

START_TEST(classic){
    char str[20] = "abcdef";
    char dest[30] = "ghklmn";

    int n_byte = 6;

    ck_assert_str_eq(
        s21_strncat(dest, str, n_byte),
        strncat(dest, str, n_byte)
    );
} END_TEST

Suite *suite_strncat(void){
    Suite *s = suite_create("suite_strncat");
    TCase *tc = tcase_create("tc_strncat");

    tcase_add_test(tc, classic);

    suite_add_tcase(s, tc);

    return s;
}