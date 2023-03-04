#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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
  char length;      // Длина
} Prototype;

  #define SPACES " \t\n\v"
  // #define S21_INFINITY 1.0 / 0.0

long long int s21_atoi(char *str);
int isNumber(char c);
int s21_sscanf(const char *str, const char *format, ...);
int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str, int *j, va_list args, int space_counter_for_n);
int scanf_spec_d(Prototype *prot, const char *str,  char *buff_str, va_list args, int width_counter, int *j);
int scanf_spec_c(Prototype *prot, const char *str,  char *buff_str, va_list args, int *j);
int scanf_spec_s(Prototype *prot, const char *str,  va_list args,  char *buff_str, int width_counter, int *j);
void scanf_spec_n(va_list args, int *j, int space_counter_for_n);

int s21_read_format(Prototype *prot, const char *format, int i, va_list args);
int s21_check_prec(const char *format, int i, int *this_is_prec, Prototype *prot, va_list args);
void s21_check_width(const char *format, int i, int *this_is_width, Prototype *prot);
void s21_check_flags(const char *format, int i, Prototype *prot, int *this_is_prec, int *this_is_width);
bool s21_check_number(const char *format, int i);
int s21_write_number(const char *format, int *i);

#endif  // SRC_S21_SSCANF_H_