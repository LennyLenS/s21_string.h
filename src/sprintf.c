#include "s21_string.h"

int main() {
  char str[256];
  // long int x = -244;
  sprintf(str, "%#e", 123.);
  int x = 12345678;
  
  printf("%0.5d!\n", x);
 // printf("%d!\n", x);


}

// %[флаги][ширина][.точность][длина]спецификатор

// +- не совмещаются с #, но если нет # +- работает (проверить 0+-)
