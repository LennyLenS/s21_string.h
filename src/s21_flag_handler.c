#include "s21_sprintf.h"
#include "s21_string_files/s21_string.h"

char *add_sign_or_space(char *buf_str, Prototype prot, int sign);

char *main_func(char *str, Prototype *prot);

char *add_char_left(char *str, int n, int str_size, char c, Prototype prot);
char *add_char_right(char *str, int n, int str_size, char c);
char *n_shift(char *str, int negativ_num, Prototype prot);
char *add_sharp_sign(char *str, Prototype prot);

char *main_func(char *str, Prototype *prot) {
  // printf("start str:%s\n", str);
  prot->width_number =
      prot->width_number != 0 ? prot->width_number : prot->width_star;
  char *str1;

  char *res;
  // int str_len = s21_strlen(str);
  int negativ_num;
  if (*str == '-') {
    negativ_num = 1;
    str1 = (char *)malloc(s21_strlen(str));
    for (int i = 1; i <= (int)s21_strlen(str); ++i) {
      str1[i - 1] = str[i];
    }
  } else {
    str1 = (char *)malloc(s21_strlen(str) + 1);
    for (int i = 0; i < (int)s21_strlen(str) + 1; ++i) {
      str1[i] = str[i];
    }
    negativ_num = 0;
  }
  str = str1;

  // printf("!%s!\n", str);
  if (prot->spec == 'f' || prot->spec == 'g' || prot->spec == 'G' ||
      prot->spec == 'e' || prot->spec == 'E') {
    prot->prec_number = -1;
  }
  if (prot->spec == 'o' || prot->spec == 'u' || prot->spec == 'x' ||
      prot->spec == 'X') {
    prot->plus_flag = 0;
    prot->space_flag = 0;
  }
  if (prot->spec != 's') {
    if (prot->prec_number != -1) {
      if (prot->spec == 'd' || prot->spec == 'i' || prot->spec == 'o' ||
          prot->spec == 'u' || prot->spec == 'x' || prot->spec == 'X' ||
          prot->spec == 'n') {  //  это только для целыx чисел
        if (prot->prec_number > (int)s21_strlen(str)) {
          // printf("1:%s\n", str);
          char *buff_str =
              add_char_left(str, prot->prec_number - (int)s21_strlen(str) - 1,
                            (int)s21_strlen(str) + 1, '0', *prot);
          // printf("2:%s\n", buff_str);
          free(str);
          str = buff_str;
        }
      }

      // printf("Buf str:%s\n", str);
      if (prot->sharp_flag) {
        char *buff_str = add_sharp_sign(str, *prot);
        free(str);
        str = buff_str;
      }
      if (prot->width_number != 0 || prot->width_star != 0) {
        char *buff_str = n_shift(str, negativ_num, *prot);
        free(str);
        str = buff_str;
      } else {
        // printf("3case\n");
        char *buff_str = add_sign_or_space(str, *prot, negativ_num);
        free(str);
        str = buff_str;
      }
    } else {
      if (prot->sharp_flag) {
        char *buff_str = add_sharp_sign(str, *prot);
        free(str);
        str = buff_str;
      }
      if (prot->width_number != 0 || prot->width_star != 0) {
        // printf("!%s!\n", str);
        char *buff_str = n_shift(str, negativ_num, *prot);
        free(str);
        str = buff_str;
        // printf("!%s!\n", str);
      } else {
        //  printf("6case\n");
        char *buff_str = add_sign_or_space(str, *prot, negativ_num);
        free(str);
        str = buff_str;
      }
      // add_sign_or_space(str, prot, negativ_num);
    }
  } else {
    if (!prot->minus_flag) {
      if (prot->width_number > (int)s21_strlen(str)) {
        // printf("wi:%d \n", prot->width_number );
        char *buff_str =
            add_char_left(str, prot->width_number - (int)s21_strlen(str) - 1,
                          (int)s21_strlen(str) + 1, ' ', *prot);
        free(str);
        str = buff_str;
        // printf("str:%s\n", str);
      }
    } else {
      if (prot->width_number > (int)s21_strlen(str)) {
        // printf("wi:%d \n", prot->width_number );
        char *buff_str =
            add_char_right(str, prot->width_number - (int)s21_strlen(str) - 1,
                           (int)s21_strlen(str) + 1, ' ');
        free(str);
        str = buff_str;
        // printf("str:%s\n", str);
      }
    }
  }
  // printf("last: %d\n", (int)res[strlen(res)-1] );
  char *buff_str = add_char_right(str, 1, s21_strlen(str) + 1, '\0');
  free(str);
  str = buff_str;
  // printf("@!%s@\n", str);

  res = str;
  // printf("str fin:%s\n", res);
  return res;
}

char *add_sharp_sign(char *str, Prototype prot) {
  char *res;
  if ((prot.spec == 'o' || prot.spec == 'x' || prot.spec == 'X') &&
      *str == '0' && s21_strlen(str) == 1) {
    res = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    s21_memcpy(res, str, s21_strlen(str) + 1);

  } else if ((prot.spec == 'o' &&
              (prot.prec_number == -1 || prot.prec_number == 0)) ||
             prot.spec == 'x' || prot.spec == 'X') {
    int n = prot.spec == 'o' ? 1 : 2;

    res = (char *)malloc((s21_strlen(str) + 1 + n) * sizeof(char));

    for (int i = n; i < (int)s21_strlen(str) + 2; i++) {
      res[i] = str[i - n];
    }
    if (prot.spec == 'o') {
      res[0] = '0';
    } else if (prot.spec == 'x' || prot.spec == 'X') {
      res[0] = '0';
      res[1] = prot.spec;
    }
    res[s21_strlen(str) + n] = '\0';
  } else {
    res = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    s21_memcpy(res, str, s21_strlen(str) + 1);
  }
  return res;
}

char *n_shift(char *str, int negativ_num, Prototype prot) {
  int sign_size = 0;
  if (negativ_num == 1 || prot.plus_flag == 1 || prot.space_flag) {
    sign_size = 1;
  }
  if (prot.minus_flag == 1) {
    if ((int)s21_strlen(str) >= (prot.width_number + prot.width_star)) {
      char *buff_str = add_sign_or_space(str, prot, negativ_num);
      str = buff_str;
    } else {
      int str_size = s21_strlen(str);
      char *buff_str = add_sign_or_space(str, prot, negativ_num);
      str = buff_str;
      buff_str =
          add_char_right(str, prot.width_number - str_size - 1 - sign_size,
                         str_size + 1 + sign_size, ' ');

      free(str);
      str = buff_str;
    }
  } else {
    if ((int)s21_strlen(str) >= prot.width_number) {
      char *buff_str = add_sign_or_space(str, prot, negativ_num);
      // printf("!!%s@\n", buff_str);
      str = buff_str;
    } else {
      if (prot.zero_flag || *str == '0') {
        // printf("%d\n", (int)s21_strlen(str));
        char *buff_str = add_char_left(
            str, prot.width_number - s21_strlen(str) - 1 - sign_size,
            s21_strlen(str) + 1, ' ', prot);
        str = buff_str;
        buff_str = add_sign_or_space(str, prot, negativ_num);
        free(str);
        str = buff_str;

      } else {
        int str_size = s21_strlen(str);
        char *buff_str = add_sign_or_space(str, prot, negativ_num);
        str = buff_str;
        // printf("%d\n", (int)s21_strlen(str));
        buff_str =
            add_char_left(str, prot.width_number - str_size - 1 - sign_size,
                          str_size + 1 + sign_size, ' ', prot);
        free(str);
        str = buff_str;
      }
    }
  }
  return str;
}

char *add_sign_or_space(char *buf_str, Prototype prot, int sign) {
  // printf("@%s@\n", buf_str);
  char *res;
  if (prot.plus_flag == 1 || sign == 1 || prot.space_flag) {
    int str_size = s21_strlen(buf_str);
    res = (char *)malloc((str_size + 2) * sizeof(char));

    for (int i = 1; i < str_size + 2; i++) {
      res[i] = buf_str[i - 1];
    }

    if (sign == 1) {  // если отрицательное число то по дефолту ставим -
      res[0] = '-';
    } else if (sign == 0 && prot.plus_flag) {
      res[0] = '+';
    } else if (sign == 0 && !prot.plus_flag && prot.space_flag) {
      res[0] = ' ';
    }
    // res = add_sign(str, prot, sign_of_num);
  } else {
    // printf("no flags\n");
    int str_size = s21_strlen(buf_str);
    // printf("len: %d\n", str_size);
    res = (char *)malloc((str_size + 1) * sizeof(char));
    s21_memcpy(res, buf_str, s21_strlen(buf_str) + 1);
    // printf("@%s@\n", res);
  }

  return res;
}

char *add_char_left(char *str, int n, int str_size, char c, Prototype prot) {
  if (prot.zero_flag == 1) {
    c = '0';
  }
  int j = str_size - 1;
  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));

  for (int i = str_size + n; i >= 0; i--) {
    if (j >= 0) {
      res[i] = str[j];
      j--;
    } else {
      res[i] = c;
    }
  }
  res[str_size + n] = '\0';
  return res;
}

char *add_char_right(char *str, int n, int str_size, char c) {
  char *res = (char *)malloc((str_size + n + 1) * sizeof(char));
  for (int i = 0; i < str_size + n; i++) {
    if (i < str_size - 1) {
      res[i] = str[i];
    } else {
      res[i] = c;
    }
  }
  res[str_size + n] = '\0';
  return res;
}
