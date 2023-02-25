#include "s21_specifiers.h"
#include "sub_func.h"
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

int specifier_f(char *buff, va_list args, Prototype prot){
	if(prot.prec_number == -1){
		prot.prec_number = 6;
	}
	if(prot.length == 'L'){
		long double a = va_arg(args, long double);
		DoubleInStr(buff, a, prot.prec_number);
	}
	else{
		double a = va_arg(args, double);
		LongDoubleInStr(buff, a, prot.prec_number);
	}
	return s21_strlen(buff);
}

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

void s21_spec_n(va_list args, int j){
    int *var = va_arg(args, int*);
    *var = j;
}

int specifier_o(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 10, 0);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 10, 0);
	}

	return s21_strlen(buff);
}


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

int specifier_u(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 8, 0);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 8, 0);
	}
	return s21_strlen(buff);
}

int specifier_X(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 16, 1);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 16, 1);
	}

	return s21_strlen(buff);
}

int specifier_x(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 16, 0);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 16, 0);
	}

	return s21_strlen(buff);
}

