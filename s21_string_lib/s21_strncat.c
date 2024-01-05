//
// Created by anrdew sviatie on 04.01.2024.
//

#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n){

    size_t dest_len = strlen(dest);
    size_t i = 0;

    for (; i < n && src[i] != '\0'; i++){
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}