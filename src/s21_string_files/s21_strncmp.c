#include "s21_string.h"
// Сравнивает не более первых n байтов str1 и str2.

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int res = 0;
  int flag = 1;
  for (size_t i = 1; i < n && *str1 == *str2 && flag == 1; i++) {
    str1++;
    str2++;
    if (*str1 == '\0' && *str2 == '\0') flag = 0;
  }
  res = *str1 - *str2;
  return res;
}
