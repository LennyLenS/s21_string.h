#include <limits.h>
#include <stdio.h>

#include "./s21_string_files/s21_string.h"
#include "s21_sprintf.h"
int main() {
  // char str1[200];
  // char str2[200];
  // char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  // double num = 573429.56589367;
  // sprintf(str1, str3, num, num, num, num, num);
  // s21_sprintf(str2, str3, num, num, num, num, num);
  // printf("!%s!\n!%s!\n", str1, str2);

  char str4[200];
  char str5[200];
  char *str6 = "test: %Lg!\n";
  long double num1 = NAN;
  sprintf(str4, str6, num1, num1, num1, num1, num1);
  s21_sprintf(str5, str6, num1, num1, num1, num1, num1);

  printf("!%s!\n!%s!\n", str4, str5);

  // char str7[200];
  // char str8[200];
  // char *str9 = "test: %+20.13g!\ntest: %+25.7g!";
  // double num2 = 0.00000235300;
  // sprintf(str7, str9, num2, num2, num2, num2, num2);
  // s21_sprintf(str8, str9, num2, num2, num2, num2, num2);

  // printf("!%s!\n!%s!\n", str7, str8);
}
