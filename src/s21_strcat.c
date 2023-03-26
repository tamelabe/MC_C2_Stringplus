#include "s21_string.h"
char *s21_strcat(char *dest, const char *src) {
    s21_size_t l = s21_strlen(dest);
    int x = 0;
    for (int i = 0 ; src[i] != '\0' ; i++) {
        dest[l + i] = src[i];
        x++;
    }
    dest[l + x] = '\0';
    return dest;
}
