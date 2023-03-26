#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include "s21_string.h"

typedef struct {
    int sign;
    int sign_exists;
    int grade;
    int asterisk;
    int width;
    int num_power;
    int num_power_call;
    int prefix_ex;
    int undef_num_ex;
    long long unsigned int val_to_transform;
    long double val_ld_to_transform;
    char type;
    char lenght;
} symbols;

typedef struct {
    char *fmt;
    char *fmt_const;
    char *str;
    char *str_start;
    int errors;
    int count;
    int fmt_lenght;
} positions;

//  Main function
int s21_sscanf(const char *str, const char *format, ...);
//  Actions
void spec_width(symbols *sym, positions *pos);
void spec_lenght(symbols *sym, positions *pos);
void spec_type(symbols sym, positions *pos, va_list args);
//  Converters
void string_to_int(symbols *sym, positions *pos, va_list args);
void string_to_char(symbols sym, positions *pos, va_list args);
void string_to_float(symbols sym, positions *pos, va_list args);
void string_to_array(symbols sym, positions *pos, va_list args);
void read_sym_count(positions *pos, va_list args);
void string_to_adress(symbols sym, positions *pos, va_list args);
void string_to_digit(positions *pos);
void int_transform(symbols *sym, va_list args);
void unsig_transform(symbols *sym, va_list args);
void float_transform(symbols *sym, va_list args);
//  Addons
void science_notation(positions *pos, symbols *sym, va_list args);
//  Checkers
void check_asterisk(symbols *sym, positions *pos);
int check_number(symbols sym, char num);
void check_space_btw_specs(positions *pos);
int check_signs_existence(positions *pos, symbols *sym);
int check_spaces(const char *str);
long double check_undefined_nums(positions *pos, symbols *sym);
void check_smlr(positions *pos);
//  Helpers
void fmt_move_forward(positions *pos);
void symbols_init(symbols *sym);
int sym_converter(int grade, char sym);
void grade_identifier(symbols *sym, positions *pos);
int width_counter(symbols sym, positions pos, int k);
int width_counter_plus(symbols sym, positions pos, int k, int kp);
//  const char *show_classification(double x);

#endif  // SRC_S21_SSCANF_H_
