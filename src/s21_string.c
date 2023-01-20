#include "s21_string.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

// Длина сроки
s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  const char *p = str;
  while (*p != '\0') {
    size++;
    p++;
  };
  return size;
}

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
  return result;
}

// соединение строк
char *s21_strncat(char *dest, const char *src, size_t n) {
  char *result = dest;

  if (n > 0) {
    while (*dest != '\0') {
      dest++;
    }
    while ((*(dest++) = *(src++)) != 0) {
      n--;
      if (n == 0) {
        *dest = '\0';
        break;
      }
    }
  }
  return result;
}

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  const char *s1, *s2;
  for (s1 = str1; *s1 != '\0'; ++s1) {
    for (s2 = str2; *s2 != '\0'; ++s2) {
      if (*s1 == *s2) return (char *)s1;
    }
  }
  return NULL;
}

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

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2.
size_t s21_strspn(const char *str1, const char *str2) {
  const char *p;
  for (p = str1; *p != '\0'; ++p) {
    if (!s21_strchr(str2, *p)) break;
  }
  return p - str1;
}