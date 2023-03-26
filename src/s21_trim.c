#include "s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
    char *res = S21_NULL;
    if (src != S21_NULL) {
        if (trim_chars != S21_NULL && *trim_chars) {
            s21_size_t trim_chars_len = s21_strlen(trim_chars);
            s21_size_t src_len = s21_strlen(src);
            s21_size_t start_index = 0;
            s21_size_t end_index = src_len;
            s21_size_t count_memory;
            for (s21_size_t i = 0; i <= src_len; i++) {
                s21_size_t count = 0;
                for (s21_size_t j = 0; j <= trim_chars_len; j++) {
                    if (src[i] == trim_chars[j]) {
                        start_index++;
                        break;
                    }
                    count++;
                }
                if (count == trim_chars_len + 1) {
                    break;
                }
            }
            if (start_index < (src_len / 2) + 1) {
                for (s21_size_t i = src_len - 1; i != 0; i--) {
                    s21_size_t count = 0;
                    for (s21_size_t j = 0; j < trim_chars_len; j++) {
                        if (src[i] == trim_chars[j]) {
                            end_index--;
                            break;
                        }
                        count++;
                    }
                    if (count == trim_chars_len) {
                        break;
                    }
                }
                count_memory = src_len - start_index - (src_len - end_index);
            } else {
                count_memory = src_len - start_index + 1;
            }
            res = (char*)malloc((count_memory + 1) * sizeof(char));
            for (s21_size_t i = 0; i < count_memory; i++) {
                res[i] = src[start_index + i];
            }
            res[count_memory] = '\0';
        } else {
            res = s21_trim(src, " \t\n");
        }
    }
    return res;
}
