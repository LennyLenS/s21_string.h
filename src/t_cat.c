#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

char *s21_strcat(char *dest, const char *src);

int main (void)
{    
  // Массив со строкой для поиска
  char str1 [70]="ert43d2542345d2f345dw4svf5fhg";
  char str2 [70]="//t435dqxfvg4664he464234";
  char str3 [70]="ert43d2542345d2f345erfdw45fhg";
//   char str [44]="uu/uuu/uuuu";
//   char str2 [44]="uu/uuu/uuuu";

  
    printf("ret *%s\n", strcat(str1, str2));
    printf("ret *%s\n", s21_strcat(str3, str2));
    printf("qq\n");
    
    // for(int i = 0; i <38; i++){
    //     printf("%d %c\n", i, haystack[i]);
    // }
  return 0;
}

char *s21_strcat(char *dest, const char *src){
    int p = (int)strlen(dest);
    int i = 0;
    while(*src != '\0') {
        *(dest + p +i) = *src;
        i++;
        src++;
    };
    return dest;
}