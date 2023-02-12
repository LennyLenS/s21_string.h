#include "sub_func.h"

void shift_str(char *str, int size){
	for(int i = size_ans - 1; i > 0; -i){
		str[i] = str[i - 1];
	}
}

void UDecInNumSys(char *buff, unsigned int n, int mes){
	int size_ans = 0;
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		if(n % mes > 9){
			ans[0] = n % mes - 10 + 'A';
		}else{
			ans[0] = n % mes + '0';
		}
		n /= mes;
	}
	buff[size_ans + 1] = '\0';

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