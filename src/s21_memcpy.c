#include "s21_string.h"
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char* _dest = (unsigned char*)dest;
    const unsigned char* _src = (const unsigned char*)src;
    while (n--) {
        *_dest++ = *_src++;
    }
    return dest;
}
