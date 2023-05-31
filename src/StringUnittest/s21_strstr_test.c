#include "s21_tests.h"

START_TEST(empty_haystack) {
  char haystack[] = "";
  char needle[] = "Hello everyone123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(some_needle_in_haystack) {
  char haystack[] = "hellello";
  char needle[] = "el";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(empty_needle) {
  char haystack[] = "Some meaningless text";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(regular_test) {
  char haystack[] = "Hello World";
  char needle[] = "World";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(no_match_test) {
  char haystack[] = "i need this text";
  char needle[] = "sorry";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(register_test) {
  char haystack[] = "Hello World";
  char needle[] = "world";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(one_symbol_test) {
  char haystack[] = "Hi";
  char needle[] = "i";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite* suite_strstr() {
  Suite* suite = suite_create("strstr_suite");
  TCase* tcase_core = tcase_create("strstr_tc");

  tcase_add_test(tcase_core, empty_haystack);
  tcase_add_test(tcase_core, some_needle_in_haystack);
  tcase_add_test(tcase_core, empty_haystack_and_needle);
  tcase_add_test(tcase_core, empty_needle);
  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, no_match_test);
  tcase_add_test(tcase_core, register_test);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
