#include "s21_sprintf.h"
#include "s21_string.h"
// #include <malloc.h>

char *add_sign(char *buf_str, Prototype pr, int sign);

char *main_func(char *str, Prototype pr);

char *add_char(char *str, int n, int str_size, char c);
// void add_char(char *str, int str_size);

// char *add_sign(char *buf_str);

// %[флаги][ширина][.точность][длина]спецификатор

int main() {
  char *a = "123456";

  char str[256];
  sprintf(str, "%+10.20d", 123456);
  printf("in lib:\n%s.\n", str);
  Prototype pr = {0};

  pr.spec = 'd';
  pr.minus_flag = 0;    // выпавниваем по левому краю
  pr.plus_flag = 1;     // выводит знак
  pr.width_number = 10; // ширина
  pr.prec_number = 20;  // точность
  // int n = strlen(a); // длина

  printf("My:\n%s", main_func(a, pr));

  return 0;
}

char *main_func(char *str, Prototype pr) { 
  char *res;
  int n = 4, sign_of_num;
  if (*str == '-') {
    sign_of_num = 1;
    str = str + 1;
  } else {
    sign_of_num = 0;
  }
  printf("sign:%d\n", sign_of_num);

  if (n >= pr.width_number) { //ok
    if (n >= pr.prec_number) {
       if (pr.plus_flag == 1 || sign_of_num == 1) {
          res = add_sign(str, pr, sign_of_num);
        } else {
           res = str;
        }
    } else if (n < pr.prec_number) {  // ok
    
     int buf = pr.prec_number - n;
    // if (pr.plus_flag == 1 || sign_of_num == 1) {
    //       buf--;
    //     }
     
      str = add_char(str, buf-2, n+1, '0');

      if (pr.spec == 'd') {
        if (pr.plus_flag == 1 || sign_of_num == 1) {
          res = add_sign(str, pr, sign_of_num);
        } else {
          res = str;
        }
      }
    }
  }

  else if (n < pr.width_number) {
    if (n >= pr.prec_number) { // ok
      int buf =  pr.width_number - n;
      
      if (pr.spec == 'd') {
        if (pr.plus_flag == 1 || sign_of_num == 1) {
          str = add_sign(str, pr, sign_of_num);
          buf--;
        }
        str = add_char(str, buf-2, n+2, ' ');
        res = str;
      }

    } else if (n < pr.prec_number) { 
      // точность и ширина больше длины - херачим пробелы и нули перед числом
      if (pr.prec_number <= pr.width_number) { 
        printf("xuitest 2\n");
        int space_num = pr.width_number - pr.prec_number;
        str = add_char(str, pr.prec_number - n - 2, n + 1, '0');
        if (pr.plus_flag == 1 || sign_of_num == 1) {
          str = add_sign(str, pr, sign_of_num);
          space_num--;
        }
        str = add_char(str, space_num, pr.prec_number, ' ');
        res = str;
      }
      else if (pr.prec_number > pr.width_number) {
        int space_num = pr.prec_number - n;
        str = add_char(str, space_num - 2, n + 1, '0');

        if (pr.plus_flag == 1 || sign_of_num == 1) {
          str = add_sign(str, pr, sign_of_num);
        }

        res = str;
      }
    }
  }

  return res;
}

char *add_sign(char *buf_str, Prototype pr, int sign) {
  // printf("xui 0\n");
  int str_size = strlen(buf_str);
  char *res = (char *)malloc((str_size + 2) * sizeof(char));

  for (int i = 1; i < str_size + 2; i++) {
    res[i] = buf_str[i - 1];
  }

  if (sign == 1) { // если отрицательное число то по дефолту ставим -
    res[0] = '-';
  } else if (sign == 0 && pr.plus_flag) {
    res[0] = '+';
  }
  //}
  return res;
}

char *add_char(char *str, int n, int str_size, char c) {
  int j = str_size;
  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));

  for (int i = str_size + n; i >= 0; i--) {
    if (j >= 0) {
      res[i] = str[j];
      j--;

    } else {
      res[i] = c;
    }
  }

  return res;
}

/*

   -123456
    -123456


*/