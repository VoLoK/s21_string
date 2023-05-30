#include "s21_sprintf.h"

int s21_sprintf(char* str, const char* format, ...) {
  char* p = "";
  int res = 0;
  va_list list;
  va_start(list, format);
  char temp[S21_TEXTMAX];
  int size = (int)s21_strlen(format);
  int i = 0;
  unsigned char len = ' ';
  while (*format != 0 && i < size) {
    if (*format++ == '%') {
      switch (*format++) {
        case 'c':
          c_specific();
          break;
        case 'd':
          d_specific(temp, list, p, len, i, str);
          break;
        case 'f':
          f_specific();
          break;
        case 's':
          s_specific();
          break;
        case 'u':
          u_specific();
          break;
        case '%':
		  percent_specific();
          break;
      }
    } else {
      str[i++] = *(format - 1);
      str[i] = 0;
    }
  }
  return res;
}

char* s21_itoa(int input, char* buff, int num) {
  int base = 10;
  char* p;
  if (num < 0) {
    num = -num;
    p = s21_convert(buff, input, num, base);
    *--p = '-';
  } else {
    p = s21_convert(buff, input, num, base);
  }
  return p;
}

char* s21_convert(char* buff, int size, unsigned int num, int base) {
  char* p;
  p = &buff[size - 1];
  *p = '\0';
  if (num != 0) {
    while (num != 0) {
      *--p = "0123456789ABCDEF"[num % base];
      num /= base;
    }
  } else {
    *--p = '0';
  }
  return p;
}

void d_specific(char* temp, va_list list, char* p, unsigned char len, int* i,
                char* str) {
  p = s21_itoa(sizeof(temp), temp, va_arg(list, unsigned int));
  len = (unsigned char)s21_strlen(p);
  s21_memset(&str[*i], ' ', 0);
  s21_strncat(&str[*i], p, s21_strlen(str));
  *i += (len);
}

void c_specific() {}

void f_specific() {}

void s_specific(void) {}

void u_specific(void) {}

void percent_specific(void) {}
