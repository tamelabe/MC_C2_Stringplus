#include "s21_string.h"
char *s21_strerror(int errnum) {
    static char *arr[] = error;
    static char res[100];
    int i = 15;
    if (errnum < 0 || errnum > N) {
        int del;
        char ost[10]= "";
        #if defined (__APPLE__) && defined(__MACH__)
        char str[40] = "Unknown error: ";
        #elif defined(__linux__)
        char str[40] = "Unknown error ";
        i--;
        #endif
        s21_memcpy(res, str, i);
        if (errnum < 0) {
            del = errnum * (-1);
            s21_memcpy(res + i, "-", 1);
            i++;
        } else {
            del = errnum;
        }
        int n = 0;
        while (del / 10 != 0) {
            ost[n] = del % 10 + 48;
            del = del / 10;
            n++;
        }
        ost[n] = del + 48;
        for (int j = n; j >= 0; j--) {
            s21_memcpy(res + i, ost + j, 1);
            i++;
        }
        res[i] = '\0';
    } else {
        for (s21_size_t i = 0; i < 101; i++) {
            res[i] = '\0';
        }
        s21_memcpy(res, arr[errnum], s21_strlen(arr[errnum]));
    }
    return res;
}
