#include <limits.h>
#include <stdio.h>

#include "./s21_string_files/s21_string.h"
#include "s21_sprintf.h"
int main() {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %0.0o";
  int val = 0;

  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  printf("!%s!\n!%s!\n", str1, str2);
}