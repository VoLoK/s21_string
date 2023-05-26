#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>

#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
void *memcpy(void *dest, const void *src, s21_size_t n);
int strncmp(const char *str1, const char *str2, s21_size_t n);
int memcmp(const void *str1, const void *str2, s21_size_t n);

#endif
