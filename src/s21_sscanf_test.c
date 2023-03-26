// #include "s21_tests.h"
#include <check.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include "s21_sscanf.h"

START_TEST(SSCANFTest1) {
    int num1;
    int num2;
    s21_sscanf("123", "%d", &num1);
    sscanf("123", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest2) {
    int num1;
    int num2;
    s21_sscanf("123", "%10d", &num1);
    sscanf("123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest3) {
    int num1;
    int num2;
    s21_sscanf("-123", "%10d", &num1);
    sscanf("-123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest4) {
    int num1;
    int num2;
    s21_sscanf("-123", "%10d", &num1);
    sscanf("-123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest5) {
    int num1;
    int num2;
    s21_sscanf("-123", "%d", &num1);
    sscanf("-123", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest6) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("-123", "%1d", &num1);
    sscanf("-123", "%1d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest7) {
    int num1;
    int num2;
    s21_sscanf("123", "%1d", &num1);
    sscanf("123", "%1d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest8) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("||||||123|||---dqwdsc23;;;alq.vmfj", "%d", &num1);
    sscanf("||||||123|||---dqwdsc23;;;alq.vmfj", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST


START_TEST(SSCANFTest9) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("qwe|||---dqwdsc23;;;alq.vmfj", "%d", &num1);
    sscanf("qwe|||---dqwdsc23;;;alq.vmfj", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest10) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("        'ds;fsdlsdfks;df", "%4d", &num1);
    sscanf("        'ds;fsdlsdfks;df", "%4d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest11) {
    int num1;
    int num2;
    char a, b;
    s21_sscanf("123 qwe", "%4d%c", &num1, &a);
    sscanf("123 qwe", "%4d%c", &num2, &b);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest12) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("123 123", "%*d%d", &num1);
    sscanf("123 123", "%*d%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest13) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("as q12", "%*d%d", &num1);
    sscanf("fd qwe", "%*d%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest14) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("as q12", "%*i%i", &num1);
    sscanf("fd qwe", "%*i%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest15) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123214214 q12", "%*i%i", &num1);
    sscanf("123214214 qwe", "%*i%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest16) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123214214", "%i", &num1);
    sscanf("123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest17) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-123214214", "%i", &num1);
    sscanf("-123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest18) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("-123214214", "%i", &num1);
    sscanf("-123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest19) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("qwdwq wef 123", "%i", &num1);
    sscanf("qwdwq wef 123", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest20) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest23) {
    char a;
    char b;
    s21_sscanf("qwd", "%c", &a);
    sscanf("qwd", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest24) {
    char a;
    char b;
    s21_sscanf("qwd", "%c", &a);
    sscanf("qwd", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST



START_TEST(SSCANFTest25) {
    char a;
    char b;
    s21_sscanf("f", "%c", &a);
    sscanf("f", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest26) {
    char a;
    char b;
    s21_sscanf(" ", "%c", &a);
    sscanf(" ", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest27) {
    char a;
    char b;
    s21_sscanf("123", "%1c", &a);
    sscanf("123", "%1c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest28) {
    char a;
    char b;
    s21_sscanf(" 1", "%1c", &a);
    sscanf(" 1", "%1c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest29) {
    char a[1024] = "HEllo";
    char b[1024] = "HEllo";
    s21_sscanf("HEllo", "%s", a);
    sscanf("HEllo", "%s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest30) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf("HEllo", "%2s", a);
    sscanf("HEllo", "%2s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest31) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf("123 123", "%2s", a);
    sscanf("123 123", "%2s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest32) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest33) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest34) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest35) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest36) {
    //
    float a = 0;
    float b = 0;
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10f", &a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest37) {
    float a = 0;
    float b = 0;
    s21_sscanf("12.213213123", "%1f", &a);
    sscanf("12.213213123", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest38) {
    //
    float a = 0;
    float b = 0;
    s21_sscanf("-12.213213123", "%1f", &a);
    sscanf("-12.213213123", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest39) {
    float a = 0;
    float b = 0;
    s21_sscanf("-12.2132131231qwd", "%1f", &a);
    sscanf("-12.2132131231qwd", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest40) {
    //
    float a = 0;
    float b = 0;
    s21_sscanf("0.00000000000001", "%1f", &a);
    sscanf("0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest41) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.00000000000001", "%1f", &a);
    sscanf("0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest42) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000000001", "%1f", &a);
    sscanf("-0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest43) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%1f", &a);
    sscanf("-0.0000000000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest44) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%10f", &a);
    sscanf("-0.0000000000000000001", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest45) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%10f", &a);
    sscanf("-0.0000000000000000001", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest46) {
    float a = 0;
    float b = 0;
    s21_sscanf("1123.2332", "%10e", &a);
    sscanf("1123.2332", "%10e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest47) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%10e", &a);
    sscanf("-1123.2332", "%10e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest48) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%E", &a);
    sscanf("-1123.2332", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest49) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000000001", "%15E", &a);
    sscanf("0.0000000000000001", "%15E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST



START_TEST(SSCANFTest50) {
    float a = 0;
    float b = 0;
    s21_sscanf("1E42", "%E", &a);
    sscanf("1E42", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest51) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%E", &a);
    sscanf("1e42", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest52) {
    float a = 0;
    float b = 0;
    s21_sscanf("1123.2332", "%10E", &a);
    sscanf("1123.2332", "%10E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest53) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%10E", &a);
    sscanf("-1123.2332", "%10E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest54) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%E", &a);
    sscanf("-1123.2332", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest55) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000000001", "%15E", &a);
    sscanf("0.0000000000000001", "%15E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST



START_TEST(SSCANFTest56) {
    float a = 0;
    float b = 0;
    s21_sscanf("1E42", "%e", &a);
    sscanf("1E42", "%e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest57) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%e", &a);
    sscanf("1e42", "%e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest58) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%g", &a);
    sscanf("1e42", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest59) {
    float a = 0;
    float b = 0;
    s21_sscanf("_+)-=p//./.?>./[p=.['1e42", "%g", &a);
    sscanf("_+)-=p//./.?>./[p=.['1e42", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST



START_TEST(SSCANFTest60) {
    float a = 0;
    float b = 0;
    s21_sscanf("3.141592653589793238462643383279502 _+)-=p//./.?>./[p=.['1e42", "%g", &a);
    sscanf("3.141592653589793238462643383279502 _+)-=p//./.?>./[p=.['1e42", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST



START_TEST(SSCANFTest61) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000001", "%g", &a);
    sscanf("0.0000000000001", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest62) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%g", &a);
    sscanf("-0.0000000000000001", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest63) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%15g", &a);
    sscanf("-0.0000000000000001", "%15g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest64) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%1g", &a);
    sscanf("-0.0000000000000001", "%1g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest65) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000001", "%G", &a);
    sscanf("-0.00000000001", "%G", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest66) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000001", "%G", &a);
    sscanf("0.0000000000001", "%G", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest67) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%G", &a);
    sscanf("-0.0000000000000001", "%G", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest68) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%15G", &a);
    sscanf("-0.0000000000000001", "%15G", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest69) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%1G", &a);
    sscanf("-0.0000000000000001", "%1G", &b);
    ck_assert_float_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest70) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000001", "%G", &a);
    sscanf("-0.00000000001", "%G", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest71) {
    int a = 0;
    int b = 0;
    char d, c;
    s21_sscanf("124s", "%o%c", &a, &d);
    sscanf("124s", "%o%c", &b, &c);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest72) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%o", &a);
    sscanf("-124", "%o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest73) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%10o", &a);
    sscanf("-124", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest74) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%10o", &a);
    sscanf("-124", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest75) {
    int a = 0;
    int b = 0;
    s21_sscanf("1", "%10o", &a);
    sscanf("1", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest76) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf("1", "%u", &a);
    sscanf("1", "%u", &b);
    ck_assert_int_eq(a, b);
}
END_TEST


START_TEST(SSCANFTest77) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf(" +123", "%u", &a);
    sscanf(" +123", "%u", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest78) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf("123", "%n", &a);
    sscanf("123", "%n", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest79) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123", "%x", &num1);
    sscanf("123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest80) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%3x", &num1);
    sscanf("123123", "%3x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest81) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%10x", &num1);
    sscanf("123123", "%10x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest82) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*x%x", &num1);
    sscanf("123 123", "%*x%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest83) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*x%d", &num1);
    sscanf("123 123", "%*x%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest84) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0x123 123", "%x", &num1);
    sscanf("0x123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest85) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0123 123", "%x", &num1);
    sscanf("0123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest86) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0X123 123", "%x", &num1);
    sscanf("0X123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest87) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-0X123 123", "%x", &num1);
    sscanf("-0X123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest88) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("qwe 123", "%x", &num1);
    sscanf("qwe 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest89) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCDEF 123", "%x", &num1);
    sscanf("ABCDEF 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest90) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCQADEF 123", "%x", &num1);
    sscanf("ABCQADEF 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest91) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("ABCDEF -A123", "%x%x", &num1, &num3);
    sscanf("ABCDEF -A123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest92) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("228228228 -A123", "%x%x", &num1, &num3);
    sscanf("228228228 -A123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest93) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+000123ABC -0123", "%x%x", &num1, &num3);
    sscanf("+000123ABC -0123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest94) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+0001§../23ABC -0mxzcmmz123q", "%x%x", &num1, &num3);
    sscanf("+0001§../23ABC -0mxzcmmz123q", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest95) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+123", "%x%x", &num1, &num3);
    sscanf("+123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest96) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("  000  000   ", "%x%x", &num1, &num3);
    sscanf("  000  000   ", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest97) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("120x211 0x", "%x%x", &num1, &num3);
    sscanf("120x211 0x", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest98) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("120x211 0x", "%x%s", &num1, s1);
    sscanf("120x211 0x", "%x%s", &num2, s2);
    ck_assert_int_eq(num1, num2);
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTest99) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("x120x211 0x", "%x", &num1);
    sscanf("x120x211 0x", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest100) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x211. 29", "%x%f", &num1, &f1);
    sscanf("x120x211. 29", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest101) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x21.1 2.9", "%x%f", &num1, &f1);
    sscanf("x120x21.1 2.9", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest102) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x-120x.21 12.9", "%x%f", &num1, &f1);
    sscanf("x-120x.21 12.9", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest103) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("2.9 020abxC21.1", "%x%f", &num1, &f1);
    sscanf("2.9 020abxC21.1", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest104) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123", "%X", &num1);
    sscanf("123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest105) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%3X", &num1);
    sscanf("123123", "%3X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest106) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%10X", &num1);
    sscanf("123123", "%10X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest107) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*X%X", &num1);
    sscanf("123 123", "%*X%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest108) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*X%d", &num1);
    sscanf("123 123", "%*X%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest109) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0x123 123", "%X", &num1);
    sscanf("0x123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest110) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0123 123", "%X", &num1);
    sscanf("0123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest111) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0X123 123", "%X", &num1);
    sscanf("0X123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest112) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-0X123 123", "%X", &num1);
    sscanf("-0X123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest113) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("qwe 123", "%X", &num1);
    sscanf("qwe 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest114) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCDEF 123", "%X", &num1);
    sscanf("ABCDEF 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest115) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCQADEF 123", "%X", &num1);
    sscanf("ABCQADEF 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest116) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("ABCDEF -A123", "%X%X", &num1, &num3);
    sscanf("ABCDEF -A123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest117) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("228228228 -A123", "%X%X", &num1, &num3);
    sscanf("228228228 -A123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest118) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+000123ABC -0123", "%X%X", &num1, &num3);
    sscanf("+000123ABC -0123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest119) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+0001§../23ABC -0mxzcmmz123q", "%X%X", &num1, &num3);
    sscanf("+0001§../23ABC -0mxzcmmz123q", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest120) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+123", "%X%X", &num1, &num3);
    sscanf("+123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest121) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("  000  000   ", "%X%X", &num1, &num3);
    sscanf("  000  000   ", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest122) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("120x211 0x", "%X%X", &num1, &num3);
    sscanf("120x211 0x", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SSCANFTest123) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("120x211 0x", "%X%s", &num1, s1);
    sscanf("120x211 0x", "%X%s", &num2, s2);
    ck_assert_int_eq(num1, num2);
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTest124) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("x120x211 0x", "%X", &num1);
    sscanf("x120x211 0x", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest125) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x211. 29", "%X%f", &num1, &f1);
    sscanf("x120x211. 29", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest126) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x21.1 2.9", "%X%f", &num1, &f1);
    sscanf("x120x21.1 2.9", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest127) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x-120x.21 12.9", "%X%f", &num1, &f1);
    sscanf("x-120x.21 12.9", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest128) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("2.9 020abxC21.1", "%X%f", &num1, &f1);
    sscanf("2.9 020abxC21.1", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SSCANFTest129) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("123", "%p", &p1);
    sscanf("123", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest130) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%p", &p1);
    sscanf("abc12g3", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest131) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%3p", &p1);
    sscanf("abc12g3", "%3p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest132) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3 abc22", "%*p%p", &p1);
    sscanf("abc12g3 abc22", "%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest133) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf(" abc12g3 abc22", " %*p%p", &p1);
    sscanf(" abc12g3 abc22", " %*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest134) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf(" abc12g3 abc22", "-%*p%p", &p1);
    sscanf(" abc12g3 abc22", "-%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest135) {
    char a, b;
    s21_sscanf("e", "%10c", &a);
    sscanf("e", "%10c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest136) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("+123", "%p", &a);
    sscanf("+123", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest137) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("0x0X", "%p", &a);
    sscanf("0x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest138) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("x0X", "%p", &a);
    sscanf("x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest139) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("-x0X", "%p", &a);
    sscanf("-x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SSCANFTest140) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("123", "%p", &p1);
    sscanf("123", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest141) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("abc12g3", "%p", &p1);
    sscanf("abc12g3", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest142) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("abc12g3", "%3p", &p1);
    sscanf("abc12g3", "%3p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest143) {
    void *p1 = 0;
    void *p2 = 0;

    s21_sscanf("abc12g3 abc22", "%*p%p", &p1);
    sscanf("abc12g3 abc22", "%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SSCANFTest144) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];

    s21_sscanf("abc12g3 abc22", "%p%s", &p1, s1);
    sscanf("abc12g3 abc22", "%p%s", &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTest145) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];

    s21_sscanf("abc12g3 abc22", "%s%p", s1, &p1);
    sscanf("abc12g3 abc22", "%s%p", s2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTest146) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];

    s21_sscanf("  abc12g3    abc22  ", "%s%p", s1, &p1);
    sscanf("  abc12g3    abc22  ", "%s%p", s2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SSCANFTest147) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 0000 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 0000 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest148) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 0x123cc 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 0x123cc 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest149) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 030xcc 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 030xcc 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest150) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 123ab±=-1//a 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 123ab±=-1//a 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest151) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc12g3 123ab±=-1//a 12", "%d%p", &num1, &p1);
    sscanf("abc12g3 123ab±=-1//a 12", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest152) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("abc1 2g3 12 3ab±=-1// a 12", "%d%p", &num1, &p1);
    sscanf("abc1 2g3 12 3ab±=-1// a 12", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest153) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("", "%d%p", &num1, &p1);
    sscanf("", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest154) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("10 abcdef123 qwe", "%d%4p%s", &num1, &p1, s1);
    sscanf("10 abcdef123 qwe", "%d%4p%s", &num2, &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest155) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;

    s21_sscanf("10 abcdef123 qwe", "%d%1p%s", &num1, &p1, s1);
    sscanf("10 abcdef123 qwe", "%d%1p%s", &num2, &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SSCANFTest156) {
    unsigned u1 = 0;
    unsigned u2 = 0;

    s21_sscanf("+z123", "%u", &u1);
    sscanf("+z123", "%u", &u2);
    ck_assert_int_eq(u1, u2);
}
END_TEST

Suite *suite_sscanf() {
    Suite *s = suite_create("Test_scanff");   // create test group

    TCase *test1 = tcase_create("test1");   // create test group case
    TCase *test2 = tcase_create("test2");   // create test group case
    TCase *test3 = tcase_create("test3");   // create test group case
    TCase *test4 = tcase_create("test4");   // create test group case
    TCase *test5 = tcase_create("test5");   // create test group case
    TCase *test6 = tcase_create("test6");   // create test group case
    TCase *test7 = tcase_create("test7");   // create test group case
    TCase *test8 = tcase_create("test8");   // create test group case
    TCase *test9 = tcase_create("test9");   // create test group case
    TCase *test10 = tcase_create("test10");   // create test group case
    TCase *test11 = tcase_create("test11");   // create test group case
    TCase *test12 = tcase_create("test12");   // create test group case
    TCase *test13 = tcase_create("test13");   // create test group case
    TCase *test14 = tcase_create("test14");   // create test group case
    TCase *test15 = tcase_create("test15");   // create test group case
    TCase *test16 = tcase_create("test16");   // create test group case
    TCase *test17 = tcase_create("test17");   // create test group case
    TCase *test18 = tcase_create("test18");   // create test group case
    TCase *test19 = tcase_create("test19");   // create test group case
    TCase *test20 = tcase_create("test20");   // create test group case
    TCase *test23 = tcase_create("test23");
    TCase *test24 = tcase_create("test24");
    TCase *test25 = tcase_create("test25");
    TCase *test26 = tcase_create("test26");
    TCase *test27 = tcase_create("test27");
    TCase *test28 = tcase_create("test28");
    TCase *test29 = tcase_create("test29");
    TCase *test30 = tcase_create("test30");
    TCase *test31 = tcase_create("test31");
    TCase *test32 = tcase_create("test32");
    TCase *test33 = tcase_create("test33");
    TCase *test34 = tcase_create("test34");
    TCase *test35 = tcase_create("test35");
    TCase *test36 = tcase_create("test36");
    TCase *test37 = tcase_create("test37");
    TCase *test38 = tcase_create("test38");
    TCase *test39 = tcase_create("test39");
    TCase *test40 = tcase_create("test40");
    TCase *test41 = tcase_create("test41");
    TCase *test42 = tcase_create("test42");
    TCase *test43 = tcase_create("test43");
    TCase *test44 = tcase_create("test44");
    TCase *test45 = tcase_create("test45");
    TCase *test46 = tcase_create("test46");
    TCase *test47 = tcase_create("test47");
    TCase *test48 = tcase_create("test48");
    TCase *test49 = tcase_create("test49");
    TCase *test50 = tcase_create("test50");
    TCase *test51 = tcase_create("test51");
    TCase *test52 = tcase_create("test52");
    TCase *test53 = tcase_create("test53");
    TCase *test54 = tcase_create("test54");
    TCase *test55 = tcase_create("test55");
    TCase *test56 = tcase_create("test56");
    TCase *test57 = tcase_create("test57");
    TCase *test58 = tcase_create("test58");
    TCase *test59 = tcase_create("test59");
    TCase *test60 = tcase_create("test60");
    TCase *test61 = tcase_create("test61");
    TCase *test62 = tcase_create("test62");
    TCase *test63 = tcase_create("test63");
    TCase *test64 = tcase_create("test64");
    TCase *test65 = tcase_create("test65");
    TCase *test66 = tcase_create("test66");
    TCase *test67 = tcase_create("test67");
    TCase *test68 = tcase_create("test68");
    TCase *test69 = tcase_create("test69");
    TCase *test70 = tcase_create("test70");
    TCase *test71 = tcase_create("test71");
    TCase *test72 = tcase_create("test72");
    TCase *test73 = tcase_create("test73");
    TCase *test74 = tcase_create("test74");
    TCase *test75 = tcase_create("test75");
    TCase *test76 = tcase_create("test76");
    TCase *test77 = tcase_create("test77");
    TCase *test78 = tcase_create("test78");
    TCase *test79 = tcase_create("test79");
    TCase *test80 = tcase_create("test80");
    TCase *test81 = tcase_create("test81");
    TCase *test82 = tcase_create("test82");
    TCase *test83 = tcase_create("test83");
    TCase *test84 = tcase_create("test84");
    TCase *test85 = tcase_create("test85");
    TCase *test86 = tcase_create("test86");
    TCase *test87 = tcase_create("test87");
    TCase *test88 = tcase_create("test88");
    TCase *test89 = tcase_create("test89");
    TCase *test90 = tcase_create("test90");
    TCase *test91 = tcase_create("test91");
    TCase *test92 = tcase_create("test92");
    TCase *test93 = tcase_create("test93");
    TCase *test94 = tcase_create("test94");
    TCase *test95 = tcase_create("test95");
    TCase *test96 = tcase_create("test96");
    TCase *test97 = tcase_create("test97");
    TCase *test98 = tcase_create("test98");
    TCase *test99 = tcase_create("test99");
    TCase *test100 = tcase_create("test100");
    TCase *test101 = tcase_create("test101");
    TCase *test102 = tcase_create("test102");
    TCase *test103 = tcase_create("test103");
    TCase *test104 = tcase_create("test104");
    TCase *test105 = tcase_create("test105");
    TCase *test106 = tcase_create("test106");
    TCase *test107 = tcase_create("test107");
    TCase *test108 = tcase_create("test108");
    TCase *test109 = tcase_create("test109");
    TCase *test110 = tcase_create("test110");
    TCase *test111 = tcase_create("test111");
    TCase *test112 = tcase_create("test112");
    TCase *test113 = tcase_create("test113");
    TCase *test114 = tcase_create("test114");
    TCase *test115 = tcase_create("test115");
    TCase *test116 = tcase_create("test116");
    TCase *test117 = tcase_create("test117");
    TCase *test118 = tcase_create("test118");
    TCase *test119 = tcase_create("test119");
    TCase *test120 = tcase_create("test120");
    TCase *test121 = tcase_create("test121");
    TCase *test122 = tcase_create("test122");
    TCase *test123 = tcase_create("test123");
    TCase *test124 = tcase_create("test124");
    TCase *test125 = tcase_create("test125");
    TCase *test126 = tcase_create("test126");
    TCase *test127 = tcase_create("test127");
    TCase *test128 = tcase_create("test128");
    TCase *test129 = tcase_create("test129");
    TCase *test130 = tcase_create("test130");
    TCase *test131 = tcase_create("test131");
    TCase *test132 = tcase_create("test132");
    TCase *test133 = tcase_create("test133");
    TCase *test134 = tcase_create("test134");
    TCase *test135 = tcase_create("test135");
    TCase *test136 = tcase_create("test136");
    TCase *test137 = tcase_create("test137");
    TCase *test138 = tcase_create("test138");
    TCase *test139 = tcase_create("test139");
    TCase *test140 = tcase_create("test140");
    TCase *test141 = tcase_create("test141");
    TCase *test142 = tcase_create("test142");
    TCase *test143 = tcase_create("test143");
    TCase *test144 = tcase_create("test144");
    TCase *test145 = tcase_create("test145");
    TCase *test146 = tcase_create("test146");
    TCase *test147 = tcase_create("test147");
    TCase *test148 = tcase_create("test148");
    TCase *test149 = tcase_create("test149");
    TCase *test150 = tcase_create("test150");
    TCase *test151 = tcase_create("test151");
    TCase *test152 = tcase_create("test152");
    TCase *test153 = tcase_create("test153");
    TCase *test154 = tcase_create("test154");
    TCase *test155 = tcase_create("test155");
    TCase *test156 = tcase_create("test156");

    suite_add_tcase(s, test1);   // add group case to group
    suite_add_tcase(s, test2);   // add group case to group
    suite_add_tcase(s, test3);   // add group case to group
    suite_add_tcase(s, test4);   // add group case to group
    suite_add_tcase(s, test5);   // add group case to group
    suite_add_tcase(s, test6);   // add group case to group
    suite_add_tcase(s, test7);   // add group case to group
    suite_add_tcase(s, test8);   // add group case to group
    suite_add_tcase(s, test9);   // add group case to group
    suite_add_tcase(s, test10);   // add group case to group
    suite_add_tcase(s, test11);   // add group case to group
    suite_add_tcase(s, test12);   // add group case to group
    suite_add_tcase(s, test13);   // add group case to group
    suite_add_tcase(s, test14);   // add group case to group
    suite_add_tcase(s, test15);   // add group case to group
    suite_add_tcase(s, test16);   // add group case to group
    suite_add_tcase(s, test17);   // add group case to group
    suite_add_tcase(s, test18);   // add group case to group
    suite_add_tcase(s, test19);   // add group case to group
    suite_add_tcase(s, test20);   // add group case to group
    suite_add_tcase(s, test23);
    suite_add_tcase(s, test24);
    suite_add_tcase(s, test25);
    suite_add_tcase(s, test26);
    suite_add_tcase(s, test27);
    suite_add_tcase(s, test28);
    suite_add_tcase(s, test28);
    suite_add_tcase(s, test29);
    suite_add_tcase(s, test30);
    suite_add_tcase(s, test31);
    suite_add_tcase(s, test32);
    suite_add_tcase(s, test33);
    suite_add_tcase(s, test34);
    suite_add_tcase(s, test35);
    suite_add_tcase(s, test36);
    suite_add_tcase(s, test37);
    suite_add_tcase(s, test38);
    suite_add_tcase(s, test39);
    suite_add_tcase(s, test40);
    suite_add_tcase(s, test41);
    suite_add_tcase(s, test42);
    suite_add_tcase(s, test43);
    suite_add_tcase(s, test44);
    suite_add_tcase(s, test45);
    suite_add_tcase(s, test46);
    suite_add_tcase(s, test47);
    suite_add_tcase(s, test48);
    suite_add_tcase(s, test49);
    suite_add_tcase(s, test50);
    suite_add_tcase(s, test51);
    suite_add_tcase(s, test52);
    suite_add_tcase(s, test53);
    suite_add_tcase(s, test54);
    suite_add_tcase(s, test55);
    suite_add_tcase(s, test56);
    suite_add_tcase(s, test57);
    suite_add_tcase(s, test58);
    suite_add_tcase(s, test59);
    suite_add_tcase(s, test60);
    suite_add_tcase(s, test61);
    suite_add_tcase(s, test62);
    suite_add_tcase(s, test63);
    suite_add_tcase(s, test64);
    suite_add_tcase(s, test65);
    suite_add_tcase(s, test66);
    suite_add_tcase(s, test67);
    suite_add_tcase(s, test68);
    suite_add_tcase(s, test69);
    suite_add_tcase(s, test70);
    suite_add_tcase(s, test71);
    suite_add_tcase(s, test72);
    suite_add_tcase(s, test73);
    suite_add_tcase(s, test74);
    suite_add_tcase(s, test75);
    suite_add_tcase(s, test76);
    suite_add_tcase(s, test77);
    suite_add_tcase(s, test78);
    suite_add_tcase(s, test79);
    suite_add_tcase(s, test80);
    suite_add_tcase(s, test81);
    suite_add_tcase(s, test82);
    suite_add_tcase(s, test83);
    suite_add_tcase(s, test84);
    suite_add_tcase(s, test85);
    suite_add_tcase(s, test86);
    suite_add_tcase(s, test87);
    suite_add_tcase(s, test88);
    suite_add_tcase(s, test89);
    suite_add_tcase(s, test90);
    suite_add_tcase(s, test91);
    suite_add_tcase(s, test92);
    suite_add_tcase(s, test93);
    suite_add_tcase(s, test94);
    suite_add_tcase(s, test95);
    suite_add_tcase(s, test96);
    suite_add_tcase(s, test97);
    suite_add_tcase(s, test98);
    suite_add_tcase(s, test99);
    suite_add_tcase(s, test100);
    suite_add_tcase(s, test101);
    suite_add_tcase(s, test102);
    suite_add_tcase(s, test103);
    suite_add_tcase(s, test104);
    suite_add_tcase(s, test105);
    suite_add_tcase(s, test106);
    suite_add_tcase(s, test107);
    suite_add_tcase(s, test108);
    suite_add_tcase(s, test109);
    suite_add_tcase(s, test110);
    suite_add_tcase(s, test111);
    suite_add_tcase(s, test112);
    suite_add_tcase(s, test113);
    suite_add_tcase(s, test114);
    suite_add_tcase(s, test115);
    suite_add_tcase(s, test116);
    suite_add_tcase(s, test117);
    suite_add_tcase(s, test118);
    suite_add_tcase(s, test119);
    suite_add_tcase(s, test120);
    suite_add_tcase(s, test121);
    suite_add_tcase(s, test122);
    suite_add_tcase(s, test123);
    suite_add_tcase(s, test124);
    suite_add_tcase(s, test125);
    suite_add_tcase(s, test126);
    suite_add_tcase(s, test127);
    suite_add_tcase(s, test129);
    suite_add_tcase(s, test130);
    suite_add_tcase(s, test131);
    suite_add_tcase(s, test132);
    suite_add_tcase(s, test133);
    suite_add_tcase(s, test134);
    suite_add_tcase(s, test135);
    suite_add_tcase(s, test136);
    suite_add_tcase(s, test137);
    suite_add_tcase(s, test138);
    suite_add_tcase(s, test139);
    suite_add_tcase(s, test140);
    suite_add_tcase(s, test141);
    suite_add_tcase(s, test142);
    suite_add_tcase(s, test143);
    suite_add_tcase(s, test144);
    suite_add_tcase(s, test145);
    suite_add_tcase(s, test146);
    suite_add_tcase(s, test147);
    suite_add_tcase(s, test148);
    suite_add_tcase(s, test149);
    suite_add_tcase(s, test150);
    suite_add_tcase(s, test151);
    suite_add_tcase(s, test152);
    suite_add_tcase(s, test153);
    suite_add_tcase(s, test154);
    suite_add_tcase(s, test155);
    suite_add_tcase(s, test156);


    tcase_add_test(test1, SSCANFTest1);  // add test to group case
    tcase_add_test(test2, SSCANFTest2);  // add test to group case
    tcase_add_test(test3, SSCANFTest3);  // add test to group case
    tcase_add_test(test4, SSCANFTest4);  // add test to group case
    tcase_add_test(test5, SSCANFTest5);  // add test to group case
    tcase_add_test(test6, SSCANFTest6);  // add test to group case
    tcase_add_test(test7, SSCANFTest7);  // add test to group case
    tcase_add_test(test8, SSCANFTest8);  // add test to group case
    tcase_add_test(test9, SSCANFTest9);  // add test to group case
    tcase_add_test(test10, SSCANFTest10);  // add test to group case
    tcase_add_test(test11, SSCANFTest11);  // add test to group case
    tcase_add_test(test12, SSCANFTest12);  // add test to group case
    tcase_add_test(test13, SSCANFTest13);  // add test to group case
    tcase_add_test(test14, SSCANFTest14);  // add test to group case
    tcase_add_test(test15, SSCANFTest15);  // add test to group case
    tcase_add_test(test16, SSCANFTest16);  // add test to group case
    tcase_add_test(test17, SSCANFTest17);  // add test to group case
    tcase_add_test(test18, SSCANFTest18);  // add test to group case
    tcase_add_test(test19, SSCANFTest19);  // add test to group case
    tcase_add_test(test20, SSCANFTest20);  // add test to group case
    tcase_add_test(test23, SSCANFTest23);
    tcase_add_test(test24, SSCANFTest24);
    tcase_add_test(test25, SSCANFTest25);
    tcase_add_test(test26, SSCANFTest26);
    tcase_add_test(test27, SSCANFTest27);
    tcase_add_test(test28, SSCANFTest28);
    tcase_add_test(test29, SSCANFTest29);
    tcase_add_test(test30, SSCANFTest30);
    tcase_add_test(test31, SSCANFTest31);
    tcase_add_test(test32, SSCANFTest32);
    tcase_add_test(test33, SSCANFTest33);
    tcase_add_test(test34, SSCANFTest34);
    tcase_add_test(test35, SSCANFTest35);
    tcase_add_test(test36, SSCANFTest36);
    tcase_add_test(test37, SSCANFTest37);
    tcase_add_test(test38, SSCANFTest38);
    tcase_add_test(test39, SSCANFTest39);
    tcase_add_test(test40, SSCANFTest40);
    tcase_add_test(test41, SSCANFTest41);
    tcase_add_test(test42, SSCANFTest42);
    tcase_add_test(test43, SSCANFTest43);
    tcase_add_test(test44, SSCANFTest44);
    tcase_add_test(test45, SSCANFTest45);
    tcase_add_test(test46, SSCANFTest46);
    tcase_add_test(test47, SSCANFTest47);
    tcase_add_test(test48, SSCANFTest48);
    tcase_add_test(test49, SSCANFTest49);
    tcase_add_test(test50, SSCANFTest50);
    tcase_add_test(test51, SSCANFTest51);
    tcase_add_test(test52, SSCANFTest52);
    tcase_add_test(test53, SSCANFTest53);
    tcase_add_test(test54, SSCANFTest54);
    tcase_add_test(test55, SSCANFTest55);
    tcase_add_test(test56, SSCANFTest56);
    tcase_add_test(test57, SSCANFTest57);
    tcase_add_test(test58, SSCANFTest58);
    tcase_add_test(test59, SSCANFTest59);
    tcase_add_test(test60, SSCANFTest60);
    tcase_add_test(test61, SSCANFTest61);
    tcase_add_test(test62, SSCANFTest62);
    tcase_add_test(test63, SSCANFTest63);
    tcase_add_test(test64, SSCANFTest64);
    tcase_add_test(test65, SSCANFTest65);
    tcase_add_test(test66, SSCANFTest66);
    tcase_add_test(test67, SSCANFTest67);
    tcase_add_test(test68, SSCANFTest68);
    tcase_add_test(test69, SSCANFTest69);
    tcase_add_test(test70, SSCANFTest70);
    tcase_add_test(test71, SSCANFTest71);
    tcase_add_test(test72, SSCANFTest72);
    tcase_add_test(test73, SSCANFTest73);
    tcase_add_test(test74, SSCANFTest74);
    tcase_add_test(test75, SSCANFTest75);
    tcase_add_test(test76, SSCANFTest76);
    tcase_add_test(test77, SSCANFTest77);
    tcase_add_test(test78, SSCANFTest78);
    tcase_add_test(test79, SSCANFTest79);
    tcase_add_test(test80, SSCANFTest80);
    tcase_add_test(test81, SSCANFTest81);
    tcase_add_test(test82, SSCANFTest82);
    tcase_add_test(test83, SSCANFTest83);
    tcase_add_test(test84, SSCANFTest84);
    tcase_add_test(test85, SSCANFTest85);
    tcase_add_test(test86, SSCANFTest86);
    tcase_add_test(test87, SSCANFTest87);
    tcase_add_test(test88, SSCANFTest88);
    tcase_add_test(test89, SSCANFTest89);
    tcase_add_test(test90, SSCANFTest90);
    tcase_add_test(test91, SSCANFTest91);
    tcase_add_test(test92, SSCANFTest92);
    tcase_add_test(test93, SSCANFTest93);
    tcase_add_test(test94, SSCANFTest94);
    tcase_add_test(test95, SSCANFTest95);
    tcase_add_test(test96, SSCANFTest96);
    tcase_add_test(test97, SSCANFTest97);
    tcase_add_test(test98, SSCANFTest98);
    tcase_add_test(test99, SSCANFTest99);
    tcase_add_test(test100, SSCANFTest100);
    tcase_add_test(test101, SSCANFTest101);
    tcase_add_test(test102, SSCANFTest102);
    tcase_add_test(test103, SSCANFTest103);
    tcase_add_test(test104, SSCANFTest104);
    tcase_add_test(test105, SSCANFTest105);
    tcase_add_test(test106, SSCANFTest106);
    tcase_add_test(test107, SSCANFTest107);
    tcase_add_test(test108, SSCANFTest108);
    tcase_add_test(test109, SSCANFTest109);
    tcase_add_test(test110, SSCANFTest110);
    tcase_add_test(test111, SSCANFTest111);
    tcase_add_test(test112, SSCANFTest112);
    tcase_add_test(test113, SSCANFTest113);
    tcase_add_test(test114, SSCANFTest114);
    tcase_add_test(test115, SSCANFTest115);
    tcase_add_test(test116, SSCANFTest116);
    tcase_add_test(test117, SSCANFTest117);
    tcase_add_test(test118, SSCANFTest118);
    tcase_add_test(test119, SSCANFTest119);
    tcase_add_test(test120, SSCANFTest120);
    tcase_add_test(test121, SSCANFTest121);
    tcase_add_test(test122, SSCANFTest122);
    tcase_add_test(test123, SSCANFTest123);
    tcase_add_test(test124, SSCANFTest124);
    tcase_add_test(test125, SSCANFTest125);
    tcase_add_test(test126, SSCANFTest126);
    tcase_add_test(test127, SSCANFTest127);
    tcase_add_test(test128, SSCANFTest128);
    tcase_add_test(test129, SSCANFTest129);
    tcase_add_test(test130, SSCANFTest130);
    tcase_add_test(test131, SSCANFTest131);
    tcase_add_test(test132, SSCANFTest132);
    tcase_add_test(test133, SSCANFTest133);
    tcase_add_test(test134, SSCANFTest134);
    tcase_add_test(test135, SSCANFTest135);
    tcase_add_test(test136, SSCANFTest136);
    tcase_add_test(test137, SSCANFTest137);
    tcase_add_test(test138, SSCANFTest138);
    tcase_add_test(test139, SSCANFTest139);
    tcase_add_test(test140, SSCANFTest140);
    tcase_add_test(test141, SSCANFTest141);
    tcase_add_test(test142, SSCANFTest142);
    tcase_add_test(test143, SSCANFTest143);
    tcase_add_test(test144, SSCANFTest144);
    tcase_add_test(test145, SSCANFTest145);
    tcase_add_test(test146, SSCANFTest146);
    tcase_add_test(test147, SSCANFTest147);
    tcase_add_test(test148, SSCANFTest148);
    tcase_add_test(test149, SSCANFTest149);
    tcase_add_test(test150, SSCANFTest150);
    tcase_add_test(test151, SSCANFTest151);
    tcase_add_test(test152, SSCANFTest152);
    tcase_add_test(test153, SSCANFTest153);
    tcase_add_test(test154, SSCANFTest154);
    tcase_add_test(test155, SSCANFTest155);
    tcase_add_test(test156, SSCANFTest156);
    return s;
}

// int main() {
//     Suite *s = example_suite_create();
//     SRunner *runner = srunner_create(s);
//     int failed_count;
//     srunner_run_all(runner, CK_NORMAL);
//     failed_count = srunner_ntests_failed(runner);
//     srunner_free(runner);
//     return failed_count == 0 ? 0 : 1;
// }
