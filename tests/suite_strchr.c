#include "s21_tests.h"

START_TEST(url){
    char str[] = "https://edu.21-school.ru";
    int c = '.';

    ck_assert_str_eq(
        s21_strchr(str, c),
        strchr(str, c)
    );
}

START_TEST(classic){
    char str[] = "This returns a pointer to the first occurrence of the";
    int c = 'a';

    ck_assert_str_eq(
        s21_strchr(str, c),
        strchr(str, c)
    );
}

START_TEST(hard_case){
    char str[] = "123 \n 123 \n .... dsa \t\n.123\0 dasddas \0";
    int c = '.';

    ck_assert_str_eq(
        s21_strchr(str, c),
        strchr(str, c)
    );
}

START_TEST(last_chr){
    char str[] = "123 \n 123 \n .... dsa \t\n.\0 dasddas \0";
    int c = '.';

    ck_assert_str_eq(
        s21_strchr(str, c),
        strchr(str, c)
    );
}

START_TEST(after_bckslh_0){
    char str[] = "123 \n 123 \n .... dsa \t\n\0 .dasddas \0";
    int c = '.';

    ck_assert_str_eq(
        s21_strchr(str, c),
        strchr(str, c)
    );
}

START_TEST(gigachad){
    char str[] = "gigachad";
    int c = 'g';

    ck_assert_str_eq(
        s21_strchr(str, c),
        strchr(str, c)
    );
}

START_TEST(find_a) {
    char src[] = "abobasnutsa";
    char find = 'a';

    ck_assert_pstr_eq(s21_strchr(src, find),
                     strchr(src, find));
} END_TEST

START_TEST(find_A) {
    char src[] = "abobasnutAsa";
    char find = 'A';

    ck_assert_pstr_eq(s21_strchr(src, find),
                     strchr(src, find));
} END_TEST

START_TEST(find_1) {
    char src[] = "abobasnutA1sa";
    char find = '1';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(find_Z) {
    char src[] = "abobasnutAsa";
    char find = 'Z';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(find_3) {
    char src[] = "abobasnutAsa";
    char find = '3';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST

START_TEST(empty_src) {
    char src[] = "";
    char find = '3';

    ck_assert_pstr_eq(s21_strchr(src, find),
                      strchr(src, find));
} END_TEST


Suite *suite_strchr(void){
    Suite *s = suite_create("suite_strchr");
    TCase *tc = tcase_create("tc_strchr");

    tcase_add_test(tc, last_chr);
    tcase_add_test(tc, hard_case);
    tcase_add_test(tc, classic);
    tcase_add_test(tc, url);
    tcase_add_test(tc, gigachad);
    tcase_add_test(tc, find_a);
    tcase_add_test(tc, find_A);
    tcase_add_test(tc, find_1);
    tcase_add_test(tc, find_Z);
    tcase_add_test(tc, find_3);
    tcase_add_test(tc, empty_src);
    tcase_add_test(tc, after_bckslh_0);

    suite_add_tcase(s, tc);

    return s;
}