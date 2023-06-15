#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include <stdarg.h>

#include "s21_string.h"

char* s21_itoa(int input, char* buff, int num);
char* s21_convert(char* buff, int size, unsigned int num, int base);
void d_specific(char*, va_list, char*, unsigned char, int*, char*);
void c_specific(void);
void f_specific(va_list list, float value, char *p, char* temp, unsigned char len, int* i, char* str);
void s_specific(va_list, char*, unsigned char, int*, char*);
void u_specific(void);
void percent_specific(void);
char* s21_ftoa(char* buff, int size, float val, int digits);

#endif
