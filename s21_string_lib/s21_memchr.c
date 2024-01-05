#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n){
    const unsigned char *ptr = (unsigned char *)str;
    void *out = NULL;

    for (size_t i = 0; i < n && ptr; i++){
        if (*ptr == (unsigned char)c){
            out = (void*)ptr;
            break;
        }
        ptr++;
    }

    return out;
}