#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
    const char *buf;
    int flag = 0;
    int len = 0;
    while (*(needle + len)) {
        len++;
        }
        if (len == 0) {
            buf = haystack;
            flag = 1;
        } else {
            while (*haystack) {
                if (*haystack == *needle) {
                    int j = 0;
                    while (*haystack == *(needle + j) && *(needle + j) != '\0') {
                        j++;
                        haystack++;
                    }
                    if (j == len) {
                        flag = 1;
                        haystack = haystack - len;
                        break;
                    }
                } else {
                    haystack++;
                }
            }
            buf = haystack;
        }
    if (!flag) {
        buf = S21_NULL;
    }
    return (char*)buf;
}

