#include "s21_string.h"

char *s21_strpbrk(const char *s1, const char *s2)
{
 int flag=0;
    if((s1 == NULL) || (s2 == NULL))
        flag=1;
    while(*s1 && flag!=1)
    {
        if(s21_strchr(s2, *s1))
        {
            return (char *)s1;
        }
        else
        {
            s1++;
        }
    }
    return NULL;
}