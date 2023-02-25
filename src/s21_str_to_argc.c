#include "s21_string_files/s21_string.h"
#include "s21_sprintf.h"

int s21_args_to_str(int counter_symbols_str, char *str, Prototype *prot,
                    va_list args) {
  // В промежуточном массиве будет храниться строка без учета параметров
  // заданных в спецификаторе т.е флаги,ширина, точность и тд
  char intermediate_str[4096] = {'\0'};
  if (prot->spec == 'c'){
    counter_symbols_str += s21_spec_c(intermediate_str, args, prot, counter_symbols_str);
  }else if (prot->spec == 'd' || prot->spec == 'i'){
    counter_symbols_str += s21_spec_id(args, prot, intermediate_str);
  }else if (prot->spec == 's'){
    counter_symbols_str += s21_spec_s(intermediate_str, args, prot, counter_symbols_str);
  }else if (prot->spec == 'n'){
    s21_spec_n(args, counter_symbols_str);
  }else if (prot->spec == 'x'){
    counter_symbols_str += specifier_x(intermediate_str, args, *prot);
  }else if (prot->spec == 'X'){
    counter_symbols_str += specifier_x(intermediate_str, args, *prot);
  }else if (prot->spec == 'o'){
    counter_symbols_str += specifier_o(intermediate_str, args, *prot);
  }else if (prot->spec == 'u'){
    counter_symbols_str += specifier_x(intermediate_str, args, *prot);
  }else if (prot->spec == 'f'){
    counter_symbols_str += specifier_f(intermediate_str, args, *prot);
  }else if (prot->spec == 'p'){
    counter_symbols_str += s21_spec_p(args, prot, intermediate_str);
  }
  s21_strcat(str, intermediate_str);
  return counter_symbols_str;
}
