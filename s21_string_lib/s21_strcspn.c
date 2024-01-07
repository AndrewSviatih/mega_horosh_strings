#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2){

    size_t ptrPosition = 0;

    for (size_t i = 0; i < strlen(str1); i++){
        int doneCheck = 0;
        for (size_t j = 0; j < strlen(str2); j++){
            if (str1[i] == str2[j]){
                doneCheck = 1;
                break;
            }
        }
        if (doneCheck){
            break;
        } else {
            ptrPosition++;
        }
    }

    return ptrPosition;
}