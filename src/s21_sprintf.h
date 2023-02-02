#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_1

#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  bool c;  // Символ
  bool d;  // Знаковое десятичное целое число
  bool i;  // Знаковое десятичное целое число
  bool e;  // Научная нотация (мантисса/экспонента) с использованием символа e
           // (вывод чисел должен совпадать с точностью до e-6)
} Specifications;

// %[флаги][ширина][.точность][длина]спецификатор
typedef struct {
  int spec;          // спецификаторы
  int minus_flag;    // флаг -
  int plus_flag;     // флаг +
  int space_flag;    // флаг ' '
  int zero_flag;     // флаг 0
  int sharp_flag;    // флаг #
  int width_number;  // Ширина (число), *
  int width_star;
  int prec;
  int prec_number;  // Точность если .число
  int prec_star;    // Точность если .*
  int length;       // Длина
  int length_h;
  int length_l;
  int length_L;
} Prototype;

void s21_sprintf(char *str, const char *format, ...);
void s21_parser(char *str, const char *format, va_list args);
int s21_read_format(Prototype *prot, const char *format, int i);
bool s21_check_number(const char *format, int i);

#endif