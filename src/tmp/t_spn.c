#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

size_t s21_strcspn(const char *str1, const char *str2);   // Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.

int main (void)
{    
  // Массив со строкой для поиска
  char str1 [44]="jxdw4oikj";
  char str2 [44]="jkio";
//   char str [44]="uu/uuu/uuuu";
//   char str2 [44]="uu/uuu/uuuu";
  // Набор символов, которые должны входить в искомый сегмент


//   printf ("Исходная строка: %s\n", str);
//   printf ("Делители: %s\n", sep);
//   printf ("Результат разбиения:\n");
  
    printf("ret *%ld    *%ld\n", s21_strcspn(str1, str2), strcspn(str1, str2));
    
    // for(int i = 0; i <38; i++){
    //     printf("%d %c\n", i, haystack[i]);
    // }
  return 0;
}

size_t s21_strspn(const char *str1, const char *str2){
    size_t count = 0;
    int flag = 0;
    printf("strq *%c\n", *str2);
    while(*str1 != '\0' && flag == 0) {
        const char *str_tmp = str2;
        while(*str_tmp != '\0'){
            printf("str *%c    %c   %d\n", *str1, *str_tmp, flag);
            if(*str1 == *str_tmp){
                count++;
                printf("qq\n");
                flag =0;
                break;
            } else {
                flag =1;
                str_tmp++;
            }
        }
        str1++;
        if(flag == 1) break;
    }
    return count;
}

size_t s21_strcspn(const char *str1, const char *str2){
    size_t count = 0;
    int flag = 0;
    printf("strq *%c\n", *str2);
    while(*str1 != '\0' && flag == 0) {
        const char *str_tmp = str2;
        while(*str_tmp != '\0'){
            printf("str *%c    %c   %d\n", *str1, *str_tmp, flag);
            if(*str1 != *str_tmp){
                flag =0;
                str_tmp++;
            } else {
                printf("qq\n");
                flag =1;
                break;
            }
        }
        str1++;
        if(flag == 1) break;
        count++;
    }
    return count;
}