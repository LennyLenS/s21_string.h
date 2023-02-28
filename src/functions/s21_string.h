#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"

#define s21_size_t unsigned long
#define S21_NULL NULL

char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, size_t n);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *src);

#endif
