#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *str_1 = (char *)str1;
  char *str_2 = (char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n && !result; i++) {
    if (str_1[i] > str_2[i]) {
      result = 1;
    } else if (str_1[i] < str_2[i]) {
      result = -1;
    }
  }
  return result;
}
