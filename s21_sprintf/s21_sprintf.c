#include "../s21_string_lib/s21_string.h"

typedef struct {
    int minus;
    int plus;
    int space;
    int hash;
    int zero;
    int width;
    int accurency;
    char lenghth;
    int number_system;
    int flag_to_size;
    int dot;
    int upper_case;
    int g;
    int e;
} Spec;

const char *get_specs(const char *format, Spec *specs) {
    while (format) {
        if (*format == '+')
            specs->plus = 1;
        else if (*format == '-')
            specs->minus = 1;
        else if (*format == '#')
            specs->hash = 1;
        else if (*format == ' ')
            specs->space = 1;
        else if (*format == '0')
            specs->zero = 1;
        else
            break;
        
        format++;
    }
    specs->space = (specs->space && !specs->plus);
    specs->zero = (specs->zero && !specs->minus);
}

const char *get_width(const char *format, int *width, va_list *input){

    *width = 0;

    if (*format == '*') {
        *width = va_arg(*input, int);
        format++;
    }

    while(*format){
        if ('0' <= *format && *format <= '9'){
            *width *= 10;
            *width += *format - '0'; 
        } else
            break;
        
        format++;
    }

    return format;

}
// "%+-014.6hd" парсим этого монстра
const char *set_specs(Spec *specs, const char *format, va_list *input) {

    format = get_specs(format, specs);
    format = get_width(format, &specs->width, input);
// для точки
    if (*format == '.') {
        specs->dot = 1;
        specs->zero = 0;
        format += 1;
        format = get_width(format, &specs->accurency, input);
    }
// для разных даблов
    if (*format == 'L')
        specs->lenghth = 'L';
    else if (*format == 'l')
        specs->lenghth = 'l';
    else if (*format == 'h') 
        specs->lenghth = 'h';

    if (specs->lenghth != 0) format += 1;

// ширина не может быть отрицательной
    if (specs->width < 0) {
        specs->width = -specs->width;
        specs->minus = 1;
    }
    
    return format;
}

char *parser(char *res, char *res_begining, const char *format, Spec specs, va_list *input){

    if (*format == 'd' || *format == 'd') {
        str = printf_decimal()
    }

}

int s21_sprintf(char *res, const char *format, ...){

    char specifiers[] = "diuoxXcsnpfFeEgG%";

    char *res_begining = res;

    va_list input = {0};
    va_start(input, format);
    
    while (*format) {
        if (*format == '%') {
            format++;
            Spec specs = {0};
            specs.number_system = 10;
            format = set_specs(&specs, format, &input);
            while (!s21_strchr(specifiers, *format)) format++;
            res = parser();
        } else {
            *res = *format;
            res++;
        }
    }


    va_end(input);

    return res - res_begining;
}