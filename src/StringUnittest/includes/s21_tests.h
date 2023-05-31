#ifndef SRC_S21_TESTS_H_
#define SRC_S21_TESTS_H_

#include <check.h>
#include <string.h>

#include "s21_string.h"

Suite *suite_memchr(void);
Suite *suite_memset(void);
Suite *suite_strchr(void);
Suite *suite_strerror(void);
Suite *suite_strlen(void);
Suite *suite_strncat(void);
Suite *suite_strncmp(void);
Suite *suite_strncpy(void);
Suite *suite_strpbrk(void);
Suite *suite_strrchr(void);
Suite *suite_strstr(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
