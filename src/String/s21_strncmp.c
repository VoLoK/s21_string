#include "s21_string.h"

int strncmp(const char *str1, const char *str2, size_t n) {
  int result = 0;
  int temp = 0;
  for (int i = 0; i < n && !result && !temp; i++) {
    if (str1[i] == '\0' && str2[i] == '\0') {
      temp = 1;
    } else if (str1[i] == '\0') {
      result = -1;
    } else if (str2[i] == '\0') {
      result = 1;
    } else if (str1[i] > str2[i]) {
      result = 1;
    } else if (str1[i] < str2[i]) {
      result = -1;
    }
  }
  return result;
}