#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <stdarg.h>

#define s21_NULL ((void*)0)
#define S21_TEXTMAX 2048

typedef long unsigned s21_size_t;

void* s21_insert(const char* src, const char* str, s21_size_t start_index);
void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
int s21_sprintf(char* str, const char* format, ...);
char* s21_strchr(const char* str, int c);
char* s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
char* s21_strpbrk(const char* s1, const char* s2);
char* s21_strrchr(const char* str, int c);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);
void* s21_to_lower(const char* str);
void* s21_to_upper(const char* str);
void* s21_trim(const char* src, const char* trim_chars);
char* s21_itoa(int input, char* buff, int num);
char* s21_convert(char* buff, int size, unsigned int num, int base);
void d_specific(char* temp, va_list list, char* p, s21_size_t len, int* i,
                char* str, long long int num, int* size, s21_size_t width,
                int* num_flag, int* minus_flag);
void c_specific(va_list list, char* str, int* i, s21_size_t width, int* size,
                int* minus_flag);
void f_specific(va_list, char*, char*, s21_size_t, int*, char*, int, int*,
                s21_size_t width, int* minus_flag);
void s_specific(va_list, char*, unsigned char, int*, char*, s21_size_t width,
                int* size, int* minus_flag);
void flag_plus(va_list list, char* str, int* i, long long int* num,
               int* num_flag);
void flag_space(va_list list, char* str, int* i, long long int* num,
                int* num_flag);
char* s21_ftoa(char* buff, int size, float val, int digits);
int get_num(char** str);
int atoi(const char* str);
void o_specific(va_list list, char* str, int* i, long long int num,
                s21_size_t width, int* size, int* minus_flag);
char* s21_reverse(char* str);
void x_specific(va_list list, char* str, int* i, int spec_x, long long int num,
                s21_size_t width, int* size, int* minus_flag);
void percent_specific(char* str, int* i, int* size);
long long cast_to_h(va_list list, const char* format, int* num_flag);
void u_specific(char* temp, va_list list, char* p, unsigned char len, int* i,
                char* str, int* size, long long int num, s21_size_t width,
                int* num_flag, int* minus_flag);
void s21_utoa(long long int n, char s[]);
long long cast_to_l(va_list list, const char* format);

#endif
