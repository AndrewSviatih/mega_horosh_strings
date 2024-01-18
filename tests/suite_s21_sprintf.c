#include "s21_tests.h"

#define BUFF_SIZE 2052

START_TEST(simple_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%012i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%0*d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%0.*i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char format[] = "%0.*i %d %4.*i %013d %d";
    int val = 69;
    ck_assert_int_eq(
        s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
        sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+5.31li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16.9hi";
    short int val = 6958;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%0.*ld";
    long val = 8581385185;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                     sprintf(str2, format, 5, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
                     sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%o";
    ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#o";
    int val = 57175;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%hd";
    short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lo";
    long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lo, %o, %ho, %.5o, %5.o";
    long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
                     sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lo";
    long int val = 84518;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    ck_assert_int_eq(s21_sprintf(str1, format, 0),
                     sprintf(str2, format, (unsigned)0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#-10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.15x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#-10x%x%X%#x%#X%5.5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                     sprintf(str2, format, val, val, val, val, val, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#-5.10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#x";
    unsigned val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#x";
    unsigned val = 18571;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#hx";
    unsigned short val = 12352;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#lx";
    unsigned long val = 18571757371571;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#2x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%#30x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                     sprintf(str2, "%f", 0.0001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                     sprintf(str2, "%u", (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_one_hex_lower) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                     sprintf(str2, "%x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                     sprintf(str2, "%x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                     sprintf(str2, "%X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                     sprintf(str2, "%X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_one_hex_lower_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                     sprintf(str2, "%-3x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                     sprintf(str2, "%-3x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                     sprintf(str2, "%13x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                     sprintf(str2, "%13x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                     sprintf(str2, "%-60X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                     sprintf(str2, "%-60X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                     sprintf(str2, "%7X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                     sprintf(str2, "%7X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(
        s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_one_hex_with_hashtag) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                     sprintf(str2, "%#x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                     sprintf(str2, "%#x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_hashtag) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                     sprintf(str2, "%#X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                     sprintf(str2, "%#X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535,
                                 -13, -0, 123213123),
                     sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13,
                             -0, 123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535,
                                 -13, -0, 123213123),
                     sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13,
                             -0, 123213123));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_one_hex_lower_with_width_star) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                     sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                     sprintf(str2, "%*x", 11, 0));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                     sprintf(str2, "%*x", 11, INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_width_star) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                     sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                     sprintf(str2, "%*X", 11, 0));
    ck_assert_str_eq(str1, str2);

    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                     sprintf(str2, "%*X", 11, INT32_MAX));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251),
                     sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                             199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251),
                     sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                             199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_one_hex_lower_with_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    int a = s21_sprintf(str1, "%*.6x", 11, 0);
    int b = sprintf(str2, "%*.6x", 11, 0);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
    int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_precision_and_other) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    int a = s21_sprintf(
        str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
        4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
    int b = sprintf(
        str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
        4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_precision_and_other) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1,
                    "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
                    -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                    41, -41, 33),
        sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
                -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
                -41, 33));
    ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_one_hex_lower_with_length) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                     sprintf(str2, "%hx", (unsigned short)-11));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                     sprintf(str2, "%hx", (unsigned short)0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                     sprintf(str2, "%hx", (unsigned short)11));
    ck_assert_str_eq(str1, str2);
    long unsigned int val = INT32_MAX;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
    ck_assert_str_eq(str1, str2);
    long unsigned int v = 0;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                     sprintf(str2, "%hx", (unsigned short)-11));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                     sprintf(str2, "%hx", (unsigned short)0));
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                     sprintf(str2, "%hx", (unsigned short)11));
    ck_assert_str_eq(str1, str2);
    long unsigned int val = INT32_MAX;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
    ck_assert_str_eq(str1, str2);
    long unsigned int v = 0;
    ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%10ld";

    ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    int a = s21_sprintf(str1, format, val);
    int b = sprintf(str2, format, val);
    ck_assert_int_eq(a, b);

    ck_assert_str_eq(str1, str2);
}
END_TEST


Suite *suite_sprintf(void) {
    Suite *s = suite_create("suite_sprintf");
    TCase *tc = tcase_create("sprintf_tc");
    tcase_add_test(tc, simple_int);
    tcase_add_test(tc, precise_int);
    tcase_add_test(tc, width_int);
    tcase_add_test(tc, minus_width_int);
    tcase_add_test(tc, plus_width_int);
    tcase_add_test(tc, padding_int);
    tcase_add_test(tc, star_width_int);
    tcase_add_test(tc, star_precision_int);
    tcase_add_test(tc, many_flags_many_ints);
    tcase_add_test(tc, flags_long_int);
    tcase_add_test(tc, flags_short_int);
    tcase_add_test(tc, flags_another_long_int);
    tcase_add_test(tc, zero_precision_zero_int);
    tcase_add_test(tc, space_flag_int);
    tcase_add_test(tc, unsigned_val);
    tcase_add_test(tc, unsigned_val_width);
    tcase_add_test(tc, unsigned_val_flags);
    tcase_add_test(tc, unsigned_val_precision);
    tcase_add_test(tc, unsigned_val_many_flags);
    tcase_add_test(tc, unsigned_val_short);
    tcase_add_test(tc, unsigned_val_long);
    tcase_add_test(tc, unsigned_val_many);
    tcase_add_test(tc, octal);
    tcase_add_test(tc, octal_width);
    tcase_add_test(tc, octal_flags);
    tcase_add_test(tc, octal_precision);
    tcase_add_test(tc, octal_many_flags);
    tcase_add_test(tc, octal_short);
    tcase_add_test(tc, octal_long);
    tcase_add_test(tc, octal_many);
    tcase_add_test(tc, octal_zero);
    tcase_add_test(tc, octal_hash);
    tcase_add_test(tc, unsigned_zero);
    tcase_add_test(tc, hex_width);
    tcase_add_test(tc, hex_flags);
    tcase_add_test(tc, hex_precision);
    tcase_add_test(tc, hex_many);
    tcase_add_test(tc, hex_many_flags);
    tcase_add_test(tc, hex_zero);
    tcase_add_test(tc, hex_huge);
    tcase_add_test(tc, hex_short);
    tcase_add_test(tc, hex_long);
    tcase_add_test(tc, hex_one_longer_width);
    tcase_add_test(tc, hex_two_longer_width);
    tcase_add_test(tc, all_empty);
    tcase_add_test(tc, empty_format_and_parameters);
    tcase_add_test(tc, test_one_dec);
    tcase_add_test(tc, test_many_dec);
    tcase_add_test(tc, test_one_int);
    tcase_add_test(tc, test_many_int);
    tcase_add_test(tc, test_one_float);
    tcase_add_test(tc, test_many_float);
    tcase_add_test(tc, test_one_unsigned_dec);
    tcase_add_test(tc, test_many_unsigned_dec);
    tcase_add_test(tc, test_one_hex_lower);
    tcase_add_test(tc, test_one_hex_upper);
    tcase_add_test(tc, test_many_hex_lower);
    tcase_add_test(tc, test_many_hex_upper);
    tcase_add_test(tc, test_one_hex_lower_with_alignment_left);
    tcase_add_test(tc, test_one_hex_lower_with_alignment_right);
    tcase_add_test(tc, test_one_hex_upper_with_alignment_left);
    tcase_add_test(tc, test_one_hex_upper_with_alignment_right);
    tcase_add_test(tc, test_many_hex_lower_with_alignment);
    tcase_add_test(tc, test_many_hex_upper_with_alignment);
    tcase_add_test(tc, test_one_hex_with_hashtag);
    tcase_add_test(tc, test_one_hex_upper_with_hashtag);
    tcase_add_test(tc, test_many_hex_lower_with_hashtag_and_alignm);
    tcase_add_test(tc, test_many_hex_upper_with_hashtag_and_alignm);
    tcase_add_test(tc, test_one_hex_lower_with_width_star);
    tcase_add_test(tc, test_one_hex_upper_with_width_star);
    tcase_add_test(tc,
                   test_many_hex_lower_with_width_star_and_align_and_hashtag);
    tcase_add_test(tc, test_many_hex_upper_with_width_star);
    tcase_add_test(tc, test_one_hex_lower_with_precision);
    tcase_add_test(tc, test_one_hex_upper_with_precision);
    tcase_add_test(tc, test_many_hex_lower_with_precision_and_other);
    tcase_add_test(tc, test_many_hex_upper_with_precision_and_other);
    tcase_add_test(tc, test_one_hex_lower_with_length);
    tcase_add_test(tc, test_one_hex_upper_with_length);
    tcase_add_test(tc, test_sprintf1);
    tcase_add_test(tc, test_sprintf4);

    suite_add_tcase(s, tc);
    return s;
}