#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *position = s21_NULL;

  if (*needle == '\0') {
    position = (char *)haystack;
  }
  while (*haystack && position == s21_NULL) {
    if (*haystack == *needle) {
      char *hay = (char *)haystack;
      char *need = (char *)needle;
      while (*hay == *need && *need != '\0') {
        hay++;
        need++;
      }
      if (*need == '\0') {
        position = (char *)haystack;
        break;
      }
    }
    haystack++;
  }
  return position;
}