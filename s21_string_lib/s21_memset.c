//
// Created by anrdew sviatie on 03.01.2024.
//

#include "s21_string.h"

void *s21_memset(void *dest, int c, size_t count){
    char *str = (char *)dest;

    for (size_t i = 0; i < count; i++){
        str[i] = c;
    }

    return str;
}