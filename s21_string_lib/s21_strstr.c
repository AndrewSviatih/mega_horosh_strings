#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *res = NULL;

    if (s21_strlen(haystack) >= s21_strlen(needle)) {
        for (size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle); i++){
            int found = 1;
            for (size_t j = i, k = 0; needle[k]; j++, k++){
                if (haystack[j] != needle[k]){
                    found = 0;
                    break;
                }
            }

            if (found) {
                res = (char *)haystack + i;
                break;
            }
        }
    }    

    return res;
}
