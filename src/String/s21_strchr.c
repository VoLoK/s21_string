#include "s21_string.h"
char* s21_strchr(const char* str, int c) {
    while (*str != (char)c) {
        if (!*str) {
            return NULL;
        }
        str++;
    }
    return (char*)str;
}
