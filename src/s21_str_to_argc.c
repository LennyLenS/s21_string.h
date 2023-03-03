#include <string.h>

#include "s21_sprintf.h"
int s21_args_to_str(int counter_symbols_str, char *str, Prototype *prot,
                    va_list args) {
  // В промежуточном массиве будет храниться строка без учета параметров
  // заданных в спецификаторе т.е флаги,ширина, точность и тд
  char intermediate_str[4096] = {'\0'};
  char *res = S21_NULL;
  int flag_s = 0;
  if (prot->spec == 'c') {
    s21_spec_c(intermediate_str, args, prot);
    res = intermediate_str;
  } else if (prot->spec == 'd' || prot->spec == 'i') {
    s21_spec_id(args, prot, intermediate_str);
    res = main_func(intermediate_str, prot);
  } else if (prot->spec == 's') {
    flag_s = s21_spec_s(intermediate_str, args, prot);
    if (flag_s == 2) {
      res = main_func(intermediate_str, prot);
    } else {
      res = intermediate_str;
    }
  } else if (prot->spec == 'n') {
    s21_spec_n(args, counter_symbols_str);
    // res = main_func(intermediate_str, prot);
    res = intermediate_str;
  } else if (prot->spec == 'x') {
    specifier_x(intermediate_str, args, *prot);
    res = main_func(intermediate_str, prot);
  } else if (prot->spec == 'X') {
    specifier_X(intermediate_str, args, *prot);
    res = main_func(intermediate_str, prot);
  } else if (prot->spec == 'o') {
    specifier_o(intermediate_str, args, *prot);
    // printf("%s\n", intermediate_str);
    res = main_func(intermediate_str, prot);
  } else if (prot->spec == 'u') {
    specifier_u(intermediate_str, args, *prot);
    res = main_func(intermediate_str, prot);
  } else if (prot->spec == 'f') {
    specifier_f(intermediate_str, args, *prot);
    // printf("%s\n", intermediate_str);
    res = main_func(intermediate_str, prot);
  } else if (prot->spec == 'p') {
    s21_spec_p(args, intermediate_str, prot);
    res = intermediate_str;
  }
  // printf("%s, %d\n", intermediate_str, counter_symbols_str);
  int index = 0;
  while (res[index] != '\0') {
    str[counter_symbols_str++] = res[index++];
  }
  str[counter_symbols_str] = '\0';
  if (prot->spec == 'f' || prot->spec == 'u' || prot->spec == 'o' ||
      prot->spec == 'X' || prot->spec == 'x' || prot->spec == 'd' ||
      prot->spec == 'i') {
    free(res);
  }
  return counter_symbols_str;
}
