#include "s21_tests.h"

START_TEST(hard) {
  char src[] = "  +123123123";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(classic) {
  char src[] = "2";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(minus) {
  char src[] = "-232332";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

START_TEST(minus_hard) {
  char src[] = "    -232332";
  ck_assert_int_eq(atoi(src), s21_atoi(src));
}
END_TEST

Suite *suite_atoi(void) {
  Suite *s = suite_create("suite_atoi");
  TCase *tc = tcase_create("atoi_tc");

  tcase_add_test(tc, hard);
  tcase_add_test(tc, classic);
  tcase_add_test(tc, minus);
  tcase_add_test(tc, minus_hard);

  suite_add_tcase(s, tc);
  return s;
}