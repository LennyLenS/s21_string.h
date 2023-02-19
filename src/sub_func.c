#include "sub_func.h"

void shift_str(char *str, int size){
	for(int i = size_ans - 1; i > 0; -i){
		str[i] = str[i - 1];
	}
}

void UDecInNumSys(char *buff, unsigned long long int n, int mes, int flag){     //  изменил int n на long long int n
	int size_ans = 0;
	char str[2];
	str[0] = 'a';
	str[1] = 'A';
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		if(n % mes > 9){
			buff[0] = n % mes - 10 + str[flag];    // поменял 'A' на 'a'
		}else{
			buff[0] = n % mes + '0';
		}
		n /= mes;
	}
	buff[size_ans] = '\0';
}

void specifier_o(char *buff, int n){
	unsigned num = (unsigned int)n;
	UDecInNumSys(buff, num, 10);
}

void specifier_u(char *buff, int n){
	unsigned num = (unsigned int)n;
	UDecInNumSys(buff, num, 8);
}

void specifier_x(char *buff, int n){
	unsigned num = (unsigned int)n;
	UDecInNumSys(buff, num, 16);
}

void specifier_X(char *buff, int n){
	unsigned num = (unsigned int)n;
	UDecInNumSys(buff, num, 16);
}

void DoubleInStr(buff, a, prot.prec_number){
	int a_int = (int)a;
	
}

void specifier_f(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		long double a = va_arg(args, long double);
		DoubleInStr(buff, a, prot.prec_number);
	}
	else{
		double a = va_arg(args, double);
		LongDoubleInStr(buff, a, prot.prec_number);
	}
}


fgfg{
	if(p){

	}
}