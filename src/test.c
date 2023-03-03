#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{

  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 1234567896541234.6495633;
  long double num2 = num / 10e17;
  // printf("%.23Lf\n", num2);
  // printf("  %Lf", num);
   int a =  sprintf(str1, str3, num, num, num);
   int b = s21_sprintf(str2, str3, num, num, num);
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}

// 72363107597385858