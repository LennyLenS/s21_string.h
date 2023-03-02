#ifndef SRC_SUB_FUNC_H_
#define SRC_SUB_FUNC_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
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

void s21_double_to_str(long double num, char *str, int pres, int sharp_flag);

void *s21_reverse (char *str);

int print_spaces(char *str, int n, int j);

int prep_string(char *str, char *strng_arg, int n, int j);

int s21_check_arg(Prototype *prot, int counter_symbols_str, char *str,
                  double num);


bool s21_mantisssa_and_degree(double *num, bool flag_zero, int *num_int, int *e,
                              Prototype *prot);

void s21_fractional_and_integer_part_of_a_number(int *num_int, double *num,
                                                 Prototype *prot,
                                                 bool flag_zero_negative,
                                                 bool flag_minus_num_g);

int s21_rounding_and_precision_number(
    double *num, int *multiply, Prototype *prot, double *save_number_for_g,
    int *e, int *check_g, int *precision, bool flag_zero_plus,
    bool flag_zero_negative, bool flag_g, int *save_precision_for_rounding_g);

void s21_writing_int_number_with_point(int *num_int, int *symbol, char *str_int,
                                       bool flag_zero_negative,
                                       int *counter_symbols_str,
                                       int *dont_write_number_with_point,
                                       double *save_number_for_g, int *e,
                                       Prototype *prot, int *num_i_g,
                                       bool flag_minus_num);

int s21_concat_fractional_number_with_degree(
    int num_i, int counter_symbols_str, char *str_double, double num,
    Prototype *prot, char symbol_e, int e, char *str_degree,
    int *dont_write_number_with_point);

void s21_check_fractional_number_for_zeros(int *multiply, char *str_double,
                                           bool flag_minus_num);
#endif