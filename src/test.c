#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "s21_sprintf.h"
int main()
{
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho%34.23n";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  int valn1 = 0, valn2 = 0;

 int a = sprintf(str1, str3, val, val2, (unsigned short)val3, &valn1);
      int b = s21_sprintf(str2, str3, val, val2, (unsigned short)val3, &valn2);
  

   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}