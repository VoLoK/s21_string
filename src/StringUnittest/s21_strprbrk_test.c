#include "s21_tests.h"

START_TEST(empty_s1) {
  char s1[] = "";
  char s2[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(some_s1_in_s2) {
  char s1[] = "hellello";
  char s2[] = "el";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(empty_s1s2) {
  char s1[] = "";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(empty_needle) {
  char s1[] = "Some meaningless text";
  char s2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(regular_test) {
  char s1[] = "Hello World";
  char s2[] = "World";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(no_match_test) {
  char s1[] = "i need this text";
  char s2[] = "sorry";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(register_test) {
  char s1[] = "Hello World";
  char s2[] = "world";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(one_symbol_test) {
  char s1[] = "Hi";
  char s2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

Suite* suite_strpbrk() {
  Suite* suite = suite_create("strpbrk_suite");
  TCase* tcase_core = tcase_create("strpbrk_tc");

  tcase_add_test(tcase_core, empty_s1);
  tcase_add_test(tcase_core, some_s1_in_s2);
  tcase_add_test(tcase_core, empty_s1s2);
  tcase_add_test(tcase_core, empty_needle);
  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, no_match_test);
  tcase_add_test(tcase_core, register_test);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
