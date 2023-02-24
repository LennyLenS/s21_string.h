#include <stdio.h>
#include <string.h>
#include "s21_string_files/s21_string.h"

int main()
{
   char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  printf("%s", s21_strtok(s2, s3));
 
    return 0;
}