#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "s21_sprintf.h"
int main()
{
  char str1[200];
  char str2[200];
  char* str3 = "%p Test %3.p Test %5.7p TEST %10p %#p %-p %+p %.p % .p";
  char* val = 0;

      sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}

