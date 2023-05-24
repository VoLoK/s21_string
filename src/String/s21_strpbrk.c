#include "s21_string.h"
// char* s21_strchr(const char* str, int c) {
//     while (*str != (char)c) {
//         if (!*str) {
//             return NULL;
//         }
//         str++;
//     }
//     return (char*)str;
// }

char *s21_strpbrk(const char *s1, const char *s2)
{
 int flag=0;
    //return null if any one is NULL
    if((s1 == NULL) || (s2 == NULL))
        flag=1;
    while(*s1 && flag!=1)
    {
        //return s1 char position if found in s2
        //if not found return NULL
        if(s21_strchr(s2, *s1))
        {
            //return from function
            //if char found in s2
            return (char *)s1;
        }
        else
        {
            s1++;
        }
    }
    return NULL;
}

int main(){
    char str [11]="0123456789";
   char sym [10]="369";
   char *p = s21_strpbrk(str,sym);
   printf("%c", *p);
}