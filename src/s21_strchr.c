#include "s21_string.h"

char* s21_strchr(const char* str, int c) {
  const char* position = s21_NULL;
  s21_size_t i = 0;

  for (i = 0;; i++) {
    if ((unsigned char)str[i] == c) {
      position = &str[i];
      break;
    }
    if (str[i] == '\0') break;
  }
  return (char*)position;
}
