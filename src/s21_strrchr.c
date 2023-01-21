#include "s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  const char *p = str;
  char *result = NULL;

  while (*p != '\0') {
    if ((int)(*p) == c) {
      result = (char *)p;
    }
    p++;
  }
  return result;
}