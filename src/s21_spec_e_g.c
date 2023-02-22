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
  char str_double_g[270] = {'\0'};
  char symbol_e = '\0';
  char str_degree[560] = {'\0'};
  bool flag_zero = false;
  bool flag_zero_negative = false;
  bool check_num_i_g = false;
  int multiply = 1;
  int dont_write_number_with_point = 0;
  int check_g = 0;
  int precision = 6;
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
  flag_zero_negative = s21_mantisssa_and_degree(&num, flag_zero, &num_int, &e);
  if (num_int == 0 && (prot->spec == 'g' || prot->spec == 'G')) {
    str_int[0] = '0';
    s21_strcat(intermediate_str, str_int);
    printf("Finally1: %s\n", intermediate_str);
    return intermediate_str;
  }
  s21_fractional_and_integer_part_of_a_number(&num_int, &num);

  dont_write_number_with_point = s21_rounding_and_precision_number(
      &num, &multiply, prot, &save_number_for_g, &e, &check_g, &precision);
  if (check_g != 1) {
    s21_writing_int_number_with_point(
        &num_int, &symbol, str_int, flag_zero_negative, &counter_symbols_str,
        &dont_write_number_with_point, &save_number_for_g, &e, prot, &num_i_g);
    counter_symbols_str = s21_concat_fractional_number_with_degree(
        num_i, counter_symbols_str, str_double, num, prot, symbol_e, e,
        str_degree, &dont_write_number_with_point);
    s21_check_fractional_number_for_zeros(&multiply, str_double);

    s21_strcat(str_int, str_double);  // соединяем 2 строки получаем число
    s21_strcat(intermediate_str,
               str_int);  // закидываем готовый результат в промежуточную строку
  } else {
    s21_writing_int_number_with_point(
        &num_int, &symbol, str_int, flag_zero_negative, &counter_symbols_str,
        &dont_write_number_with_point, &save_number_for_g, &e, prot, &num_i_g);
    save_multiply = multiply;
    precision++;
    s21_check_fractional_number_for_zeros(&multiply, str_double);
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
    s21_fractional_and_integer_part_of_a_number(&num_int, &save_number_for_g);
    if (num_i_g == 0 && check_num_i_g == false)
      save_number_for_g *= multiply_for_fractional_num;
    else {
      save_number_for_g *= multiply_num_i_g;
    }
    save_number_for_g = (int)save_number_for_g;
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
int s21_rounding_and_precision_number(double *num, int *multiply,
                                      Prototype *prot,
                                      double *save_number_for_g, int *e,
                                      int *check_g, int *precision) {
  // Тут идет округление числа если точность задана в else будет вызываться
  // функция точности
  // если после знака запятой будет < 6 цифр, то нужно округлять
  int flag = -1;
  int dont_write_number_with_point = 0;
  int counter_g = 0;
  bool flag_g_e_more_minus_four = false;
  if ((prot->spec == 'g' || prot->spec == 'G') && (*e >= -4 && *e <= 5)) {
    flag_g_e_more_minus_four = true;
    *num = *save_number_for_g;
    while (*e < 0) {
      *e += 1;
      counter_g++;
    }
    while (*e > 0) {
      *e -= 1;
      counter_g++;
    }
  }
  if (flag_g_e_more_minus_four == true) {
    *num = *save_number_for_g;
    *check_g = 1;
  }
  if (prot->prec_star != -1)
    *precision = prot->prec_star;
  else if (prot->prec_number != -1)
    *precision = prot->prec_number;
  if (prot->prec_number == 0 || prot->prec_star == 0) {
    dont_write_number_with_point = 1;
  } else {
    if (prot->prec_number == -1 || prot->prec_star == -1) {
      if (prot->spec == 'g' || prot->spec == 'G') {
        *precision -= 1;
      }
      if (prot->length == 'L')
        *num = roundl(*num * pow(10, *precision + counter_g)) /
               pow(10, *precision + counter_g);
      else
        *num = round(*num * pow(10, *precision + counter_g)) /
               pow(10, *precision + counter_g);
      for (int i = 0; i < *precision; i++) {
        *num *= 10;
        flag = (int)*num;
        if (flag == 0) *multiply *= 10;
      }
      *num = (int)*num;  // получение дробного числа в виде инта
    }
  }
  return dont_write_number_with_point;
}
void s21_writing_int_number_with_point(int *num_int, int *symbol, char *str_int,
                                       bool flag_zero_negative,
                                       int *counter_symbols_str,
                                       int *dont_write_number_with_point,
                                       double *save_number_for_g, int *e,
                                       Prototype *prot, int *num_i_g) {
  // Записываем целое число в массив char в виде "-4." если целое число
  // отрицательное. "4." если число положительное
  bool check_g = false;
  double send_to_function_num = 0;
  if ((prot->spec == 'g' || prot->spec == 'G') && (*e >= -4 && *e <= 5)) {
    *num_int = (int)*save_number_for_g;
    check_g = true;
  }
  // Здесь остановился стереть
  if (check_g == true) {
    *symbol = *num_int;
    send_to_function_num = *symbol;
  } else
    *symbol = *num_int % 10;
  if (*dont_write_number_with_point == 1) {
    str_int[0] = *symbol + '0';
  } else {
    if (*symbol < 0 || flag_zero_negative == true) {
      *symbol *= -1;
      str_int[0] = '-';
      str_int[1] = *symbol + '0';
      str_int[2] = '.';
      *counter_symbols_str += 3;
    } else {
      if (check_g == true) {
        *num_i_g = s21_double_to_str(send_to_function_num, str_int, 0);
        if (*num_i_g == 0) {
          str_int[0] = '0';
          str_int[1] = '.';
        } else {
          s21_reverse(str_int);
          str_int[*num_i_g] = '.';
        }
        if (*num_i_g == 6) str_int[*num_i_g] = '\0';
      } else {
        str_int[0] = *symbol + '0';
        str_int[1] = '.';
        *counter_symbols_str += 2;
      }
    }
  }
}

int s21_concat_fractional_number_with_degree(
    int num_i, int counter_symbols_str, char *str_double, double num,
    Prototype *prot, char symbol_e, int e, char *str_degree,
    int *dont_write_number_with_point) {
  // Записываем дробную часть числа в массив char и соединяем дробную число
  // с степенью
  if (*dont_write_number_with_point != 1) {
    num_i = s21_double_to_str(num, str_double, num_i);
    s21_reverse(str_double);
  }
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
    s21_double_to_str(e, str_degree, 0);
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
    s21_double_to_str(e, str_degree, 0);
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