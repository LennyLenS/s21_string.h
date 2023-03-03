#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "s21_sprintf.h"
int main()
{

 char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;

  int a = sprintf(str1, str3, val, val2, val3, val4, val5);
   int b = s21_sprintf(str2, str3, val, val2, val3, val4, val5);

               
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}

// 72363107597385858