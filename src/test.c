#include <stdio.h>
#include <string.h>
#include "s21_string_files/s21_string.h"

int main(){
   char buff[512];
   buff[0] = '\0';
   s21_strncat(buff, "123", 2);

   printf("%s", buff);
    
   return(0);
}