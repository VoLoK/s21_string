#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  int temp = 0;
  for (s21_size_t i = 0; i < n && !result && !temp; i++) {
    if (str1[i] == '\0' && str2[i] == '\0') {
      temp = 1;
    } else if (str1[i] == '\0') {
      result = str1[i] - str2[i];
    } else if (str2[i] == '\0') {
      result = str1[i] - str2[i];
    } else if (str1[i] > str2[i]) {
      result = str1[i] - str2[i];
    } else if (str1[i] < str2[i]) {
      result = str1[i] - str2[i];
    }
  }
  return result;
}
