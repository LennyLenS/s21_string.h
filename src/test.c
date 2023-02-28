#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{
	char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
  double num = -76.756589367;

   int a = s21_sprintf(str1, str3, num, num, num, num, num);
   int b = sprintf(str2, str3, num, num, num, num, num);
   printf("!%s!\n!%s!\n", str1, str2);
   printf("%d %d", a, b);
}