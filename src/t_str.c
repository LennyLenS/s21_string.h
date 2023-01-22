#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

char *s21_strstr(const char *haystack, const char *needle);

int main (void)
{    
  // Массив со строкой для поиска
  char haystack [44]="//$/test1//te@st2/test3//sd";
  char needle [44]="te";
//   char str [44]="uu/uuu/uuuu";
//   char str2 [44]="uu/uuu/uuuu";
  // Набор символов, которые должны входить в искомый сегмент


//   printf ("Исходная строка: %s\n", str);
//   printf ("Делители: %s\n", sep);
//   printf ("Результат разбиения:\n");
  
    printf("ret1 *%s    *%s\n", s21_strstr(haystack, needle), strstr(haystack, needle));
    
    // for(int i = 0; i <38; i++){
    //     printf("%d %c\n", i, haystack[i]);
    // }
  return 0;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if(*needle == '\0') return (char*)haystack;
    int i = 0;
    // const char *haystack_p = haystack;
    while(haystack[i] != '\0'){
        int j = 0;
        int k = i;
        // printf("%d %c\n", i, haystack[i]);
        while(needle[j] != '\0' || haystack[k] != '\0'){
            if(needle[j] != haystack[k]) break;
            // printf("%d %c  %s\n", i, needle[j], (char*)haystack_p);
            k++;
            j++;
        }
        if(needle[j] == '\0') return (char*)haystack + i;
    i++;
    }
    return NULL;
}


