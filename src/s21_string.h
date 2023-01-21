#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long int
#define s21_NULL (void *)0

char *s21_strncat(
    char *dest, const char *src,
    s21_size_t n);  // Добавляет строку, на которую указывает src, в конец строки,
                // на которую указывает dest, длиной до n символов.
char *s21_strchr(
    const char *str,
    int c);  // Выполняет поиск первого вхождения символа c (беззнаковый тип) в
             // строке, на которую указывает аргумент str.
s21_size_t s21_strlen(const char *str);  // Вычисляет длину строки str, не
                                         // включая завершающий нулевой символ.
char *s21_strpbrk(
    const char *str1,
    const char *str2);  // Находит первый символ в строке str1, который
                        // соответствует любому символу, указанному в str2.
char *s21_strrchr(
    const char *str,
    int c);  // Выполняет поиск последнего вхождения символа c (беззнаковый тип)
             // в строке, на которую указывает аргумент str.
s21_size_t s21_strspn(
    const char *str1,
    const char *str2);  // Вычисляет длину начального сегмента str1, который
                        // полностью состоит из символов str2.

#endif  // SRC_S21_STRING_H_
