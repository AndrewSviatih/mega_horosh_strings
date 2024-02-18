#ifndef STRING_S21_STRING_H
#define STRING_S21_STRING_H

#include <math.h>

#include "stdarg.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

#define S21_INT32_MAX 2147483647
#define S21_INT32_MIN -2147483648

typedef long unsigned int s21_size_t;
typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *dest, int c, s21_size_t count);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
int s21_atoi(const char *str);
char *s21_strerror(int errnum);
char *s21_strcpy(char *dest, const char *src);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_atoi(const char *str);

void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char* str, const char* format, ...);

#endif  // STRING_S21_STRING_H