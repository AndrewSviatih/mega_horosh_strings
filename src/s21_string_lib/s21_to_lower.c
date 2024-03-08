#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = S21_NULL;

  if (str == S21_NULL) {
    result = S21_NULL;
  } else {
    result = calloc(s21_strlen(str) + 1, sizeof(char));
    if (result) {
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          result[i] = str[i] - 'A' + 'a';
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