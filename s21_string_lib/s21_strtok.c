#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    static char *token = NULL;

    if (str != NULL) {
        token = str;
    } else if (token == NULL || *token == '\0') {
        return NULL;
    }

    while (*token != '\0' && s21_strchr(delim, *token)) {
        token++;
    }

    if (*token == '\0') {
        token = NULL;
        return NULL;
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