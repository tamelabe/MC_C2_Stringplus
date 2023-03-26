#include "s21_string.h"
char* s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0, j = 0;
    while (dest[i])
        i++;
    while (j < n && src[j]) {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}
