//
// Created by anrdew sviatie on 05.01.2024.
//

#include "s21_tests.h"

START_TEST(empty_str) {
        size_t n_byte = 0;
        char str[10] = "";
        int find_byte = '\0';

        ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
        memchr(str, find_byte, n_byte));
} END_TEST

START_TEST(classic) {

    char *str = "It is not realistic to test using every single possible string argument.\n"
                "the length of the string, and\n"
                "the characters that make up the string.";
    size_t n_byte = strlen(str);
    int find_byte = ',';

    ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                     memchr(str, find_byte, n_byte));
}

Suite *suite_memchr(void) {
    Suite *s = suite_create("suite_memchr");
    TCase *tc = tcase_create("memchr_tc");

    tcase_add_test(tc, empty_str);
    tcase_add_test(tc, classic);

    suite_add_tcase(s, tc);
    return s;
}