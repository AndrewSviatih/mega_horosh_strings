#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result;

  if (str == S21_NULL) {
    result = S21_NULL;
  } else {
    result = calloc(s21_strlen(str) + 1, sizeof(char));
    if (result) {
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          result[i] = str[i] - 'a' + 'A';
        } else {
          result[i] = str[i];
        }
      }
    } else {
      result = S21_NULL;
    }
  }

  if (result != S21_NULL) result[s21_strlen(str)] = '\0';

  return result;
}