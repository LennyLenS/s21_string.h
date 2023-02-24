#include "s21_specificators.h"

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