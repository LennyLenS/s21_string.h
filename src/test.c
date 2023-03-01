#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{
<<<<<<< HEAD
 char str1[400];
  char str2[400];
  char *str3 = "test: %-+.1Lf!\ntest: %- .2Lf!\ntest: %-0.3Lf!";
  long double num = -0.999999;
//   sprintf(str1, str3, num, num, num);
//   s21_sprintf(str2, str3, num, num, num);

   int a = sprintf(str1, str3, num, num, num);
   int b = s21_sprintf(str2, str3, num, num, num);
=======

   char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
   int a = sprintf(str1, str3, num, num);
   int b = s21_sprintf(str2, str3, num, num);
>>>>>>> 753c65899798ad048a723f3b61d3f695838be585
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}