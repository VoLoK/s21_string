#include "includes/s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *source = (char *)src;
  char *destination = (char *)dest;
  s21_size_t i = 0;
  for (; i < n; i++) {
    destination[i] = source[i];
  }
  destination[i] = '\0';
  return destination;
}