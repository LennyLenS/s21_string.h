#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
#include "s21_string_files/s21_string.h"

int main()
{
   char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  printf("%s", s21_strtok(s2, s3));
 
    return 0;
=======
#include <stdlib.h>

void shift_str(char *str, int size){
	for(int i = size - 1; i > 0; -i){
		str[i] = str[i - 1];
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

int main(){
	char buff[512];
	double a = 2.999;
	s21_double_to_str(a, buff, 2);
    printf("%s\n", buff);
	printf("%.2f", a);
>>>>>>> urtotsma_branch
}