#include "s21_sprintf.h"

#include "functions/s21_string.h"

int main() {
  char str[256] = {0};
  char str1[256] = {0};
  // char str2[256] = {0};
  double x = -268.723786;
  s21_sprintf(str, "%.9g", x);
  double y = -268.723786;
  // 838.65400000 при точности 18 падает %g
  // при точности только 1 сука нахуй падает -57251397732103429.56589367 %g
  // -7648938790.756589 точность 1 не проходит 16 тест падает 20 тест падает
  // точность 10 тест округляется не правильно 34 35 44 тест e spec c точностью
  // удалить нули 28 тесть при точности 15 268.723786000000
  sprintf(str1, "%.9g", y);
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