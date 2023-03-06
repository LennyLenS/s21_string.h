#ifndef SRC_SUB_FUNC_H_
#define SRC_SUB_FUNC_H_

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  char length;      // Длина
} Prototype;
void shift_str(char *str, int size);

void UDecInNumSys(char *buff, unsigned long long int n, int mes, int flag);

void s21_long_double_to_str(long double num, char *str, int pres,
                            int sharp_flag);

void *s21_reverse(char *str, int neg_flag);

int print_spaces(char *str, int n, int j);

int prep_string(char *str, char *strng_arg, int n, int j);

int s21_check_arg(Prototype *prot, char *intermediate_str,
                  int counter_symbols_str, double num);

#endif