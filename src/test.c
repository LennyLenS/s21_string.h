#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{
//char str1[100];
   char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  int a = sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  int b  = s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
   
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}