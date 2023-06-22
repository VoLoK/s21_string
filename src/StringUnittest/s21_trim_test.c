#include "s21_tests.h"

START_TEST(insert_in_empty_str) {
  char s21_str[] = "Hi";
  char s21_src[] = "";
  s21_size_t index = 3;

  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
}
END_TEST

//START_TEST(simple_test) {
//  char s21_str[] = "my ";
//  char s21_src[] = "Hello world";
//  s21_size_t index = 6;
//
//  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "Hello my world");
//}
//END_TEST
//
//START_TEST(insert_in_empty) {
//  char s21_str[] = "my";
//  char s21_src[] = "";
//  s21_size_t index = 0;
//
//  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "my");
//}
//END_TEST
//
//START_TEST(insert_in_end) {
//  char s21_str[] = " job";
//  char s21_src[] = "Good";
//  s21_size_t index = 4;
//
//  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "Good job");
//}
//END_TEST
//
//START_TEST(insert_in_start) {
//  char s21_str[] = "School";
//  char s21_src[] = "21";
//  s21_size_t index = 0;
//
//  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "School21");
//}
//END_TEST
//
//START_TEST(insert_NULL) {
//  char* s21_str = s21_NULL;
//  char s21_src[] = "Some text";
//  s21_size_t index = 0;
//
//  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), s21_NULL);
//}
//END_TEST
//
//START_TEST(insert_in_middle) {
//  char s21_str[] = "ret";
//  char s21_src[] = "consectetur";
//  s21_size_t index = 6;
//
//  ck_assert_pstr_eq(s21_insert(s21_src, s21_str, index), "consecrettetur");
//}
//END_TEST

Suite* suite_trim() {
  Suite* suite = suite_create("trim_suite");
  TCase* tcase_core = tcase_create("trim_tc");

  tcase_add_test(tcase_core, insert_in_empty_str);
//  tcase_add_test(tcase_core, simple_test);
//  tcase_add_test(tcase_core, insert_in_empty);
//  tcase_add_test(tcase_core, insert_in_end);
//  tcase_add_test(tcase_core, insert_in_start);
//  tcase_add_test(tcase_core, insert_NULL);
//  tcase_add_test(tcase_core, insert_in_middle);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
