#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>

#include "functions/s21_string.h"

typedef struct {
  bool c;  // Символ
  bool d;  // Знаковое десятичное целое число
  bool i;  // Знаковое десятичное целое число
  bool e;  // Научная нотация (мантисса/экспонента) с использованием символа e
           // (вывод чисел должен совпадать с точностью до e-6)
} Specifications;

// %[флаги][ширина][.точность][длина]спецификатор
typedef struct {
  char spec;         // спецификаторы
  int minus_flag;    // флаг -
  int plus_flag;     // флаг +
  int space_flag;    // флаг ' '
  int zero_flag;     // флаг 0
  int sharp_flag;    // флаг #
  int width_number;  // Ширина (число), *
  int width_star;
  int prec_number;  // Точность если .число
  int prec_star;    // Точность если .*
  int length;       // Длина
  int length_h;
  int length_l;
  int length_L;
} Prototype;

int s21_sprintf(char *str, const char *format, ...);
int s21_parser(char *str, const char *format, va_list args);
int s21_read_format(Prototype *prot, const char *format, int i, va_list args);
bool s21_check_number(const char *format, int i);
int s21_write_number(const char *format, int *i);
void s21_check_flags(const char *format, int i, Prototype *prot,
                     int *this_is_prec, int *this_is_width);
void s21_check_width(const char *format, int i, int *this_is_width,
                     Prototype *prot, va_list args);
int s21_check_prec(const char *format, int i, int *this_is_prec,
                   Prototype *prot, va_list args);
#endif