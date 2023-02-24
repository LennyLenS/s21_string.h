#include "s21_specificators.h"

int s21_spec_c(char *str, va_list args, Prototype *prot, int j) {
    char c = va_arg(args, int);
    int sp_qnt = 0;
    int i = 0;
    if(prot->width > 0){
        sp_qnt = prot->width -1;
    };
    if(prot->minus_flag == '-'){
        str[j] = c;
        i++;
        i += print_spaces(str, sp_qnt, j + i);
    } else {
        i += print_spaces(str, sp_qnt, j);
        str[j + i] = c;
        i++;
    };
    return i;
}