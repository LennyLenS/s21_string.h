#include "functions/s21_string.h"
#include "s21_sprintf.h"

int s21_args_to_str(int counter_symbols_str, char *str, Prototype *prot,
                    va_list args) {
  // В промежуточном массиве будет храниться строка без учета параметров
  // заданных в спецификаторе т.е флаги,ширина, точность и тд
  char intermediate_str[512] = {'\0'};
  s21_strcpy(intermediate_str, str);
  if (prot->spec == 'c')
    counter_symbols_str += s21_spec_c(counter_symbols_str, str, args);
  //   else if (prot->spec == 'd')
  //     counter_symbols_str += s21_spec_d(counter_symbols_str, str, args);
  // else if (prot->spec == 'i')
  //  counter_symbols_str += s21_spec_i(counter_symbols_str, str, args);
  else if (prot->spec == 'e' || prot->spec == 'E') {
    // if (prot->length == 'L')
    counter_symbols_str +=
        s21_spec_e_L(counter_symbols_str, str, intermediate_str, args, prot);
    //   else
    //     counter_symbols_str += s21_spec_e(counter_symbols_str, str, args,
    //     prot);
    // }
    //   else if (prot->spec == 'f')
    //     counter_symbols_str += s21_spec_f(counter_symbols_str, str, args);
    //   else if (prot->spec == 'g' || prot->spec == 'G')
    //     counter_symbols_str += s21_spec_g(counter_symbols_str, str, args);
    //   else if (prot->spec == 'o')
    //     counter_symbols_str += s21_spec_o(counter_symbols_str, str, args);
    //   else if (prot->spec == 's')
    //     counter_symbols_str += s21_spec_s(counter_symbols_str, str, a  rgs);
    //   else if (prot->spec == 'u')
    //     counter_symbols_str += s21_spec_u(counter_symbols_str, str, args);
    //   else if (prot->spec == 'x' || prot->spec == 'X')
    //     counter_symbols_str += s21_spec_x(counter_symbols_str, str, args);
    //   else if (prot->spec == 'p')
    //     counter_symbols_str += s21_spec_p(counter_symbols_str, str, args);
    //   else if (prot->spec == 'n')
    //     counter_symbols_str += s21_spec_n(counter_symbols_str, str, args);
  }
  return counter_symbols_str;
}

int s21_spec_e_L(int counter_symbols_str, char *str, char *intermediate_str,
                 va_list args, Prototype *prot) {
  (void)str;
  int e = 0;
  int num_int = 0;
  int symbol = 0;
  int num_i = 0;
  char str_int[512] = {'\0'};
  char str_double[270] = {'\0'};
  char symbol_e = '\0';
  char str_degree[256] = {'\0'};
  // Формула экспоненты N = M*n^p
  //
  long double num = va_arg(args, long double);

  num_int = (int)num;  // целая часть дробного числа
  // Мантисса + подсчет степени
  if (num >= 1 || num <= -1) {
    if (num_int >= 10 || num_int <= -10) {
      do {
        num /= 10;
        e += 1;
      } while (num > 10 || num < -10);
    }
  } else {
    do {
      num *= 10;
      e -= 1;
      num_int = (int)num;
    } while (num_int == 0);
  }
  // нужно тут округлять если меньше 4 цифр после запятой хз как
  // Разбиваем дробное число на два интовых типа целое число и дробная часть
  num_int = (int)num;
  if (num_int > 0)
    num -= num_int;
  else {
    num *= -1;
    num += num_int;
  }
  int multiply = 1;
  int flag = -1;
  if (prot->prec_number == -1 || prot->prec_star == -1) {
    for (int i = 0; i < 6; i++) {  // без заданной точности стандартная равна 6
      num *= 10;
      flag = (int)num;
      if (flag == 0) multiply *= 10;
    }
    num = (int)num;  // получение дробного числа в виде инта
  }
  // Записываем целое число в массив char в виде "-4." если целое число
  // отрицательное. "4." если число положительное
  symbol = num_int % 10;
  if (symbol < 0) {
    symbol *= -1;
    str_int[0] = '-';
    str_int[1] = symbol + '0';
    str_int[2] = '.';
    counter_symbols_str += 3;
  } else {
    str_int[0] = symbol + '0';
    str_int[1] = '.';
    counter_symbols_str += 2;
  }
  // Записываем дробную часть числа в массив char
  num_i = s21_double_to_str(num, str_double, num_i, counter_symbols_str);
  s21_reverse(str_double);
  if (prot->spec == 'E')
    symbol_e = 'E';
  else
    symbol_e = 'e';
  str_double[num_i] = symbol_e;
  counter_symbols_str++;
  if (e >= 0) str_double[num_i + 1] = '+';
  if (e < 0) str_double[num_i + 1] = '-';
  if (e >= 10) {
    s21_double_to_str(e, str_degree, 0, counter_symbols_str);
    s21_reverse(str_degree);
  } else {
    str_double[num_i + 2] = '0';
    counter_symbols_str++;
  }
  if (e == 0)
    str_double[num_i + 3] = '0';
  else {
    s21_double_to_str(e, str_degree, 0, counter_symbols_str);
    s21_reverse(str_degree);
    s21_strcat(str_double, str_degree);  // соединяем число с степенью
  }
  // printf("Check %s\n", str_int);
  int check = 0;
  if (multiply >= 10)
    check = s21_strlen(
        str_double);  // дофиксить баг если число подано с нулем пример в мэйне
  printf("Check %d\n", check);
  s21_strcat(str_int, str_double);  // соединяем 2 строки получаем число
  s21_strcat(intermediate_str,
             str_int);  // закидываем готовый результат в промежуточную строку

  printf("Дробная часть %s\n", str_double);
  printf("Finally1: %s\n", str_int);
  printf("intermediate_str: %s\n", intermediate_str);
  return num;
}

int s21_double_to_str(long double num, char *str_double, int num_i,
                      int counter_symbols_str) {
  while (num > 0) {
    int num_double = 0;
    num_double = (int)num % 10;
    str_double[num_i] = num_double + '0';
    num_i++;
    num /= 10;
    num = (int)num;
    counter_symbols_str++;
  }
  return num_i;
}

void *s21_reverse(char *str) {
  if (str == NULL) return NULL;
  int bgn = 0;
  int end = strlen(str) - 1;
  char temp;
  while (bgn < end) {
    temp = str[bgn];
    *(str + bgn) = *(str + end);
    *(str + end) = temp;
    bgn++;
    end--;
  }
  return str;
}

int s21_spec_c(int counter_symbols_str, char *str, va_list args) {
  (void)args;
  (void)str;
  counter_symbols_str++;
  return counter_symbols_str;
}
