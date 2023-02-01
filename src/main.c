#include <stdio.h>

#include "s21_string.h"
#include "string.h"

// тут я тестирую последнюю функцю
int main() {
  char str[11] = "0123456789";
  // Набор символов, которые должны входить в искомый сегмент
  char sym[10] = "210";

  // Определяем длину начального сегмента, содержащего символы “210”

  printf("In my lib: %ld\n", s21_strspn(str, sym));
  printf("In orig lib: %ld\n", strspn(str, sym));
  return 0;
}