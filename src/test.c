#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{
   char str1[400];
  char str2[400];
  char *str3 = "%20.10f\n%20.15f\n%-20.5f!";
  double num = -76.756589;

   int a = sprintf(str1, str3, num, num, num);
   int b = s21_sprintf(str2, str3, num, num, num);
   printf("!%s!\n!%s!\n", str1, str2);
   printf("%d %d", a, b);
}