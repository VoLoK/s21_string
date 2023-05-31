#include "s21_tests.h"

START_TEST(find_in_empty_str) {
  char s21_str[] = "";
  char s21_c = '\0';
  char str[] = "";
  char c = '\0';
  s21_size_t n = 0;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_empty_in_str) {
  char s21_str[] = "someIntellectualText";
  char s21_c = '\0';
  char str[] = "someIntellectualText";
  char c = '\0';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_uppercase) {
  char s21_str[] = "hello";
  char s21_c = 'H';
  char str[] = "hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_in_start) {
  char s21_str[] = "Hello";
  char s21_c = 'H';
  char str[] = "Hello";
  char c = 'H';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_in_end) {
  char s21_str[] = "hello";
  char s21_c = 'o';
  char str[] = "hello";
  char c = 'o';
  s21_size_t n = 5;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_num_in_string) {
  char s21_str[] = "hel3523522lo";
  char s21_c = '2';
  char str[] = "hel3523522lo";
  char c = '2';
  s21_size_t n = 10;

  ck_assert_pstr_eq(s21_memchr(s21_str, s21_c, n), memchr(str, c, n));
}
END_TEST

START_TEST(find_num_in_array) {
  int s21_arr[] = {1, 43, 235, 7, 23, 111, 9, 0};
  int s21_c = 235;
  int arr[] = {1, 43, 235, 7, 23, 111, 9, 0};
  int c = 235;
  s21_size_t n = sizeof(int) * 8;

  ck_assert_pstr_eq(s21_memchr(s21_arr, s21_c, n), memchr(arr, c, n));
}
END_TEST

Suite* suite_memchr() {
  Suite* suite = suite_create("memchr_suite");
  TCase* tcase_core = tcase_create("memchr_tc");

  tcase_add_test(tcase_core, find_in_empty_str);
  tcase_add_test(tcase_core, find_empty_in_str);
  tcase_add_test(tcase_core, find_uppercase);
  tcase_add_test(tcase_core, find_in_start);
  tcase_add_test(tcase_core, find_in_end);
  tcase_add_test(tcase_core, find_num_in_string);
  tcase_add_test(tcase_core, find_num_in_array);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
