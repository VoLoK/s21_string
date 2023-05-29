#include "s21_tests.h"

START_TEST(empty) {
  const char str1[] = "";
  const char str2[] = "";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str1) {
  const char str1[] = "";
  const char str2[] = "123";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(empty_str2) {
  const char str1[] = "123";
  const char str2[] = "";
  s21_size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(str1_more_str2) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(str1_less_str2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite* suite_strncmp() {
  Suite* suite = suite_create("strncmp_suite");
  TCase* tcase_core = tcase_create("strncmp_tc");

  tcase_add_test(tcase_core, empty);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, str1_more_str2);
  tcase_add_test(tcase_core, str1_less_str2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}