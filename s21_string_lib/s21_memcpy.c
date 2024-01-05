//
// Created by anrdew sviatie on 02.01.2024.
//

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n){

    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;

    for (size_t i = 0; i < n; i++){
        d[i] = s[i];
    }

    return dest;
}