#include "s21_tests.h"

START_TEST(str1_more_str2) {
  const char str1[] = "1a3bc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(str1_less_str2) {
  const char str1[] = "123abc";
  const char str2[] = "1a3bc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(equal) {
  const char str1[] = "123abc";
  const char str2[] = "123abc";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite* suite_memcmp() {
  Suite* suite = suite_create("memcmp_suite");
  TCase* tcase_core = tcase_create("memcmp_tc");

  tcase_add_test(tcase_core, str1_more_str2);
  tcase_add_test(tcase_core, str1_less_str2);
  tcase_add_test(tcase_core, equal);

  suite_add_tcase(suite, tcase_core);
  return suite;
}