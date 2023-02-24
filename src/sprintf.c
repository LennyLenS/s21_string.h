#include "s21_string.h"

int main() {
  char str[256];
  long int x = -244;
  sprintf(str, "%10.10ld", x);
  printf("%s", str);
  // int r = '9';
  // printf("%d", r);
}

// %[флаги][ширина][.точность][длина]спецификатор

// +- не совмещаются с #, но если нет # +- работает (проверить 0+-)
