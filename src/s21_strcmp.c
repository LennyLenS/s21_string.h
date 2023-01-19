// #include <stdio.h>

#include "s21_string.h"
// Сравнивает строку, на которую указывает str1, со строкой, на которую
// указывает str2.

int main() {
  const char str1[16] = "12345";
  const char str2[16] = "12345";
  s21_strcmp(str1, str2);
}

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  bool flag = true;
  while (*str1 == *str2 && flag == true) {
    str1++;
    str2++;
    if (*str1 == '\0' && *str2 == '\0') flag = false;
  }
  res = *str1 - *str2;
  // printf("%d", res);
  return res;
}