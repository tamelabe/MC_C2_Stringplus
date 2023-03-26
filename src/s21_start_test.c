#include "s21_tests.h"
Suite *suite_sscanf();
int main() {
    Suite *s1 = suite_string();
    Suite *s2 = suite_sprintf();
    Suite *s3 = suite_sscanf();

    SRunner *runner1 = srunner_create(s1);
    SRunner *runner2 = srunner_create(s2);
    SRunner *runner3 = srunner_create(s3);
    int failed_count;
    srunner_set_fork_status(runner1, CK_NOFORK);
    srunner_run_all(runner1, CK_NORMAL);
    failed_count = srunner_ntests_failed(runner1);
    srunner_free(runner1);
    srunner_set_fork_status(runner2, CK_NOFORK);
    srunner_run_all(runner2, CK_NORMAL);
    failed_count = srunner_ntests_failed(runner2);
    srunner_free(runner2);
    srunner_set_fork_status(runner3, CK_NOFORK);
    srunner_run_all(runner3, CK_NORMAL);
    failed_count = srunner_ntests_failed(runner3);
    srunner_free(runner3);
    return failed_count == 0 ? 0 : 1;
}
