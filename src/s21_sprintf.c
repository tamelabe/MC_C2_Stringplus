#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
    setlocale(LC_ALL, "");
    //  STRUCT
    symbols sym;
    positions pos;
    //  ARGS
    va_list args;
    va_start(args, format);

    pos.str_lenght = s21_strlen(format);
    pos.str = (char*)str;
    pos.fmt = (char*)format;

    for(; *pos.fmt; pos.fmt++) {
        s21_init_symbols(&sym);
        if (*pos.fmt != '%') {
            *pos.str = *pos.fmt;
            pos.str++;
        } else if (*++pos.fmt == '%') {
            *pos.str = '%';
            pos.str++;
        } else {
            s21_parse(&sym, &pos, args);
        }
        if (sym.type != '\0')
            s21_check_type(sym, &pos, args, str);
    }
    *pos.str = '\0';
    return s21_strlen(str);
}

void s21_init_symbols(symbols *sym) {
    sym->width = 0;
    sym->precision = 0;
    sym->presence_precision = 0;
    sym->lenght = 0;
    sym->type = '\0';
    sym->minus = 0;
    sym->plus = 0;
    sym->space = 0;
    sym->grid = 0;
    sym->zero = 0;
    sym->negative_sign = 0;
    sym->presence_sign = 0;
    sym->number_size = 0;
    sym->dif_prec_and_num_size = 0;
    sym->dif_width_and_num_size = 0;
    sym->size_int_part = 0;
    sym->presence_g = 0;
    sym->presence_dot = 0;
}

// PARSE
void s21_parse(symbols *sym, positions *pos, va_list args) {
    while (*pos->fmt != '%' && *pos->fmt != '\0' && sym->type == '\0') {
        if (!sym->width && !sym->precision && !sym->lenght && !sym->type)
            s21_parse_flags(sym, pos);
        if (!sym->precision && !sym->lenght && !sym->type)
            s21_parse_width(sym, pos, args);
        if (!sym->lenght && !sym->type)
            s21_parse_precision(sym, pos, args);
        if (!sym->type) {
            s21_parse_lenght(sym, pos);
            s21_parse_type(sym, pos);
        }
    }
}

void s21_parse_flags(symbols *sym, positions *pos) {
    if (*pos->fmt == '-') {
        sym->minus = 1;
        pos->fmt++;
    } else if (*pos->fmt == '+') {
        sym->plus = 1;
        pos->fmt++;
    } else if (*pos->fmt == ' ') {
        sym->space = 1;
        pos->fmt++;
    } else if (*pos->fmt == '#') {
        sym->grid = 1;
        pos->fmt++;
    } else if (*pos->fmt == '0') {
        sym->zero = 1;
        pos->fmt++;
    }
}

void s21_parse_width(symbols *sym, positions *pos, va_list args) {
    char temp[pos->str_lenght];
    if (*pos->fmt == '*') {
        pos->fmt++;
        sym->width = va_arg(args, int);
        if (sym->width < 0) {
            sym->minus = 1;
            sym->width *= -1;
        }
    } else if (*pos->fmt >= '1' && *pos->fmt <= '9') {
        s21_size_t i;
        for (i = 0; *pos->fmt >= '0' && *pos->fmt <= '9'; i++, pos->fmt++) {
            temp[i] = *pos->fmt;
        }
        temp[i] = '\0';
        sym->width = s21_string_to_int(temp);
    }
}

void s21_parse_precision(symbols *sym, positions *pos, va_list args) {
    char temp[pos->str_lenght];
    if (*pos->fmt == '.') {
        sym->presence_dot = 1;
        pos->fmt++;
        if (*pos->fmt == '*') {
            sym->precision = va_arg(args, int);
            if (sym->precision < 0) {
                sym->precision = 0;
                sym->presence_precision = 1;
            }
            pos->fmt++;
        } else if (*pos->fmt >= '0' && *pos->fmt <= '9') {
            s21_size_t i;
            for (i = 0; *pos->fmt >= '0' && *pos->fmt <= '9'; i++, pos->fmt++) {
                temp[i] = *pos->fmt;
            }
            temp[i] = '\0';
            sym->precision = s21_string_to_int(temp);
            sym->presence_precision = 1;
        } else
            sym->precision = 0;
    }
}

void s21_parse_lenght(symbols *sym, positions *pos) {
    if (*pos->fmt == 'h' || *pos->fmt == 'l' || *pos->fmt == 'L') {
        sym->lenght = *pos->fmt;
        pos->fmt++;
    }
}

void s21_parse_type(symbols *sym, positions *pos) {
    if (*pos->fmt == 'c' || *pos->fmt == 'd' || *pos->fmt == 'i' ||
        *pos->fmt == 'e' || *pos->fmt == 'E' || *pos->fmt == 'f' ||
        *pos->fmt == 'g' || *pos->fmt == 'G' || *pos->fmt == 'o' ||
        *pos->fmt == 'O' || *pos->fmt == 's' || *pos->fmt == 'u' ||
        *pos->fmt == 'x' || *pos->fmt == 'X' || *pos->fmt == 'p' ||
        *pos->fmt == 'n') {
        sym->type = *pos->fmt;
        }
}

void s21_check_type(symbols sym, positions *pos, va_list args, char* str) {
    switch (sym.type) {
        case 'c':
            s21_running_char(&sym, pos, (s21_wchar_t)va_arg(args, int));
            break;
        case 'd':
        case 'i':
        case 'u':
            s21_running_int(&sym, pos, s21_check_number_lenght(sym, args));
            break;
        case 'f':
            s21_start_float(&sym, pos, s21_check_float_lenght(sym, args));
            break;
        case 'g':
        case 'G':
            s21_running_g(&sym, pos, s21_check_float_lenght(sym, args));
            break;
        case 'e':
        case 'E':
            s21_start_e(&sym, pos, s21_check_float_lenght(sym, args));
            break;
        case 's':
            s21_running_string(&sym, pos, va_arg(args, char*));
            break;
        case 'o':
            s21_running_oct(&sym, pos, va_arg(args, unsigned long long));
            break;
        case 'p':
        case 'x':
        case 'X':
            s21_running_hex(&sym, pos, va_arg(args, unsigned long));
            break;
        case 'n': {
            s21_running_n(va_arg(args, int*), str);
            break;
        }
    }
}

// INT
long long s21_check_number_lenght(symbols sym, va_list args) {
    long long number = 0;
    if (sym.type == 'd' || sym.type == 'i') {
        if (sym.lenght == 'h') {
            number = (short) va_arg(args, int);
        } else if (sym.lenght == 'l') {
            number = va_arg(args, long);
        } else {
            number = va_arg(args, int);
        }
    } else if (sym.type == 'u' || sym.type == 'o' || sym.type == 'x' || sym.type == 'X') {
        if (sym.lenght == 'h') {
            number = (unsigned long) va_arg(args, unsigned int);
        } else if (sym.lenght == 'l') {
            number = (unsigned long) va_arg(args, unsigned long);
        } else {
            number = va_arg(args, unsigned int);
        }
    }
    return number;
}

short s21_check_sign(symbols *sym, long long number) {
    if (number < 0)
        sym->negative_sign = 1;
    return sym->negative_sign || sym->space || sym->plus;
}

unsigned long long s21_settings_for_int(symbols *sym, long long number) {
    sym->presence_sign = s21_check_sign(sym, number);
    unsigned long long unsigned_number = sym->negative_sign ? -number : number;
    sym->number_size = s21_count_digits(unsigned_number, 10);
    if (sym->precision > sym->number_size)
        sym->dif_prec_and_num_size = sym->precision - sym->number_size;
    if (sym->dif_prec_and_num_size > 0)
        sym->number_size += sym->dif_prec_and_num_size;
    if (sym->width > sym->number_size)
        sym->dif_width_and_num_size = sym->width - sym->number_size;
    return unsigned_number;
}

char* s21_compose_string_of_int(symbols *sym, long long number) {
    unsigned long long unsigned_number = s21_settings_for_int(sym, number);
    short sign;
    int lenght_result_string = sym->number_size + sym->dif_width_and_num_size + 1;
    char* result_string = (char*)malloc((lenght_result_string + 1) * sizeof(char));
    s21_memset(result_string, 0, lenght_result_string);
    char* string_for_sign = (char*)malloc((lenght_result_string) * sizeof(char));
    char* string_with_precision = (char*)malloc((sym->number_size + 1) * sizeof(char));
    s21_memset(string_for_sign, 0, lenght_result_string);
    s21_memset(string_with_precision, 0, (sym->number_size + 1));
    if (number == 0 && !sym->precision && sym->presence_precision) {
        result_string[0] = '\0';
        return result_string;
    }
    if (result_string && string_for_sign && string_with_precision) {
        if (sym->zero || sym->dif_prec_and_num_size > 0) {
            sign = 0;
        } else {
            sign = s21_add_sign(sym, &string_for_sign);
        }
        if (sym->dif_prec_and_num_size > 0) {
            int count_zeros = sym->dif_prec_and_num_size - sign;
            s21_int_to_string(string_with_precision + sign, unsigned_number);
            s21_add_spaces_or_zeros_left(string_with_precision, string_for_sign, '0', count_zeros);
            // s21_add_sign(sym, &string_for_sign);
        } else 
            s21_int_to_string(string_for_sign + sign, unsigned_number);
        char symbol = sym->zero ? '0' : ' ';
        int sign_count = sym->dif_width_and_num_size - sym->presence_sign;
        if (sym->minus) {
            s21_add_spaces_or_zeros_right(string_for_sign, result_string, symbol, sign_count);
        } else {
            s21_add_spaces_or_zeros_left(string_for_sign, result_string, symbol, sign_count);
            // s21_add_sign(sym, &result_string);
        }
        free(string_for_sign);
        free(string_with_precision);
    }
    return result_string;
}

void s21_running_int(symbols *sym, positions *pos, long long number) {
    char* result = s21_compose_string_of_int(sym, number);
    if (result) {
        if (sym->zero || sym->dif_prec_and_num_size)
            s21_add_sign(sym, &result);
        s21_strcpy(pos->str, result);
        pos->str += s21_strlen(result);
        free(result);
    }
}

short s21_add_sign(symbols *sym, char** str) {
    int count = sym->number_size + sym->dif_width_and_num_size + 2;
    short position = 0;
    char* string_with_sign = malloc(count * sizeof(char));
    if (string_with_sign) {
        if (sym->negative_sign) {
            string_with_sign[position++] = '-';
            sym->negative_sign = 0;
            sym->space = 0;
            sym->plus = 0;
        } else if (sym->plus) {
            string_with_sign[position++] = '+';
            sym->plus = 0;
        } else if (sym->space && sym->precision < sym->number_size) {
            string_with_sign[position++] = ' ';
            sym->space = 0;
        }
        string_with_sign[position] = '\0';
        s21_strcat(string_with_sign, *str);
        free(*str);
        *str = string_with_sign;
    }
    return position;
}

short s21_count_digits(unsigned long long num, short base) {
    int count = 0;
    if (num == 0) {
        count = 1;
    } else {
        while (num) {
            num /= base;
            count++;
        }
    }
    return count;
}

void s21_int_to_string(char* str, unsigned long long number) {
    short count = s21_count_digits(number, 10);
    if (number == 0) {
        str[0] = '0';
    }
    for (int i = count; i > 0; i--) {
        int k = number / pow(10, i - 1);
        *str++ = k + '0';
        number -= k * pow(10, i - 1);
    }
    *str = '\0';
}

// CHAR
void s21_running_char(symbols *sym, positions *pos, s21_wchar_t c) {
    if (sym->minus) {
        *pos->str++ = c;
        s21_compose_string_of_char(sym, pos);
    } else {
        s21_compose_string_of_char(sym, pos);
        *pos->str++ = c;
    }
}

void s21_compose_string_of_char(symbols *sym, positions *pos) {
    short dif = sym->width ? sym->width - 1 : 0;
    while (dif > 0) {
        *pos->str = ' ';
        pos->str++;
        dif--;
    }
}

//FLOAT
long double s21_check_float_lenght(symbols sym, va_list args) {
    long double result = sym.lenght == 'L' ? va_arg(args, long double) : va_arg(args, double);
    return result;
}

unsigned long long s21_find_float_int_parts(symbols *sym, long double *number, s21_size_t *int_part) {
    unsigned long long float_part_number = 0;
    long int_part_number = (long)(*number);
    sym->precision = sym->presence_precision || sym->presence_dot ? sym->precision : 6;
    sym->presence_sign = s21_check_sign(sym, int_part_number);
    if (sym->negative_sign) {
        *number *= -1.0;
        int_part_number *= -1.0;
    }
    sym->size_int_part = s21_count_digits(int_part_number, 10);
    float_part_number = (*number - int_part_number) * s21_number_order(sym->precision + 1);
    if (!sym->precision) {
        int_part_number = float_part_number >= 5 ? int_part_number + 1 : int_part_number;
        float_part_number = 0;
    }
    float_part_number = (float_part_number + 5) / 10;
    if ((sym->type == 'e' || sym->type == 'E') && *number < 1) {
        int count = 0;
        long double check_number = *number;
        if (check_number != 0) {
            while (!(long)check_number) {
                check_number *= 10;
                count++;
            }
        }
        int_part_number = (long)float_part_number / s21_number_order(s21_count_digits(float_part_number, 10) - 1);
        float_part_number = float_part_number % s21_number_order(s21_count_digits(float_part_number, 10) - 1) * s21_number_order(count);
        sym->degree_size = sym->degree_size - count;
    }
    *int_part = int_part_number;
    return float_part_number;
}

short s21_float_size(symbols *sym, short size_int_part) {
    short float_size = size_int_part + sym->precision + (sym->precision ? 1 : 0);
    if (sym->type == 'e' || sym->type == 'E') {
        short e = s21_count_digits(sym->degree_size, 10);
        float_size += 2 + (e > 1 ? e : 2);
    }
    return float_size;
}

int s21_additional_zeros(symbols *sym, unsigned long long *float_part) {
    int zeros;
    if (sym->presence_g && !sym->grid) {
        zeros = s21_count_zeros(float_part);
    } else
        zeros = 0;
    sym->precision -= zeros;
    return zeros;
}

void s21_add_float_part(symbols *sym, int last_pos, char* result) {
    if (sym->type == 'e') {
        result[last_pos++] = 'e';
    } else if (sym->type == 'E') {
        result[last_pos++] = 'E';
    }
    result[last_pos++] = sym->degree_size >= 0 ? '+' : '-';
    if (sym->degree_size < 0)
        sym->degree_size *= -1;
    short size = s21_count_digits(sym->degree_size, 10);
    char e[21];
    s21_int_to_string(e, sym->degree_size);
    int i = 0;
    if (size == 1)
        result[last_pos++] = '0';
    for (; size; size--)
        result[last_pos++] = e[i++];
    result[last_pos] = '\0';
}

void s21_float_part_to_string(symbols *sym, unsigned long long float_part, char* result, int dot_pos) {
    int pos = sym->precision + dot_pos;
    int last_pos = pos;
    // unsigned long long count_zeros = float_part;
    // count_zeros = s21_count_zeros(&count_zeros);
    result[pos + 1] = '\0';
    if (sym->precision != 0 || (sym->presence_g && sym->grid)) {
        result[dot_pos] = '.';
        last_pos++;
    }
    while (float_part) {
        result[pos--] = (float_part % 10) + '0';
        float_part /= 10;
    }
    while (pos > dot_pos) {
        result[pos] = '0';
        pos--;
    }
    if (sym->type == 'e' || sym->type == 'E') {
        // last_pos = count_zeros;
        s21_add_float_part(sym, last_pos, result);
    }
}

char* s21_compose_string_of_float(symbols *sym, long double number) {
    s21_size_t int_part = 0;
    unsigned long long float_part = s21_find_float_int_parts(sym, &number, &int_part);
    short number_size = s21_float_size(sym, sym->size_int_part);
    sym->number_size = number_size + 1;
    short dif = sym->width - number_size;
    dif = dif <= 0 ? number_size : number_size + dif;
    char* result_string = S21_NULL;
    char* result = malloc((number_size + 1) * sizeof(char));
    s21_memset(result, 0, (number_size + 1));
    if (result) {
        short sign = sym->zero ? 0 : s21_add_sign(sym, &result);
        s21_additional_zeros(sym, &float_part);
        s21_int_to_string(result + sign, int_part);
        s21_float_part_to_string(sym, float_part, result, sym->size_int_part + sign);
        result_string = realloc(result_string, (dif + 2) * sizeof(char));
        if (result_string) {
            sym->dif_width_and_num_size = dif;
            sym->number_size = s21_number_count_with_e(result);
            char symbol = sym->zero ? 0 : ' ';
            int additional_signs_size = dif - number_size - sym->presence_sign - (sym->precision && sym->presence_g && sym->grid);
            if (sym->minus || sym->precision < sym->degree_size) {
                s21_add_spaces_or_zeros_right(result, result_string, symbol, additional_signs_size);
            } else
                s21_add_spaces_or_zeros_left(result, result_string, symbol, additional_signs_size);
        }
        free(result);
    }
    return result_string;
}

char* s21_running_float(symbols *sym, long double number) {
    char* result_string = s21_compose_string_of_float(sym, number);
    if (result_string) {
        if (sym->zero)
            s21_add_sign(sym, &result_string);
    }
    return result_string;
}

void s21_start_float(symbols *sym, positions *pos, long double number) {
    char* result = s21_running_float(sym, number);
    if (result) {
        s21_string_to_string(pos, result);
        free(result);
    }
}

// E or e
void s21_negative_degree(symbols *sym, long double number) {
    short size = 0;
    int new_number = (int)number;
    sym->precision = sym->presence_precision || !sym->precision ? sym->precision : 6;
    int precision = sym->precision;
    for (; !new_number && precision; size++, precision--) {
        number *= 10;
        new_number = (int)number;
    }
    sym->degree_size = -size;
}

char* s21_running_e(symbols *sym, long double number) {
    long double new_number;
    int int_part_number = (int)number;
    if (!int_part_number) {
        s21_negative_degree(sym, number);
        new_number = number * s21_number_order(-sym->degree_size);
    } else {
        int_part_number = int_part_number < 0 ? -int_part_number : int_part_number;
        int size = s21_count_digits(int_part_number, 10);
        sym->degree_size = size - 1;
        new_number = number / (s21_number_order(sym->degree_size));
    }
    return s21_running_float(sym, new_number);
}

void s21_start_e(symbols *sym, positions *pos, long double number) {
    char* result = s21_running_e(sym, number);
    if (result) {
        s21_string_to_string(pos, result);
        free(result);
    }
}

// G
void s21_check_precision(symbols *sym) {
    sym->precision = sym->precision < 0 ? 0 : sym->precision;
}

void s21_check_zeros(symbols *sym, long double number) {
    int precision = sym->presence_precision ? sym->precision : 6;
    int check = 0;
    unsigned long long float_part = (number - (long)number) * s21_number_order(sym->precision + 1);
    for (; precision; precision--) {
        check = float_part % 10;
        if (check) {
            break;
        } else
            float_part /= 10;
    }
    if (!precision)
        sym->precision = 0;
}

void s21_running_g(symbols *sym, positions *pos, long double number) {
    s21_check_zeros(sym, number);
    sym->precision = !sym->presence_precision ? 6 : sym->precision;
    int precision = sym->precision;
    sym->presence_g = 1;
    sym->type = sym->type == 'g' ? 'e' : 'E';
    sym->precision = precision - 1;
    s21_check_precision(sym);
    char* result_e = s21_running_e(sym, number);
    // int size_e = sym->number_size;

    sym->type = 'f';
    int int_part_float = (int)number;
    int_part_float = int_part_float < 0 ? -int_part_float : int_part_float;
    int size_int_part = s21_count_digits(int_part_float, 10);
    sym->precision = precision - size_int_part;
    s21_check_precision(sym);
    char* result_f = s21_running_float(sym, number);
    // int size_f = sym->number_size;
    if (s21_strlen(result_e) < s21_strlen(result_f)) {
        s21_string_to_string(pos, result_e);
    } else
        s21_string_to_string(pos, result_f);
    free(result_e);
    free(result_f);
}

// STRING
void s21_additional_symbols(symbols *sym, positions *pos, s21_size_t size) {
    int dif = 0;
    if (sym->width && (sym->precision < sym->width)) {
        dif = size;
    } else {
        dif = sym->width == 0 ? 0 : (int)(sym->width - size);
    }
    for(;dif > 0; dif--)
        *pos->str++ = ' ';
}

void s21_running_string(symbols *sym, positions *pos, char* string) {
    int string_size = s21_strlen(string);
    int count = 0;
    if (!sym->minus && sym->width > sym->precision && sym->width > string_size) {
        sym->dif_width_and_num_size = sym->width - string_size;
        s21_additional_symbols(sym, pos, sym->dif_width_and_num_size);
    } else if (!sym->minus && sym->width > sym->precision && sym->precision < string_size && sym->presence_precision) {
        sym->dif_width_and_num_size = sym->width - sym->precision;
        s21_additional_symbols(sym, pos, sym->dif_width_and_num_size);
    }
    if (!sym->presence_precision) {
        while (*string) {
            *pos->str++ = *(string++);
            count++;
        }
    } else {
        int number_presision = sym->precision;
        for(; *string && number_presision; number_presision--, count++) 
            *pos->str++ = *(string++);
    }
    sym->dif_width_and_num_size = sym->width - count;
    if (sym->minus && sym->dif_width_and_num_size > 0)
        s21_additional_symbols(sym, pos, sym->dif_width_and_num_size);
}

// OCT
void s21_add_prefix(symbols *sym, char** string) {
    int pos = 0;
    int size = s21_strlen(*string);
    char* prefix = malloc((size + 3) * sizeof(char));
    if (prefix) {
        switch (sym->type) {
            case 'x':
            case 'X':
            case 'p':
                if (sym->grid || sym->type == 'p') {
                    prefix[pos++] = '0';
                    prefix[pos++] = sym->type == 'X' ? 'X' : 'x';
                    prefix[pos] = '\0';
                    s21_strcat(prefix, *string);
                }
                break;
            case 'o':
                if (sym->grid) {
                    prefix[pos++] = '0';
                    prefix[pos] = '\0';
                    s21_strcat(prefix, *string);
                }
                break;
        }
        free(*string);
    }
    *string = prefix;
}

char* s21_compose_string_of_oct(symbols *sym, unsigned long long number) {
    sym->number_size = s21_count_digits(number, 8);
    char* result_oct = malloc((sym->number_size + 1) * sizeof(char));
    if (result_oct) {
        unsigned long long oct_number = 0;
        for (int i = 0; number != 0; i++) {
            oct_number += (number % 8) * s21_number_order(i);
            number /= 8;
        }
        s21_int_to_string(result_oct, oct_number);
    }
    return result_oct;
}

void s21_running_oct(symbols *sym, positions *pos, unsigned long long number) {
    int need_prefix = sym->grid && number != 0;
    char* result_oct_string = s21_compose_string_of_oct(sym, number);
    if (result_oct_string) {
        int size = sym->number_size;
        if (need_prefix && !sym->zero)
            s21_add_prefix(sym, &result_oct_string);
        sym->dif_width_and_num_size = sym->width ? sym->width - size : 0;
        sym->dif_prec_and_num_size = sym->presence_precision && sym->precision > size ? sym->precision - size : 0;  // Новшества. Если что удалить
        sym->dif_width_and_num_size = sym->dif_width_and_num_size > sym->dif_prec_and_num_size ? sym->dif_width_and_num_size : sym->dif_prec_and_num_size; // Новшества. Если что удалить
        char* result_string = malloc((sym->dif_width_and_num_size + size + need_prefix + 2));
        char symbol = sym->zero || sym->precision > sym->number_size ? '0' : ' ';
        if (sym->minus && sym->precision < sym->width) {
            s21_add_spaces_or_zeros_right(result_oct_string, result_string, symbol, sym->dif_width_and_num_size);
        } else
            s21_add_spaces_or_zeros_left(result_oct_string, result_string, symbol, sym->dif_width_and_num_size);  // было dif_width_and_num_size
        if (need_prefix && sym->zero)
            s21_compose_string_of_oct(sym, number);
        s21_string_to_string(pos, result_string);
        free(result_oct_string);
        free(result_string);
    }
}

// HEX
void s21_compose_string_of_hex(symbols *sym, char* string, unsigned long number) {
    const char low[] = "0123456789abcdef";
    const char upper[] = "0123456789ABCDEF";
    int index;
    string[sym->number_size] = '\0';
    int size = sym->precision > sym->number_size ? sym->precision : sym->number_size;
    while (size) {
        index = number % 16;
        string[--size] = sym->type == 'X' ? upper[index] : low[index];
        number /= 16;
    }
} 

void s21_running_hex(symbols *sym, positions *pos, unsigned long long number) {
    sym->number_size = s21_count_digits(number, 16);
    sym->number_size = sym->precision > sym->number_size ? sym->precision : sym->number_size;
    int need_prefix = (sym->grid || sym->type == 'p') && number != 0;
    char* result_hex_string = malloc((sym->number_size + 1) * sizeof(char));
    if (result_hex_string) {
        s21_compose_string_of_hex(sym, result_hex_string, number);
        if ((need_prefix && !sym->zero) || sym->type == 'p')
            s21_add_prefix(sym, &result_hex_string);
        sym->dif_width_and_num_size = sym->width > sym->number_size ? sym->width - sym->number_size - need_prefix * 2 : 0;
        int size = sym->dif_width_and_num_size + sym->number_size + need_prefix * 2 + 1;
        char* result_string = (char*)malloc((size + 7) * sizeof(char));
        if (result_string) {
            sym->dif_prec_and_num_size = sym->presence_precision && sym->precision > size ? sym->precision - sym->number_size : 0;
            sym->dif_width_and_num_size = sym->dif_width_and_num_size > sym->dif_prec_and_num_size ? sym->dif_width_and_num_size : sym->dif_prec_and_num_size;
            char symbol = sym->zero || sym->precision > sym->number_size ? '0' : ' ';
            if (sym->minus && sym->precision < sym->width) {
                s21_add_spaces_or_zeros_right(result_hex_string, result_string, symbol, sym->dif_width_and_num_size);
            } else
                s21_add_spaces_or_zeros_left(result_hex_string, result_string, symbol, sym->dif_width_and_num_size);
            if (need_prefix && sym->zero)
                s21_strcat(result_string + s21_strlen(result_string), s21_compose_string_of_oct(sym, number));
            s21_string_to_string(pos, result_string);
            free(result_hex_string);
            free(result_string);
        }
    }
}

// N
void s21_running_n(int* n, char* str) {
    *n = s21_strlen(str);
}

void s21_string_to_string(positions *pos, char* s) {
    for (; *s != '\0'; s++, pos->str++)
        *pos->str = *s;
}

int s21_string_to_int(char *string) {
    s21_size_t len = s21_strlen(string);
    int number = 0;
    for(; *string; len--, string++) {
        number += (*string - '0') * pow(10, len - 1);
    }
    return number;
}

void s21_add_spaces_or_zeros_right(char* from, char* to, char symbol, short count) {
    while (*from)
        *(to++) = *(from++);
    for (; count > 0; count--)
        *(to++) = symbol;
    *to = '\0';
}

void s21_add_spaces_or_zeros_left(char* from, char* to, char symbol, short count) {
    for (; count > 0; count--)
        *(to++) = symbol;
    while (*from)
        (*to++) = *(from++);
    *to = '\0';
}

unsigned long long s21_number_order(int number) {
    unsigned long long result = 1;
    for (; number; number--)
        result *= 10;
    return result;
}

int s21_count_zeros(unsigned long long *number) {
    int count = 0;
    int buf = 0;
    while(*number) {
        buf = *number % 10;
        if (buf != 0) {
            break;
        } else {
            *number /=10;
            count++;
        }
    }
    return count;
}

short s21_is_number(char symbol) {
    short result = symbol >= '0' && symbol <= '9' ? 1 : 0;
    return result;
}

int s21_number_count_with_e(char* str) {
    s21_size_t size = s21_strlen(str);
    int count = 0;
    for (s21_size_t i = 0; i < size; i++) {
        if (s21_is_number(str[i]))
            count++;
        if (str[i] == 'e' || str[i] == 'E')
            break;
    }
    return count;
}

// int main() {
//     char str1[1000] = "";
//     char str2[1000] = "";
//     int n1  = 0;
//     int n2 = 0;
//     int r1 = s21_sprintf(str1, "%n", &n1);
//     int r2 = sprintf(str2, "%n", &n2);
//     // puts(str1);
//     printf("my_count = %d\n", r1);
//     printf("\n");

//     // puts(str2);
//     printf("count = %d\n", r2);
//     return 0;
// }
