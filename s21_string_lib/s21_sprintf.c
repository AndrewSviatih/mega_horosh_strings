#include "s21_string.h"

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
} Spec;

int s21_sprintf(char *res, const char *format, ...);

const char *get_specs(const char *format, Spec *specs);
const char *get_width(const char *format, int *width, va_list *input);
const char *set_specs(Spec *specs, const char *format, va_list *input);
char *parser(char *res, const char *format, Spec specs, va_list *input,
             char *first_char);

char get_num_char(int num, int upper_case);
s21_size_t get_size_of_decimal(Spec *specs, long int num);
int decimal_to_string(Spec specs, char *str_to_num, long int num,
                      s21_size_t s21_size_to_decimal);
char *print_decimal(char *res, Spec specs, va_list *input);

Spec set_number_system(Spec specs, char format);
s21_size_t get_buff_size_hex(Spec *specs, unsigned long int num);
int u_o_x_X_to_string(char *str_to_num, Spec *specs, unsigned long int num,
                      s21_size_t s21_size_to_decimal);
char *print_hex(char *res, Spec specs, va_list *input);

char *print_c(char *res, Spec specs, char symb);
char *print_s(char *res, Spec specs, va_list *input);
char *print_p(char *res, Spec *specs, va_list *input);
char *print_e_g(char *res, Spec specs, va_list *input);

char *print_float(char *res, Spec *specs, va_list *input);
Spec set_specs_float(Spec specs, char format);
void reverse(char *str, int len);
int intToStr(s21_size_t x, char str[], s21_size_t d, Spec *specs);
void ftoa(long double n, char *res, int afterpoint, Spec *specs);
int normalize(long double *num, Spec *specs);
Spec cutter(Spec specs, long double num);

int s21_sprintf(char *res, const char *format, ...) {
  char specifiers[] = "diuoxXcsnpfFeEgG%";
  char *first_char = res;

  va_list input = {0};
  va_start(input, format);

  while (*format) {
    if (*format == '%') {
      format++;
      Spec specs = {0};
      specs.number_system = 10;
      format = set_specs(&specs, format, &input);
      while (!s21_strchr(specifiers, *format)) format++;
      res = parser(res, format, specs, &input, first_char);
      *res = '\0';
    } else {
      *res = *format;
      res++;
      *res = '\0';
    }
    format++;
  }

  va_end(input);

  return res - first_char;
}

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

const char *get_width(const char *format, int *width, va_list *input) {
  *width = 0;

  if (*format == '*') {
    *width = va_arg(*input, int);
    format++;
  }

  while (*format) {
    if ('0' <= *format && *format <= '9') {
      *width *= 10;
      *width += *format - '0';
    } else {
      break;
    }
    format++;
  }

  return format;
}

const char *set_specs(Spec *specs, const char *format, va_list *input) {
  format = get_specs(format, specs);
  format = get_width(format, &specs->width, input);

  if (*format == '.') {
    specs->dot = 1;
    specs->zero = 0;
    format += 1;
    format = get_width(format, &specs->accurency, input);
  }

  if (*format == 'L')
    specs->length = 'L';
  else if (*format == 'l')
    specs->length = 'l';
  else if (*format == 'h')
    specs->length = 'h';

  if (specs->length != 0) format += 1;

  if (specs->width < 0) {
    specs->width = -specs->width;
    specs->minus = 1;
  }

  return format;
}

s21_size_t get_size_of_decimal(Spec *specs, long int num) {
  s21_size_t ress = 0;

  long int copy_num = num;

  if (copy_num < 0) copy_num = -copy_num;

  while (copy_num > 0) {
    copy_num /= 10;
    ress++;
  }

  if (copy_num == 0 && ress == 0 &&
      (specs->accurency || specs->width || specs->space)) {
    ress++;
  }

  if ((s21_size_t)specs->width > ress) ress = specs->width;
  if ((s21_size_t)specs->accurency > ress) ress = specs->accurency;

  if (specs->space || specs->plus || num < 0) {
    specs->flag_to_size = 1;
    ress++;
  }
  if (ress == 0 && copy_num == 0 && !specs->accurency && !specs->width &&
      !specs->space && !specs->dot)
    ress++;

  return ress;
}

char get_num_char(int num, int upper_case) {
  char flag = '0';
  switch (num) {
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

int decimal_to_string(Spec specs, char *str_to_num, long int num,
                      s21_size_t s21_size_to_decimal) {
  int flag = 0;

  if (num < 0) {
    num = -num;
    flag = 1;
  }

  int i = 0;
  long int copy_num = num;

  if ((copy_num == 0 && (specs.accurency || specs.width || specs.space)) ||
      (copy_num == 0 &&
       (!specs.accurency && !specs.width && !specs.space && !specs.dot))) {
    str_to_num[i] = '0';
    i++;
    s21_size_to_decimal--;
  }

  while (copy_num && str_to_num && s21_size_to_decimal) {
    char sym = get_num_char(copy_num % specs.number_system, specs.upper_case);
    str_to_num[i] = sym;
    i++;
    s21_size_to_decimal--;
    copy_num /= 10;
  }

  if (flag) num = -num;

  if (specs.accurency - i > 0) {
    specs.accurency -= i;
    specs.zero = 1;
  } else {
    flag = 1;
  }

  if (s21_size_to_decimal == 1 && specs.zero == 1 && specs.flag_to_size == 1)
    specs.zero = 0;

  while (specs.zero && str_to_num &&
         (s21_size_to_decimal - specs.flag_to_size > 0) &&
         (specs.accurency || flag)) {
    if ((s21_size_to_decimal == 1 && specs.flag_to_size == 1)) break;

    str_to_num[i] = '0';
    s21_size_to_decimal--;
    specs.accurency--;
    i++;
  }

  if (specs.space && num >= 0 && s21_size_to_decimal) {
    str_to_num[i] = ' ';
    i++;
    s21_size_to_decimal--;
  }
  if (num < 0 && s21_size_to_decimal) {
    str_to_num[i] = '-';
    i++;
    s21_size_to_decimal--;
  }
  if (num > 0 && specs.plus && s21_size_to_decimal) {
    str_to_num[i] = '+';
    i++;
    s21_size_to_decimal--;
  }

  if (s21_size_to_decimal > 0 && specs.minus == 0) {
    while ((s21_size_to_decimal - specs.flag_to_size > 0) && str_to_num) {
      str_to_num[i] = ' ';
      i++;
      s21_size_to_decimal--;
    }
  }

  return i;
}

char *print_decimal(char *res, Spec specs, va_list *input) {
  long int num = 0;

  if (specs.length == 'l') {
    num = (long int)va_arg(*input, long int);
  } else if (specs.length == 'h') {
    num = (int)va_arg(*input, int);
  } else {
    num = (int)va_arg(*input, int);
  }

  s21_size_t s21_size_to_decimal = get_size_of_decimal(&specs, num);
  char *str_to_num = malloc(sizeof(char) * s21_size_to_decimal);

  if (str_to_num) {
    int i = decimal_to_string(specs, str_to_num, num, s21_size_to_decimal);

    for (int j = i - 1; j >= 0; j--) {
      *res = str_to_num[j];
      res++;
    }

    while ((i < specs.width)) {
      *res = ' ';
      res++;
      i++;
    }
  }

  if (str_to_num) free(str_to_num);

  return res;
}

Spec set_number_system(Spec specs, char format) {
  if (format == 'o') {
    specs.number_system = 8;
  } else if (format == 'x' || format == 'X') {
    specs.number_system = 16;
  }
  if (format == 'X') specs.upper_case = 1;

  return specs;
}

s21_size_t get_buff_size_hex(Spec *specs, unsigned long int num) {
  s21_size_t res = 0;

  unsigned long int copy_num = num;

  if (copy_num && num) {
    if (specs->number_system == 8) {
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

  if (copy_num == 0 && res == 0 &&
      (specs->accurency || specs->width || specs->space)) {
    res++;
  }

  if ((s21_size_t)specs->width > res) res = specs->width;
  if ((s21_size_t)specs->accurency >= res) {
    res = specs->accurency;
    if (specs->hash && specs->number_system == 16 && num) {
      res += 2;
    } else if (specs->hash && specs->number_system == 8 && num) {
      res++;
    }
  }

  if (res == 0 && copy_num == 0 && !specs->accurency && !specs->width &&
      !specs->space && !specs->dot)
    res++;

  return res;
}

int u_o_x_X_to_string(char *str_to_num, Spec *specs, unsigned long int num,
                      s21_size_t s21_size_to_decimal) {
  int flag = 0;

  int i = 0;
  unsigned long int copy_num = num;

  if (specs->hash && specs->number_system == 8 && copy_num) {
    specs->flag_to_size = 1;
  } else if (specs->hash && specs->number_system == 16 && copy_num) {
    specs->flag_to_size = 2;
  }

  while (copy_num && str_to_num && s21_size_to_decimal) {
    char sym = get_num_char(copy_num % specs->number_system, specs->upper_case);
    str_to_num[i] = sym;
    i++;
    s21_size_to_decimal--;
    copy_num /= specs->number_system;
  }

  if (!copy_num && !num) {
    if (specs->number_system == 16 && specs->accurency) {
      while ((specs->accurency > 1)) {
        str_to_num[i] = '0';
        s21_size_to_decimal--;
        specs->accurency--;
        i++;
      }
    }
    str_to_num[i] = '0';
    i++;
    s21_size_to_decimal--;
  }

  if (flag) num = -num;

  if (specs->accurency - i > 0) {
    specs->accurency -= i;
    specs->zero = 1;
  } else {
    flag = 1;
  }

  if (s21_size_to_decimal == 1 && specs->zero == 1 && specs->flag_to_size == 1)
    specs->zero = 0;

  while (specs->zero && str_to_num &&
         (s21_size_to_decimal - specs->flag_to_size > 0) &&
         (specs->accurency || flag)) {
    if ((s21_size_to_decimal == 1 && specs->flag_to_size == 1)) break;

    str_to_num[i] = '0';
    s21_size_to_decimal--;
    specs->accurency--;
    i++;
  }

  while (!specs->minus && (s21_size_to_decimal - specs->flag_to_size > 0) &&
         ((specs->accurency || flag) || specs->accurency < specs->width)) {
    if ((s21_size_to_decimal == 1 && specs->flag_to_size == 1)) break;
    if (specs->hash && specs->width && specs->number_system == 16) break;
    str_to_num[i] = ' ';
    s21_size_to_decimal--;
    specs->accurency--;
    i++;
  }

  if (num) {
    if (specs->hash && specs->number_system == 8) {
      str_to_num[i] = '0';
      i++;
      s21_size_to_decimal--;
    } else if (specs->hash && specs->number_system == 16) {
      if (specs->upper_case) {
        str_to_num[i] = 'X';
        i++;
        str_to_num[i] = '0';
        i++;
        s21_size_to_decimal -= 2;
      } else if (!specs->upper_case) {
        str_to_num[i] = 'x';
        i++;
        str_to_num[i] = '0';
        i++;
        s21_size_to_decimal -= 2;
      }
    }
  }

  while (!specs->minus && specs->hash && specs->width &&
         specs->number_system == 16 && (s21_size_to_decimal > 0) &&
         (specs->accurency || flag)) {
    if ((s21_size_to_decimal == 1 && specs->flag_to_size == 1)) break;
    str_to_num[i] = ' ';
    s21_size_to_decimal--;
    specs->accurency--;
    i++;
  }

  return i;
}

char *print_hex(char *res, Spec specs, va_list *input) {
  unsigned long int num = 0;
  if (specs.length == 'l') {
    num = (unsigned long int)va_arg(*input, unsigned long int);
  } else if (specs.length == 'h') {
    num = (unsigned int)va_arg(*input, unsigned int);
  } else {
    num = (unsigned int)va_arg(*input, unsigned int);
  }

  s21_size_t s21_size_to_num = get_buff_size_hex(&specs, num);
  char *buffer = malloc(sizeof(char) * s21_size_to_num);

  int i = u_o_x_X_to_string(buffer, &specs, num, s21_size_to_num);

  if (buffer) {
    for (int j = i - 1; j >= 0; j--) {
      *res = buffer[j];
      res++;
    }
    while ((i < specs.width)) {
      *res = ' ';
      res++;
      i++;
    }
  }

  if (buffer) free(buffer);

  return res;
}

char *print_c(char *res, Spec specs, char symb) {
  char *ptr = S21_NULL;

  while (!specs.minus && specs.width - 1 > 0) {
    *res = ' ';
    res++;
    specs.width--;
  }

  if (symb < 127) {
    *res = symb;
    res++;
    if (specs.minus) {
      while (specs.width - 1 > 0) {
        *res = ' ';
        res++;
        specs.width--;
      }
    }
  }
  ptr = res;

  return ptr;
}

char *print_s(char *res, Spec specs, va_list *input) {
  char *res_ptr = res;
  char *string_input = va_arg(*input, char *);

  if (string_input) {
    int tmp_width = specs.width;

    if ((s21_size_t)specs.width < s21_strlen(string_input)) {
      specs.width = s21_strlen(string_input);
    }

    int needed_spaces = specs.width - s21_strlen(string_input);

    if (specs.accurency == 0) specs.accurency = specs.width;

    if (specs.accurency != 0 && specs.accurency < tmp_width)
      needed_spaces = tmp_width - specs.accurency;

    if (!specs.minus) {
      while (needed_spaces) {
        *res = ' ';
        res++;
        needed_spaces--;
      }
    }

    while (*string_input != '\0') {
      if (!specs.accurency) break;
      *res = *string_input;
      res++;
      string_input++;
      specs.accurency--;
    }

    if (specs.minus) {
      while (needed_spaces) {
        *res = ' ';
        res++;
        needed_spaces--;
      }
    }
  } else {
    res = s21_memcpy(res, "(S21_NULL)", 6);
    res += 6;
  }

  if (res_ptr) res_ptr = res;
  return res_ptr;
}

char *print_p(char *res, Spec *specs, va_list *input) {
  unsigned long int ptr_name =
      (unsigned long int)va_arg(*input, unsigned long int);

  if (ptr_name == 0) {
    res = s21_memcpy(res, "(nil)", 5);
    res += 5;
  } else {
    specs->number_system = 16;
    specs->hash = 1;
    specs->upper_case = 0;

    s21_size_t s21_size_to_num = get_buff_size_hex(specs, ptr_name);
    char *buffer = malloc(sizeof(char) * s21_size_to_num);

    int i = u_o_x_X_to_string(buffer, specs, ptr_name, s21_size_to_num);

    if (buffer) {
      for (int j = i - 1; j >= 0; j--) {
        *res = buffer[j];
        res++;
      }
      while ((i < specs->width)) {
        *res = ' ';
        res++;
        i++;
      }
    }

    if (buffer) free(buffer);
  }

  return res;
}

Spec set_specs_float(Spec specs, char format) {
  if (format == 'g' || format == 'G') {
    specs.g = 1;
  } else if (format == 'e' || format == 'E') {
    specs.e = 1;
  }
  if (format == 'G' || format == 'E' || format == 'F') specs.upper_case = 1;
  return specs;
}

void reverse(char *str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

int intToStr(s21_size_t x, char str[], s21_size_t d, Spec *specs) {
  s21_size_t i = 0;
  if (x == 0) {
    str[i++] = '0';
  } else {
    while (x) {
      str[i++] = (x % 10) + '0';
      x = x / 10;
    }

    while (i < d) str[i++] = '0';

    if (specs->negetive) {
      str[i++] = '-';
      specs->negetive = 0;
    }

    reverse(str, i);
  }

  str[i] = '\0';
  return i;
}

void ftoa(long double n, char *res, int afterpoint, Spec *specs) {
  s21_size_t ipart;
  long double fpart;
  if (n < 0) {
    n = -n;
    specs->negetive = 1;
  }
  if (specs->accurency == 0 && specs->dot) {
    ipart = roundl(n);
  } else {
    ipart = (s21_size_t)n;
    fpart = n - (long double)ipart;
  }

  s21_size_t i = intToStr(ipart, res, 0, specs);

  if (afterpoint != 0 || !specs->dot) {
    res[i] = '.';

    if (ipart || fpart) {
      fpart = roundl(fpart * powl(10, afterpoint)) / powl(10, afterpoint) +
              5 / powl(10, afterpoint + 1);
      fpart = fpart * pow(10, afterpoint);
      intToStr(fpart, res + i + 1, afterpoint, specs);
    } else {
      i++;
      while (specs->accurency) {
        res[i] = '0';
        i++;
        specs->accurency--;
      }
    }
  }
}

char *print_float(char *res, Spec *specs, va_list *input) {
  long double num = 0;
  if (specs->length == 'L') {
    num = va_arg(*input, long double);
  } else {
    num = va_arg(*input, double);
  }

  if (!specs->dot) specs->accurency = 6;

  char *buffer = malloc(sizeof(char) * 1056);
  ftoa(num, buffer, specs->accurency, specs);
  s21_size_t buffer_lenght = s21_strlen(buffer);

  if (!specs->minus && specs->width) {
    if (specs->zero) {
      while ((s21_size_t)specs->width > buffer_lenght + specs->plus) {
        *res = '0';
        res++;
        specs->width--;
      }
    } else {
      while ((s21_size_t)specs->width > buffer_lenght + specs->plus) {
        *res = ' ';
        res++;
        specs->width--;
      }
    }
  }

  if (specs->space && !specs->plus) {
    if (num >= 0 && (specs->minus || specs->space) &&
        specs->width != (long int)buffer_lenght) {
      *res = ' ';
      res++;
      specs->width--;
    }
  } else if (specs->plus) {
    if (num >= 0) {
      *res = '+';
      res++;
      specs->width--;
    }
  }

  for (int i = 0; buffer[i] != '\0'; i++) {
    *res = buffer[i];
    res++;
  }

  if (s21_strcmp(buffer, "0.0") == 0 && specs->accurency > 1) {
    while (specs->accurency > 1) {
      *res = '0';
      res++;
      specs->accurency--;
    }
  }

  if (specs->minus && specs->width) {
    if (specs->zero) {
      while (specs->width > (long int)buffer_lenght) {
        *res = '0';
        res++;
        specs->width--;
      }
    } else {
      while (specs->width > (long int)buffer_lenght) {
        *res = ' ';
        res++;
        specs->width--;
      }
    }
  }

  free(buffer);
  return res;
}

int normalize(long double *num, Spec *specs) {
  int i = 0;

  if (fabsl(*num) > 1) {
    while (fabsl(*num) > 10) {
      *num /= 10;
      i++;

      specs->e = 2;
    }
  } else {
    while (fabsl(*num) < 0.999999) {
      if (*num == 0) {
        specs->e = 2;
        break;
      }
      *num *= 10;
      i++;
      specs->e = 1;
    }
  }
  return i;
}

Spec cutter(Spec specs, long double num) {
  Spec buffer_specs = specs;
  long double copy_num = num;

  int e = normalize(&copy_num, &buffer_specs);

  if (buffer_specs.accurency == 0 && !buffer_specs.dot)
    buffer_specs.accurency = 6;

  if ((e <= 4 && buffer_specs.e == 1) || (buffer_specs.e == 2 && e < 6))
    buffer_specs.e = 0;

  return buffer_specs;
}

char *print_e_g(char *res, Spec specs, va_list *input) {
  long double num = 0;
  s21_size_t size = 0;
  int e;

  if (specs.length == 'L') {
    num = va_arg(*input, long double);
  } else {
    num = va_arg(*input, double);
  }

  if (specs.g) specs = cutter(specs, num);

  if (specs.e) {
    e = normalize(&num, &specs);
    if (e < 100)
      size += 2;
    else
      size += 3;
  }

  char *buffer = malloc(sizeof(char) * 1056);
  ftoa(num, buffer, specs.accurency, &specs);

  for (int i = 0; buffer[i] != '\0'; i++) {
    *res = buffer[i];
    res++;
  }

  return res;
}

char *parser(char *res, const char *format, Spec specs, va_list *input,
             char *first_char) {
  if (*format == 'd' || *format == 'i') {
    res = print_decimal(res, specs, input);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    specs = set_number_system(specs, *format);
    res = print_hex(res, specs, input);
  } else if (*format == 'c') {
    int symb = va_arg(*input, int);
    res = print_c(res, specs, symb);
  } else if (*format == 's') {
    res = print_s(res, specs, input);
  } else if (*format == 'p') {
    res = print_p(res, &specs, input);
  } else if (*format == 'n') {
    int *n = va_arg(*input, int *);
    *n = (int)(res - first_char);
  } else if (*format == '%') {
    res = print_c(res, specs, '%');
  } else if (*format == 'f' || *format == 'F') {
    specs = set_specs_float(specs, *format);
    res = print_float(res, &specs, input);
  } else if (*format == 'e' || *format == 'E' || *format == 'g' ||
             *format == 'G') {
    specs = set_specs_float(specs, *format);
    res = print_e_g(res, specs, input);
  }
  return res;
}