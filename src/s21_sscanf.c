#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
    //  STRUCTS
    symbols sym;
    positions pos;
    //  ARGS
    va_list args;
    va_start(args, format);

    pos.count = 0;  //  values that sscanf returns
    pos.fmt_lenght = s21_strlen(format);  // format controller
    pos.str = (char*)str;
    pos.str_start = pos.str;
    pos.fmt_const = (char*)calloc((s21_strlen(format) + 1), sizeof(char));  //  Copying array for changing specs
    s21_strcpy(pos.fmt_const, format);
    pos.fmt = pos.fmt_const;  // Assignment adress for dynamic pointer
    while (*pos.fmt != '\0' && pos.fmt_lenght > 0) {
        if (*pos.fmt == '%') {
            symbols_init(&sym);
            fmt_move_forward(&pos);
            check_asterisk(&sym, &pos);
            spec_width(&sym, &pos);
            spec_lenght(&sym, &pos);
            spec_type(sym, &pos, args);
            check_smlr(&pos);
        } else if (*pos.fmt == ' ' || *pos.fmt == '\n' || *pos.fmt == '\t') {
            fmt_move_forward(&pos);
        } else {
            check_space_btw_specs(&pos);
        }
    }
    if (pos.fmt_lenght <= 0 && pos.count == 0 && check_spaces(str)) {
        pos.count = EOF;
    }
    free(pos.fmt_const);
    va_end(args);
    return pos.count;
}

void spec_width(symbols *sym, positions *pos) {
    int k = 0;
    while (check_number(*sym, pos->fmt[k])) {
        k++;
    }
    for (int i = k - 1; i >= 0; i--) {
        if (check_number(*sym, pos->fmt[i])) {
            sym->width += sym_converter(sym->grade, pos->fmt[i]) * pow(sym->grade, k - 1 - i);
        }
    }
    if (sym->width == 0) {
        sym->width = -1;
    }
    pos->fmt += k;
}

void spec_lenght(symbols *sym, positions *pos) {  // NEED TO COMPLETE
    char dec[3] = {'h', 'l'};
    char dec_type[7] = {'i', 'd', 'o', 'X', 'x', 'u'};
    char flt[3] = {'l', 'L'};
    char flt_type[6] = {'e', 'E', 'f', 'G', 'g'};
    if (s21_strchr(dec, pos->fmt[0]) && s21_strchr(dec_type, pos->fmt[1])) {
        sym->lenght = *pos->fmt;
        pos->fmt++;
    } else if (pos->fmt[0] == 'l' && pos->fmt[1] == 'l' && s21_strchr(dec_type, pos->fmt[2])) {
        sym->lenght = 'M';
        pos->fmt += 2;
    } else if (s21_strchr(flt, pos->fmt[0]) && s21_strchr(flt_type, pos->fmt[1])) {
        sym->lenght = *pos->fmt;
        pos->fmt++;
    } else if (pos->fmt[0] == 'l' && pos->fmt[1] == 'c') {
        sym->lenght = 'W';
        pos->fmt++;
    }
}

void spec_type(symbols sym, positions *pos, va_list args) {
    switch (*pos->fmt) {
        case 'i': {
            string_to_digit(pos);
            break;
        }
        case 'o':
        case 'x':
        case 'X':
        case 'u':
        case 'd': {
            string_to_int(&sym, pos, args);
            break;
        }
        case 'c': {
            string_to_char(sym, pos, args);
            break;
        }
        case 'e':
        case 'E':
        case 'g':
        case 'G':
        case 'f': {
            string_to_float(sym, pos, args);
            break;
        }
        case 's': {
            string_to_array(sym, pos, args);
            break;
        }
        case 'n': {
            read_sym_count(pos, args);
            break;
        }
        case 'p': {
            string_to_adress(sym, pos, args);
            break;
        }
        default: {
            pos->fmt_lenght = 0;
            fmt_move_forward(pos);
        }
    }
}

void string_to_digit(positions *pos) {
    while (*pos->str == ' ' || *pos->str == '\n' || *pos->str == '\t') {
        pos->str++;
    }
    if (pos->str[0] != '0') {
        *pos->fmt = 'd';
    } else if (pos->str[1] == 'X' || pos->str[1] == 'x') {
        *pos->fmt = 'x';
    } else {
        *pos->fmt = 'o';
    }
    while (*pos->fmt != '%')
        pos->fmt--;
}

void string_to_int(symbols *sym, positions *pos, va_list args) {
    int k = 0, s = 0, count = 0;
    const char temp[3] = {8, 16};
    while (*pos->str == ' ' || *pos->str == '\n' || *pos->str == '\t') {
        pos->str++;
    }
    s = check_signs_existence(pos, sym);
    grade_identifier(sym, pos);
    k = width_counter(*sym, *pos, k);
    if (sym->width != -1 && sym->width <= k && sym->sign_exists == 1 && sym->num_power_call == 0) {
        k -= s;
    }
    for (int i = k - 1; i >= 0; i--) {
        if (check_number(*sym, pos->str[i]) && sym->asterisk == 0) {
            sym->val_to_transform += sym_converter(sym->grade, pos->str[i]) *
            (long long unsigned)pow(sym->grade, k - 1 - i);
            count = 1;
        }
    }
    pos->str += k;
    if (sym->asterisk == 0) {
        if (s21_strchr(temp, sym->grade) || *pos->fmt == 'u') {
            unsig_transform(sym, args);
        } else {
            int_transform(sym, args);
        }
    }
    if (count == 0 && sym->prefix_ex != 1 && sym->asterisk == 0)
        pos->fmt_lenght = 0;
    if (sym->num_power_call == 0) {
        if (count == 0 && sym->prefix_ex == 1 && sym->asterisk == 0)
            count = 1;
        pos->count += count;
        fmt_move_forward(pos);
    }
}

void string_to_char(symbols sym, positions *pos, va_list args) {
    if (sym.lenght == 'W') {
        wchar_t *arg_wchar = va_arg(args, wchar_t*);
        if (sym.asterisk == 0) {
            for (size_t i = 0; i < s21_strlen(pos->str) + 1; i++) {
                arg_wchar[i] = (wchar_t)pos->str[i];
            }
        }
        pos->count++;
    } else if (sym.asterisk == 0 && *pos->str != '\0') {
        char *arg_char = va_arg(args, char*);
        *arg_char = *pos->str;
        pos->count++;
    }
    pos->str++;
    while (*pos->str == ' ')
        pos->str++;
    fmt_move_forward(pos);
}

void string_to_float(symbols sym, positions *pos, va_list args) {
    int k = 0, kp = 0, s = 0, int_part = 0, count = 0;
    while (*pos->str == ' ' || *pos->str == '\n' || *pos->str == '\t') {
        pos->str++;
    }
    s = check_signs_existence(pos, &sym);
    k = width_counter(sym, *pos, k);
    if (sym.width != -1 && sym.width <= k && sym.sign_exists == 1) {
        k -= s;
    }
    for (int i = k - 1; i >= 0; i--) {
        if (check_number(sym, pos->str[i])) {
            int_part += (pos->str[i] - 48) * pow(10, k - 1 - i);
            count = 1;
        }
    }
    if (count == 0) {
        sym.val_ld_to_transform = check_undefined_nums(pos, &sym);
    }
    pos->str += k;
    if (*pos->str == '.') {
        pos->str++;
        k++;
        kp = width_counter_plus(sym, *pos, k, kp);
        for (int i = 0; i < kp; i++) {
            if (check_number(sym, pos->str[i])) {
                sym.val_ld_to_transform += (pos->str[i] - 48) / pow(10, i + 1);
                count = 1;
            }
        }
    }
    sym.val_ld_to_transform += int_part;
    pos->str += kp;
    science_notation(pos, &sym, args);
    sym.val_ld_to_transform *= pow(10, sym.num_power);
    if (sym.asterisk == 0) {
        float_transform(&sym, args);
        count += sym.undef_num_ex;
        pos->count += count;
    }
    if (count == 0 && sym.asterisk == 0)
        pos->fmt_lenght = 0;
    fmt_move_forward(pos);
}

void string_to_array(symbols sym, positions *pos, va_list args) {
    int k = 0, flag = 0;
    char *arg_array;
    //  char *temp = pos->str;
    //  const char array[5] = {'\0', ' ', '\n', '\t'};
    char* m = (char*)malloc((s21_strlen(pos->str) + 1) * (sizeof(char)));
    if (sym.asterisk == 0) {
        arg_array = va_arg(args, char*);
    } else {
        arg_array = m;
    }
    while (*pos->str == ' ' || *pos->str == '\n' || *pos->str == '\t') {
        pos->str++;
    }
    k = sym.width;
    //  while (!(strchr(array, *pos->str)) && k != 0) {
    while (*pos->str != '\0' && *pos->str != ' ' && *pos->str != '\n' && *pos->str != '\t' && k != 0) {
        *arg_array = *pos->str;
        arg_array++;
        pos->str++;
        k--;
        flag = 1;
    }
    if (flag == 0 && sym.asterisk == 0)
        pos->fmt_lenght = 0;
    if (sym.asterisk == 0 && flag == 1)
        pos->count++;
    *arg_array = '\0';
    free(m);
    fmt_move_forward(pos);
}

void read_sym_count(positions *pos, va_list args) {
    int *arg_count = va_arg(args, int*);
    while (*pos->str == ' ' || *pos->str == '\n' || *pos->str == '\t') {
        pos->str++;
    }
    *arg_count = pos->str - pos->str_start;
    fmt_move_forward(pos);
}

void string_to_adress(symbols sym, positions *pos, va_list args) {
    int k = 0, count = 0;
    unsigned long int res = 0, m = 0;
    unsigned long int *arg_void;
    if (sym.asterisk == 0) {
        arg_void = va_arg(args, unsigned long int*);
    } else {
        arg_void = &m;
    }
    while (*pos->str == ' ' || *pos->str == '\n' || *pos->str == '\t') {
        pos->str++;
    }
    check_signs_existence(pos, &sym);
    grade_identifier(&sym, pos);
    k = width_counter(sym, *pos, k);
    for (int i = k - 1; i >= 0; i--) {
        if (check_number(sym, pos->str[i])) {
            res += (sym_converter(sym.grade, pos->str[i]) * pow(sym.grade, k - 1 - i));
            count = 1;
        }
    }
    if (sym.sign != -1) {
        *arg_void = res;
    } else {
        *arg_void = 0 - res;
    }
    if (count == 0 && sym.asterisk == 0)
        pos->fmt_lenght = 0;
    pos->str += k;
    pos->count += count;
    fmt_move_forward(pos);
}

void fmt_move_forward(positions *pos) {
    pos->fmt_lenght--;
    pos->fmt++;
}

void symbols_init(symbols *sym) {
    sym->asterisk = 0;
    sym->sign = 1;
    sym->sign_exists = 0;
    sym->width = 0;
    sym->type = 0;
    sym->lenght = 0;
    sym->val_to_transform = 0;
    sym->val_ld_to_transform = 0;
    sym->grade = 10;
    sym->num_power = 0;
    sym->num_power_call = 0;
    sym->prefix_ex = 0;
    sym->undef_num_ex = 0;
}

void grade_identifier(symbols *sym, positions *pos) {
    if (*pos->fmt == 'o') {
        sym->grade = 8;
        if (*pos->str == '0') {
            pos->str += 1;
            sym->prefix_ex = 1;
        }
    } else if (*pos->fmt == 'x' || *pos->fmt == 'X' || *pos->fmt == 'p') {
        sym->grade = 16;
        if (*pos->str == '0' && (pos->str[1] == 'X' || pos->str[1] == 'x')) {
            pos->str += 2;
            sym->prefix_ex = 1;
        }
    }
}

int sym_converter(int grade, char sym) {
    int res = 0;
    if (sym >= '0' && sym <= '9') {
        res = sym - 48;
    } else if (sym >= 'a' && sym <= 'f' && grade == 16) {
        res = sym - 87;
    } else if (sym >= 'A' && sym <= 'F' && grade == 16) {
        res = sym - 55;
    }
    return res;
}

int width_counter(symbols sym, positions pos, int k) {
    if (sym.width == -1) {
        while (check_number(sym, pos.str[k])) {
            k++;
        }
    } else {
        while (k < sym.width && check_number(sym, pos.str[k])) {
            k++;
        }
    }
    return k;
}

int width_counter_plus(symbols sym, positions pos, int k, int kp) {
    if (sym.width == -1) {
        while (check_number(sym, pos.str[kp])) {
            kp++;
        }
    } else {
            while (kp < sym.width - k && check_number(sym, pos.str[kp]))
            kp++;
        }
    return kp;
}

void check_asterisk(symbols *sym, positions *pos) {
    if (*pos->fmt == '*') {
        sym->asterisk = 1;
        pos->fmt++;
    }
}

int check_number(symbols sym, char num) {
    int res = 0;
    if (sym.grade == 8 && (num >= '0' && num <= '7'))
        res = 1;
    else if (sym.grade == 10 && ((num >= '0' && num <= '9')))
        res = 1;
    else if (sym.grade == 16)
        if ((num >= '0' && num <= '9') || ((num >= 'a' && num <= 'f') || (num >= 'A' && num <= 'F')))
            res = 1;
    return res;
}

long double check_undefined_nums(positions *pos, symbols *sym) {
    long double num = 0;
    if (pos->str[0] =='i' || pos->str[0] == 'I') {
        if (pos->str[1] == 'n' || pos->str[1] == 'N') {
            if (pos->str[2] == 'f' || pos->str[2] == 'F') {
                num = INFINITY;
                sym->undef_num_ex = 1;
                pos->str += 3;
            }
        }
    } else if (pos->str[0] =='n' || pos->str[0] == 'N') {
        if (pos->str[1] == 'a' || pos->str[1] == 'A') {
            if (pos->str[2] == 'n' || pos->str[2] == 'N') {
                num = NAN;
                sym->undef_num_ex = 1;
                pos->str += 3;
            }
        }
    }
    return num;
}

void check_space_btw_specs(positions *pos) {
    char *fmt_end;
    fmt_end = s21_memchr(pos->fmt, '%', s21_strlen(pos->fmt));
    if (fmt_end != NULL) {
        int k = 0;
        k = fmt_end - pos->fmt;
        for (int i  = 0; i < k; i++) {
            if (pos->str[i] == pos->fmt[i]) {
                pos->fmt_lenght--;
            } else {
                pos->fmt_lenght = 0;
                break;
            }
        }
        pos->str += k;
        pos->fmt += k;
    } else {
        pos->fmt_lenght = 0;
    }
}

int check_signs_existence(positions *pos, symbols *sym) {
    int s = 0;
    if (pos->str[0] == '-') {
        sym->sign = -1;
        sym->sign_exists = 1;
        pos->str++;
        s++;
    } else if (pos->str[0] == '+') {
        pos->str++;
        sym->sign_exists = 1;
        s++;
    }
    return s;
}

void check_smlr(positions *pos) {
    while (*pos->str == *pos->fmt && *pos->str != '\0' && *pos->fmt != '\0') {
        pos->str++;
        pos->fmt++;
    }
}

void science_notation(positions *pos, symbols *sym, va_list args) {
    if ((*pos->str == 'e' || *pos->str == 'E') && sym->num_power_call == 0) {
        int sign = 0;
        pos->str++;
        sym->num_power = 0;
        sym->num_power_call = 1;
        sign = sym->sign;
        sym->sign = 1;
        sym->lenght = 'F';
        string_to_int(sym, pos, args);
        sym->sign = sign;
    }
}

void int_transform(symbols *sym, va_list args) {
    if (sym->lenght == 'h') {
        short *arg_short = va_arg(args, short*);
        if (arg_short != NULL) {
            *arg_short = (short)sym->val_to_transform;
            *arg_short *= sym->sign;
        }
    } else if (sym->lenght == 'l') {
        long *arg_short = va_arg(args, long*);
        if (arg_short != NULL) {
            *arg_short = (long)sym->val_to_transform;
            *arg_short *= sym->sign;
        }
    } else if (sym->lenght == 'M') {
        long long *arg_llint = va_arg(args, long long*);
        if (arg_llint != NULL) {
            *arg_llint = sym->val_to_transform;
            *arg_llint *= sym->sign;
        }
    } else if (sym->lenght == 'F') {
        sym->num_power = (int)sym->val_to_transform;
        sym->num_power *= sym->sign;
    } else {
        int *arg_int = va_arg(args, int*);
        if (arg_int != NULL) {
            *arg_int = (int)sym->val_to_transform;
            *arg_int *= sym->sign;
        }
    }
}

void unsig_transform(symbols *sym, va_list args) {
    if (sym->lenght == 'h') {
        unsigned short *arg_short = va_arg(args, unsigned short*);
        if (arg_short != NULL) {
            *arg_short = (unsigned short)(sym->val_to_transform * sym->sign);
        }
    } else if (sym->lenght == 'l') {
        unsigned long *arg_short = va_arg(args, unsigned long*);
        if (arg_short != NULL) {
            *arg_short = (unsigned long)(sym->val_to_transform * sym->sign);
        }
    } else if (sym->lenght == 'M') {
        unsigned long long *arg_llint = va_arg(args, unsigned long long*);
        if (arg_llint != NULL) {
            *arg_llint = (unsigned long long)(sym->val_to_transform * sym->sign);
        }
    } else {
        unsigned int *arg_int = va_arg(args, unsigned int*);
        if (arg_int != NULL) {
            *arg_int = (unsigned int)(sym->val_to_transform * sym->sign);
        }
    }
}

void float_transform(symbols *sym, va_list args) {
    if (sym->lenght == 'L') {
        long double *arg_ldouble = va_arg(args, long double*);
        if (arg_ldouble != NULL) {
            *arg_ldouble = sym->val_ld_to_transform;
            if (sym->sign == -1 && sym->width != 1)
                *arg_ldouble = sym->val_ld_to_transform * sym->sign;
        }
    } else if (sym->lenght == 'l') {
        double *arg_double = va_arg(args, double*);
        if (arg_double != NULL) {
            *arg_double = (double)sym->val_ld_to_transform;
            if (sym->sign == -1 && sym->width != 1)
                *arg_double = (double)(sym->val_ld_to_transform * sym->sign);
        }
    } else {
        float *arg_float = va_arg(args, float*);
        if (arg_float != NULL) {
            *arg_float = (float)sym->val_ld_to_transform;
            if (sym->sign == -1 && sym->width != 1)
                *arg_float = (float)(sym->val_ld_to_transform * sym->sign);
        }
    }
}

int check_spaces(const char *str) {
    int res = 0, i = 0;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
        res++;
        i++;
    }
    if (res == (int)s21_strlen(str) || s21_strlen(str) == 0) {
        res = 1;
    }
    return res;
}
