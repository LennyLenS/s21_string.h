#include "s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
  size_t count = 0;
  int flag = 0;
  while (*str1 != '\0' && flag == 0) {
    const char *str_tmp = str2;
    while (*str_tmp != '\0') {
      if (*str1 == *str_tmp) {
        count++;
        flag = 0;
        break;
      } else {
        flag = 1;
        str_tmp++;
      }
    }
    str1++;
    if (flag == 1) break;
  }
  return count;
}