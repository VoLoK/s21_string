#include "s21_string.h"

void *memchr(const void *str, int c, size_t n) {
    const char *ptr = (const char *)str;
    size_t i;
    
    for (i = 0; i < n; i++)
        if (prt[i] == c)
            return (void *)&prt[i];
    
    return NULL;
}
