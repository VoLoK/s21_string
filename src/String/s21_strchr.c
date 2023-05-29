#include "s21_string.h"
char *s21_strchr(const char* str, int c){
    char *zavupa[4096];
    int flag=0;
    while (*str !='\0')
    {
        if (*str == c) *zavupa= (char *) str;
        str++;
        flag=1;
    }
    return (flag!=0) ? *zavupa :NULL;
}   
