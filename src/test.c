#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void shift_str(char *str, int size){
	for(int i = size - 1; i > 0; i--){
		str[i] = str[i - 1];
	}
}
void UDecInNumSys(char *buff, unsigned int n, int mes){
	int size_ans = 0;
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		if(n % mes > 9){
			buff[0] = n % mes - 10 + 'A';
		}else{
			buff[0] = n % mes + '0';
		}
		n /= mes;
	}
	buff[size_ans + 1] = '\0';

}

void specifier_o(char *buff, int n){
	unsigned num = (unsigned int)n;
	UDecInNumSys(buff, num, 10);
}

int main(){
    unsigned a = 1956;
    char buff[512];
    UDecInNumSys(buff, a, 2);
    printf("%g", 456.5600001);
}