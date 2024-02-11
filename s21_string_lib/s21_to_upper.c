#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result;

  if (str == S21_NULL) {
    result = S21_NULL;
  } else {
    result = calloc(s21_strlen(str) + 1, sizeof(char));
    int flag = 1;
    for (s21_size_t i = 0; i < s21_strlen(str) && flag == 1; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - 'a' + 'A';
      } else if (str[i] >= 0 && str[i] < 127) {
        result[i] = str[i];
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