#include "s21_string.h"

// char *s21_strchr(const char *str, int c) {
//     while (*str != '\0') {
//         if (*str == c) {
//             return (char *)str;
//         }
//         str++;
//     }
//     return NULL;
// }

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

// size_t s21_strlen(const char *str) {
//     size_t length = 0;
//     while (*str != '\0') {
//         length++;
//         str++;
//     }
//     return length;
// }

// int main() {
//     char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
//     char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
//     const char delims[] = "+_! =";

//     char *got = s21_strtok(str1, delims);
//     char *expected = strtok(str2, delims);

//     s21_strlen(got);
//     s21_strlen(expected);


//     while (got && expected) {
//         got = s21_strtok(NULL, delims);
//         expected = strtok(NULL, delims);

//         if (got || expected) {
//             s21_strlen(got);
//             s21_strlen(expected);
//         } else {
//             ;
//         }
//     }

//     return 0;
// }