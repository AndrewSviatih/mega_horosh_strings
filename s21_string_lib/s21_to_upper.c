#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result;

  if (str == S21_NULL) {
    result = S21_NULL;
  } else {
    result = calloc(s21_strlen(str), sizeof(char));
    int flag = 1;
    for (s21_size_t i = 0; i < s21_strlen(str) && flag == 1; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - 'a' + 'A';
      } else if ((str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ') {
        result[i] = str[i];
      } else {
        flag = 0;
        free(result);
        result = S21_NULL;
      }
    }
  }

  return result;
}