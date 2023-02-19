#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void s21_double_to_str(double num, char *str, int pres) {
	int n = 0;
	double num1 = 0, num2 = num;
	while(num >= 1){
		num /= 10;
		n++;
	}
	for(int i = 0; i < n; ++i){
		num *= 10;
		int y = (int)num;
		num1 = num1 * 10 + y;
		num -= y;
		str[0] = y + '0';
		str++;
	}
	str[0] = '.';
	str++;
	num2 -= num1;
	for(int i = 0; i < pres; ++i){
		num2 *= 10;
		int y = (int)num2;
		num2 -= y;
		str[0] = y + '0';
		str++;
	}
	str[0] = '\0';
}

int main(){
	char buff[512];
	double a = 3123.12;
	s21_double_to_str(a, buff, 30);
    printf("%s\n", buff);
	printf("%.30f", a);
}