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

char *DecInHex(int n);
char *DecInOct(int n);
char *DecInBin(int n);

char *specifier_o(unsigned int n);
#endif