//
// Created by anrdew sviatie on 05.01.2024.
//

#ifndef STRING_S21_STRING_H
#define STRING_S21_STRING_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *dest, int c, size_t count);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);

#endif //STRING_S21_STRING_H