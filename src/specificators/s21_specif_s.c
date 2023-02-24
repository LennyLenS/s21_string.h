#include "s21_specificators.h"

int s21_spec_s(char *str, va_list args, Prototype *prot, int j) {
    int i = 0;
    int len = 0;
    int sp_qnt = 0;
    char *strng_arg = va_arg(args, char*);

    if(prot->precision == -1) {
        len = (int)strlen(strng_arg);
    } else {
        len = prot->precision;
    };
    
    if(prot->width < len) prot->width = len;

    sp_qnt = prot->width - len;

    if(prot->minus_flag == '-'){
        i += prep_string(str, strng_arg, len, j);
        i += print_spaces(str, sp_qnt, j + i);
    } else {
        i += print_spaces(str, sp_qnt, j);
        i += prep_string(str, strng_arg, len, j + i);
    };
    return i;
}