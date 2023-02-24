#include "s21_specificators.h"

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
