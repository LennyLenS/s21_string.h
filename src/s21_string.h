#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdlib.h>

#define s21_size_t unsigned int;     // или через  typedef unsigned int size_t; ?  будем привязываться к размеру адреса?
#define NULL // <either 0, 0L, or (void *)0> [0 in C++]  нашел это, но не знаю как правильно, (void *)0  - ok

void *memchr(const void *str, int c, size_t n);
int memcmp(const void *str1, const void *str2, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *str, int c, size_t n);
size_t strlen(const char *str);
