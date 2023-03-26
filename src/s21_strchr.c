#include "s21_string.h"
char *s21_strchr(const char *str, int c) {
    const char* pos = S21_NULL;
    while (*str) {
        if (*str == c) {
            break;
        }
        str++;
    }
    if (*str == c) {
        pos = str;
    }
    return (char *) pos;
}
