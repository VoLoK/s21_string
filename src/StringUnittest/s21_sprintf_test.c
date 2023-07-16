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

START_TEST(f_simple) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 4.3;
  float system = 4.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_simple_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 0.34;
  float system = 0.34;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 9.3425789;
  float system = 9.3425789;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_big_int_part) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 10.3;
  float system = 10.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 0;
  float system = 0;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_simple) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.322;
  float system = 2.322;
  s21_sprintf(s21_buff, "This is %.2f number", s21);
  sprintf(buff, "This is %.2f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_simple_rounding) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_hard_rounding) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_hard_rounding_minus) {
  char s21_buff[100] = "";
  char buff[100] = "";
  float s21 = -2.3228;
  float system = -2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

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
  s21_sprintf(s21_buff, "result: %+d", 0);
  sprintf(buff, "result: %+d", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "result: % d", 25);
  sprintf(buff, "result: % d", 25);
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

START_TEST(x_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 15);
  sprintf(buff, "%x", 15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(X_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 11);
  sprintf(buff, "%X", 11);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 1505);
  sprintf(buff, "%x", 1505);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(X_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 12345678);
  sprintf(buff, "%X", 12345678);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%x", 0);
  sprintf(buff, "%x", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(X_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%X", 0);
  sprintf(buff, "%X", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_simple_test) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 10);
  sprintf(buff, "%o", 10);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_before_eight) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 7);
  sprintf(buff, "%o", 7);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 0);
  sprintf(buff, "%o", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_big_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%o", 12345678);
  sprintf(buff, "%o", 12345678);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_uint_max) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned int number = UINT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_int_max) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = INT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_negative_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = -100;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_int_max_plus_number) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned int number = (unsigned int)INT_MAX + 100;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_with_zero) {
  char s21_buff[100] = "";
  char buff[100] = "";
  int number = 0;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%5d", 1568);
  sprintf(buff, "%5d", 1568);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%4f", 15.15);
  sprintf(buff, "%4f", 15.15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%10c", 'z');
  sprintf(buff, "%10c", 'z');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%3s", "Hello, world!");
  sprintf(buff, "%3s", "Hello, world!");
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(o_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%4o", 256);
  sprintf(buff, "%4o", 256);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(x_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%15x", 15);
  sprintf(buff, "%15x", 15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_width) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%8u", 15678940);
  sprintf(buff, "%8u", 15678940);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(percent_one) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%% %d", 1);
  sprintf(buff, "%% %d", 1);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(percent_some) {
  char s21_buff[100] = "";
  char buff[100] = "";
  s21_sprintf(s21_buff, "%%%%%% %f", 1.0);
  sprintf(buff, "%%%%%% %f", 1.0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_d) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int d = 1234567890;
  s21_sprintf(s21_buff, "%ld", d);
  sprintf(buff, "%ld", d);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_o) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int o = 84518;
  s21_sprintf(s21_buff, "%lo", o);
  sprintf(buff, "%lo", o);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_u) {
  char s21_buff[100] = "";
  char buff[100] = "";
  unsigned long int u = 1234567890;
  s21_sprintf(s21_buff, "%lu", u);
  sprintf(buff, "%lu", u);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(l_x) {
  char s21_buff[100] = "";
  char buff[100] = "";
  long int x = 15;
  s21_sprintf(s21_buff, "%lx", x);
  sprintf(buff, "%lx", x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(short_int_uns_oct_hex) {
  char s21_buff[100] = "";
  char buff[100] = "";
   int x = 15;
  s21_sprintf(s21_buff, "%hd %hu %ho %hx", x, x, x, x);
  sprintf(buff, "%hd %hu %ho %hx", x, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(left_justify_plus_short) {
  char s21_buff[100] = "";
  char buff[100] = "";
   int x = 15;
  s21_sprintf(s21_buff, "%-10hd %-5hu %-7ho %-2hx", x, x, x, x);
  sprintf(buff, "%-10hd %-5hu %-7ho %-2hx", x, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(left_justify) {
  char s21_buff[100] = "";
  char buff[100] = "";
   int x = 15;
  s21_sprintf(s21_buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  sprintf(buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(short_border_numbers) {
  char s21_buff[100] = "";
  char buff[100] = "";
   int x = INT_MAX;
   unsigned int y = UINT_MAX;
   int z = -123;
   int k = -1;
  s21_sprintf(s21_buff, "%hd %hu %hx %ho", x, y, z, k);
  sprintf(buff, "%hd %hu %hx %ho", x, y, z, k);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(short_and_int_uint_alternation) {
  char s21_buff[100] = "";
  char buff[100] = "";
   int x = INT_MAX;
   unsigned int y = UINT_MAX;
   int z = -123;
   int k = -1;
  s21_sprintf(s21_buff, "%d %hd %u %hu", x, y, z, k);
  sprintf(buff, "%d %hd %u %hu", x, y, z, k);
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
  tcase_add_test(tcase_core, f_simple);
  tcase_add_test(tcase_core, f_simple_zero);
  tcase_add_test(tcase_core, f_big_number);
  tcase_add_test(tcase_core, f_big_int_part);
  tcase_add_test(tcase_core, f_zero);
  tcase_add_test(tcase_core, exactness_simple);
  tcase_add_test(tcase_core, exactness_with_simple_rounding);
  tcase_add_test(tcase_core, exactness_with_hard_rounding);
  tcase_add_test(tcase_core, exactness_with_hard_rounding_minus);
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
  tcase_add_test(tcase_core, x_simple_test);
  tcase_add_test(tcase_core, X_simple_test);
  tcase_add_test(tcase_core, x_big_number);
  tcase_add_test(tcase_core, X_big_number);
  tcase_add_test(tcase_core, x_zero);
  tcase_add_test(tcase_core, X_zero);
  tcase_add_test(tcase_core, o_simple_test);
  tcase_add_test(tcase_core, o_before_eight);
  tcase_add_test(tcase_core, o_zero);
  tcase_add_test(tcase_core, o_big_number);
  tcase_add_test(tcase_core, u_uint_max);
  tcase_add_test(tcase_core, u_int_max);
  tcase_add_test(tcase_core, d_width);
  tcase_add_test(tcase_core, f_width);
  tcase_add_test(tcase_core, c_width);
  tcase_add_test(tcase_core, s_width);
  tcase_add_test(tcase_core, o_width);
  tcase_add_test(tcase_core, x_width);
  tcase_add_test(tcase_core, u_width);
  tcase_add_test(tcase_core, percent_one);
  tcase_add_test(tcase_core, percent_some);
  tcase_add_test(tcase_core, l_d);
  tcase_add_test(tcase_core, l_o);
  tcase_add_test(tcase_core, l_u);
  tcase_add_test(tcase_core, l_x);
  tcase_add_test(tcase_core, u_negative_number);
  tcase_add_test(tcase_core, u_int_max_plus_number);
  tcase_add_test(tcase_core, u_with_zero);
  tcase_add_test(tcase_core, short_int_uns_oct_hex);
  tcase_add_test(tcase_core, left_justify);
  tcase_add_test(tcase_core, left_justify_plus_short);
  tcase_add_test(tcase_core, short_border_numbers);
  tcase_add_test(tcase_core, short_and_int_uint_alternation);


  suite_add_tcase(suite, tcase_core);
  return suite;
}
