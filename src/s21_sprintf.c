#include "s21_sprintf.h"

#include "s21_string.h"

int main() {
  char str[256] = {0};
  // int x = 0;
  s21_sprintf(str, "%c", 's');
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;            // указатель на аргументы
  va_start(args, format);  // выделение памяти для arg
  s21_parser(str, format, args);
  va_end(args);
}

int s21_parser(char *str, const char *format, va_list args) {
  int i = 2;
  Prototype prot = s21_init_prototype();
  s21_read_prototype();
}

Prototype s21_init_prototype() {
  Prototype prot;
  prot.specification = 0;
  prot.flags = 0;
  prot.minus_flags = 0;
  prot.space_flags = 0;
  prot.zero_flags = 0;
  prot.sharp_flags = 0;
  prot.width = 0;
  prot.width_star = 0;
  prot.precision = -1;
  prot.length = 0;
  return prot;
}
