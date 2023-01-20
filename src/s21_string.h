#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, size_t n);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);

#endif