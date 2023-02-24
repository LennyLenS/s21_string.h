#include <stdio.h>
#include <string.h>
#include "s21_string_files/s21_string.h"
#include "s21_sprintf.c"

int main()
{
	char *s = (char *)malloc(5000);
   s21_sprintf(s, "a %d a %u", 12, 64);
   printf("%s", s);
}