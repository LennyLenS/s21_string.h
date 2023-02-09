#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void shift_str(char *str, int size){
	for(int i = size - 1; i > 0; i--){
		str[i] = str[i - 1];
	}
}
void UDecInStr(char *buff, unsigned int n){
	int size_ans = 0;
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		buff[0] = n % 10 + '0';
		n /= 10;
	}
	buff[size_ans + 1] = '\0';

}

int main(){
    unsigned a = 1956;
    char buff[512];
    UDecInStr(buff, a);
    printf("%s", buff);
}