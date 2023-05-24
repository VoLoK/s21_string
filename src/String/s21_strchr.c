#include "s21_string.h"
// char *s21_strchr(const char *str, int c);
// int main(){
// const char strok[10]="sosi116";
//     printf("%c", *s21_strchr(strok,'6'));

// }

char* s21_strchr(const char* str, int c) {
    while (*str != (char)c) {
        if (!*str) {
            return NULL;
        }
        str++;
    }
    return (char*)str;
}
