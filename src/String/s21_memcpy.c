#include "s21_string.h"

void *memcpy(void *dest, const void *src, s21_size_t n) {
    char *source = (char *) src;
    char *destination = (char *) dest;
    int i = 0;
    for (; i < n; i++) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}