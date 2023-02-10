#include "functions/s21_string.h"
#include "s21_sprintf.h"

int s21_args_to_str(int j, char *str, Prototype *prot, va_list args) {
  if (prot->spec == 'c') j += s21_spec_c(j, str, args);
  //   else if (prot->spec == 'd')
  //     j += s21_spec_d(j, str, args);
  // else if (prot->spec == 'i')
  //  j += s21_spec_i(j, str, args);
  else if (prot->spec == 'e' || prot->spec == 'E') {
    // if (prot->length == 'L')
    j += s21_spec_e_L(j, str, args, prot);
    //   else
    //     j += s21_spec_e(j, str, args, prot);
    // }
    //   else if (prot->spec == 'f')
    //     j += s21_spec_f(j, str, args);
    //   else if (prot->spec == 'g' || prot->spec == 'G')
    //     j += s21_spec_g(j, str, args);
    //   else if (prot->spec == 'o')
    //     j += s21_spec_o(j, str, args);
    //   else if (prot->spec == 's')
    //     j += s21_spec_s(j, str, a  rgs);
    //   else if (prot->spec == 'u')
    //     j += s21_spec_u(j, str, args);
    //   else if (prot->spec == 'x' || prot->spec == 'X')
    //     j += s21_spec_x(j, str, args);
    //   else if (prot->spec == 'p')
    //     j += s21_spec_p(j, str, args);
    //   else if (prot->spec == 'n')
    //     j += s21_spec_n(j, str, args);
  }
  return j;
}

int s21_spec_e_L(int j, char *str, va_list args, Prototype *prot) {
  (void)str;
  (void)j;
  (void)prot;
  int e = 0;
  int num_int = 0;
  // Формула экспоненты N = M*n^p
  long double num = va_arg(args, long double);
  num_int = (int)num;  // целая часть дробного числа
  // Мантисса + подсчет степени
  if (num >= 1 || num <= -1) {
    if (num_int >= 10 || num_int <= -10) {
      do {
        num /= 10;
        e += 1;
      } while (num > 10);
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
  num -= num_int;
  if (prot->prec_number == -1 || prot->prec_star == -1) {
    for (int i = 0; i < 6; i++)  // без заданной точности стандартная равна 6
      num *= 10;  // получение дробного числа в виде инта
    num = (int)num;
  }
  printf("s21_spri: %Lf\n", num);
  return num;
}

int s21_spec_c(int j, char *str, va_list args) {
  (void)args;
  (void)str;
  j++;
  return j;
}
