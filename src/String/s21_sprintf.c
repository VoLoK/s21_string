#include "s21_sprintf.h"

int s21_sprintf(char* str, const char* format, ...) {
  char* p = "";
  int res = 0;
  int pers_num = 6;
  va_list list;
  va_start(list, format);
  char temp[S21_TEXTMAX];
  int size = (int)s21_strlen(format);
  int i = 0;
  long long int num = -1;
  s21_size_t len = 0;
  while (*format != 0 && i < size) {
    if (*format++ == '%') {
      if (*format == '+') {
        flag_plus(list, str, &i, &num);
        format++;
      } else if (*format == ' ') {
        flag_space(list, str, &i, &num);
        format++;
      }
      if (*format == '.') {
        format++;
        pers_num = get_num((char**)&format);
      }
      if (*format == 'h') {
        format++;
        num = cast_to_h(list, format);
      }
      switch (*format++) {
        case 'c':
          c_specific(list, str, &i);
          break;
        case 'd':
          d_specific(temp, list, p, len, &i, str, num, &size);
          break;
        case 'f':
          f_specific(list, p, temp, len, &i, str, pers_num, &size);
          break;
        case 's':
          s_specific(list, p, len, &i, str);
          break;
        case 'o':
          o_specific(list, str, &i, num);
          break;
        case 'x':
          x_specific(list, str, &i, 1, num);
          break;
        case 'X':
          x_specific(list, str, &i, 0, num);
          break;
        case 'u':
          u_specific(temp, list, p, len, &i, str, &size, num);
          break;
        case '%':
          percent_specific();
      }
    } else {
      str[i++] = *(format - 1);
      str[i] = 0;
    }
  }
  va_end(list);
  return res;
}

void flag_plus(va_list list, char* str, int* i, long long int* num) {
  *num = va_arg(list, int);
  if (*num >= 0) {
    s21_memset(&str[*i], '+', 1);
    *i += 1;
  }
}

void flag_space(va_list list, char* str, int* i, long long int* num) {
  *num = va_arg(list, int);
  if (*num >= 0) {
    s21_memset(&str[*i], ' ', 1);
    *i += 1;
  }
}

int get_num(char** str) {
  char ch;
  char temp[10];
  char* copy = temp;
  char* str_copy = *str;
  while ((ch = *str_copy) != '.' && ch < ':') {
    *copy++ = ch;
    str_copy++;
  }
  *str = str_copy;
  *copy = 0;
  return atoi(temp);
}

void c_specific(va_list list, char* str, int* i) {
  char c = va_arg(list, int);
  s21_memset(&str[*i], c, 1);
  *i += 1;
}

void d_specific(char* temp, va_list list, char* p, s21_size_t len, int* i,
                char* str, long long int num, int* size) {
  if (num != -1) {
    p = s21_itoa(S21_TEXTMAX, temp, (int)num);
  } else {
    p = s21_itoa(S21_TEXTMAX, temp, va_arg(list, int));
  }
  len = s21_strlen(p);
  s21_strncat(str, p, len);
  *i += len;
  *size += len;
}

void f_specific(va_list list, char* p, char* temp, s21_size_t len, int* i,
                char* str, int pers_num, int* size) {
  float value = (float)va_arg(list, double);
  p = s21_ftoa(temp, S21_TEXTMAX, value, pers_num);
  len = s21_strlen(p);
  s21_strncat(&str[*i], p, s21_strlen(p));
  *i += len;
  *size += len;
}

void s_specific(va_list list, char* p, unsigned char len, int* i, char* str) {
  p = va_arg(list, char*);
  len = (unsigned char)s21_strlen(p);
  s21_memset(&str[*i], ' ', 0);
  s21_strncat(&str[*i], p, len);
  *i += (len);
}

void o_specific(va_list list, char* str, int* i, long long int num) {
  if (num == -1) {
    num = va_arg(list, int);
  }
  if (num == 0) {
    s21_memset(&str[*i], '0', 1);
    *i += 1;
  } else {
    char str2[100] = "";
    int rez = 0;
    int j = 0;
    while (num != 0 && num > 0) {
      rez = num % 8;
      num = num / 8;
      s21_memset(&str2[j], rez + '0', 1);
      j++;
    }
    s21_reverse(str2);
    s21_size_t len_str2 = s21_strlen(str2);
    s21_memcpy(&str[*i], str2, len_str2);
    *i += len_str2;
  }
}

void x_specific(va_list list, char* str, int* i, int spec_x,
                long long int num) {
  if (num == -1) {
    num = va_arg(list, int);
  }
  if (num == 0) {
    s21_memset(&str[*i], '0', 1);
    *i += 1;
  } else {
    char str2[100] = "";
    int rez = 0;
    int j = 0;
    char* format = spec_x ? "0123456789abcdef" : "0123456789ABCDEF";
    while (num != 0 && num > 0) {
      rez = num % 16;
      num = num / 16;
      if (rez) s21_memset(&str2[j], format[rez], 1);
      j++;
    }
    s21_reverse(str2);
    s21_size_t len_str2 = s21_strlen(str2);
    s21_memcpy(&str[*i], str2, len_str2);
    *i += len_str2;
  }
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

char* s21_reverse(char* str) {
  char tmp;
  s21_size_t i, j;
  s21_size_t len_str = s21_strlen(str);
  for (i = 0, j = len_str - 1; i < j; i++, j--) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
  return str;
}

char* f_to_str(char* buff, int size, float value, int digits, int* flag) {
  int i = 0;
  int factor = 10;
  int num = (int)value;
  int sub;
  char* p;
  p = &buff[size - 1];
  *p = '\0';
  if (value < 0) {
    num *= -1;
    value *= -1;
  }
  while (i++ < digits) {
    value = value * factor;
    num = num * factor;
    sub = value - num;
    *(p - digits) = sub + '0';
    p++;
    num += sub;
  }
  i = 0;
  int copy_value = value * 10;
  if (copy_value % 10 >= 5) {
    num = num + 1;
    double ost = num - value;
    if (ost <= 0.11573) {
      *flag = 1;
    }
    while (i++ < digits) {
      p--;
      *(p - digits) = (num % 10) + '0';
      num = num / 10;
    }
  }
  return &buff[size - 1] - digits;
}

char* s21_ftoa(char* buff, int size, float value, int digits) {
  char* p;
  int flag = 0;
  char* q;
  p = f_to_str(buff, size, value, digits, &flag);
  if (*p != '\0') {
    *--p = '.';
  }
  if (flag == 1) {
    value += 1;
  }
  q = s21_itoa((int)(p - &buff[0]), buff, (int)value);
  if (value > -1 && value < 0) {
    *--q = '-';
  }
  int p_count = (int)s21_strlen(p);
  s21_strncat(q, p, p_count);
  return q;
}

long long cast_to_h(va_list list, const char* format) {
  long long int num;
  if (*format == 'd' || *format == 'i') {
    num = (short int)va_arg(list, long long int);
  } else {
    num = (unsigned short)va_arg(list, long long int);
  }
  return num;
}

void s21_utoa(long long int n, char s[]) {
  long long int sign;
  int i;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  s21_reverse(s);
}

void u_specific(char* temp, va_list list, char* p, unsigned char len, int* i,
                char* str, int* size, long long num) {
  if (num == -1) {
    num = va_arg(list, unsigned int);
  }
  if ((num > 0) && num <= INT_MAX) {
    d_specific(temp, list, p, len, i, str, num, size);
  } else {
    unsigned int usum = UINT_MAX - atoi(str);
    char str2[1000];
    s21_utoa(usum, str2);
    s21_size_t len = s21_strlen(str2);
    s21_strncat(str, str2, len);
  }
}

void percent_specific(void) {}
