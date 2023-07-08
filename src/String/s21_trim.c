#include <stdlib.h>

#include "s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  char* res = s21_NULL;
  if (src && trim_chars) {
    char* start = (char*)src;
    char* end = (char*)src + s21_strlen(src);
    for (; *start && s21_strchr(trim_chars, *start); start++)
      ;
    for (; end != start && s21_strchr(trim_chars, *(end - 1)); end--)
      ;
    res = (char*)malloc((end - start + 1) * sizeof(char));
    if (res) {
      s21_strncpy(res, start, end - start);
      *(res + (end - start)) = '\0';
    }
  }
  return res;
}
