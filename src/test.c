#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "s21_sprintf.h"
int main()
{
   char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  int a = sprintf(str1, str3, val, val2, val3, val4, val5);
   int b = s21_sprintf(str2, str3, val, val2, val3, val4, val5);
  

   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}