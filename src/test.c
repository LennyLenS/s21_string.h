#include <limits.h>
#include <stdio.h>

#include "./s21_string_files/s21_string.h"
#include "s21_sprintf.h"
int main() {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  printf("!%s!\n!%s!\n", str1, str2);

  char str3[200];
  char str4[200];
  char *str5 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  sprintf(str3, str5, num, num, num, num, num);
  s21_sprintf(str4, str5, num, num, num, num, num);

  printf("!%s!\n!%s!\n", str3, str4);
}
