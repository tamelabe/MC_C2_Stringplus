#include "s21_string.h"
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char* _dest = (char*)dest;
    const char* _src = (char*)src;
    char *tmp = (char*)malloc(sizeof(char) * n);
    if (tmp) {
        s21_memcpy(tmp, _src, n);
        s21_memcpy(_dest, tmp, n);
        free(tmp);
    }
    return dest;
}
