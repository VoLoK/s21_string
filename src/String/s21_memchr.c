#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *ptr = (const char *)str;

  for (s21_size_t i = 0; i < n; i++)
    if (ptr[i] == c) return (void *)&ptr[i];

  return s21_NULL;
}