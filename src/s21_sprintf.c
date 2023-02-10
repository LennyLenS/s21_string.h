#include "s21_sprintf.h"

#include "functions/s21_string.h"

int main() {
  char str[256] = {0};
  char str1[256] = {0};
  long double x = 4.23578;
  s21_sprintf(str, "string%e", x);
  // если после знака запятой будет 4 цифры, то нужно округлять
  long double y = 4.23578;
  sprintf(str1, "%LE", y);
  printf("Original: %s", str1);
}

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  va_list args;            // указатель на аргументы
  va_start(args, format);  // выделение памяти для arg
  result = s21_parser(str, format, args);
  va_end(args);  // очищение памяти
  return result;
}

int s21_parser(char *str, const char *format, va_list args) {
  int i = -1;
  int j = 0;  // считает количество символов в массиве str
  while (format[++i] != '\0') {
    if (format[i] != '%') {
      str[j] = format[i];
      j++;
    }
    if (format[i] == '%') {
      Prototype prot = {'\0', 0, 0, 0, 0, 0, 0, 0, -1, -1, '\0'};
      // обработка спецификатора и его параметров
      i = s21_read_format(&prot, format, i, args);
      if (prot.spec == '%') {
        str[j] = format[i];
        j++;
        continue;
      }
      // перевод args в массив str и возвращение количество символов в массиве
      j = s21_args_to_str(j, str, &prot, args);
    }
  }
  return j;
}