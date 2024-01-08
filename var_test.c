#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "s21_string_lib/s21_string.h"

#define BUFF_SIZE 1000

int main() {
    char res[BUFF_SIZE];

    int res_diff = s21_sprintf(res, "%s: %d + %d = %d", "Sum of", 2, 2, 2+2);

    printf("%s\n", res);
    printf("%d\n", res_diff);
}