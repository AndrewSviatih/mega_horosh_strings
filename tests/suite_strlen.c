#include "s21_tests.h"

START_TEST(empty) {
    char src[] = "";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(aboba_lecture) {
    char src[] = "sadsda";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(num) {
    char src[] = "987623456124678";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(string) {
    char src[] = "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(abisal_no_dal) {
    char src[] = "abisal\0no_dal";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(dai_mne_pen) {
    char src[] = "dai_mne_pen(321321)...123...123";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(Floppy_disk) {
    char src[] = "Floppy_disk";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(Russky_kot_Shlepa) {
    char src[] = "Russky_kot_Shlepa";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(kot_Vasily) {
    char src[] = "kot Vasily";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

START_TEST(floppa) {
    char src[] = "floppa";

    ck_assert_int_eq(s21_strlen(src),
                     strlen(src));
} END_TEST

Suite *suite_strlen(void){
    Suite *s = suite_create("suite_strlen");
    TCase *tc = tcase_create("tc_strlen");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, aboba_lecture);
    tcase_add_test(tc, abisal_no_dal);
    tcase_add_test(tc, num);
    tcase_add_test(tc, string);
    tcase_add_test(tc, dai_mne_pen);
    tcase_add_test(tc, Floppy_disk);
    tcase_add_test(tc, Russky_kot_Shlepa);
    tcase_add_test(tc, kot_Vasily);
    tcase_add_test(tc, floppa);

    suite_add_tcase(s, tc);

    return s;
}