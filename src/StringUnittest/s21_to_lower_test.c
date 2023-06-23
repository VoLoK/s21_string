#include "s21_tests.h"

START_TEST(simple_lower_case) {
  const char s21_str[] = "ABC";

  ck_assert_str_eq(s21_to_lower(s21_str), "abc");
}
END_TEST

START_TEST(empty_str) {
  const char s21_str[] = "";

  ck_assert_pstr_eq(s21_to_lower(s21_str), NULL);
}
END_TEST

START_TEST(letters_and_numbers) {
  char s21_str[] = "ABC123ABC";

  ck_assert_str_eq(s21_to_lower(s21_str), "abc123abc");
}
END_TEST

START_TEST(lowercase) {
  char s21_str[] = "abc";

  ck_assert_str_eq(s21_to_lower(s21_str), "abc");
}
END_TEST

Suite* suite_to_lower() {
  Suite* suite = suite_create("to_lower_suite");
  TCase* tcase_core = tcase_create("to_lower_tc");

  tcase_add_test(tcase_core, simple_lower_case);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, lowercase);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
