#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) {
    return s21_NULL;
  }

  char *res = malloc((src_len + str_len + 1) * sizeof(char));
  if (res == s21_NULL) {
    return s21_NULL;
  }

  s21_memcpy(res, src, start_index);
  s21_memcpy(res + start_index, str, str_len);
  s21_memcpy(res + start_index + str_len, src + start_index,
             src_len - start_index);
  res[s21_strlen(res)] = '\0';
  free(res);
  return (void *)res;
}
