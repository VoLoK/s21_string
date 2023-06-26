#include "s21_tests.h"

START_TEST(d_simple_int) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = 5;
  int system = 5;
    s21_sprintf(s21_buff, "This is %d", s21);
    sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_negative_int) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = -19;
  int system = -19;
    s21_sprintf(s21_buff, "This is %d", s21);
    sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_int_in_middle_of_str) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int s21 = 1024;
  int system = 1024;
    s21_sprintf(s21_buff, "This is %d number", s21);
    sprintf(buff, "This is %d number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char* s21 = "Hello str";
  char* system = "Hello str";
    s21_sprintf(s21_buff, "This is %s", s21);
    sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_empty_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char* s21 = "";
  char* system = "";
    s21_sprintf(s21_buff, "This is %s", s21);
    sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_int_str_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char* s21 = "12345";
  char* system = "12345";
    s21_sprintf(s21_buff, "This is %s", s21);
    sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_str_in_middle_of_str) {
  char s21_buff[100] = "";
  char buff[100] = "";
  char* s21 = "my";
  char* system = "my";
  s21_sprintf(s21_buff, "This is %s string", s21);
  sprintf(buff, "This is %s string", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_simple_char) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", 'c');
  sprintf(buff, "%c", 'c');

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_number_ASCII) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", 67);
  sprintf(buff, "%c", 67);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_number_char) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", '8');
  sprintf(buff, "%c", '8');

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_space_char) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%c", ' ');
  sprintf(buff, "%c", ' ');

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", 21);
  sprintf(buff, "%+d", 21);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", -250);
  sprintf(buff, "%+d", -250);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%+d", 0);
  sprintf(buff, "%+d", 0);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", 25);
  sprintf(buff, "% d", 25);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", -1000);
  sprintf(buff, "% d", -1000);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "% d", 0);
  sprintf(buff, "% d", 0);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

Suite* suite_sprintf() {
  Suite* suite = suite_create("sprintf_suite");
  TCase* tcase_core = tcase_create("sprintf_tc");

  tcase_add_test(tcase_core, d_simple_int);
  tcase_add_test(tcase_core, d_negative_int);
  tcase_add_test(tcase_core, d_int_in_middle_of_str);
  tcase_add_test(tcase_core, s_simple_test);
  tcase_add_test(tcase_core, s_empty_test);
  tcase_add_test(tcase_core, s_int_str_test);
  tcase_add_test(tcase_core, s_str_in_middle_of_str);
//  tcase_add_test(tcase_core, insert_in_middle);
  tcase_add_test(tcase_core, c_simple_char);
  tcase_add_test(tcase_core, c_number_ASCII);
  tcase_add_test(tcase_core, c_number_char);
  tcase_add_test(tcase_core, c_space_char);
  tcase_add_test(tcase_core, flag_plus_simple_test);
  tcase_add_test(tcase_core, flag_plus_negative_number);
  tcase_add_test(tcase_core, flag_plus_zero);
  tcase_add_test(tcase_core, flag_space_simple_test);
  tcase_add_test(tcase_core, flag_space_negative_number);
  tcase_add_test(tcase_core, flag_space_zero);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

