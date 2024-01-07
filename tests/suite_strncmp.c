#include "s21_tests.h"

START_TEST(classic){
    char src[10] = "123456789";
    char dest[10] = "12345";
    size_t n = 5;

    ck_assert_int_eq(
        s21_strncmp(dest, src, n),
        strncmp(dest, src, n)
    );
}

START_TEST(hard){
    char src[] = "abcdsddas \n\n\t abcdaasdas . \0 .dsadasasd das d";
    char dest[] = "abcd";
    size_t n = 4;

    ck_assert_int_eq(
        s21_strncmp(dest, src, n),
        strncmp(dest, src, n)
    );
}

START_TEST(empty) {
    char str1[] = "";
    char str2[] = "";
    size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_) {
    char str1[] = "floppa";
    char str2[] = "";
    size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(_floppa) {
    char str1[] = "";
    char str2[] = "floppa";
    size_t n_byte = 0;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa_zero_byte) {
    char str1[] = "floppabazbazkotya";
    char str2[] = "floppabaz";
    size_t n_byte = 10;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

START_TEST(floppa_floppa_one_byte) {
    char str1[] = "floppa";
    char str2[] = "floppa";
    size_t n_byte = 1;

    int got = s21_strncmp(str1, str2, n_byte);
    int expected = strncmp(str1, str2, n_byte);

    if (got > 1) got = 1;
    if (expected > 1) expected = 1;

    if (got < -1) got = -1;
    if (expected < -1) expected = -1;

    ck_assert_int_eq(got, expected);
} END_TEST

Suite *suite_strncmp (void){
    Suite *s = suite_create("suite_strncmp");
    TCase *tc = tcase_create("tc_strncmp");

    tcase_add_test(tc, classic);
    tcase_add_test(tc, hard);
    tcase_add_test(tc, floppa_floppa_one_byte);
    tcase_add_test(tc, empty);
    tcase_add_test(tc, floppa_floppa_zero_byte);
    tcase_add_test(tc, _floppa);
    tcase_add_test(tc, floppa_);

    suite_add_tcase(s, tc);

    return s;
}