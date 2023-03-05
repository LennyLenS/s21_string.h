#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "s21_sprintf.h"
int main()
{
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  sprintf(str1, str3, val, val2, val3, val4);
                   s21_sprintf(str2, str3, val, val2, val3, val4);

   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}

