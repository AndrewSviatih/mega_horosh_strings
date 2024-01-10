//
// Created by anrdew sviatie on 05.01.2024.
//

#ifndef STRING_S21_STRING_H
#define STRING_S21_STRING_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "stdint.h"

#define S21_INT32_MAX 2147483647
#define S21_INT32_MIN -2147483648

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *dest, int c, size_t count);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
int s21_sprintf(char *str, const char *format, ...);
size_t s21_strlen(const char *str);
int s21_atoi(const char *str);
char *s21_strerror(int errnum);
char *s21_strcpy(char *dest, const char *src);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

#endif //STRING_S21_STRING_H