#include "s21_specificators.h"

int s21_spec_id(va_list args, Prototype *prot, char *charbuf) {
    int len = 0;
    int i = 0;
    long int num = 0;
    if(prot->length == 'h'){
        num = (short)va_arg(args, int);
    } else if(prot->length == 'l'){
        num = va_arg(args, long int);
    } else {
        num = va_arg(args, int);
    };
    
    int num_i = 0;
    while (num > 0)
    {
        int tmp_dig;
        tmp_dig = num%10;
        num = num / 10;
        charbuf[num_i] = tmp_dig + '0';
        num_i++;
    }
    s21_reverse(charbuf);
   
    return num_i;
}