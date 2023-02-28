#ifndef SRC_S21_FLAG_HANDLER_
#define SRC_S21_FLAG_HANDLER_


#include "./specificators/s21_specifiers.h"

char *add_sign_or_space(char *buf_str, Prototype prot, int sign);

char *main_func(char *str, Prototype *prot);

char *add_char_left(char *str, int n, int str_size, char c, Prototype prot);
char *add_char_right(char *str, int n, int str_size, char c);
char *n_shift(char *str, int negativ_num, Prototype prot);
char *add_sharp_sign(char *str, Prototype prot);


#endif