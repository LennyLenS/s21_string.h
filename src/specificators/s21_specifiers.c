#include <stdarg.h>
#include <string.h>
#include "s21_specifiers.h"

int specifier_f(char *buff, va_list args, Prototype prot){
	if(prot.prec_number == -1){
		prot.prec_number = 6;
	}
	if(prot.length == 'L'){
		long double a = va_arg(args, long double);
		s21_double_to_str(a, buff, prot.prec_number, prot.sharp_flag);
	}
	else{
		double a = va_arg(args, double);
		s21_double_to_str(a, buff, prot.prec_number, prot.sharp_flag);
	}
	return s21_strlen(buff);
}


int specifier_o(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 8, 0);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 8, 0);
        }else{
            buff[0] = ' ';
        }
	}

	return s21_strlen(buff);
}

int specifier_u(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 10, 0);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 10, 0);
        }else{
            buff[0] = ' ';
        }
	}
	return s21_strlen(buff);
}

int specifier_X(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 1);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 1);
        }else{
            buff[0] = ' ';
        }
	}

	return s21_strlen(buff);
}

int specifier_x(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 0);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 0);
        }else{
            buff[0] = ' ';
        }
	}

	return s21_strlen(buff);
}

int s21_spec_p(va_list args, char *charbuf, Prototype *prot){
    void *num = va_arg(args, void*);
    char buff[512] = {'\0'};
    long long int num2 = (long long int)num;
    if(num == S21_NULL) num2 = 0;
    int i = 0;
    UDecInNumSys(buff, num2, 16, 0);

    int p_len = s21_strlen(buff);
    int space_len = 0;
    int zero_len = 0;
    if(prot->prec_number > p_len) zero_len = prot->prec_number - p_len;
    if(prot->width_number > p_len + zero_len + 2) space_len = prot->width_number - (p_len + zero_len + 2);

    if(prot->minus_flag != 1){
        for(int k = 0; k < space_len; k++){
            *(charbuf + i) = ' ';
            i++;
        };
    }

    s21_strcat(charbuf, "0x");
    i +=2;

    for(int k = 0; k < zero_len; k++){
        *(charbuf + i) = '0';
        i++;
    };

    s21_strcat(charbuf, buff);
    i += p_len;
    if(prot->minus_flag == 1){
        for(int k = 0; k < space_len; k++){
            *(charbuf + i) = ' ';
            i++;
        };
    }
    return s21_strlen(charbuf);
}


void s21_spec_n(va_list args, int j){
    int *var = va_arg(args, int*);
    *var = j;
}

int s21_spec_id(va_list args, Prototype *prot, char *charbuf) {
    // long long int_128 num = 0;
    __int128_t num = 0;
    int neg_flag = 0;
    if(prot->length == 'h'){
        num = (short)va_arg(args, int);
    } else if(prot->length == 'l'){
        num = va_arg(args, long int);
    } else {
        num = va_arg(args, int);
    };
    // printf("!d %lld\n", num);

    int num_i = 0;

    if(num < 0){
        neg_flag = 1;
        num *= -1;
        charbuf[num_i] = '-';
        num_i = 1;
    }

    if(num == 0){
        if (prot->prec_number == 0) {
            charbuf[num_i] = '\0';
        num_i++;
        } else {
            charbuf[num_i] = '0';
            num_i++;
        }
    } else {
        while (num > 0){
            int tmp_dig = 0;
            tmp_dig = num%10;
            num = num / 10;
            charbuf[num_i] = tmp_dig + '0';
            num_i++;
        }
    }
    printf("!@ %s\n", charbuf);
    s21_reverse(charbuf, neg_flag);
    return num_i;
}


int s21_spec_s(char *str, va_list args, Prototype *prot) {
    int i = 0;
    int len = 0;
    int sp_qnt = 0;
    char *strng_arg = va_arg(args, char*);

    if(strng_arg == S21_NULL){
        s21_strcpy(str, "(null)");
        return 2;
    }

    if(prot->prec_number == -1) {
        len = (int)s21_strlen(strng_arg);
    } else {
        len = prot->prec_number;
    };
    
    if(prot->width_number < len) prot->width_number = len;

    sp_qnt = prot->width_number - len;

    if(prot->minus_flag == 1){
        i += prep_string(str, strng_arg, len, i);
        i += print_spaces(str, sp_qnt, i);
    } else {
        i += print_spaces(str, sp_qnt, i);
        i += prep_string(str, strng_arg, len, i);
    };
    return i;
}

int s21_spec_c(char *str, va_list args, Prototype *prot) {
    char c = va_arg(args, int);
    // if(c == '\0') c = 0;
    //  printf(":%d:\n", c);
    int sp_qnt = 0;
    int i = 0;
    int ret = 0;
    if(prot->width_number > 0){
        sp_qnt = prot->width_number -1;
    };
    if(prot->minus_flag == 1){
        str[i] = c;
        i++;
        i += print_spaces(str, sp_qnt, i);
    } else {
        i += print_spaces(str, sp_qnt, i);
        str[i] = c;
        i++;
    };
    if(c == 0) ret = -1;
    // printf("i :%d: s:%d:\n", i, str[i]);
    return ret;
}