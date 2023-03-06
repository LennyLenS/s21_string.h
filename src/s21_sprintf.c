#include "s21_sprintf.h"

#include "functions/s21_string.h"

int main() {
  char str[256] = {0};
  char str1[256] = {0};
  // char str2[256] = {0};
  long double x = 76.756589;
  s21_sprintf(str, "%#Lg", x);
  long double y = 76.756589;
  // точность 10 тест округляется не правильно 34 35 44 тест e spec c точностью
  // в 34 35 поменять точность с 10 на 7 44 убрать %e
  // Ошибки снизу %g
  // 838.654 при точности 18 падает %g +++ до точности 14 работает
  // 16 тест падает 20 тест падает +++
  // -7648938790.756589  +- падает при большом целом теперь точность 1 проходит
  // точность 15 падает тест 31 точность 13 тест 32  --- до 10 точности только
  // тест 35 34 g, 38 тест 13 точность падает, 39 точность 15  ????
  // тест 40,41 не убираются незначащие нули +++
  // 42 43 тест лишний нолик при 9 --- 9 точность убрать
  // точности ок 45 тест 1.  ++++
  // шарпы везде работают!
  sprintf(str1, "%#Lg", y);
  printf("Original: %s\n", str1);
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
  int counter_symbols_str = 0;
  while (format[++i] != '\0') {
    if (format[i] != '%') {
      str[counter_symbols_str] = format[i];
      counter_symbols_str++;
    }
    if (format[i] == '%') {
      Prototype prot = {'\0', 0, 0, 0, 0, 0, 0, 0, -1, -1, '\0'};
      // обработка спецификатора и его параметров
      i = s21_read_format(&prot, format, i, args);
      if (prot.spec == '%') {
        str[counter_symbols_str] = format[i];
        counter_symbols_str++;
        continue;
      }
      // перевод args в массив str и возвращение количество символов в массиве
      counter_symbols_str =
          s21_args_to_str(counter_symbols_str, str, &prot, args);
    }
  }
  return counter_symbols_str;
}