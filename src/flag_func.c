#include "s21_sprintf.h"
#include "s21_string.h"
#include <string.h>

char *add_sign(char *buf_str, Prototype pr, int sign);

char *main_func(char *str, Prototype pr);

char *add_char(char *str, int n, int str_size, char c);
char *add_char_right(char *str, int n, int str_size, char c);

int main() {
  char *a = "123.4567"; 

  char str[256];
  sprintf(str, "%+12.1f", 123.4567);
  printf("in lib:\n%s!\n", str);
  Prototype pr = {0};

  pr.spec = 'f';
  pr.minus_flag = 0;    // выпавниваем по левому краю
  pr.plus_flag = 1;     // выводит знак
  pr.width_number = 12; // ширина
  pr.prec_number = 1;   // точность
  // int n = strlen(a); // длина

  printf("My:\n%s!\n", main_func(a, pr));

  return 0;
}

char *main_func(char *str, Prototype pr) {
  char *res; 
  int n = strlen(str), sign_of_num;
  if (*str == '-') {
    sign_of_num = 1;
    str = str + 1;
  } else {
    sign_of_num = 0;
  }
  //printf("sign:%d\n", sign_of_num);
   int len_drob_part;
   char *dot_place;
    if (pr.spec == 'f') {
         dot_place = strstr(str, ".");
         //printf("Dot place:%s\n", dot_place);
         len_drob_part = (int)(strlen(dot_place) - 1);
         //printf("Drob part: %d\n", len_drob_part);
         n = len_drob_part;
         
    }

  if (n >= pr.width_number) { // ok
    if (n >= pr.prec_number) {
      
      if (pr.spec == 'd') {
        if (pr.plus_flag == 1 || sign_of_num == 1) {
          res = add_sign(str, pr, sign_of_num);
        } else {
            res = str;
        } 
      } else if (pr.spec == 'f') {
        printf("1 case\n");
          if (pr.plus_flag == 1 || sign_of_num == 1) {
            str = add_sign(str, pr, sign_of_num);
          }
        memcpy(res, str, strlen(str)- len_drob_part + pr.prec_number);
      } 
    
    
    } else if (n < pr.prec_number) { // ok

      int buf = pr.prec_number - n;
      // str = add_char(str, buf - 2, n + 1, '0');
      // printf("xui 1\n");
     
      if (pr.spec == 'd') {
         str = add_char(str, buf - 2, n + 1, '0');
        if (pr.plus_flag == 1 || sign_of_num == 1) {
          res = add_sign(str, pr, sign_of_num);
        } else {
          res = str;
        }
      } else if (pr.spec == 'f') {
          printf("2 case\n");
            if (pr.plus_flag == 1 || sign_of_num == 1) {
              str = add_sign(str, pr, sign_of_num);
            }
         
          res = add_char_right(str, buf, strlen(str), '0');
      }
    }
  }

  else if ((int)strlen(str) < pr.width_number) { // дина строки < точности 
    if (n >= pr.prec_number) { // ok
      int buf = pr.spec == 'f' ? pr.width_number - strlen(str) -1: pr.width_number - strlen(str);

     
        if (pr.plus_flag || sign_of_num == 1) {
          str = add_sign(str, pr, sign_of_num);
          //buf++;
          n++;
        }

        if (pr.spec == 'd' ) {
          if (pr.minus_flag) {
            // if (pr.plus_flag || sign_of_num == 1) {
            //   n++;
            // }
            //printf("xui 1\n");
            str = add_char_right(str, buf-2, strlen(str), ' ');
          } else {
            // printf("xui 1\n");
            str = add_char(str, buf-2, (int)strlen(str) + 1, ' ');
          }
          res = str;
      } else if (pr.spec == 'f') {
         printf("xui 1\n");
         char *buf_res = (char *)malloc((pr.width_number + 1) * sizeof(char));
         memcpy(buf_res, str, strlen(str)- len_drob_part + pr.prec_number);  
         // buf_res[strlen(str)- len_drob_part + pr.prec_number + 1] = '\0';

         if (pr.minus_flag) {
          printf("xui test\n");
            res = add_char_right(buf_res, buf - 2, (int)strlen(buf_res) + 1, ' ');
          } else {
            res = add_char(buf_res, buf - 2, (int)strlen(buf_res) + 1, ' ');
          }

      }

    } else if (n < pr.prec_number) {
      // точность и ширина больше длины - херачим пробелы и нули перед числом
      if (pr.prec_number <= pr.width_number) {

        int space_num = pr.width_number - pr.prec_number;
        str = add_char(str, pr.prec_number - n, n, '0');
        if (pr.plus_flag == 1 || sign_of_num == 1) {
          str = add_sign(str, pr, sign_of_num);
          space_num--;
        }
        if (pr.minus_flag) {
             str = add_char_right(str, space_num, pr.prec_number, ' ');
        } else {
             str = add_char(str, space_num, pr.prec_number, ' ');
        }
       
        res = str;

      } else if (pr.prec_number > pr.width_number) {
        if (pr.spec == 'd') { 
        int space_num = pr.prec_number - n;
        str = add_char(str, space_num, n + 1, '0');

        if (pr.plus_flag == 1 || sign_of_num == 1) {
          str = add_sign(str, pr, sign_of_num);
        }

        res = str;
      } else if (pr.spec == 'f') {
           printf("xui 1\n");
        int buf = pr.width_number - (int)strlen(str);
         char *buf_res = (char *)malloc((pr.width_number + 1) * sizeof(char));
         memcpy(buf_res, str, strlen(str)- len_drob_part + pr.prec_number);  
         // buf_res[strlen(str)- len_drob_part + pr.prec_number + 1] = '\0';

         if (pr.minus_flag) {
          printf("xui test\n");
            res = add_char_right(buf_res, buf - 2, (int)strlen(buf_res) + 1, ' ');
          } else {
            res = add_char(buf_res, buf, (int)strlen(buf_res) + 1, ' ');
          }
      } 
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
  int j = str_size-2;
  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));

  for (int i = str_size; i >= 0; i--) {
    if (j >= 0) {
      res[i] = str[j];
      j--;
     //  printf("§");
    } else {
      res[i] = c;
    } 
   printf("%c ", res[i]);
  }

  return res;
}

char *add_char_right(char *str, int n, int str_size, char c) {

  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));

  for (int i = 0; i < str_size + n; i++) {
    if (i < str_size-1) {
      res[i] = str[i];
      printf("§");
    } else {
      res[i] = c;
    }
    printf("%c ", res[i]);
  }

  return res;
}
