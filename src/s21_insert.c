#include "s21_string.h"
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = S21_NULL;
    if (src != S21_NULL && str != S21_NULL) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t str_len = s21_strlen(str);
        s21_size_t new_len = src_len + str_len;
        if (str_len >= start_index)
            res = (char *)malloc(sizeof(char) * new_len + 1);
        if (res) {
            for (s21_size_t i = 0, j = 0, m = 0; i < new_len; i++) {
                if (i >= start_index && j < src_len) {
                    res[i] = src[j];
                    j++;
                } else {
                    res[i] = str[m];
                    m++;
                }
            }
            res[new_len] = '\0';
        }
    }
    return res;
}
