#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "s21_string_lib/s21_string.h"

#define BUFF_SIZE 1000

int main() {
    char res[BUFF_SIZE];

    char *resk = "         d adssadasdd ad asd a";

    sprintf(res, "%4-s", resk);

    printf("%s\n", res);
}