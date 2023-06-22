#include "s21_string.h"

void *s21_to_lower(const char *str) {
  int i = 0;
  if (!str || str[i] == '\0') {
    return NULL;
  }
  char *copy_str = (char *)malloc(s21_strlen(str));
  for (int i = 0; str[i] != '\0'; i++) { 
    if (str[i] >= 'A' && str[i] <= 'Z') {
      copy_str[i] = str[i] + 32;
    } else {
      copy_str[i] = str[i];
    }
  }
  return (copy_str);
}
