#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = S21_NULL;

  if (str == S21_NULL) {
    result = S21_NULL;
  } else {
    result = calloc(s21_strlen(str) + 1, sizeof(char));
    int flag = 1;
    for (s21_size_t i = 0, result_len = 0; i < s21_strlen(str) && flag == 1;
         i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        result[result_len] = str[i] - 'A' + 'a';
        result_len++;
      } else if (str[i] < 127) {
        result[result_len] = str[i];
        result_len++;
      } else {
        flag = 0;
        free(result);
        result = S21_NULL;
      }
    }
  }

  if (result != S21_NULL) result[s21_strlen(str)] = '\0';

  return result;
}