#include "s21_specificators.h"

int s21_spec_p(va_list args, Prototype *prot, char *charbuf){
    void *num = va_arg(args, void*);
    char buff[512] = {'\0'};
    // printf("pt1 %p \n", num);
    long long int num2 = (long long int)num;
    UDecInNumSys(buff, num2, 16);   // Добавить флаг
    strcpy(charbuf, "0x");
    strcpy(charbuf, buff);
    // printf("pt2 0x%s \n", buff);
    return strlen(charbuf);
}
