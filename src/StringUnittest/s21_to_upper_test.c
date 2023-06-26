#include "s21_tests.h"

START_TEST(simple_upper_case) {
  const char s21_str[] = "abc";

  ck_assert_str_eq(s21_to_upper(s21_str), "ABC");
}
END_TEST

START_TEST(empty_str) {
  const char s21_str[] = "";

  ck_assert_pstr_eq(s21_to_upper(s21_str), NULL);
}
END_TEST

START_TEST(letters_and_numbers) {
  char s21_str[] = "abc123abc";

  ck_assert_str_eq(s21_to_upper(s21_str), "ABC123ABC");
}
END_TEST

START_TEST(uppercase) {
  char s21_str[] = "ABC";

  ck_assert_str_eq(s21_to_upper(s21_str), "ABC");
}
END_TEST

Suite* suite_to_upper() {
  Suite* suite = suite_create("to_upper_suite");
  TCase* tcase_core = tcase_create("to_upper_tc");

  tcase_add_test(tcase_core, simple_upper_case);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, uppercase);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
