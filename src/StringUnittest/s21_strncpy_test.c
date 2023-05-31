#include "s21_tests.h"

START_TEST(empty) {
  char s21_dest[] = "";
  char s21_src[] = "";
  char dest[] = "";
  char src[] = "";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(n_zero) {
  char s21_dest[] = "Hello";
  char s21_src[] = "world";
  char dest[] = "Hello";
  char src[] = "world";
  s21_size_t n = 0;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(empty_dest) {
  char s21_dest[3] = "";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[3] = "";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 2;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(not_enough_byte_n) {
  char s21_dest[30] = "Lorem ipsum";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[30] = "Lorem ipsum";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 1;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(enough_byte_n) {
  char s21_dest[30] = "Lorem ipsum";
  char s21_src[20] = "Lorem ipsum integer";
  char dest[30] = "Lorem ipsum";
  char src[20] = "Lorem ipsum integer";
  s21_size_t n = 19;

  ck_assert_str_eq(s21_strncpy(s21_dest, s21_src, n), strncpy(dest, src, n));
}
END_TEST

Suite* suite_strncpy() {
  Suite* suite = suite_create("strncpy_suite");
  TCase* tcase_core = tcase_create("strncpy_tc");

  tcase_add_test(tcase_core, empty);
  tcase_add_test(tcase_core, n_zero);
  tcase_add_test(tcase_core, empty_dest);
  tcase_add_test(tcase_core, not_enough_byte_n);
  tcase_add_test(tcase_core, enough_byte_n);

  suite_add_tcase(suite, tcase_core);
  return suite;
}