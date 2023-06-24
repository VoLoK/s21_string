#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include <stdarg.h>

#include "s21_string.h"

char* s21_itoa(int input, char* buff, int num);
char* s21_convert(char* buff, int size, unsigned int num, int base);
void d_specific(char* temp, va_list list, char* p, unsigned char len, int* i,
                char* str, int num, int* size);
void c_specific(va_list list, char* str, int* i);
void f_specific(va_list, char*, char*, unsigned char, int*, char*, int);
void s_specific(va_list, char*, unsigned char, int*, char*);
void u_specific(void);
void percent_specific(void);
void flag_plus(va_list list, char* str, int* i, int* num);
void flag_space(va_list list, char* str, int* i, int* num);
char* s21_ftoa(char* buff, int size, float val, int digits);
int get_num(char** str);
int atoi(const char* str);
void o_specific(va_list list, char* str, int* i);
char* s21_reverse(char* str);

#endif
