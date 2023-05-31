#include "s21_tests.h"

START_TEST(some_in_str) {
  char str[] = "hellell56o";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(empty_str) {
  char str[] = "";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(one_symbol_test) {
  char str[] = "1";

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite* suite_strlen() {
  Suite* suite = suite_create("strlen_suite");
  TCase* tcase_core = tcase_create("strlen_tc");
  tcase_add_test(tcase_core, some_in_str);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
