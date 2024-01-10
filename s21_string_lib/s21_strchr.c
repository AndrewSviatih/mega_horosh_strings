#include "s21_string.h"

char *s21_strchr(const char *str, int c){

    char *neededPtr = NULL;

    for (size_t i = 0; i < s21_strlen(str); i++){
        if (c == str[i]){
            neededPtr = ((char *)str) + i;
            break;
        }
    }

    return neededPtr;
}