#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(){
    char s[] = "true\0fail";
    char *s2 = (char *)malloc(100);
    printf("%s", (char*)s21_memchr(s, 'i', 8));
}