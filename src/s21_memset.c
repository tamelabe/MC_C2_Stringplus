#include "s21_string.h"
void *s21_memset(void *str, int c, s21_size_t n) {
    if (str) {
        char* tmp = (char*)str;
        while (n--)
            *tmp++ = c;
    }
    return str;
}
