#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  bool c;  // Символ
  bool d;  // Знаковое десятичное целое число
  bool i;  // Знаковое десятичное целое число
  bool e;  // Научная нотация (мантисса/экспонента) с использованием символа e
           // (вывод чисел должен совпадать с точностью до e-6)
} Specifications;

typedef struct {
  int specification;  // спецификаторы
  int flags;          // флаги спринтфа -, +, " ", #, 0
  int minus_flags;
  int plus_flags;
  int space_flags;
  int zero_flags;
  int sharp_flags;
  int width;  // Ширина (число), *
  int width_star;
  int precision;  // Точность
  int length;     // Длина

} Prototype;

Prototype s21_init_prototype();
int s21_sprintf(char *str, const char *format, ...);
int s21_parser(char *str, const char *format, va_list args);

#endif