#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../s21_string.h"

#define s21_size_t unsigned long long
#define s21_NULL 0
#define F_LEFT 1
#define F_SIGN 2
#define F_SPACE 4
#define F_HESHTAG 8
#define F_NULL 16
#define F_DOUBLE 1
#define F_LONG_DOUBLE 2
#define F_Float 1024            
#define F_SHORT_SHORT_INT 2048  
#define F_SHORT_INT 4
#define F_INT 8
#define F_LONG_INT 16
#define F_LONG_LONG_INT 32
#define F_STR 64
#define F_CHAR 128
#define F_PTR 256
#define F_N 512
#define CHAR_PTR char *

typedef struct t_S21SscanfArgs {
  int not_fill;
  int width;
  int length;
  char format;
  int count_fill_sym;
} S21SscanfArgs;


int ParseNum(const char **p_format) {
  int result = 0;
  while (*(*p_format) >= '0' && *(*p_format) <= '9') {
    result *= 10;
    result += *(*p_format) - '0';
    ++(*p_format);
  }
  return result;
}

int ParseLength(const char **p_format) {
  int result = 0;
  switch (*(*p_format)) {
    case 'h':
      ++(*p_format);
      if (*(*p_format) == 'h') {
        ++(*p_format);
        result = *p_format == s21_strpbrk(*p_format, "idouxXn")
                     ? F_SHORT_SHORT_INT
                     : -1;
      } else {
        result =
            *p_format == s21_strpbrk(*p_format, "idouxcXn") ? F_SHORT_INT : -1;
      }
      break;
    case 'L':
      ++(*p_format);
      result =
          *p_format == s21_strpbrk(*p_format, "eEfgG") ? F_LONG_DOUBLE : -1;
      break;
    case 'l':
      ++(*p_format);
      if (*(*p_format) == 'l') {
        ++(*p_format);
        result = *p_format == s21_strpbrk(*p_format, "idouxXn")
                     ? F_LONG_LONG_INT
                     : -1;
      } else if (*p_format == s21_strpbrk(*p_format, "idouxXcsn")) {
        result = F_LONG_INT;
      } else if (*p_format == s21_strpbrk(*p_format, "eEfgG")) {
        result = F_DOUBLE;
      } else {
        result = -1;
      }
      break;
    default:
      if (*p_format == s21_strpbrk(*p_format, "idouxXn")) {
        result |= F_INT;
      } else if (*p_format == s21_strpbrk(*p_format, "eEfgG")) {
        result |= F_Float;
      } else if (*(*p_format) == 's') {
        result |= F_STR;
      } else if (*(*p_format) == 'c') {
        result |= F_CHAR;
      } else if (*(*p_format) == 'p') {
        result |= F_PTR;
      } else if (*(*p_format) == 'n') {
        result |= F_N;
      } else
        result = -1;
  }
  return result;
}

int is_separator(const char *s) {
  int result = 0;
  if (*s == ' ' || *s == '\n' || *s == '\t') {
    result = 1;
  }
  return result;
}

S21SscanfArgs *ParseArgScanf(const char **p_format) {
  S21SscanfArgs *result = s21_NULL;
  char *ident = s21_strpbrk(*p_format, "cdieEfgGosuxXpn");
  int err = 0;
  if (ident != s21_NULL) {
    result = (S21SscanfArgs *)malloc(sizeof(S21SscanfArgs));
    if (**p_format == '*') {
      result->not_fill = 1;
      ++(*p_format);
    } else {
      result->not_fill = 0;
    }
    if (**p_format >= '0' && **p_format <= '9') {
      result->width = ParseNum(p_format);
    } else {
      result->width = -1;
    }
    result->length = ParseLength(p_format);
    if (result->length != -1)
      result->format = *(*p_format);
    else
      err = 1;
  }
  if (err) {
    free(result);
    result = s21_NULL;
  }
  return result;
}

int FillChar(S21SscanfArgs *elems, va_list *args, const char **p_str) {
  int err = 0;
  if (**p_str != '\0') {
    if (!elems->not_fill) {
      char *sym = va_arg(*args, char *);
      *sym = **p_str;
    }
    int count = elems->width == -1 ? 1 : elems->width;
    while (**p_str != '\0' && count > 0) {
      (*p_str)++;
      --count;
    }
  } else {
    err = -1;
  }
  return err;
}

int FillStr(S21SscanfArgs *elems, va_list *args, const char **p_str) {
  int err = 0;
  while (is_separator(*p_str)) {
    ++(*p_str);
  }
  if (**p_str != '\0') {
    if (!elems->not_fill) {
      char *str = va_arg(*args, char *);
      while (**p_str != '\0' && !is_separator(*p_str) && elems->width != 0) {
        *(str++) = *((*p_str)++);
        --elems->width;
      }
      *str = '\0';
    } else {
      ;
      while (**p_str != '\0' && !is_separator(*p_str) && elems->width != 0) {
        (*p_str)++;
        --elems->width;
      }
    }
  } else {
    err = 1;
  }
  return err;
}

void FillIntVal(S21SscanfArgs *elems, va_list *args, long long val) {
  if (elems->length & F_SHORT_SHORT_INT) {
    char *n = va_arg(*args, char *);
    *n = val;
  } else if (elems->length & F_SHORT_INT) {
    short int *n = va_arg(*args, short int *);
    *n = val;
  } else if (elems->length & F_INT) {
    int *n = va_arg(*args, int *);
    *n = val;
  } else if (elems->length & F_LONG_INT) {
    long *n = va_arg(*args, long *);
    *n = val;
  } else {
    long long *n = va_arg(*args, long long *);
    *n = val;
  }
}

int FillNScanf(S21SscanfArgs *elems, va_list *args) {  //заполнить n
  int err = 0;
  FillIntVal(elems, args, elems->count_fill_sym);
  elems->not_fill = 1;
  return err;
}

long double ParseDoubleNum(const char **p_str, S21SscanfArgs *elems) {
  long double result = 0.;
  while (*(*p_str) >= '0' && *(*p_str) <= '9' && elems->width != 0) {
    result *= 10.;
    result += *(*p_str) - '0';
    ++(*p_str);
    --elems->width;
  }
  return result;
}

long double ParseMantis(const char **p_str, S21SscanfArgs *elems) {
  long double result = 0.;
  long double degree = 10.;
  while (*(*p_str) >= '0' && *(*p_str) <= '9' && elems->width != 0) {
    result += (*((*p_str)++) - '0') / degree;
    degree *= 10.;
    --elems->width;
  }
  return result;
}

void ParseEeGg(const char **p_str, int *plus, long double *degree,
               S21SscanfArgs *elems) {
  const char *temp_p_str = *p_str;
  if ((**p_str == 'e' || **p_str == 'E') &&
      elems->width != 0) {  
    ++(*p_str);
    --elems->width;
    if (**p_str == '+' && elems->width != 0) {
      ++(*p_str);
      --elems->width;
    } else if (**p_str == '-' && elems->width != 0) {
      *plus = 0;
      ++(*p_str);
      --elems->width;
    }
    if (**p_str >= '0' && **p_str <= '9' && elems->width != 0) {
      *degree = ParseDoubleNum(p_str, elems);
    } else {
      *p_str = temp_p_str;
    }
  }
}

void FillDoubleVal(S21SscanfArgs *elems, va_list *args, long double val) {
  if (elems->length & F_Float) {
    float *n = va_arg(*args, float *);
    *n = val;
  } else if (elems->length & F_DOUBLE) {
    double *n = va_arg(*args, double *);
    *n = val;
  } else {
    long double *n = va_arg(*args, long double *);
    *n = val;
  }
}

int IsNan(const char **p_str) {
  int result = 0;
  const char *temp_p_str = *p_str;
  if (**p_str != '\0' && (**p_str == 'n' || **p_str == 'N')) {
    ++(*p_str);
    if (**p_str != '\0' && (**p_str == 'a' || **p_str == 'A')) {
      ++(*p_str);
      if (**p_str != '\0' && (**p_str == 'n' || **p_str == 'N')) {
        ++(*p_str);
        result = 1;
      } else {
        *p_str = temp_p_str;
      }
    } else {
      *p_str = temp_p_str;
    }
  }
  return result;
}

int IsInf(const char **p_str) {
  int result = 0;
  const char *temp_p_str = *p_str;
  if (**p_str != '\0' && (**p_str == 'i' || **p_str == 'I')) {
    ++(*p_str);
    if (**p_str != '\0' && (**p_str == 'n' || **p_str == 'N')) {
      ++(*p_str);
      if (**p_str != '\0' && (**p_str == 'f' || **p_str == 'F')) {
        ++(*p_str);
        result = 1;
      } else {
        *p_str = temp_p_str;
      }
    } else {
      *p_str = temp_p_str;
    }
  }
  return result;
}

int FillDouble(S21SscanfArgs *elems, va_list *args, const char **p_str) {
  int err = 0;
  while (is_separator(*p_str)) ++(*p_str);
  int sign_plus = 1;
  const char *temp_p_str = *p_str;
  if (**p_str != '\0' && (**p_str == '+' || **p_str == '-') &&
      elems->width != 0) {
    sign_plus = *((*p_str)++) == '+' ? 1 : 0;
    --elems->width;
  }
  long double val = 0;
  if (elems->width != 0 && elems->width != 1 && elems->width != 2 &&
      IsNan(p_str)) {
    val = sign_plus ? -NAN : -NAN;  
    if (!elems->not_fill && !err) FillDoubleVal(elems, args, val);
  } else if (elems->width != 0 && elems->width != 1 && elems->width != 2 &&
             IsInf(p_str)) {
    val = sign_plus ? INFINITY : -INFINITY;
    if (!elems->not_fill && !err) FillDoubleVal(elems, args, val);
  } else if (**p_str != '\0' &&
             ((**p_str >= '0' && **p_str <= '9') || **p_str == '.') &&
             elems->width != 0) {
    long double val = ParseDoubleNum(p_str, elems);
    long double degree = 0.;
    if (**p_str == '.' && elems->width != 0) {
      ++(*p_str);
      --elems->width;
      val += ParseMantis(p_str, elems);
    }
    val *= sign_plus ? 1. : -1.;
    ParseEeGg(p_str, &sign_plus, &degree, elems);
    for (int i = 0; i < degree; ++i)
      val *= sign_plus == 1 ? 10. : 0.1;   
                                          
    if (!elems->not_fill) FillDoubleVal(elems, args, val);
  } else {
    *p_str = temp_p_str;
    err = **p_str == '\0' ? -1 : 1;
  }
  return err;
}

int isOverflowMult(long long val1, long long val2) {
  long long result = val1 * val2;
  return val1 == result / val2 ? 0 : 1;
}

int isOverflowSum(long long val1, long long val2) {
  return (LLONG_MAX - val1 >= val2) ? 0 : 1;
}

int isOverflowSub(long long val1, long long val2) {
  return (LLONG_MIN + val2 <= val1) ? 0 : 1;
}

unsigned long long GetUVal(S21SscanfArgs *elems, long long temp_res) {
  unsigned long long result = 0;
  switch (elems->length) {
    case F_SHORT_SHORT_INT:
      result = UCHAR_MAX - temp_res + 1;
      break;
    case F_SHORT_INT:
      result = USHRT_MAX - temp_res + 1;
      break;
    case F_INT:
      result = UINT_MAX - temp_res + 1;
      break;
    case F_LONG_INT:
      result = ULONG_MAX - temp_res + 1;
      break;
    case F_LONG_LONG_INT:
      result = ULLONG_MAX - temp_res + 1;
      break;
  }
  return result;
}

unsigned long long ParseOct(const char **p_str, S21SscanfArgs *elems,
                            int sign_plus) {
  unsigned long long result = 0;
  long long temp_res = 0;
  int is_overflow = 0;
  while (**p_str >= '0' && **p_str <= '7' && elems->width != 0) {
    if (isOverflowMult(temp_res, 8)) {
      temp_res = sign_plus ? LLONG_MAX : LLONG_MIN;
      is_overflow = 1;
      break;
    } else
      temp_res *= 8;
    int dig = *((*p_str)++) - '0';
    if (!sign_plus && isOverflowSub(temp_res, dig)) {
      is_overflow = 1;
      temp_res = LLONG_MIN;
      break;
    } else if (sign_plus && isOverflowSum(temp_res, dig)) {
      is_overflow = 1;
      temp_res = LLONG_MAX;
      break;
    } else
      temp_res += dig;
    --elems->width;
  }
  result = sign_plus ? (unsigned long long)temp_res : GetUVal(elems, temp_res);
  if (is_overflow)
    while (*(*p_str) >= '0' && *(*p_str) <= '9' && elems->width != 0) {
      ++(*p_str);
      --elems->width;
    }
  return result;
                            }
  

void SkipHexPrefix(const char **p_str, S21SscanfArgs *elems) {
  if (**p_str != '\0' && **p_str == '0' && elems->width != 0) {
    ++(*p_str);
    --elems->width;
  }
  if (**p_str != '\0' && (**p_str == 'x' || **p_str == 'X') &&
      elems->width != 0) {
    if (elems->width != 1) ++(*p_str);
    --elems->width;
  }
}

int GetHexDigit(const char **p_str) {
  int dig;
  if (**p_str >= '0' && **p_str <= '9')
    dig = (*((*p_str)++) - '0');
  else if (**p_str >= 'a' && **p_str <= 'f')
    dig = (*((*p_str)++) - 87);
  else
    dig = (*((*p_str)++) - 55);
  return dig;
}

unsigned long long ParseHex(const char **p_str, S21SscanfArgs *elems,
                            int sign_plus) {
  unsigned long long result = 0;
  long long temp_res = 0;
  int is_overflow = 0;
  SkipHexPrefix(p_str, elems);
  while (((**p_str >= '0' && **p_str <= '9') ||
          (**p_str >= 'a' && **p_str <= 'f') ||
          (**p_str >= 'A' && **p_str <= 'F')) &&
         elems->width != 0) {
    if (isOverflowMult(temp_res, 16)) {
      temp_res = sign_plus ? LLONG_MAX : LLONG_MIN;
      is_overflow = 1;
      break;
    } else
      temp_res *= 16;
    int dig = GetHexDigit(p_str);
    if (!sign_plus && isOverflowSub(temp_res, dig)) {
      is_overflow = 1;
      temp_res = LLONG_MIN;
      break;
    } else if (sign_plus && isOverflowSum(temp_res, dig)) {
      is_overflow = 1;
      temp_res = LLONG_MAX;
      break;
    } else
      temp_res += dig;
    --elems->width;
  }
  result = sign_plus ? (unsigned long long)temp_res : GetUVal(elems, temp_res);
  if (is_overflow) {
    while (((**p_str >= '0' && **p_str <= '9') ||
            (**p_str >= 'a' && **p_str <= 'f') ||
            (**p_str >= 'A' && **p_str <= 'F')) &&
           elems->width != 0) {
      ++(*p_str);
      --elems->width;
    }
  }
  return result;
}

void FillUIntVal(S21SscanfArgs *elems, va_list *args, unsigned long long val) {
  if (elems->format == 'p') {
    unsigned long long **n = va_arg(*args, unsigned long long **);
    *n = (unsigned long long *)val;
  } else if (elems->length & F_SHORT_SHORT_INT) {
    unsigned char *n = va_arg(*args, unsigned char *);
    *n = val;
  } else if (elems->length & F_SHORT_INT) {
    unsigned short int *n = va_arg(*args, unsigned short int *);
    *n = val;
  } else if (elems->length & F_INT) {
    unsigned int *n = va_arg(*args, unsigned int *);
    *n = val;
  } else if (elems->length & F_LONG_INT) {
    unsigned long *n = va_arg(*args, unsigned long *);
    *n = val;
  } else {
    unsigned long long *n = va_arg(*args, unsigned long long *);
    *n = val;
  }
}

long long ParseDec(const char **p_str, S21SscanfArgs *elems, int sign_plus) {
  long long result = 0.;
  int is_overflow = 0;
  while (*(*p_str) >= '0' && *(*p_str) <= '9' && elems->width != 0) {
    if (isOverflowMult(result, 10)) {
      result = sign_plus ? LLONG_MAX : LLONG_MIN;
      is_overflow = 1;
      break;
    } else {
      result *= 10;
    }
    int dig = *((*p_str)++) - '0';
    if (!sign_plus && isOverflowSub(result, dig)) {
      result = LLONG_MIN;
      is_overflow = 1;
      break;
    } else if (sign_plus && isOverflowSum(result, dig)) {
      result = LLONG_MAX;
      is_overflow = 1;
      break;
    } else {
      result += sign_plus ? dig : -dig;
    }
    --elems->width;
  }
  if (is_overflow) {
    while (*(*p_str) >= '0' && *(*p_str) <= '9' && elems->width != 0) {
      ++(*p_str);
      --elems->width;
    }
  }
  return result;
}

int FillDec(S21SscanfArgs *elems, va_list *args, const char **p_str,
            int sign_plus) {
  int res = 0;
  if (**p_str != '\0' && (**p_str >= '0' && **p_str <= '9') &&
      elems->width != 0) {
    long long val = ParseDec(p_str, elems, sign_plus);
    if (!elems->not_fill) {
      elems->format == 'd' ? FillIntVal(elems, args, val)
                           : FillUIntVal(elems, args, (unsigned long long)val);
    }
    res = 1;
  }
  return res;
}

int FillHex(S21SscanfArgs *elems, va_list *args, const char **p_str,
            int sign_plus) {
  int res = 0;
  if (**p_str != '\0' &&
      ((**p_str >= '0' && **p_str <= '9') ||
       (**p_str >= 'a' && **p_str <= 'f') ||
       (**p_str >= 'A' && **p_str <= 'F')) &&
      elems->width != 0) {  // hex
    unsigned long long int val = ParseHex(p_str, elems, sign_plus);
    if (!elems->not_fill) {
      FillUIntVal(elems, args, val);
    }
    res = 1;
  }
  return res;
}

int FillOct(S21SscanfArgs *elems, va_list *args, const char **p_str,
            int sign_plus) {
  int res = 0;
  if (**p_str != '\0' && (**p_str >= '0' && **p_str <= '7') &&
      elems->width != 0) {
    unsigned long long int val = ParseOct(p_str, elems, sign_plus);
    if (!elems->not_fill) {
      FillUIntVal(elems, args, val);
    }
    res = 1;
  }
  return res;
}

int FillIntOther(S21SscanfArgs *elems, va_list *args, const char **p_str) {
  int err = 0;
  while (is_separator(*p_str)) ++(*p_str);
  int sign_plus = 1;
  const char *temp_p_str = *p_str;
  if (**p_str != '\0' && (**p_str == '+' || **p_str == '-') &&
      elems->width != 0) {
    sign_plus = **p_str == '+' ? 1 : 0;
    ++(*p_str);
    --elems->width;
  }
  int f_fill = 0;
  switch (elems->format) {
    case 'd':
    case 'u':
      f_fill = FillDec(elems, args, p_str, sign_plus);
      break;
    case 'X':
    case 'x':
    case 'p':
      f_fill = FillHex(elems, args, p_str, sign_plus);
      break;
    case 'o':
      f_fill = FillOct(elems, args, p_str, sign_plus);
      break;
  }
  if (!f_fill) {
    *p_str = temp_p_str;
    err = **p_str == '\0' ? -1 : 1;
  }
  return err;
}

int FillInt(S21SscanfArgs *elems, va_list *args, const char **p_str) {
  int err = 0;
  while (is_separator(*p_str)) {
    ++(*p_str);
  }
  const char *temp_p_str = *p_str;
  if (*temp_p_str != '\0' && (*temp_p_str == '+' || *temp_p_str == '-')) {
    ++temp_p_str;
  }
  if (*temp_p_str != '\0' && *temp_p_str == '0' &&
      (*(temp_p_str + 1) == 'x' || *(temp_p_str + 1) == 'X')) {
    elems->format = 'x';
    err = FillIntOther(elems, args, p_str);
  } else if (*temp_p_str == '0') {
    elems->format = 'o';
    err = FillIntOther(elems, args, p_str);
  } else if (*temp_p_str >= '0' && *temp_p_str <= '9') {
    elems->format = 'd';
    err = FillIntOther(elems, args, p_str);
  } else {
    err = **p_str == '\0' ? -1 : 1;
  }
  return err;
}

int FillValue(S21SscanfArgs *elems, va_list *args, const char **p_str) {
  int err = 0;
  switch (elems->format) {
    case 'c':
      err = FillChar(elems, args, p_str);
      break;
    case 's':
      err = FillStr(elems, args, p_str);
      break;
    case 'i':
      err = FillInt(elems, args, p_str);
      break;
    case 'd':
    case 'o':
    case 'x':
    case 'X':
    case 'p':
    case 'u':
      err = FillIntOther(elems, args, p_str);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      err = FillDouble(elems, args, p_str);
      break;
    case 'n':
      err = FillNScanf(elems, args);
      break;
  }
  return err;
}

int Scan_Value(const char *str, const char **p_str, const char **p_format,
            va_list *args, int *fill_count) {
  int err = 0;
  S21SscanfArgs *elems = ParseArgScanf(p_format);
  if (elems != s21_NULL) {
    if (**p_str == '\0' && elems->format != 'n' && elems->format != 's') {
      err = -1;
    } else {
      elems->count_fill_sym = labs(*p_str - str);  
      err = FillValue(elems, args, p_str);
      if (err) {
        free(elems);
      } else {
        *fill_count += elems->not_fill ? 0 : 1;
        free(elems);
      }
    }
  } else {
    err = 1;
  }
  return err;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int fill_count = 0;
  const char *p_str = str;
  int err = 0;
  for (const char *p_format = format; *p_format != '\0'; ++p_format) {
    if (is_separator(p_str) && is_separator(p_format))
      while (is_separator(p_str)) ++p_str;
    while (*p_format == *p_str && *p_format != '%' && *p_format != '\0') {
      ++p_format;
      ++p_str;
    }
    if (*p_format != '%' && !is_separator(p_str) && !is_separator(p_format) &&
        *p_format != *p_str)
      break;
    if (*p_format == '%') {
      ++p_format;
      if (*p_format == '%') {
        ++p_str;
      } else {
        err = Scan_Value(str, &p_str, &p_format, &args, &fill_count);
        if (err) {
          break;
        }
      }
    }
  }
  va_end(args);
  return err == -1 ? err : fill_count;
}

