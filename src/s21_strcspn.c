#include "s21_string.h"
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len1 = s21_strlen(str1);
    s21_size_t len2 = s21_strlen(str2);
    s21_size_t i;
    s21_size_t count;
    s21_size_t flag = 0;
    for (i = 0; i < len1; i++) {
        if (flag) {
            break;
        }
        for (s21_size_t j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                count = i;
                flag++;
                break;
            }
        }
    }
    if (!flag) {
        count = i;
    }
    return count;
}
