#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{

 char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 823631075973858585858447757573.6495633;

  long int k = (long int)(num + 0.0000001f);
  printf("%li\n", k);
   
}

// 72363107597385858