#include "s21_string.h"
void *s21_to_upper(const char *str) {
    s21_size_t i;
    char* buf = S21_NULL;
    if (str != S21_NULL) {
        buf = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
        for (i = 0; *str; str++, i++) {
            if (*str > 96 && *str < 123) {
            *(buf + i) = *(str) - 32;
            } else {
                *(buf + i) = *(str);
            }
        }
        *(buf + i) = '\0';
    }
    return buf;
}
