#include "s21_sprintf.h"
char *main_func(char *str, Prototype *prot) {
  char *res;
  int str_len = s21_strlen(str);
  int negativ_num;

  if (*str == '-') {
    negativ_num = 1;
    str = str + 1;
  } else {
    negativ_num = 0;
  }
  if (prot->spec == 'f' || prot->spec == 'g' || prot->spec == 'G' ||
      prot->spec == 'e' || prot->spec == 'E') {
    prot->prec_number = -1;
  }
  if (prot->prec_number != -1) {
    if (prot->spec == 'd' || prot->spec == 'i' || prot->spec == 'o' ||
        prot->spec == 'u' || prot->spec == 'x' ||
        prot->spec == 'X') {  //  это только для целыx чисел
      str = prot->prec_number >= str_len
                ? add_char_left(str, prot->prec_number - str_len - 1,
                                str_len + 1, '0', *prot)
                : str;
      // printf("Buf str:%s\n", str);
    }
    if (prot->sharp_flag) {
      str = add_sharp_sign(str, *prot);
    }

    if (prot->width_number != 0) {
      str = n_shift(str, negativ_num, *prot);
    } else {
      // printf("3case\n");
      str = add_sign_or_space(str, *prot, negativ_num);
    }
    res = str;

  } else {
    if (prot->sharp_flag) {
      str = add_sharp_sign(str, *prot);
    }
    // printf("точность нет\n");
    if (prot->width_number != 0) {
      // printf("есть ширина 2\n");
      str = n_shift(str, negativ_num, *prot);
    } else {
      // printf("6case\n");
      str = add_sign_or_space(str, *prot, negativ_num);
    }
    res = str;  // add_sign_or_space(str, prot, negativ_num);
  }

  // printf("last: %d\n", (int)res[strlen(res)-1] );
  res = add_char_right(str, 1, strlen(str) + 1, '\0');
  // printf("last 2: %d\n", (int)res[strlen(res)] );
  return res;

  // return add_char_right(str, 1 , strlen(str), '\0');
}

char *add_sharp_sign(char *str, Prototype prot) {
  char *res;
  if ((prot.spec == 'o' && prot.prec_number == -1) || prot.spec == 'x' ||
      prot.spec == 'X') {
    int n = prot.spec == 'o' ? 1 : 2;

    res = (char *)malloc((strlen(str) + 1 + n) * sizeof(char));
    // printf("len: %ld\n", strlen(str));

    for (int i = n; i < (int)strlen(str) + 2; i++) {
      res[i] = str[i - n];
    }
    if (prot.spec == 'o') {
      res[0] = '0';
    } else if (prot.spec == 'x' || prot.spec == 'X') {
      res[0] = '0';
      res[1] = prot.spec;
    }
  } else {
    res = str;
  }
  return res;
}

char *n_shift(char *str, int negativ_num, Prototype prot) {
  int sign_size = 0;
  if (negativ_num == 1 || prot.plus_flag == 1) {
    sign_size = 1;
  }
  if (!prot.minus_flag) {
    // printf("1case\n");
    str = (int)strlen(str) >= prot.width_number
              ? add_sign_or_space(str, prot, negativ_num)
              : add_char_left(add_sign_or_space(str, prot, negativ_num),
                              prot.width_number - strlen(str) - 1 - sign_size,
                              strlen(str) + 1 + sign_size, ' ', prot);
  } else {
    // printf("2case\n");
    str = (int)strlen(str) >= prot.width_number
              ? add_sign_or_space(str, prot, negativ_num)
              : add_char_right(add_sign_or_space(str, prot, negativ_num),
                               prot.width_number - strlen(str) - 1 - sign_size,
                               strlen(str) + 1 + sign_size, ' ');
  }
  return str;
}

char *add_sign_or_space(char *buf_str, Prototype prot, int sign) {
  char *res;
  if (prot.plus_flag == 1 || sign == 1 || prot.space_flag) {
    int str_size = strlen(buf_str);
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
    int str_size = strlen(buf_str);
    res = (char *)malloc((str_size + 1) * sizeof(char));
    res = buf_str;
  }
  return res;
}

char *add_char_left(char *str, int n, int str_size, char c, Prototype prot) {
  if (prot.zero_flag) {
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