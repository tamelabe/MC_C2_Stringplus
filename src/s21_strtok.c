#include "s21_string.h"
char *s21_strtok(char *str, const char *delim) {
    static char* next;
    char* result = S21_NULL;
    if (*str) {
        next = str;
        while (*next && s21_strchr(delim, *next))
            *next = '\0';
    }
    if (!*next) {
        result = S21_NULL;
    } else {
        str = next;
        while (*next && !s21_strchr(delim, *next))
            ++next;
        while (*next && s21_strchr(delim, *next))
            *next++ = '\0';
        result = str;
    }
    return result;
}
