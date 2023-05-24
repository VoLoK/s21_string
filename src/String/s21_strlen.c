#include "s21_string.h"
s21_size_t s21_strlen(const char *str){
    s21_size_t len;
    for (len = 0; *(str + len); len++);
    return len;
}