#include "functions/s21_string.h"
#include "s21_sprintf.h"

int s21_double_to_str(long double num, char *str_double, int num_i) {
  while (num > 0) {
    int num_double = 0;
    num_double = (int)num % 10;
    str_double[num_i] = num_double + '0';
    num_i++;
    num /= 10;
    num = (int)num;
  }
  return num_i;
}

int s21_isnan(double number) {
  int result = 0;
  if (number != number) {
    result = 1;
  }
  return result;
}

void *s21_reverse(char *str) {
  if (str == NULL) return NULL;
  int bgn = 0;
  int end = strlen(str) - 1;
  char temp;
  while (bgn < end) {
    temp = str[bgn];
    *(str + bgn) = *(str + end);
    *(str + end) = temp;
    bgn++;
    end--;
  }
  return str;
}