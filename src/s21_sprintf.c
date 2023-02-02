#include "s21_sprintf.h"

#include "s21_string.h"

int main() {
  char str[256] = {0};
  long int x = 0;
  s21_sprintf(str, "%-10.10ld%c", x, 's');
}

void s21_sprintf(char *str, const char *format, ...) {
  // int result = 0;
  va_list args;            // указатель на аргументы
  va_start(args, format);  // выделение памяти для arg
  s21_parser(str, format, args);
  // result = s21_parser(str, format, args);
  va_end(args);  // очищение памяти
  // return result;
}

void s21_parser(char *str, const char *format, va_list args) {
  (void)str;
  (void)args;
  int i = -1;
  while (format[i++]) {
    // if (format[i] != '%') {
    //   s21_move_char_to_str();
    // }
    if (format[i] == '%') {
      Prototype prot = {0};
      s21_read_format(&prot, format, i);
    }
  }
}
// %[флаги][ширина][.точность][длина]спецификатор
int s21_read_format(Prototype *prot, const char *format, int i) {
  int this_is_width = 0;
  int this_is_prec = 0;
  int this_is_length = 0;
  int this_is_flag = 0;
  while (format[i]) {
    // Check flags
    if (format[i] == '+' && this_is_length == 0 && this_is_prec == 0 &&
        this_is_width == 0) {
      prot->plus_flag = 1;
      this_is_flag = 1;
    } else if (format[i] == '-' && this_is_length == 0 && this_is_prec == 0 &&
               this_is_width == 0) {
      prot->minus_flag = 1;
      this_is_flag = 1;
    } else if (format[i] == ' ' && this_is_length == 0 && this_is_prec == 0 &&
               this_is_width == 0) {
      prot->space_flag = 1;
      this_is_flag = 1;
    } else if (format[i] == '#' && this_is_length == 0 && this_is_prec == 0 &&
               this_is_width == 0) {
      prot->sharp_flag = 1;
      this_is_flag = 1;
    } else if (format[i] == '0' && this_is_length == 0 && this_is_prec == 0 &&
               this_is_width == 0) {
      prot->zero_flag = 1;
      this_is_flag = 1;
    }
    // Check width
    if (this_is_width == 0 && this_is_prec == 0 && prot->width_star == 0 &&
        s21_check_number(format, i) == true) {
      prot->width_number = 1;
      this_is_width = 1;
    } else if (this_is_width == 0 && this_is_prec == 0 &&
               prot->width_number == 0 && format[i] == '*') {
      prot->width_star = 1;
      this_is_width = 1;
    }
    // Check prec
    if (this_is_width == 0 && this_is_flag == 0 && format[i] == '.') {
      prot->prec = 1;
      i++;
      if (s21_check_number(format, i) == true)
        prot->prec_number = 1;
      else if (format[i] == '*')
        prot->prec_star = 1;
    }
    // Check length
    if ((this_is_width == 0 && this_is_flag == 0 && this_is_prec == 0)) {
      if (format[i] == 'h')
        prot->length_h = 1;
      else if (format[i] == 'l')
        prot->length_l = 1;
      else if (format[i] == 'L')
        prot->length_L = 1;
    }
    // Check spec
    if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i' ||
        format[i] == 'e' || format[i] == 'E' || format[i] == 'f' ||
        format[i] == 'g' || format[i] == 'G' || format[i] == 'o' ||
        format[i] == 's' || format[i] == 'u' || format[i] == 'x' ||
        format[i] == 'X' || format[i] == 'p' || format[i] == 'n')
      prot->spec = 1;
    if (prot->spec == 1)
      break;
    else
      i++;  // в самый конец
  }
  return i;
}

bool s21_check_number(const char *format, int i) {
  bool result = false;
  // Найден баг проверяю char '1' c int 1 исправить
  for (int n = 0; n <= 9; n++) {
    if (format[i] == n) result = true;
  }
  return result;
}
