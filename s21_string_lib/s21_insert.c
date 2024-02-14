#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result;

  if (!src || (s21_strlen(src) < start_index)) {
    result = S21_NULL;
  } else if (!str) {
    result = calloc(s21_strlen(src) + 1, sizeof(char));
    result = s21_strcpy(result, src);
  } else {
    result = calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    int flag = 1;
    for (s21_size_t i = 0; i < s21_strlen(src) + s21_strlen(str) && flag == 1;
         i++) {
      if (i < start_index) {
        result[i] = src[i];
      } else if (i >= start_index && i < start_index + s21_strlen(str)) {
        result[i] = str[i - start_index];
      } else if (i >= start_index + s21_strlen(str)) {
        result[i] = src[i - s21_strlen(str)];
      } else {
        flag = 0;
        free(result);
        result = S21_NULL;
      }
    }
  }

  return result;
}