#include "s21_string.h"

void *s21_memset(void *dest, int c, s21_size_t count) {
  char *str = (char *)dest;

  for (s21_size_t i = 0; i < count; i++) {
    str[i] = c;
  }

  return str;
}