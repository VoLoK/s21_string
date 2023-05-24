#include "s21_string.h"
// size_t s21_strlen(const char *str);
// int main(){
//     const char * stroka="123456";
//     printf("%d",s21_strlen(stroka));
// }
s21_size_t s21_strlen(const char *str){
    size_t len;
    for (len = 0; *(str + len); len++)
        ;
    return len;
}