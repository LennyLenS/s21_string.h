#include <stdio.h>
#include <string.h>
#include "s21_string_files/s21_string.h"

int main(){
   char buff[512];
   buff[0] = '\0';

   printf("%s\n", s21_strerror(97));
   printf("%s", strerror(98));
   return(0);
}