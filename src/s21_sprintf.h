#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include "s21_string.h"

typedef struct {
    int width;
    int precision;
    int presence_precision;
    char lenght;
    char type;
    int minus;
    int plus;
    int space;
    int grid;
    int zero;
    int negative_sign;
    int presence_sign;
    int number_size;
    int dif_prec_and_num_size;
    int dif_width_and_num_size;
    int size_int_part;
    int presence_g;
    int degree_size;
    int presence_dot;
} symbols;

typedef struct {
    char *fmt;
    char *str;
    s21_size_t str_lenght;
} positions;

int s21_sprintf(char *str, const char *format, ...);
void s21_init_symbols(symbols *sym);
void s21_parse(symbols *sym, positions *pos, va_list args);
void s21_parse_flags(symbols *sym, positions *pos);
void s21_parse_width(symbols *sym, positions *pos, va_list args);
void s21_parse_precision(symbols *sym, positions *pos, va_list args);
void s21_parse_lenght(symbols *sym, positions *pos);
void s21_parse_type(symbols *sym, positions *pos);
void s21_check_type(symbols sym, positions *pos, va_list args, char* str);
//INT
long long s21_check_number_lenght(symbols sym, va_list args);
short s21_check_sign(symbols *sym, long long number);
unsigned long long s21_settings_for_int(symbols *sym, long long number);
char* s21_compose_string_of_int(symbols *sym, long long number);
void s21_running_int(symbols *sym, positions *pos, long long number);
short s21_add_sign(symbols *sym, char** str);
short s21_count_digits(unsigned long long num, short base);
void s21_int_to_string(char* str, unsigned long long number);
//CHAR
void s21_running_char(symbols *sym, positions *pos, s21_wchar_t с);
void s21_compose_string_of_char(symbols *sym, positions *pos);
//FLOAT
long double s21_check_float_lenght(symbols sym, va_list args);
unsigned long long s21_find_float_int_parts(symbols *sym, long double *number, s21_size_t *int_part);
short s21_float_size(symbols *sym, short size_int_part);
int s21_additional_zeros(symbols *sym, unsigned long long *exponent);
void s21_float_part_to_string(symbols *sym, unsigned long long float_part, char* result, int dot_pos);
void s21_add_float_part(symbols *sym, int last_pos, char* result);
char* s21_compose_string_of_float(symbols *sym, long double number);
char* s21_running_float(symbols *sym, long double number);
void s21_start_float(symbols *sym, positions *pos, long double number);
//E or e
char* s21_running_e(symbols *sym, long double number);
void s21_start_e(symbols *sym, positions *pos, long double number);
void s21_negative_degree(symbols *sym, long double number);
//G
void s21_check_precision(symbols *sym);
void s21_check_zeros(symbols *sym, long double number);
void s21_running_g(symbols *sym, positions *pos, long double number);
int s21_count_zeros(unsigned long long *number);
// STRING
void s21_additional_symbols(symbols *sym, positions *pos, s21_size_t size);
void s21_running_string(symbols *sym, positions *pos, char* string);
//OCT
void s21_add_prefix(symbols *sym, char** string);
char* s21_compose_string_of_oct(symbols *sym, unsigned long long number);
void s21_running_oct(symbols *sym, positions *pos, unsigned long long number);
// HEX
void s21_running_hex(symbols *sym, positions *pos, unsigned long long number);
void s21_compose_string_of_hex(symbols *sym, char* string, unsigned long number);
// N
void s21_running_n(int *n, char* str);
// USEFUL FUNCTIONS
void s21_add_spaces_or_zeros_right(char* from, char* to, char symbol, short count);
void s21_add_spaces_or_zeros_left(char* from, char* to, char symbol, short count);
unsigned long long s21_number_order(int number);

void s21_string_to_string(positions *pos, char* s);
int s21_string_to_int(char *string);
short s21_is_number(char symbol);
int s21_number_count_with_e(char* str);
#endif  //  SRC_S21_SPRINTF_H_