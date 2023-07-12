#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <limits.h>
#include <stdarg.h>

#include "s21_string.h"

char* s21_itoa(int input, char* buff, int num);
char* s21_convert(char* buff, int size, unsigned int num, int base);
void d_specific(char* temp, va_list list, char* p, s21_size_t len, int* i,
                char* str, long long int num, int* size, s21_size_t width);
void c_specific(va_list list, char* str, int* i, s21_size_t width);
void f_specific(va_list, char*, char*, s21_size_t, int*, char*, int, int*,
                s21_size_t width);
void s_specific(va_list, char*, unsigned char, int*, char*, s21_size_t width);
void flag_plus(va_list list, char* str, int* i, long long int* num);
void flag_space(va_list list, char* str, int* i, long long int* num);
char* s21_ftoa(char* buff, int size, float val, int digits);
int get_num(char** str);
int atoi(const char* str);
void o_specific(va_list list, char* str, int* i, long long int num, s21_size_t width);
char* s21_reverse(char* str);
void x_specific(va_list list, char* str, int* i, int spec_x, long long int num,
                s21_size_t width);
void percent_specific(va_list list, char* str, int* i, long long int* num);
long long cast_to_h(va_list list, const char* format);
void u_specific(char* temp, va_list list, char* p, unsigned char len, int* i,
                char* str, int* size, long long int num, s21_size_t width);
void s21_utoa(long long int n, char s[]);
long long cast_to_l(va_list list, const char* format);

#endif
