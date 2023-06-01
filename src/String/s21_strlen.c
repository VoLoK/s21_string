#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *s;

  for (s = str; *s; ++s)
    ;
  return (s - str);
}
