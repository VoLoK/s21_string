#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

// For printf
#include <stdio.h>

#  define s21_NULL ((void*)0)

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);

#endif
