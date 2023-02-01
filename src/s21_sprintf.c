#include "s21_sprintf.h"

#include "s21_string.h"

// int main() {
//   char str[256] = {0};
//   int x = 0;
//   s21_sprintf(str, "%c", 's');
// }

int s21_sprintf(char *str, const char *format, ...) {
  // int result = 0;
  va_list args;            // указатель на аргументы
  va_start(args, format);  // выделение памяти для arg
  s21_parser(str, format, args);
  // result = s21_parser(str, format, args);
  va_end(args);
  // return result;
}

int s21_parser(char *str, const char *format, va_list args) {
  int i = -1;
  while (format[i++]) {
    Prototype prot = s21_init_prototype();
    s21_read_format(&prot, format, i);
  }
}
// %[флаги][ширина][.точность][длина]спецификатор
int s21_read_format(Prototype *prot, const char *format, int i) {
  int this_is_width = 0;
  int this_is_precision = 0;
  int this_is_length = 0;
  do {
    if (format[i] == '+' && this_is_length == 0 && this_is_precision == 0 &&
        this_is_width == 0) {
      prot->plus_flag = 1;
    } else if (format[i] == '-' && this_is_length == 0 &&
               this_is_precision == 0 && this_is_width == 0) {
      prot->minus_flag = 1;
    } else if (format[i] == ' ' && this_is_length == 0 &&
               this_is_precision == 0 && this_is_width == 0) {
      prot->space_flag = 1;
    } else if (format[i] == '#' && this_is_length == 0 &&
               this_is_precision == 0 && this_is_width == 0) {
      prot->sharp_flag = 1;
    } else if (format[i] == '0' && this_is_length == 0 &&
               this_is_precision == 0 && this_is_width == 0) {
      prot->zero_flag = 1;
    }
    bool check_width = s21_check_width();
    i++;  // в самый конец
  } while (format[i] != '\0');
}

bool s21_check_width() {
  for (int i = 0; i <= 9; i++) {
  }
}

Prototype s21_init_prototype() {
  Prototype prot;
  prot.specification = 0;
  // prot.flag = 0;
  prot.minus_flag = 0;
  prot.space_flag = 0;
  prot.zero_flag = 0;
  prot.sharp_flag = 0;
  prot.width = 0;
  prot.width_star = 0;
  prot.precision = -1;
  prot.length = 0;
  return prot;
}
