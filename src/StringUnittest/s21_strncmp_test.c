#include "s21_tests.h"

START_TEST(some_test) {
  char s21_dest[] = "someIntellectualText_el_ell";
  char s21_src[] = "ell";
  s21_size_t n = 100;

  ck_assert_int_eq(s21_strncmp(s21_dest, s21_src, n),
                   strncmp(s21_dest, s21_src, n));
}
END_TEST

START_TEST(zero_n_test) {
  char s21_dest[] = "someIntellectualText_someIntellectualText";
  char s21_src[] = "some";
  s21_size_t n = 0;

  ck_assert_int_eq(s21_strncmp(s21_dest, s21_src, n),
                   strncmp(s21_dest, s21_src, n));
}
END_TEST

START_TEST(empty_test) {
  char s21_dest[] = "";
  char s21_src[] = "\0";
  s21_size_t n = 0;

  ck_assert_int_eq(s21_strncmp(s21_dest, s21_src, n),
                   strncmp(s21_dest, s21_src, n));
}
END_TEST

START_TEST(middle_text_test) {
  char s21_dest[] = "UmbroBigbroKAKUmbroBigbro";
  char s21_src[] = "KAK";
  s21_size_t n = 100;

  ck_assert_int_eq(s21_strncmp(s21_dest, s21_src, n),
                   strncmp(s21_dest, s21_src, n));
}
END_TEST

START_TEST(replace_register_test) {
  char s21_dest[] = "hello";
  char s21_src[] = "Hello";
  s21_size_t n = 20;

  ck_assert_int_eq(s21_strncmp(s21_dest, s21_src, n),
                   strncmp(s21_dest, s21_src, n));
}
END_TEST

START_TEST(long_test) {
  char s21_dest[] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce nec "
      "tempus felis. Nullam dapibus nam.";
  char s21_src[] = "***";
  s21_size_t n = 100;

  ck_assert_int_eq(s21_strncmp(s21_dest, s21_src, n),
                   strncmp(s21_dest, s21_src, n));
}
END_TEST

Suite* suite_strncmp() {
  Suite* suite = suite_create("strncmp_suite");
  TCase* tcase_core = tcase_create("strncmp_tc");

  tcase_add_test(tcase_core, some_test);
  tcase_add_test(tcase_core, zero_n_test);
  tcase_add_test(tcase_core, empty_test);
  tcase_add_test(tcase_core, middle_text_test);
  tcase_add_test(tcase_core, replace_register_test);
  tcase_add_test(tcase_core, long_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
