#include <stdio.h>
#include <limits.h>
#include "s21_sprintf.h"
#include "./s21_string_files/s21_string.h"
int main()
{
    char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 76.756589367;
  sprintf(str1, str3, num, num, num, num, num);
                   s21_sprintf(str2, str3, num, num, num, num, num);

      
   printf("!%s!\n!%s!\n", str1, str2);
}

