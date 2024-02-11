#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *token = S21_NULL;

  if (str != S21_NULL) {
    token = str;
  } else if (token == S21_NULL || *token == '\0') {
    return S21_NULL;
  }

  while (*token != '\0' && s21_strchr(delim, *token)) {
    token++;
  }

  if (*token == '\0') {
    token = S21_NULL;
    return S21_NULL;
  }

  char *start_ptr = token;

  while (*token != '\0' && !s21_strchr(delim, *token)) {
    token++;
  }

  if (*token != '\0') {
    *token = '\0';
    token++;
  }

  return start_ptr;
}