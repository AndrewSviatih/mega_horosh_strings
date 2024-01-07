#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "../s21_string_lib/s21_string.h"

Suite *suite_memchr(void);
Suite *suite_memcmp(void);
Suite *suite_memcpy(void);
Suite *suite_memset (void);
Suite *suite_strncat(void);
Suite *suite_strchr(void);
Suite *suite_strncmp (void);
Suite *suite_strncpy (void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_