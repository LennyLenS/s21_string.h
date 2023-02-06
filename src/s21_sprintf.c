#include "s21_sprintf.h"

#include "functions/s21_string.h"

int main() {
  char str[256] = {0};
  // long int x = 0;
  s21_sprintf(str, "string%%");
}

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  va_list args;            // указатель на аргументы
  va_start(args, format);  // выделение памяти для arg
  // s21_parser(str, format, args);
  result = s21_parser(str, format, args);
  va_end(args);  // очищение памяти
  return result;
}