#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (unsigned char *)str;
  void *out = S21_NULL;

  for (s21_size_t i = 0; i < n && ptr; i++) {
    if (*ptr == (unsigned char)c) {
      out = (void *)ptr;
      break;
    }
    ptr++;
  }

  return out;
}