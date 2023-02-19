#include "s21_string.h"

// первое вхождение символа с в строку str
char *s21_strchr(const char *str, int c) {
  const char *p = str;
  char *result = NULL;

  while (*p != '\0') {
    if ((int)(*p) == c) {
      result = (char *)p;
      break;
    }
    p++;
  }
  if(c == '\0'){
    result = (char *)p;
  }
  return result;
}
