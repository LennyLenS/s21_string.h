#include "s21_sprintf.h"
#include "s21_string.h"

int main() {
  char str[256] = {0};
  long int x = 0;
  s21_sprintf(str, "%*.*ld%c", 10, 5, x, 's');
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
  int i = -1;
  while (format[i++]) {
    // if (format[i] != '%') {
    //   s21_move_char_to_str();
    // }
    if (format[i] == '%') {
      Prototype prot = {0};
      s21_read_format(&prot, format, i, args);
    }
  }
}
// %[флаги][ширина][.точность][длина]спецификатор
int s21_read_format(Prototype *prot, const char *format, int i, va_list args) {
  int this_is_width = 0;
  int this_is_prec = 0;
  while (format[i]) {
    // Check flags
    if (format[i] == '+') {
      prot->plus_flag = 1;
    } else if (format[i] == '-') {
      prot->minus_flag = 1;
    } else if (format[i] == ' ') {
      prot->space_flag = 1;
    } else if (format[i] == '#') {
      prot->sharp_flag = 1;
    } else if (format[i] == '0' && this_is_prec == 0 && this_is_width == 0) {
      prot->zero_flag = 1;
    }
    // Check width
    if (s21_check_number(format, i) == true && this_is_width == 0) {
      prot->width_number = s21_write_number(format, &i);
      this_is_width = 1;
    } else if (prot->width_number == 0 && format[i] == '*' &&
               this_is_width == 0) {
      prot->width_star = va_arg(args, int);
      this_is_width = 1;
    }
    // Check prec
    if (format[i] == '.') {
      i++;
      if (s21_check_number(format, i) == true && this_is_prec == 0) {
        prot->prec_number = s21_write_number(format, &i);
        this_is_prec = 1;
      } else if (format[i] == '*' && this_is_prec == 0) {
        prot->prec_star = va_arg(args, int);
        this_is_prec = 1;
      }
    }
    // Check length
    if (format[i] == 'h') {
      prot->length_h = 1;
    } else if (format[i] == 'l') {
      prot->length_l = 1;
    } else if (format[i] == 'L') {
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
  if (format[i] >= '0' && format[i] <= '9') result = true;
  return result;
}

int s21_write_number(const char *format, int *i) {
  int width = 0;
  width += format[*i] - '0';
  *i += 1;
  while (s21_check_number(format, *i) == true) {
    width *= 10;
    width += format[*i] - '0';
    *i += 1;
  }
  return width;
}
