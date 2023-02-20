#include "functions/s21_string.h"
#include "s21_sprintf.h"

char *s21_spec_e(int counter_symbols_str, char *str, char *intermediate_str,
                 va_list args, Prototype *prot) {
  int e = 0;
  int num_int = 0;
  int symbol = 0;
  int num_i = 0;
  char str_int[512] = {'\0'};
  char str_double[270] = {'\0'};
  char symbol_e = '\0';
  char str_degree[560] = {'\0'};
  bool flag_zero = false;
  bool flag_zero_negative = false;
  int multiply = 1;
  // Формула экспоненты N = M*n^p
  double num = 0.;
  if (num == 0 && (prot->spec == 'g' || prot->spec == 'G')) {
    str_int[0] = '0';
    s21_strcat(intermediate_str, str_int);
    printf("Finally1: %s\n", intermediate_str);
    return intermediate_str;
  }

  if (prot->length == 'L')
    num = va_arg(args, long double);
  else
    num = va_arg(args, double);
  if (s21_check_arg(prot, counter_symbols_str, str, num) != 0)
    return intermediate_str;
  flag_zero_negative = s21_mantisssa_and_degree(&num, flag_zero, &num_int, &e);
  s21_fractional_and_integer_part_of_a_number(&num_int, &num);
  s21_rounding_and_precision_number(&num, &multiply, prot);
  s21_writing_int_number_with_point(&num_int, &symbol, str_int,
                                    flag_zero_negative, &counter_symbols_str);
  counter_symbols_str = s21_concat_fractional_number_with_degree(
      num_i, counter_symbols_str, str_double, num, prot, symbol_e, e,
      str_degree);
  // ------------------------------------------------------
  s21_check_fractional_number_for_zeros(&multiply, str_double);

  s21_strcat(str_int, str_double);  // соединяем 2 строки получаем число
  s21_strcat(intermediate_str,
             str_int);  // закидываем готовый результат в промежуточную строку

  printf("Дробная часть %s\n", str_double);
  printf("Finally1: %s\n", str_int);
  printf("intermediate_str: %s\n", intermediate_str);
  return intermediate_str;
}

int s21_check_arg(Prototype *prot, int counter_symbols_str, char *str,
                  double num) {
  int flag_check_arg = 0;
  if (num == INFINITY || num == -INFINITY) {
    int counter = 0;
    if (num == -INFINITY) {
      str[counter_symbols_str] = '-';
      counter++;
    }
    if (prot->spec == 'E' || prot->spec == 'G') {
      str[counter_symbols_str + counter] = 'I';
      str[counter_symbols_str + counter + 1] = 'N';
      str[counter_symbols_str + counter + 2] = 'F';
    } else {
      str[counter_symbols_str + counter] = 'i';
      str[counter_symbols_str + counter + 1] = 'n';
      str[counter_symbols_str + counter + 2] = 'f';
    }
    if (counter > 0)
      counter_symbols_str += 4;
    else
      counter_symbols_str += 3;
    printf("s21check: %s\n", str);
    return counter_symbols_str;
  }
  if (s21_isnan(num) == 1) {
    if (prot->spec == 'E' || prot->spec == 'G') {
      str[counter_symbols_str] = 'N';
      str[counter_symbols_str + 1] = 'A';
      str[counter_symbols_str + 2] = 'N';
    } else {
      str[counter_symbols_str] = 'n';
      str[counter_symbols_str + 1] = 'a';
      str[counter_symbols_str + 2] = 'n';
    }
    counter_symbols_str += 3;
    printf("s21check: %s\n", str);
    return counter_symbols_str;
  }
  return flag_check_arg;
}

bool s21_mantisssa_and_degree(double *num, bool flag_zero, int *num_int,
                              int *e) {
  bool flag_zero_negative = false;
  if (*num == 0) flag_zero = true;
  if (1.0 / *num == -INFINITY) flag_zero_negative = true;
  *num_int = (int)*num;  // целая часть дробного числа
  // Мантисса + подсчет степени
  if (*num >= 1 || *num <= -1 || flag_zero == true) {
    if ((*num_int >= 10 || *num_int <= -10)) {
      do {
        *num /= 10;
        *e += 1;
      } while (*num > 10 || *num < -10);
    }

  } else {
    do {
      *num *= 10;
      *e -= 1;
      *num_int = (int)*num;
    } while (*num_int == 0 && flag_zero == false);
  }
  return flag_zero_negative;
}
void s21_fractional_and_integer_part_of_a_number(int *num_int, double *num) {
  // Разбиваем дробное число на два интовых типа целое число и дробная часть
  *num_int = (int)*num;
  if (*num_int >= 0)
    *num -= *num_int;
  else {
    *num *= -1;
    *num += *num_int;
  }
}
void s21_rounding_and_precision_number(double *num, int *multiply,
                                       Prototype *prot) {
  // Тут идет округление числа если точность задана в else будет вызываться
  // функция точности
  // если после знака запятой будет < 6 цифр, то нужно округлять
  int flag = -1;
  if (prot->prec_number == -1 || prot->prec_star == -1) {
    int precision = 6;  // без заданной точности стандартная равна 6
    if (prot->spec == 'g' || prot->spec == 'G') precision--;
    if (prot->length == 'L')
      *num = roundl(*num * pow(10, precision)) / pow(10, precision);
    else
      *num = round(*num * pow(10, precision)) / pow(10, precision);

    for (int i = 0; i < precision; i++) {
      *num *= 10;
      flag = (int)*num;
      if (flag == 0) *multiply *= 10;
    }
    *num = (int)*num;  // получение дробного числа в виде инта
  }
}
void s21_writing_int_number_with_point(int *num_int, int *symbol, char *str_int,
                                       bool flag_zero_negative,
                                       int *counter_symbols_str) {
  // Записываем целое число в массив char в виде "-4." если целое число
  // отрицательное. "4." если число положительное
  *symbol = *num_int % 10;
  if (*symbol < 0 || flag_zero_negative == true) {
    *symbol *= -1;
    str_int[0] = '-';
    str_int[1] = *symbol + '0';
    str_int[2] = '.';
    *counter_symbols_str += 3;
  } else {
    str_int[0] = *symbol + '0';
    str_int[1] = '.';
    *counter_symbols_str += 2;
  }
}

int s21_concat_fractional_number_with_degree(int num_i, int counter_symbols_str,
                                             char *str_double, double num,
                                             Prototype *prot, char symbol_e,
                                             int e, char *str_degree) {
  // Записываем дробную часть числа в массив char и соединяем дробную число
  // с степенью
  num_i = s21_double_to_str(num, str_double, num_i, counter_symbols_str);
  s21_reverse(str_double);
  if (prot->spec == 'E' || prot->spec == 'G')
    symbol_e = 'E';
  else
    symbol_e = 'e';
  str_double[num_i] = symbol_e;
  counter_symbols_str++;
  if (e >= 0) {
    str_double[num_i + 1] = '+';
    counter_symbols_str++;
  }
  if (e < 0) {
    str_double[num_i + 1] = '-';
    counter_symbols_str++;
  }
  if (e >= 10) {
    s21_double_to_str(e, str_degree, 0, counter_symbols_str);
    s21_reverse(str_degree);
  } else {
    str_double[num_i + 2] = '0';
    counter_symbols_str++;
  }
  if (e == 0) {
    str_double[num_i + 3] = '0';
    counter_symbols_str++;
  } else {
    if (e < 0) e *= -1;
    s21_double_to_str(e, str_degree, 0, counter_symbols_str);
    s21_reverse(str_degree);
    s21_strcat(str_double, str_degree);  // соединяем число с степенью
  }
  return counter_symbols_str;
}

void s21_check_fractional_number_for_zeros(int *multiply, char *str_double) {
  // Проверка на то,что есть ли в дробной части нули
  while (*multiply >= 10) {
    int check = s21_strlen(str_double) - 1;
    for (; check >= 0; check--) {
      str_double[check + 1] = str_double[check];
    }
    str_double[0] = '0';
    *multiply /= 10;
  }
}