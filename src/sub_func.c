#include "sub_func.h"

void shift_str(char *str, int size){
	for(int i = ans - 1; i > 0; -i){
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

void specifier_o(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 10, 0);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 10, 0);
	}
}

void specifier_u(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 8, 0);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 8, 0);
	}
}

void specifier_x(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 16, 0);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 16, 0);
	}
}

void specifier_X(char *buff, va_list args, Prototype prot){
	if(prot.length == 'L'){
		unsigned long int num = va_arg(args, unsigned long int);
		UDecInNumSys(buff, num, 16, 1);
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
		UDecInNumSys(buff, num, 16, 1);
	}
}

void s21_double_to_str(double num, char *str, int pres) {
	int count_before_dot = 0, index = 0;
	double num1 = 0, num2 = num;
	while(num >= 1){
		num /= 10;
		count_before_dot++;
	}
	for(int i = 0; i < count_before_dot; ++i){
		num *= 10;
		int y = (int)num;
		num1 = num1 * 10 + y;
		num -= y;
		str[index++] = y + '0';
	}
	if(count_before_dot == 0){
		str[index++] = '0';
	}
	str[index++] = '.';
	num2 -= num1;
	for(int i = 0; i < pres; ++i){
		num2 *= 10;
		int y = (int)num2;
		num2 -= y;
		str[index++] = y + '0';
	}


	num2 *= 10;
	int y = (int)num2;
	if(y >= 5){
		int trans = 1;
		for(int i = count_before_dot + pres; i > 0; --i){
			if(str[i] != '.'){
				int a = str[i] - '0';
				str[i] = (a + trans) % 10 + '0';
				trans = (a + 1) / 10;
			}
		}

		if(trans == 1 && str[0] == '9'){
			shift_str(str, count_before_dot + pres + 1);
			str[1] = '0';
			str[0] = '1';
		}
		else if(trans == 1){
			str[0] = str[0] + 1;
		}

	}
	str[index] = '\0';
}

void specifier_f(char *buff, va_list args, Prototype prot){
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
}

