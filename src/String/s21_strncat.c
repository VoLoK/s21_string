#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ref = dest;
    
    while (*ref)
        ref++;
    while (n--)
        *ref++ = *src++;
    *ref = '\0';
    
    return dest;
}
