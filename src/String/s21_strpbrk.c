#include "s21_string.h"

char *s21_strpbrk(const char *s1, const char *s2) {
  char *fp[2048];
  int flag = 0;
  if ((s1 == s21_NULL) || (s2 == s21_NULL)) flag = 1;
  while (*s1 && flag != 1) {
    if (!s21_strchr(s2, *s1)) {
      s1++;
    } else {
      flag = 1;
      *fp = (char *)s1;
    }
  }
  return (flag != 0) ? *fp : s21_NULL;
}
