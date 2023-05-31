#include "s21_tests.h"

START_TEST(empty_str) {
  char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(some_cin_str) {
  char str[] = "hellell556o";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(empty_str_and_c) {
  char str[] = "";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(empty_c) {
  char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(regular_test) {
  char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(no_match_test) {
  char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(one_symbol_test) {
  char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite* suite_strrchr() {
  Suite* suite = suite_create("strrchr_suite");
  TCase* tcase_core = tcase_create("strrchr_tc");
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, some_cin_str);
  tcase_add_test(tcase_core, empty_c);
  tcase_add_test(tcase_core, empty_str_and_c);
  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, no_match_test);
  tcase_add_test(tcase_core, one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
