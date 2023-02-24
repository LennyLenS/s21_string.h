#include "s21_specificators.h"

char *s21_spec_e(int counter_symbols_str, char *str, char *intermediate_str,
                 va_list args, Prototype *prot) {
  int e = 0;
  int num_int = 0;
  int symbol = 0;
  int num_i = 0;
  char str_int[512] = {'\0'};
  char str_double[270] = {'\0'};
  char str_double_g[270] = {'\0'};
  char symbol_e = '\0';
  char str_degree[560] = {'\0'};
  bool flag_zero = false;
  bool flag_zero_negative = false;
  bool flag_zero_plus = false;
  bool flag_minus_num = false;
  bool flag_minus_num_g = false;
  bool check_num_i_g = false;
  bool flag_g = false;
  int multiply = 1;
  int dont_write_number_with_point = 0;
  int check_g = 0;
  int precision = 6;
  int save_precision_for_rounding_g = 0;
  int save_multiply = 0;
  int multiply_for_fractional_num = 1;
  int multiply_num_i_g = 1;
  int num_i_g = 0;
  double num = 0.;
  if (prot->length == 'L')
    num = va_arg(args, long double);
  else
    num = va_arg(args, double);
  double save_number_for_g = num;
  if (s21_check_arg(prot, counter_symbols_str, str, num) != 0)
    return intermediate_str;
  if (prot->spec == 'g' || prot->spec == 'G') flag_g = true;
  if ((prot->spec == 'e' || prot->spec == 'E') && (num < 1 && num > 0.0) &&
      flag_zero_plus == false)
    flag_zero_plus = true;
  if ((prot->spec == 'g' || prot->spec == 'G') && (num < 1 && num > 0.0) &&
      flag_zero_plus == false)
    flag_zero_plus = true;
  if ((prot->spec == 'g' || prot->spec == 'G') && (num < 0))
    flag_minus_num_g = true;
  flag_zero_negative =
      s21_mantisssa_and_degree(&num, flag_zero, &num_int, &e, prot);
  if (num_int == 0 && (prot->spec == 'g' || prot->spec == 'G')) {
    str_int[0] = '0';
    s21_strcat(intermediate_str, str_int);
    printf("Finally1: %s\n", intermediate_str);
    return intermediate_str;
  }
  s21_fractional_and_integer_part_of_a_number(
      &num_int, &num, prot, flag_zero_negative, flag_minus_num_g);
  dont_write_number_with_point = s21_rounding_and_precision_number(
      &num, &multiply, prot, &save_number_for_g, &e, &check_g, &precision,
      flag_zero_plus, flag_zero_negative, flag_g,
      &save_precision_for_rounding_g);
  if (check_g != 1) {
    s21_writing_int_number_with_point(
        &num_int, &symbol, str_int, flag_zero_negative, &counter_symbols_str,
        &dont_write_number_with_point, &save_number_for_g, &e, prot, &num_i_g,
        flag_minus_num);
    counter_symbols_str = s21_concat_fractional_number_with_degree(
        num_i, counter_symbols_str, str_double, num, prot, symbol_e, e,
        str_degree, &dont_write_number_with_point);
    s21_check_fractional_number_for_zeros(&multiply, str_double,
                                          flag_minus_num);

    s21_strcat(str_int, str_double);  // соединяем 2 строки получаем число
    s21_strcat(intermediate_str,
               str_int);  // закидываем готовый результат в промежуточную строку
  } else {
    s21_writing_int_number_with_point(
        &num_int, &symbol, str_int, flag_zero_negative, &counter_symbols_str,
        &dont_write_number_with_point, &save_number_for_g, &e, prot, &num_i_g,
        flag_minus_num);
    save_multiply = multiply;
    precision++;
    s21_check_fractional_number_for_zeros(&multiply, str_double,
                                          flag_minus_num);
    while (precision > 0 && multiply != 1) {
      precision--;
      save_multiply *= 10;
    }
    //  Разобраться с дробной частью частью когда степень e положительная

    save_number_for_g *= save_multiply;
    // Разобраться с точностью
    if (num_i_g == 0) {
      while (precision > 0) {
        precision--;
        multiply_for_fractional_num *= 10;
      }
    } else
      num_i_g = precision - num_i_g;
    if (num_i_g != 0) {
      while (num_i_g > 0) {
        num_i_g--;
        multiply_num_i_g *= 10;
      }
      check_num_i_g = true;
    }
    s21_fractional_and_integer_part_of_a_number(&num_int, &save_number_for_g,
                                                prot, flag_zero_negative,
                                                flag_minus_num_g);
    if (num_i_g == 0 && check_num_i_g == false)
      save_number_for_g *= multiply_for_fractional_num;
    // ТУТ ТОЖЕ НАДО ОКРУГЛЯТЬ
    else {
      save_number_for_g *= multiply_num_i_g;
      save_number_for_g =
          round(save_number_for_g * pow(10, save_precision_for_rounding_g)) /
          pow(10, save_precision_for_rounding_g);
    }
    save_number_for_g = (int)save_number_for_g;
    // if (save_number_for_g < 0) save_number_for_g *= -1;
    s21_double_to_str(save_number_for_g, str_double_g, num_i);
    s21_reverse(str_double_g);
    s21_strcat(str_double, str_double_g);
    s21_strcat(str_int, str_double);
  }

  printf("Дробная часть %s\n", str_double);
  printf("Finally1: %s\n", str_int);
  printf("intermediate_str: %s\n", intermediate_str);
  return intermediate_str;
}