#include "s21_tests.h"

START_TEST(all_std_errors) {
  for (int i = -10; i < 150; i++) {
    char* s21_err = s21_strerror(i);
    char* err = strerror(i);
    ck_assert_str_eq(s21_err, err);
  }
}
END_TEST

Suite* suite_strerror() {
  Suite* suite = suite_create("strerror_suite");
  TCase* tcase_core = tcase_create("strerror_tc");

  tcase_add_test(tcase_core, all_std_errors);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
