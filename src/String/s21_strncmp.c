#include "s21_string.h"

int strncmp(const char *str1, const char *str2, size_t n) {
  int result = 0;
  for (int i = 0; i < n && !result; i++) {
    if (str1[i] > str2[i]) {
      result = 1;
    } else if (str1[i] < str2[i]) {
      result = -1;
    }
  }
  return result;
}