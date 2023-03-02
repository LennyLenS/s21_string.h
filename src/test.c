#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{

  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
   int a = sprintf(str1, str3, val, val2, val3);
   int b = s21_sprintf(str2, str3, val, val2, val3);
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}