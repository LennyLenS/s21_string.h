#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{
 char str1[400];
  char str2[400];
  char *str3 = "test: %-+.1Lf!\ntest: %- .2Lf!\ntest: %-0.3Lf!";
  long double num = -0.999999;
//   sprintf(str1, str3, num, num, num);
//   s21_sprintf(str2, str3, num, num, num);

   int a = sprintf(str1, str3, num, num, num);
   int b = s21_sprintf(str2, str3, num, num, num);
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", a, b);
}