#include "../s21_string_lib/s21_string.h"

int s21_sprintf(char *res, const char *format, ...){

    va_list input = {0};
    va_start(input, format);
    char *res_begining = res;
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int arg = va_arg(input, int);
                char arg_str[12];
                itoa(arg);
                strcpy(res, arg_str);
                while (*res != '\0') {
                    res++;
                }
            } else if (*format == 's') {
                char *arg = va_arg(input, char *);
                strcpy(res, arg); 
                while (*res != '\0') {
                    res++;
                }
            } else {
                *res = *format;
                res++;
            }
        format++;
        }
    }
    va_end(input);

    return res - res_begining;
}