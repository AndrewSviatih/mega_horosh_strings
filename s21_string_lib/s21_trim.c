#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result;

  if (src == S21_NULL) {
    result = S21_NULL;
    printf("trim: src is null\n");
  } else {
    s21_size_t start_index = 0;
    s21_size_t end_index = s21_strlen(src) - 1;
    s21_size_t src_length = s21_strlen(src);
    while (start_index < src_length &&
           s21_strchr(trim_chars, src[start_index]) != S21_NULL) {
      start_index++;
    }

    while (end_index >= start_index &&
           s21_strchr(trim_chars, src[end_index]) != S21_NULL) {
      end_index--;
    }
    result = calloc(end_index - start_index + 1, sizeof(char));
    s21_strncpy(result, src + start_index, end_index - start_index + 1);
    result[end_index - start_index + 1] = '\0';
  }

  return result;
}