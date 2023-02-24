#ifndef SRC_SUB_FUNC_H_
#define SRC_SUB_FUNC_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

int specifier_o(char *buff, va_list args, Prototype prot);

int specifier_u(char *buff, va_list args, Prototype prot);

int specifier_X(char *buff, va_list args, Prototype prot);

void s21_double_to_str(double num, char *str, int pres);
int specifier_f(char *buff, va_list args, Prototype prot);
#endif