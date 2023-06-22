#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  int i = 0;
  if (!str || str[i] == '\0') {
    return NULL;
  }

  char *copy_str = (char *)malloc(s21_strlen(str));
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z') {
      copy_str[i] = str[i] - 32;
    } else {
      copy_str[i] = str[i];
    }
    i++;
  }
  return (copy_str);
}
