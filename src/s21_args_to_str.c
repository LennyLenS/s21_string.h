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
    counter_symbols_str +=
        s21_spec_e(counter_symbols_str, str, intermediate_str, args, prot);
  }
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

  return counter_symbols_str;
}

int s21_spec_e(int counter_symbols_str, char *str, char *intermediate_str,
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
  // Формула экспоненты N = M*n^p
  // добавить условие на проверку какое число long double или double тоесть
  // в самом начале
  // в va_arg только менять тип данных
  double num = 0.;
  if (prot->length == 'L')
    num = va_arg(args, long double);
  else
    num = va_arg(args, double);
  if (num == INFINITY || num == -INFINITY) {
    int counter = 0;
    if (num == -INFINITY) {
      str[counter_symbols_str] = '-';
      counter++;
    }
    if (num == INFINITY || num == -INFINITY) {
      str[counter_symbols_str + counter] = 'I';
      str[counter_symbols_str + counter + 1] = 'N';
      str[counter_symbols_str + counter + 2] = 'F';
      if (counter > 0)
        counter_symbols_str += 4;
      else
        counter_symbols_str += 3;
      printf("s21check: %s\n", str);
      return counter_symbols_str;
    }
  }
  if (s21_isnan(num) == 1) {
    str[counter_symbols_str] = 'N';
    str[counter_symbols_str + 1] = 'A';
    str[counter_symbols_str + 2] = 'N';
    printf("s21check: %s\n", str);
    return counter_symbols_str;
  }
  if (num == 0) flag_zero = true;
  if (1.0 / num == -INFINITY) flag_zero_negative = true;
  num_int = (int)num;  // целая часть дробного числа
  // Мантисса + подсчет степени
  if (num >= 1 || num <= -1 || flag_zero == true) {
    if ((num_int >= 10 || num_int <= -10)) {
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
    } while (num_int == 0 && flag_zero == false);
  }
  // Разбиваем дробное число на два интовых типа целое число и дробная часть
  num_int = (int)num;
  if (num_int >= 0)
    num -= num_int;
  else {
    num *= -1;
    num += num_int;
  }
  int multiply = 1;
  int flag = -1;
  // Тут идет округление числа если точность задана в else будет вызываться
  // функция точности
  // если после знака запятой будет < 6 цифр, то нужно округлять
  if (prot->prec_number == -1 || prot->prec_star == -1) {
    int precision = 6;  // без заданной точности стандартная равна 6
    num = roundl(num * pow(10, precision)) / pow(10, precision);
    // printf("Check %Lf\n", num);
    for (int i = 0; i < 6; i++) {
      num *= 10;
      flag = (int)num;
      if (flag == 0) multiply *= 10;
    }
    num = (int)num;  // получение дробного числа в виде инта
  }
  // Записываем целое число в массив char в виде "-4." если целое число
  // отрицательное. "4." если число положительное
  symbol = num_int % 10;
  if (symbol < 0 || flag_zero_negative == true) {
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
    if (e < 0) e *= -1;
    s21_double_to_str(e, str_degree, 0, counter_symbols_str);
    s21_reverse(str_degree);
    s21_strcat(str_double, str_degree);  // соединяем число с степенью
  }
  // printf("Check %s\n", str_int);

  while (multiply >= 10) {
    int check = s21_strlen(str_double) - 1;
    for (; check >= 0; check--) {
      str_double[check + 1] = str_double[check];
    }
    str_double[0] = '0';
    multiply /= 10;
  }

  s21_strcat(str_int, str_double);  // соединяем 2 строки получаем число
  s21_strcat(intermediate_str,
             str_int);  // закидываем готовый результат в промежуточную строку

  printf("Дробная часть %s\n", str_double);
  printf("Finally1: %s\n", str_int);
  printf("intermediate_str: %s\n", intermediate_str);
  return counter_symbols_str;
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

int s21_isnan(double number) {
  int result = 0;
  if (number != number) {
    result = 1;
  }
  return result;
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
