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
  else if (prot->spec == 'e' || prot->spec == 'E' || prot->spec == 'g' ||
           prot->spec == 'G') {
    counter_symbols_str +=
        s21_spec_e(counter_symbols_str, str, intermediate_str, args, prot);
  }
  //   else
  //     counter_symbols_str += s21_spec_e(counter_symbols_str, str, args,
  //     prot);
  // }
  //   else if (prot->spec == 'f')
  //     counter_symbols_str += s21_spec_f(counter_symbols_str, str, args);
  // после 7-ой точности e убирается тоесть .72
  // else if (prot->spec == 'g' || prot->spec == 'G')
  //   counter_symbols_str +=
  //       s21_spec_g(counter_symbols_str, str, intermediate_str, args, prot);
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

int s21_spec_c(int counter_symbols_str, char *str, va_list args) {
  (void)args;
  (void)str;
  counter_symbols_str++;
  return counter_symbols_str;
}
