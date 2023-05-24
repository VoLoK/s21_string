#include "s21_tests.h"

START_TEST(some_test) {
  char s21_dest[] = "someIntellectualText";
  char s21_src = 'i';
  char dest[] = "someIntellectualText";
  char src = 'i';
  s21_size_t n = 7;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(zero_n_test) {
  char s21_dest[] = "someIntellectualText";
  char s21_src = 'i';
  char dest[] = "someIntellectualText";
  char src = 'i';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(empty_test) {
  char s21_dest[] = "";
  char s21_src = '\0';
  char dest[] = "";
  char src = '\0';
  s21_size_t n = 0;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(replace_number_test) {
  char s21_dest[] = "hello";
  char s21_src = '2';
  char dest[] = "hello";
  char src = '2';
  s21_size_t n = 3;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(replace_register_test) {
  char s21_dest[] = "hello";
  char s21_src = 'H';
  char dest[] = "hello";
  char src = 'H';
  s21_size_t n = 1;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

START_TEST(long_test) {
  char s21_dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char s21_src = '*';
  char dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char src = '*';
  s21_size_t n = 10;

  ck_assert_str_eq(s21_memset(s21_dest, s21_src, n), memset(dest, src, n));
}
END_TEST

Suite* suite_memset() {
  Suite* suite = suite_create("memset_suite");
  TCase* tcase_core = tcase_create("memset_tc");

  tcase_add_test(tcase_core, some_test);
  tcase_add_test(tcase_core, zero_n_test);
  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, replace_number_test);
  tcase_add_test(tcase_core, replace_register_test);
  tcase_add_test(tcase_core, long_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
