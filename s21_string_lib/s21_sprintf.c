#include "../s21_string_lib/s21_string.h"
#include "string.h"

typedef struct {
    int minus;
    int plus;
    int space;
    int hash;
    int zero;
    int width;
    int accurency;
    char length;
    int number_system;
    int flag_to_size;
    int dot;
    int upper_case;
    int g;
    int e;
    int negetive;
    int spec_u;
    int spec_x;
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

    return format;
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
        } else {
            break;
        }
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
        specs->length = 'L';
    else if (*format == 'l')
        specs->length = 'l';
    else if (*format == 'h') 
        specs->length = 'h';

    if (specs->length != 0) format += 1;

// ширина не может быть отрицательной
    if (specs->width < 0) {
        specs->width = -specs->width;
        specs->minus = 1;
    }
    
    return format;
}

size_t get_size_of_decimal(Spec *specs, long int num){

    size_t ress = 0;

    long int copy_num = num;

    if (copy_num < 0) copy_num = -copy_num;

    while (copy_num > 0) {
        copy_num /= 10;
        ress++;
    }

    if (copy_num == 0 && ress == 0 && (specs->accurency || specs->width || specs->space)) {
        ress++;
    }

    if ((size_t)specs->width > ress) ress = specs->width;
    if ((size_t)specs->accurency > ress) ress = specs->accurency;

    if (specs->space || specs->plus || num < 0) {
        specs->flag_to_size = 1;
        ress++;
    }
    if (ress == 0 && copy_num == 0 && !specs->accurency && !specs->width && !specs->space && !specs->dot) 
        ress++;

    printf("%zu\n", ress);

    return ress;
}

char get_num_char(int num, int upper_case){
    char flag = '0';
    switch (num)
    {
    case 10:
        flag = (char)('a' - upper_case * 32);
        break;
    case 11:
        flag = (char)('b' - upper_case * 32);
        break;
    case 12:
        flag = (char)('c' - upper_case * 32);
        break;
    case 13:
        flag = (char)('d' - upper_case * 32);
        break;
    case 14:
        flag = (char)('e' - upper_case * 32);
        break;
    case 15:
        flag = (char)('f' - upper_case * 32);
        break;
    default:
        break;
    }

    if (num >= 0 && num <= 9) flag = (char)(num + 48);

    return flag;
}

int decimal_to_string(Spec specs, char *str_to_num, long int num, size_t size_to_decimal){

    int flag = 0;

    if (num < 0){
        num = -num;
        flag = 1;
    }

    int i = 0;
    long int copy_num = num;
// в функцию
    if ((copy_num == 0 && (specs.accurency || specs.width || specs.space)) ||
        (copy_num == 0 && (!specs.accurency && !specs.width && !specs.space && !specs.dot))){

        char symb = '0';
        str_to_num[i] = symb;
        i++;
        size_to_decimal--;
    }

    while (copy_num && str_to_num && size_to_decimal){
        char sym = get_num_char(copy_num % specs.number_system, specs.upper_case);
        str_to_num[i] = sym;
        i++;
        size_to_decimal--;
        copy_num /= 10;
    }

    if (flag) num = -num;
// в функцию
    if (specs.accurency - i > 0) {
        specs.accurency -= i;
        specs.zero = 1;
    } else {
        flag = 1;
    }

    if (size_to_decimal == 1 && specs.zero == 1 && specs.flag_to_size == 1) 
        specs.zero = 0;
// в функцию
    while (specs.zero && str_to_num && (size_to_decimal - specs.flag_to_size > 0) && (specs.accurency || flag)) {
        if ((size_to_decimal == 1 && specs.flag_to_size == 1))
            break;

        str_to_num[i] = '0';
        size_to_decimal--;
        specs.accurency--;
        i++;
    }
// в функцию
    if (specs.space && num >= 0 && size_to_decimal){
        str_to_num[i] = ' ';
        i++;
        size_to_decimal--;
    }
    if (num < 0 && size_to_decimal) {
        str_to_num[i] = '-';
        i++;
        size_to_decimal--;
    }
    if (num > 0 && specs.plus && size_to_decimal) {
        str_to_num[i] = '+';
        i++;
        size_to_decimal--;
    }

    if (size_to_decimal > 0 && specs.minus == 0) {
        while ((size_to_decimal - specs.flag_to_size > 0) && str_to_num) {
            str_to_num[i] = ' ';
            i++;
            size_to_decimal--;
        }
    }

    return i;
}

char *print_decimal(char *res, Spec specs, va_list *input){

    long int num = 0;

    if (specs.length == 'l') {
        num = (long int)va_arg(*input, long int);
    } else if (specs.length == 'h') {
        num = (int)va_arg(*input, int);
    } else {
        num = (int) va_arg(*input, int);
    }

    size_t size_to_decimal = get_size_of_decimal(&specs, num);
    char *str_to_num = malloc(sizeof(char) * size_to_decimal);

    if (str_to_num) {
        // в обратную сторону пуляем
        int i = decimal_to_string(specs, str_to_num, num, size_to_decimal);
        // делаем зеркальное пространство наоборот как во мстителях
        for (int j = i - 1; j >= 0; j--){
            *res = str_to_num[j];
            res++;
        }
        // если кто то вдруг решил сделать ширину без '-', то заполняем дальше пробелы, зочем????????
        while ((i < specs.width)){
            *res = ' ';
            res++;
            i++;
        }
    }

    if (str_to_num) free(str_to_num);

    return res;
}

Spec set_number_system(Spec specs, char format){
    if (format == 'o') {
        specs.number_system = 8;
    } else if (format == 'x' || format == 'X'){
        specs.number_system = 16;
    } 
    if (format == 'X') specs.upper_case = 1;

    return specs;
}

size_t get_buff_size_hex(Spec *specs, unsigned long int num){

    size_t res = 0;

    unsigned long int copy_num = num;

    if (copy_num && num) {
        if (specs->number_system == 8){
            while (copy_num > 0) {
                copy_num /= 8;
                res++;
            }
        if (specs->hash) res++;
        } else if (specs->number_system == 16) {
            while (copy_num > 0) {
                copy_num /= 16;
                res++;
            }
            if (specs->hash) res += 2;
        } else {
            while (copy_num > 0) {
                copy_num /= 10;
                res++;
            }
        }
    }


    if (copy_num == 0 && res == 0 && (specs->accurency || specs->width || specs->space)) {
        res++;
    }

    if ((size_t)specs->width > res) res = specs->width;
    if ((size_t)specs->accurency >= res) {
        res = specs->accurency;
        if (specs->hash && specs->number_system == 16 && num) {
            res += 2;
        } else if (specs->hash && specs->number_system == 8 && num){
            res++;
        }
    }

    
    if (res == 0 && copy_num == 0 && !specs->accurency && !specs->width && !specs->space && !specs->dot)
        res++;

    printf("%zu\n", res);
    return res;
}

int u_o_x_X_to_string(char *str_to_num, Spec specs, unsigned long int num, size_t size_to_decimal) {

    int flag = 0;
    // int flag_u_spec = 0;
    int i = 0;
    unsigned long int copy_num = num;

    if (specs.hash && specs.number_system == 8 && copy_num) {
        specs.flag_to_size = 1;
    } else if (specs.hash && specs.number_system == 16 && copy_num) {
        specs.flag_to_size = 2;
    }
// в функцию
    while (copy_num && str_to_num && size_to_decimal) {
        char sym = get_num_char(copy_num % specs.number_system, specs.upper_case);
        str_to_num[i] = sym;
        i++;
        size_to_decimal--;
        copy_num /= specs.number_system;
    }

    if (!copy_num && !num) {
        if (specs.spec_x && specs.accurency) {
            while ((specs.accurency > 1)) {
                str_to_num[i] = '0';
                size_to_decimal--;
                specs.accurency--;
                i++;
            }
        }
        str_to_num[i] = '0';
        i++;
        size_to_decimal--;
    }

    if (flag) num = -num;
// в функцию
    if (specs.accurency - i > 0) {
        specs.accurency -= i;
        specs.zero = 1;
    } else {
        flag = 1;
    }

    if (size_to_decimal == 1 && specs.zero == 1 && specs.flag_to_size == 1)
        specs.zero = 0;
// в функцию
//     char *format = "%#-5.10x";
    while (specs.zero && str_to_num && (size_to_decimal - specs.flag_to_size > 0) && (specs.accurency || flag)) {
        if ((size_to_decimal == 1 && specs.flag_to_size == 1))
            break;
        
        str_to_num[i] = '0';
        size_to_decimal--;
        specs.accurency--;
        i++;
    }

    while (!specs.minus && (size_to_decimal - specs.flag_to_size > 0) && ((specs.accurency || flag) || specs.accurency < specs.width)) {
        if ((size_to_decimal == 1 && specs.flag_to_size == 1)) break;
        if (specs.hash && specs.width && specs.spec_x) break;
        str_to_num[i] = ' ';
        size_to_decimal--;
        specs.accurency--;
        i++;
    }

    if (num) {
        if (specs.hash && specs.number_system == 8) {
            str_to_num[i] = '0';
            i++;
            size_to_decimal--;
        } else if (specs.hash && specs.number_system == 16) {
            if (specs.upper_case) {
                str_to_num[i] = 'X';
                i++;
                str_to_num[i] = '0';
                i++;
                size_to_decimal -= 2;
            } else if (!specs.upper_case) {
                str_to_num[i] = 'x';
                i++;
                str_to_num[i] = '0';
                i++;
                size_to_decimal -= 2;
            }
        }
    }

    while (!specs.minus && specs.hash && specs.width && specs.spec_x && (size_to_decimal > 0) && (specs.accurency || flag)) {
        if ((size_to_decimal == 1 && specs.flag_to_size == 1))
            break;
        str_to_num[i] = ' ';
        size_to_decimal--;
        specs.accurency--;
        i++;
    }

    return i;
}

char *print_hex(char *res, Spec specs, va_list *input){

    unsigned long int num = 0;
    if (specs.length == 'l') {
        num = (unsigned long int)va_arg(*input, unsigned long int);
    } else if (specs.length == 'h') {
        num = (unsigned int)va_arg(*input, unsigned int);
    } else {
        num = (unsigned int)va_arg(*input, unsigned int);
    }

    size_t size_to_num = get_buff_size_hex(&specs, num);
    char *buffer = malloc(sizeof(char) * size_to_num);

    int i = u_o_x_X_to_string(buffer, specs, num, size_to_num);

    if (buffer) {
        for (int j = i - 1; j >= 0; j--){
            *res = buffer[j];
            res++;
        }
        // если кто то вдруг решил сделать ширину без '-', то заполняем дальше пробелы, зочем????????
        // теперь пон зочем ^_^
        while ((i < specs.width)){
            *res = ' ';
            res++;
            i++;
        }
    }
    
    if (buffer) free(buffer);

    return res;
}

char *parser(char *res, const char *format, Spec specs, va_list *input){

    if (*format == 'd' || *format == 'i'){
        res = print_decimal(res, specs, input);
    } else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X') {
        specs = set_number_system(specs, *format);
        res = print_hex(res, specs, input);
    }
    return res;
}

int s21_sprintf(char *res, const char *format, ...){

    char specifiers[] = "diuoxXcsnpfFeEgG%";

    char *start = res;
    // int res_lenght = sizeof(&res);
    // printf("%d\n", res_lenght);

    // for (long unsigned int i = 0; i < res_lenght; i++) {
    //     res[i] = '\0';
    // }



    va_list input = {0};
    va_start(input, format);
    
    while (*format) {
        if (*format == '%') {
            format++;
            Spec specs = {0};
            specs.number_system = 10;
            format = set_specs(&specs, format, &input);
            while (!strchr(specifiers, *format)) format++;
            if (*format == 'u') {
                specs.spec_u = 1;
            } else if (*format == 'x'){
                specs.spec_x = 1;
            }
            res = parser(res, format, specs, &input);
            *res = '\0';
        } else {
            *res = *format;
            res++;
            *res = '\0';
        }
        format++;
    }

    va_end(input);

    return res - start;
}

// int main() {

// //    "%+-014.6hd adsdsa: %ld dsaads: %s %x";

// //   не прошло тесты:  int res_diff_count = s21_sprintf(res, "%+-3.6hd", 123213); sprintf(res2, "%+-3.6hd", 123213);

// // "%+-014.6hd"

//     // int res_diff_count = s21_sprintf(res, "%#-10x", 858158158);
//     // sprintf(res2, "%5x", 858158158);

//     char str1[10000];
//     char str2[10000];

//     int res_int_1 = s21_sprintf(
//         str1, "%hx", -11);
//     int res_int_2 = sprintf(
//         str2, "%hx", -11); 

//     printf("%s|\n", str2);
//     printf("%s|\n", str1);
    
//     printf("%d %d\n", res_int_2, res_int_1);
// }