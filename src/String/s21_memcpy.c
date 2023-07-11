#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *source = (char *)src;
  char *destination = (char *)dest;
  while (n-- > 0)
    *destination++ = *source++;
  return dest;
}
