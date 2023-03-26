#include "s21_tests.h"
#include "s21_string.h"
START_TEST(MEMCHRTest) {
    char str1[10] = "Hello";
    char str2[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1, 'H', 5), memchr(str1, 'H', 5), 5);
    ck_assert_msg(s21_memchr(str1, 'h', 5) == S21_NULL, "Failed: Str == NULL");
    ck_assert_msg(s21_memchr(str2, 'h', 5) == S21_NULL, "Failed: Str == NULL");
    ck_assert_mem_eq(s21_memchr(str2, 'l', 5), memchr(str2, 'l', 5), 3);
    ck_assert_mem_eq(s21_memchr(str2, 'l', 0), memchr(str2, 'l', 0), 0);
}
END_TEST

START_TEST(MEMCMPTest) {
    char str1[] = "School21";
    char str2[] = "School21";
    char str3[] = "Schol";
    char str4[] = "";
    char str5[] = "";
    char str6[] = "test\0test";
    char str7[] = "test";
    ck_assert_int_eq(s21_memcmp(str1, str2, 8), memcmp(str1, str2, 8));
    ck_assert_int_gt(s21_memcmp(str1, str3, 5), 0);
    ck_assert_int_lt(s21_memcmp(str3, str1, 6), 0);
    ck_assert_int_eq(s21_memcmp(str1, str3, 3), memcmp(str1, str3, 3));
    ck_assert_int_gt(s21_memcmp(str1, str4, 8), 0);
    ck_assert_int_gt(s21_memcmp(str4, str5, 5), 0);
    ck_assert_int_eq(s21_memcmp(str1, str3, 0), memcmp(str1, str3, 0));
    ck_assert_int_eq(s21_memcmp(str6, str7, 10), memcmp(str6, str7, 10));
}
END_TEST

START_TEST(MEMCPYTest) {
    char *str1 = "School21";
    char *str2 = "School21 School21";
    char *str3 = "Sco\0ol21";
    char dest1[20];
    char dest2[20];
    ck_assert_mem_eq(s21_memcpy(dest1, str1, 8), memcpy(dest2, str1, 8), 8);
    ck_assert_mem_eq(s21_memcpy(dest1, str2, 17), memcpy(dest2, str2, 17), 17);
    ck_assert_mem_eq(s21_memcpy(dest1, str1, 8), memcpy(dest2, str1, 8), 0);
    ck_assert_mem_eq(s21_memcpy(dest1, str3, 9), memcpy(dest2, str3, 9), 9);
    ck_assert_mem_eq(s21_memcpy(dest1, str1, 3), memcpy(dest2, str1, 3), 3);
}
END_TEST

START_TEST(MEMMOVETest) {
    char dest1[20] = "qwe";
    char dest2[20] = "qwe";
    char dest3[20] = "zzz";
    char *str1 = "School21";
    char *str2 = "School\0";
    ck_assert_mem_eq(s21_memmove(dest1, str1, 8), memmove(dest2, str1, 8), 11);
    ck_assert_mem_eq(s21_memmove(dest1 + 2, str1, 8), memmove(dest2 + 2, str1, 8), 11);
    ck_assert_mem_eq(s21_memmove(dest1, str1, 3), memmove(dest2, str1, 3), 3);
    ck_assert_mem_eq(s21_memmove(dest1, str1, 0), memmove(dest2, str1, 0), 3);
    ck_assert_mem_eq(s21_memmove(dest1, str2, 7), memmove(dest2, str2, 7), 7);
    ck_assert_mem_eq(s21_memmove(dest3, str1, 10), memmove(dest3, str1, 8), 8);
}
END_TEST

START_TEST(MEMSETTest) {
    char str1[20] = "1234567890";
    char str2[20] = "1234567890";
    char str3[20] = "qwertyjuio";
    ck_assert_mem_eq(s21_memset(str1, '1', 10), memset(str2, '1', 10), 10);
    ck_assert_mem_eq(s21_memset(str1, '1', 5), memset(str2, '1', 5), 10);
    ck_assert_mem_eq(s21_memset(str1, '\0', 5), memset(str2, '\0', 5), 10);
    ck_assert_mem_eq(s21_memset(str1, 'q', 8), memset(str2, 'q', 8), 10);
    ck_assert_mem_eq(s21_memset(str1 + 2, 'q', 8), memset(str3 + 2, 'q', 8), 10);
}
END_TEST

START_TEST(STRCATTest) {
    char str1[1024] = "first string ";
    char str2[1024] = "second string";
    char str3[1024] = "";
    char str4[1024] = "q w e r t y     ";
    char str5[1024] = "\n\0";
    char str6[1024] = "qwerty\0qwerty";
    ck_assert_str_eq(s21_strcat(str1, str2), strcat(str1, str2));
    ck_assert_str_eq(s21_strcat(str3, str1), strcat(str3, str1));
    ck_assert_str_eq(s21_strcat(str3, str1), strcat(str3, str1));
    ck_assert_str_eq(s21_strcat(str4, str1), strcat(str4, str1));
    ck_assert_str_eq(s21_strcat(str5, str1), strcat(str5, str1));
    ck_assert_str_eq(s21_strcat(str5, str6), strcat(str5, str6));
}
END_TEST

START_TEST(STRNCATTest) {
    char str1[1024] = "School21";
    char str2[] = "School42";
    char str3[1024] = "";
    char str4[] = "School21\0School21";
    ck_assert_str_eq(s21_strncat(str1, str2, 8), strncat(str1, str2, 8));
    ck_assert_str_eq(s21_strncat(str1, str2, 3), strncat(str1, str2, 3));
    ck_assert_str_eq(s21_strncat(str3, str2, 8), strncat(str3, str2, 8));
    ck_assert_str_eq(s21_strncat(str1, str4, 17), strncat(str1, str4, 17));
    ck_assert_str_eq(s21_strncat(str1, str2, 10), strncat(str1, str2, 10));
}
END_TEST

START_TEST(STRCHRTest) {
    char str1[] = "School 21";
    char str2[] = "";
    int c = 'o';
    int c1 = 'h';
    int c2 = ' ';
    int c3 = '\0';
    ck_assert_str_eq(s21_strchr(str1, c), strchr(str1, c));
    ck_assert_str_eq(s21_strchr(str1, c1), strchr(str1, c1));
    ck_assert_str_eq(s21_strchr(str1, c2), strchr(str1, c2));
    ck_assert_str_eq(s21_strchr(str1, c3), strchr(str1, c3));
    ck_assert_str_eq(s21_strchr(str2, c3), strchr(str2, c3));
}
END_TEST

START_TEST(STRCMPTest) {
    char str1[10] = "School21";
    char str2[10] = "School21";
    char str3[10] = "School42";
    char str4[10] = "";
    char str5[10] = "";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
    ck_assert_int_eq(s21_strcmp(str1, str3), strcmp(str1, str3));
    ck_assert_int_eq(s21_strcmp(str1, str4), strcmp(str1, str4));
    ck_assert_int_eq(s21_strcmp(str4, str1), strcmp(str4, str1));
    ck_assert_int_eq(s21_strcmp(str4, str5), strcmp(str4, str5));
}
END_TEST

START_TEST(STRNCMPTest) {
    char *str1 = "School21";
    char *str2 = "School21";
    char *str3 = "";
    char *str4 = "";
    char *str5 = "qwerty";
    char *str6 = "School21\0School21";
    ck_assert_int_eq(s21_strncmp(str1, str2, 8), strncmp(str1, str2, 8));
    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
    ck_assert_int_eq(s21_strncmp(str3, str4, 3), strncmp(str3, str4, 3));
    ck_assert_int_eq(s21_strncmp(str1, str4, 8), strncmp(str1, str4, 8));
    ck_assert_int_eq(s21_strncmp(str1, str5, 8), strncmp(str1, str5, 8));
    ck_assert_int_eq(s21_strncmp(str1, str6, 17), strncmp(str1, str6, 17));
}
END_TEST

START_TEST(STRCPYTest) {
    char str1[20] = "School21";
    char str1_1[20] = "";
    char str1_2[20] = "\0";
    char str2[20];
    char str3[20];
    char str4[20] = "qwerty";
    char str5[20] = "qwerty";
    ck_assert_str_eq(s21_strcpy(str2, str1), strcpy(str3, str1));
    ck_assert_str_eq(s21_strcpy(str2, str1_1), strcpy(str3, str1_1));
    ck_assert_str_eq(s21_strcpy(str4, str1), strcpy(str5, str1));
    ck_assert_str_eq(s21_strcpy(str1, str1_2), strcpy(str1, str1_2));
}
END_TEST

START_TEST(STRNCPYTest) {
    char str1[1024] = "School21";
    char str2[] = " School42";
    char str3[1024] = "";
    char str4[1024] = " Sch\0ool42";
    ck_assert_str_eq(s21_strncpy(str1, str2, 9), strncpy(str1, str2, 9));
    ck_assert_str_eq(s21_strncpy(str1, str2, 3), strncpy(str1, str2, 3));
    ck_assert_str_eq(s21_strncpy(str3, str2, 9), strncpy(str3, str2, 9));
    ck_assert_str_eq(s21_strncpy(str1, str4, 9), strncpy(str1, str4, 9));
}
END_TEST

START_TEST(STRCSPNTest) {
    char str1[20] = "School21";
    char str2[20] = "qwerty";
    char str3[20] = "qwe2";
    char str4[20] = "";
    char str5[20] = "\0";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
    ck_assert_int_eq(s21_strcspn(str1, str3), strcspn(str1, str3));
    ck_assert_int_eq(s21_strcspn(str1, str4), strcspn(str1, str4));
    ck_assert_int_eq(s21_strcspn(str1, str5), strcspn(str1, str5));
    ck_assert_int_eq(s21_strcspn(str5, str1), strcspn(str5, str1));
}
END_TEST

START_TEST(STRERRORTest) {
    for (int i = -100; i < 200; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(STRLENTest) {
    char *str1 = "School21";
    char *str2 = "School      21";
    char *str3 = "";
    char *str4 = "School21\0School21";
    ck_assert_int_eq(s21_strlen(str1), strlen(str1));
    ck_assert_int_eq(s21_strlen(str2), strlen(str2));
    ck_assert_int_eq(s21_strlen(str3), strlen(str3));
    ck_assert_int_eq(s21_strlen(str4), strlen(str4));
}
END_TEST

START_TEST(STRPBRKTest) {
    char str1[20] = "School21 cool";
    char str2[20] = "School21 cool";
    ck_assert_str_eq(s21_strpbrk(str1, "cool"), strpbrk(str2, "cool"));
    ck_assert_str_eq(s21_strpbrk(str1, " "), strpbrk(str2, " "));
    ck_assert_str_eq(s21_strpbrk(str1, "o"), strpbrk(str2, "o"));
    ck_assert_ptr_eq(s21_strpbrk(str1, "qw"), strpbrk(str2, "qw"));
    ck_assert_ptr_eq(s21_strpbrk(str1, ""), strpbrk(str2, ""));
}
END_TEST

START_TEST(STRRCHRTest) {
    char str1[20] = "School21";
    char c1 = 'o';
    char c2 = 'p';
    char c3 = '\0';
    ck_assert_ptr_eq(s21_strrchr(str1, c1), strrchr(str1, c1));
    ck_assert_ptr_eq(s21_strrchr(str1, c2), strrchr(str1, c2));
    ck_assert_ptr_eq(s21_strrchr(str1, c3), strrchr(str1, c3));
}
END_TEST

START_TEST(STRSPNTest) {
    char str1[20] = "School21";
    char str2[20] = "56452";
    char str3[20] = "qwe";
    char str4[20] = "wgngofun2njnp1";
    ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
    ck_assert_int_eq(s21_strspn(str1, str3), strspn(str1, str3));
    ck_assert_int_eq(s21_strspn(str1, str4), strspn(str1, str4));
}
END_TEST

START_TEST(STRSTRTest) {
    char str1[20] = "School21";
    char str2[20] = "Sch";
    char str3[20] = "";
    char str4[20] = "qwe";
    char str5[30] = "School21 qwerty School21";
    ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
    ck_assert_str_eq(s21_strstr(str1, str3), strstr(str1, str3));
    ck_assert_ptr_eq(s21_strstr(str1, str4), strstr(str1, str4));
    ck_assert_ptr_eq(s21_strstr(str5, str1), strstr(str5, str1));
}
END_TEST

START_TEST(STRTOKTest) {
    char str[30] = "test1/test2/test3/test4";
    char delim1[10] = "/";
    char delim2[10] = ",";
    char delim3[10] = "t";
    ck_assert_str_eq(s21_strtok(str, delim1), strtok(str, delim1));
    ck_assert_str_eq(s21_strtok(str, delim2), strtok(str, delim2));
    ck_assert_ptr_eq(s21_strtok(str, delim3), strtok(str, delim3));
}
END_TEST

START_TEST(TO_UPPERTest) {
    char str1[10] = "School21";
    char str2[10] = "";
    char* str3 = S21_NULL;
    ck_assert_str_eq(s21_to_upper(str1), "SCHOOL21");
    ck_assert_str_eq(s21_to_upper(str2), "");
    ck_assert_ptr_eq(s21_to_upper(str3), NULL);
}
END_TEST

START_TEST(TO_LOWERTest) {
    char str1[10] = "SCHOOL21";
    char str2[10] = "";
    char* str3 = S21_NULL;
    ck_assert_str_eq(s21_to_lower(str1), "school21");
    ck_assert_str_eq(s21_to_lower(str2), "");
    ck_assert_ptr_eq(s21_to_lower(str3), NULL);
}
END_TEST

START_TEST(INSERTTest) {
    char src1[10] = "abcd";
    char str1[10] = "qwerty";
    ck_assert_str_eq(s21_insert(src1, str1, 2), "qwabcderty");
}
END_TEST

START_TEST(TRIMTest) {
    char *str1 = "WoW, I love it!";
    char *str2 = "WoW, I love it!W";
    char *str3 = NULL;
    char *str4 = "     1";
    char *trim1 = "W";
    char *trim2 = "P";
    char *trim3 = "WoW, I love it!";
    char *trim4 = NULL;
    char *trim5 = " ";
    ck_assert_str_eq(s21_trim(str1, trim1), "oW, I love it!");
    ck_assert_str_eq(s21_trim(str2, trim1), "oW, I love it!");
    ck_assert_str_eq(s21_trim(str2, trim2), "WoW, I love it!W");
    ck_assert_str_eq(s21_trim(str1, trim3), "");
    ck_assert_str_eq(s21_trim(str1, trim4), "WoW, I love it!");
    ck_assert_ptr_eq(s21_trim(str3, trim3), NULL);
    ck_assert_str_eq(s21_trim(str4, trim5), "1");
}
END_TEST

Suite *suite_string() {
    Suite *s = suite_create("Test_string");
    TCase *memchr_test = tcase_create("MEMCHR");
    TCase *memcmp_test = tcase_create("MEMCMP");
    TCase *memcpy_test = tcase_create("MEMCPY");
    TCase *memmove_test = tcase_create("MEMMOVE");
    TCase *memset_test = tcase_create("MEMSET");
    TCase *strcat_test = tcase_create("STRCAT");
    TCase *strncat_test = tcase_create("STRNCAT");
    TCase *strchr_test = tcase_create("STRCHR");
    TCase *strcmp_test = tcase_create("STRCMP");
    TCase *strncmp_test = tcase_create("STRNCMP");
    TCase *strcpy_test = tcase_create("STRCPY");
    TCase *strncpy_test = tcase_create("STRNCPY");
    TCase *strcspn_test = tcase_create("STRCSPN");
    TCase *strerror_test = tcase_create("STRERROR");
    TCase *strlen_test = tcase_create("STRLEN");
    TCase *strpbrk_test = tcase_create("STRPBRK");
    TCase *strrchr_test = tcase_create("STRRCHR");
    TCase *strspn_test = tcase_create("STRSPN");
    TCase *strstr_test = tcase_create("STRSTR");
    TCase *strtok_test = tcase_create("STRTOK");
    TCase *to_upper_test = tcase_create("TO_UPPERTest");
    TCase *to_lower_test = tcase_create("TO_LOWERTest");
    TCase *insert_test = tcase_create("INSERTTest");
    TCase *trim_test = tcase_create("TRIMTest");
    suite_add_tcase(s, memchr_test);
    tcase_add_test(memchr_test, MEMCHRTest);
    suite_add_tcase(s, memcmp_test);
    tcase_add_test(memchr_test, MEMCMPTest);
    suite_add_tcase(s, memcpy_test);
    tcase_add_test(memcpy_test, MEMCPYTest);
    suite_add_tcase(s, memmove_test);
    tcase_add_test(memmove_test, MEMMOVETest);
    suite_add_tcase(s, memset_test);
    tcase_add_test(memset_test, MEMSETTest);
    suite_add_tcase(s, strcat_test);
    tcase_add_test(strcat_test, STRCATTest);
    suite_add_tcase(s, strncat_test);
    tcase_add_test(strncat_test, STRNCATTest);
    suite_add_tcase(s, strchr_test);
    tcase_add_test(strchr_test, STRCHRTest);
    suite_add_tcase(s, strcmp_test);
    tcase_add_test(strcmp_test, STRCMPTest);
    suite_add_tcase(s, strncmp_test);
    tcase_add_test(strncmp_test, STRNCMPTest);
    suite_add_tcase(s, strcpy_test);
    tcase_add_test(strcpy_test, STRCPYTest);
    suite_add_tcase(s, strncpy_test);
    tcase_add_test(strncpy_test, STRNCPYTest);
    suite_add_tcase(s, strcspn_test);
    tcase_add_test(strcspn_test, STRCSPNTest);
    suite_add_tcase(s, strerror_test);
    tcase_add_test(strerror_test, STRERRORTest);
    suite_add_tcase(s, strlen_test);
    tcase_add_test(strlen_test, STRLENTest);
    suite_add_tcase(s, strpbrk_test);
    tcase_add_test(strpbrk_test, STRPBRKTest);
    suite_add_tcase(s, strrchr_test);
    tcase_add_test(strrchr_test, STRRCHRTest);
    suite_add_tcase(s, strspn_test);
    tcase_add_test(strspn_test, STRSPNTest);
    suite_add_tcase(s, strstr_test);
    tcase_add_test(strstr_test, STRSTRTest);
    suite_add_tcase(s, strtok_test);
    tcase_add_test(strtok_test, STRTOKTest);
    suite_add_tcase(s, to_upper_test);
    tcase_add_test(to_upper_test, TO_UPPERTest);
    suite_add_tcase(s, to_lower_test);
    tcase_add_test(to_lower_test, TO_LOWERTest);
    suite_add_tcase(s, insert_test);
    tcase_add_test(insert_test, INSERTTest);
    suite_add_tcase(s, trim_test);
    tcase_add_test(trim_test, TRIMTest);
    return s;
}
