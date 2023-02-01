#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2.
size_t s21_strspn(const char *str1, const char *str2) {
  const char *p;
  for (p = str1; *p != '\0'; ++p) {
    if (!s21_strchr(str2, *p)) break;
  }
  return p - str1;
}
