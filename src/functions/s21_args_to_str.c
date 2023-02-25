#include "functions/s21_string.h"
#include "s21_sprintf.h"

int s21_args_to_str(int j, char *str, Prototype *prot, va_list args) {
  if (prot->spec == 'c') j += s21_spec_c(j, str, args);
  //   else if (prot->spec == 'd')
  //     j += s21_spec_d(j, str, args);
  // else if (prot->spec == 'i')
  //  j += s21_spec_i(j, str, args);
  else if (prot->spec == 'e' || prot->spec == 'E')
    j += s21_spec_e(j, str, args);
  //   else if (prot->spec == 'f')
  //     j += s21_spec_f(j, str, args);
  //   else if (prot->spec == 'g' || prot->spec == 'G')
  //     j += s21_spec_g(j, str, args);
  //   else if (prot->spec == 'o')
  //     j += s21_spec_o(j, str, args);
  //   else if (prot->spec == 's')
  //     j += s21_spec_s(j, str, args);
  //   else if (prot->spec == 'u')
  //     j += s21_spec_u(j, str, args);
  //   else if (prot->spec == 'x' || prot->spec == 'X')
  //     j += s21_spec_x(j, str, args);
  //   else if (prot->spec == 'p')
  //     j += s21_spec_p(j, str, args);
  //   else if (prot->spec == 'n')
  //     j += s21_spec_n(j, str, args);
  return j;
}

int s21_spec_c(int j, char *str, va_list args) {
  j++;
  return j;
}
