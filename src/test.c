#include <stdio.h>
#include <limits.h>
#include "s21_sprintf.h"
#include "./s21_string_files/s21_string.h"
int main()
{
   char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WHAT IS THIS";
  char *val2 = "idx";
  char *val3 = "PPAP";
  char *val4 = "I don't";
  char *val5 = "What is lovin'?!";

  sprintf(str1, str3, val, val2, val3, val4, val5);
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5);

   printf("!%s!\n!%s!\n", str1, str2);
}

