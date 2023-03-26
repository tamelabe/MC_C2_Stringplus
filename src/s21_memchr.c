#include "s21_string.h"
void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *ptr = (unsigned char*) str;
    char* flag = S21_NULL;
    for (s21_size_t i = 0; i < n && ptr; i++) {
        if (*ptr == (unsigned char)c) {
            flag = (char*)str + i;
            break;
        }
        ptr++;
    }
    return flag;
}