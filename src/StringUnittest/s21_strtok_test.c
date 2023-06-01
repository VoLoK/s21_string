#include "s21_tests.h"

START_TEST(simple_token_string) {
  char s21_str[] = "Maecenas++mollis_*_!malesuada massa=======vitae";
  char str[] = "Maecenas++mollis__!malesuada massa=======vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_token_string) {
  char s21_str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  char str[] = "      Maecenas++mollis__! D !malesuada _massa=======vitae ";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(not_all_delims) {
  char s21_str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae";
  char str[] = "Maecenas++mollis__!D!malesuada_massa=======vitae*";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(no_delims) {
  char s21_str[] = "MaecenasmollisMalesuadaMassaVitae";
  char str[] = "MaecenasmollisMalesuadaMassaVitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(delims_str) {
  char s21_str[] = "++!!= _";
  char str[] = "++!!= _";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_pstr_eq(s21, system);
}
END_TEST

START_TEST(delims_in_word) {
  char s21_str[] = "Maece+*+nasmollis    !malesu     ada=massa___vitae";
  char str[] = "Maece++nasmollis    !malesu     ada=massa___vitae";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_word) {
  char s21_str[] = "!M+*+N***L M=M_F_V*H";
  char str[] = "!M+*+N***L M=M_F_V*H";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

START_TEST(hard_string) {
  char s21_str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  char str[] =
      "        !          Maece+*+nasmol***lis    !malesu     "
      "ada=massa_f__vitae*** *** *** hi";
  const char delim[] = "! *_=+";

  char *s21 = s21_strtok(s21_str, delim);
  char *system = strtok(str, delim);

  ck_assert_uint_eq(s21_strlen(s21), s21_strlen(system));
  ck_assert_str_eq(s21, system);

  while (s21 && system) {
    s21 = s21_strtok(NULL, delim);
    system = strtok(NULL, delim);
    ck_assert_pstr_eq(s21, system);
  }
}
END_TEST

Suite *suite_strtok() {
  Suite *suite = suite_create("strtok_suite");
  TCase *tcase_core = tcase_create("strtok_tc");

  tcase_add_test(tcase_core, simple_token_string);
  tcase_add_test(tcase_core, hard_token_string);
  tcase_add_test(tcase_core, not_all_delims);
  tcase_add_test(tcase_core, no_delims);
  tcase_add_test(tcase_core, delims_str);
  tcase_add_test(tcase_core, delims_in_word);
  tcase_add_test(tcase_core, hard_word);
  tcase_add_test(tcase_core, hard_string);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
