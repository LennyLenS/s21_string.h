#ifndef SRC_S21_SPECIFICATORS_
#define SRC_S21_SPECIFICATORS_

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "sub_func.h"
#include "../s21_string_files/s21_string.h"

int specifier_o(char *buff, va_list args, Prototype prot);
int specifier_x(char *buff, va_list args, Prototype prot);
int specifier_X(char *buff, va_list args, Prototype prot);
int specifier_u(char *buff, va_list args, Prototype prot);
int specifier_f(char *buff, va_list args, Prototype prot);

int s21_spec_c(char *str, va_list args, Prototype *prot, int j);
int s21_spec_id(va_list args, Prototype *prot, char *charbuf);
void s21_spec_n(va_list args, int j);
int s21_spec_s(char *str, va_list args, Prototype *prot, int j);
int s21_spec_p(va_list args, char *charbuf);

#endif
