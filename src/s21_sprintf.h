#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>

#include "functions/s21_string.h"

#define PRECISION 6;

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
int s21_args_to_str(int j, char *str, Prototype *prot, va_list args);
int s21_spec_c(int j, char *str, va_list args);
char *s21_spec_e(int j, char *str, char *intermediate_str, va_list args,
                 Prototype *prot);
// int s21_spec_e(int j, char *str, va_list args, Prototype *prot);
void *s21_reverse(char *str);
int s21_double_to_str(long double num, char *str_double, int num_i);
int s21_isnan(double number);
int s21_spec_g(int counter_symbols_str, char *str, char *intermediate_str,
               va_list args, Prototype *prot);
int s21_check_arg(Prototype *prot, int counter_symbols_str, char *str,
                  double num);
bool s21_mantisssa_and_degree(double *num, bool flag_zero, int *num_int,
                              int *e);
void s21_fractional_and_integer_part_of_a_number(int *num_int, double *num);
int s21_rounding_and_precision_number(double *num, int *multiply,
                                      Prototype *prot,
                                      double *save_number_for_g, int *e,
                                      int *check_g, int *precison);
void s21_writing_int_number_with_point(int *num_int, int *symbol, char *str_int,
                                       bool flag_zero_negative,
                                       int *counter_symbols_str,
                                       int *dont_write_number_with_point,
                                       double *save_number_for_g, int *e,
                                       Prototype *prot);
int s21_concat_fractional_number_with_degree(int num_i, int counter_symbols_str,
                                             char *str_double, double num,
                                             Prototype *prot, char symbol_e,
                                             int e, char *str_degree,
                                             int *dont_write_number_with_point);
void s21_check_fractional_number_for_zeros(int *multiply, char *str_double);

#endif