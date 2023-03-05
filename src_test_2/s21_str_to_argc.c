#include "s21_sprintf.h"
#include <string.h>
int s21_args_to_str(int counter_symbols_str, char *str, Prototype *prot,
                    va_list args) {
  // В промежуточном массиве будет храниться строка без учета параметров
  // заданных в спецификаторе т.е флаги,ширина, точность и тд
  char intermediate_str[4096] = {'\0'};
  char *res = S21_NULL;
  if (prot->spec == 'c'){
    s21_spec_c(intermediate_str, args, prot);
    res = intermediate_str;
  }else if (prot->spec == 'd' || prot->spec == 'i'){
    s21_spec_id(args, prot, intermediate_str);
    res = main_func(intermediate_str, prot);
  }else if (prot->spec == 's'){
    int flag_s = s21_spec_s(intermediate_str, args, prot);
    if(flag_s == 2){
      res = main_func(intermediate_str, prot);
    } else {
      res = intermediate_str;
    }
  }else if (prot->spec == 'n'){
    s21_spec_n(args, counter_symbols_str);
    // res = main_func(intermediate_str, prot);
    res = intermediate_str;
  }else if (prot->spec == 'x'){
    specifier_x(intermediate_str, args, *prot);
    res = main_func(intermediate_str, prot);
  }else if (prot->spec == 'X'){
    specifier_X(intermediate_str, args, *prot);
    res = main_func(intermediate_str, prot);
  }else if (prot->spec == 'o'){
    specifier_o(intermediate_str, args, *prot);
    //printf("%s\n", intermediate_str);
    res = main_func(intermediate_str, prot);
  }else if (prot->spec == 'u'){
    specifier_x(intermediate_str, args, *prot);
    res = main_func(intermediate_str, prot);
  }else if (prot->spec == 'f'){
    specifier_f(intermediate_str, args, *prot);
    //printf("%s\n", intermediate_str);
    res = main_func(intermediate_str, prot);
  }else if (prot->spec == 'p'){
    s21_spec_p(args, intermediate_str, prot);
    res = intermediate_str;
  }
  //printf("%s, %d\n", intermediate_str, counter_symbols_str);
  while(*res != '\0'){
    str[counter_symbols_str++] = *res;
    res++;
  }
  str[counter_symbols_str] = '\0';
  return counter_symbols_str;
}