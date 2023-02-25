#include "s21_sprintf.h"
#include "s21_string.h"
#include <string.h>

char *add_sign_or_space(char *buf_str, Prototype pr, int sign);

char *main_func(char *str, Prototype pr);

char *add_char_left(char *str, int n, int str_size, char c, Prototype pr);
char *add_char_right(char *str, int n, int str_size, char c);
char *n_shift(char *str, int negativ_num, Prototype pr);


int main() {
  char *a = "-123";

  char str[256];
  sprintf(str, "%15d", -123);
  printf("in lib:\n%s!\n", str);
  Prototype pr = {0};

  pr.spec = 'd';
  pr.minus_flag = 0; // выпавниваем по левому краю
  pr.plus_flag = 0;  // выводит знак
  pr.space_flag = 0;
  pr.zero_flag = 0;
  pr.width_number = 15; // ширина
  pr.prec_number = -1;  // точность
  // int n = strlen(a); // длина

  printf("My:\n%s!\n", main_func(a, pr));

  return 0;
}

char *main_func(char *str, Prototype pr) {
  char *res;
  int str_len = strlen(str);
  int negativ_num;

  if (*str == '-') {
    negativ_num = 1;
    str = str + 1;
  } else {
    negativ_num = 0;
  }
  if (pr.spec == 'f' || pr.spec == 'g' || pr.spec == 'G' || pr.spec == 'e' ||
      pr.spec == 'E') {
    pr.prec_number = -1;
  }
  if (pr.prec_number != -1) {
    //  это только для целыx чисел
    if (pr.spec == 'd' || pr.spec == 'i' || pr.spec == '0' || pr.spec == 'u' ||
        pr.spec == 'x' || pr.spec == 'X') {
      str = pr.prec_number >= str_len
                ? add_char_left(str, pr.prec_number - str_len, str_len, '0', pr)
                : str;
    }

    if (pr.width_number != -1) {
    str = n_shift(str, negativ_num, pr);
    } else {
      // printf("3case\n");
      str = add_sign_or_space(str, pr, negativ_num);
    }
    res = str;

  } else {
    //printf("точность нет\n");
    if (pr.width_number != -1) {
      //printf("есть ширина 2\n");
     str = n_shift(str, negativ_num, pr);
    } else {
      // printf("6case\n");
      str = add_sign_or_space(str, pr, negativ_num);
    }
    res = str; // add_sign_or_space(str, pr, negativ_num);
  }
  return res;
}


char *n_shift(char *str, int negativ_num, Prototype pr) {
if (!pr.minus_flag) {
        printf("1case\n");
        str =
            (int)strlen(str) >= pr.width_number
                ? add_sign_or_space(str, pr, negativ_num)
                : add_char_left(add_sign_or_space(str, pr, negativ_num),
                                pr.width_number - strlen(str) - 1 - negativ_num,
                                strlen(str) + 1, ' ', pr);
      } else {
        printf("2case\n");
        str = (int)strlen(str) >= pr.width_number
                  ? add_sign_or_space(str, pr, negativ_num)
                  : add_char_right(add_sign_or_space(str, pr, negativ_num),
                                   pr.width_number - strlen(str) - 1 -
                                       negativ_num,
                                   strlen(str) + 1 + negativ_num, ' ');
      }
      return str;
}

char *add_sign_or_space(char *buf_str, Prototype pr, int sign) {
  char *res;
  if (pr.plus_flag == 1 || sign == 1 || pr.space_flag) {
    int str_size = strlen(buf_str);
    res = (char *)malloc((str_size + 2) * sizeof(char));

    for (int i = 1; i < str_size + 2; i++) {
      res[i] = buf_str[i - 1];
    }

    if (sign == 1) { // если отрицательное число то по дефолту ставим -
      res[0] = '-';
    } else if (sign == 0 && pr.plus_flag) {
      res[0] = '+';
    } else if (sign == 0 && !pr.plus_flag && pr.space_flag) {
      res[0] = ' ';
    }
    // res = add_sign(str, pr, sign_of_num);
  } else {
    int str_size = strlen(buf_str);
    res = (char *)malloc((str_size + 1) * sizeof(char));
    res = buf_str;
  }
  return res;
}

char *add_char_left(char *str, int n, int str_size, char c, Prototype pr) {
  if (pr.zero_flag) {
    c = '0';
  }
  int j = str_size - 1;
  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));

  for (int i = str_size + n; i >= 0; i--) {
    if (j >= 0) {
      res[i] = str[j];
      j--;
      //  printf("§");
    } else {
      res[i] = c;
    }
    // printf("%c ", res[i]);
  }

  return res;
}

char *add_char_right(char *str, int n, int str_size, char c) {

  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));

  for (int i = 0; i < str_size + n; i++) {
    if (i < str_size - 1) {
      res[i] = str[i];
      // printf("§");
    } else {
      res[i] = c;
    }
    // printf("%c ", res[i]);
  }

  return res;
}
