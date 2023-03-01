#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{

   char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
   int a = sprintf(str1, str3, num, num);
   int b = s21_sprintf(str2, str3, num, num);
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}