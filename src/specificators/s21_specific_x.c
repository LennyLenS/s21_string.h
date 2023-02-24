#include "s21_specificators.h"

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