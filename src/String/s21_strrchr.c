#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *cfind = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == (char)c) {
        cfind = str;
      }
    } while (*str++);
  }
  return (char *)cfind;
}
