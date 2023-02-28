#include "s21_string.h"

// Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
  int save_i = 0;
  int i = 0;
  for (i = 0; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  if (save_i == 0) save_i = i;
  if (src[i] == '\0') dest[i] = '\0';
  return dest;
}