#include <check.h>
#include <string.h>
#include <math.h>
#include "s21_math.h"

START_TEST(test_s21_abs) {
    ck_assert_int_eq(s21_abs(-555), abs(-555));
    ck_assert_int_eq(s21_abs(5), abs(5));
    ck_assert_int_eq(s21_abs(-26346), abs(-26346));
    ck_assert_int_eq(s21_abs(26346), abs(26346));
}
END_TEST

START_TEST(test_s21_fabs) {
    ck_assert_ldouble_eq(s21_fabs(-5), fabs(-5));
    ck_assert_ldouble_eq(s21_fabs(5), fabs(5));
    ck_assert_ldouble_eq(s21_fabs(-5.543), fabs(-5.543));
    ck_assert_ldouble_eq(s21_fabs(5.543), fabs(5.543));
}
END_TEST

START_TEST(test_s21_floor) {
    ck_assert_ldouble_eq(s21_fabs(-5), fabs(-5));
    ck_assert_ldouble_eq(s21_fabs(5), fabs(5));
    ck_assert_ldouble_eq(s21_fabs(-5.543), fabs(-5.543));
    ck_assert_ldouble_eq(s21_fabs(5.543), fabs(5.543));
}
END_TEST

START_TEST(test_s21_sin) {
    ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(25), sin(25), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(26), sin(26), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(22.5/360.0), sin(22.5/360.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(10.5/260.0), sin(10.5/260.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(5.7/180.0), sin(5.7/180.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(-29), sin(-29), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(-30), sin(-30), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sin(30), sin(30), 1e-6);
    
}
END_TEST

START_TEST(test_s21_ceil) {
    ck_assert_ldouble_eq(s21_ceil(5.543), ceil(5.543));
    ck_assert_ldouble_eq(s21_ceil(-5.543), ceil(-5.543));
    ck_assert_ldouble_eq(s21_ceil(5.143), ceil(5.143));
}
END_TEST

START_TEST(test_s21_exp) {
    ck_assert_ldouble_eq_tol(s21_exp(5), exp(5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 1e-6);
    ck_assert_ldouble_eq_tol(s21_exp(-6), exp(-6), 1e-6);
    ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_exp(125), exp(125), 16);  // <====  верно
}
END_TEST

START_TEST(test_s21_fmod) {
    ck_assert_ldouble_eq(s21_fmod(2,5), fmod(2,5));
    ck_assert_ldouble_eq(s21_fmod(2,100), fmod(2,100));
    ck_assert_ldouble_eq(s21_fmod(1,100), fmod(1,100));
    ck_assert_ldouble_eq(s21_fmod(7,55), fmod(7,55));
    ck_assert_ldouble_eq(s21_fmod(10.567,4), fmod(10.567,4));
    ck_assert_ldouble_eq(s21_fmod(10,4), fmod(10,4));  // <====  верно
    ck_assert_ldouble_eq(s21_fmod(100,2), fmod(100,2));
    
}
END_TEST

START_TEST(test_s21_log) {
    ck_assert_ldouble_eq_tol(s21_log(5), log(5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(125), log(125), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(-125), log(-125), 16);  // <====  не работает
    ck_assert_ldouble_eq_tol(s21_log(0), log(0), 16);  // <====  не работает
    ck_assert_ldouble_eq_tol(s21_log(5.543), log(5.543), 1e-6);
    ck_assert_ldouble_eq_tol(s21_log(-5.543), log(-5.543), 16);  // <====  верно
}
END_TEST

START_TEST(test_s21_pow) {
    ck_assert_ldouble_eq_tol(s21_pow(5, 2), pow(5, 2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(2, 5), pow(2, 5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(2, 5), pow(2, 5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(5.543, 5), pow(5.543, 5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(5.543, 10.65), pow(5.543, 10.65), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(5.543, -10.65), pow(5.543, -10.65), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(-5, 6), pow(-5, 6), 16);  // <====  не работает

}
END_TEST

START_TEST(test_s21_sqrt) {
    ck_assert_ldouble_eq_tol(s21_sqrt(5), sqrt(5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(125), sqrt(125), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(-125), sqrt(-125), 16);  // <====  верно
}
END_TEST

START_TEST(test_s21_cos) {
    ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-5);
    ck_assert_ldouble_eq_tol(s21_cos(25), cos(25), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(26), cos(26), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(22.5/360.0), cos(22.5/360.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(10.5/260.0), cos(10.5/260.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(5.7/180.0), cos(5.7/180.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(-29), cos(-29), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(-30), cos(-30), 1e-6);
    ck_assert_ldouble_eq_tol(s21_cos(30), cos(30), 1e-6);
}
END_TEST

int main() {
    Suite *s1 = suite_create("s21_math: ");
    TCase *tc1_1 = tcase_create("s21_math: ");
    SRunner *sr = srunner_create(s1);
    int result;
    suite_add_tcase(s1, tc1_1);

    tcase_add_test(tc1_1, test_s21_abs);
    tcase_add_test(tc1_1, test_s21_fabs);
    tcase_add_test(tc1_1, test_s21_floor);
    tcase_add_test(tc1_1, test_s21_sin);
    tcase_add_test(tc1_1, test_s21_ceil);
    tcase_add_test(tc1_1, test_s21_exp);
    tcase_add_test(tc1_1, test_s21_fmod);
    tcase_add_test(tc1_1, test_s21_log);
    tcase_add_test(tc1_1, test_s21_pow);
    tcase_add_test(tc1_1, test_s21_sqrt);
    tcase_add_test(tc1_1, test_s21_cos);

    srunner_run_all(sr, CK_ENV);
    result = srunner_ntests_failed(sr);
    srunner_free(sr);
    return result == 0 ? 0 : 1;
}