#include "s21_string.h"
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int answ = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (*((char*)str1 + i) != *((char*)str2 + i)) {
            answ = *((char*)str1 + i) - *((char*)str2 + i);
            break;
        }
    }
    #if defined(__linux__)
    if (answ < 0)
        answ = -1;
    if (answ > 0)
        answ = 1;
    #endif
    return answ;
}
