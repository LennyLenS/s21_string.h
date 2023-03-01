#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{

  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
   int a = sprintf(str1, str3, val, val2, val3, val4);
   int b = s21_sprintf(str2, str3, val, val2, val3, val4);
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}