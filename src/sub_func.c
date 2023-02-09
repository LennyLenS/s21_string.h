#include "sub_func.h"

void shift_str(char *str, int size){
	for(int i = size_ans - 1; i > 0; -i){
		str[i] = str[i - 1];
	}
}
char *DecInHex(int n){
	int size = (int)ceil(log2(n + 1) / 4) + 1;
	char *ans = (char *)malloc(size);
	int pos = size - 2;
	while(n > 0){
		int residue = n % 16;
		n /= 16;
		if(residue <= 9){
			ans[pos--] = residue + '0';
		}else{
			ans[pos--] = residue - 10 + 'A';
		}
	}
	ans[size - 1] = '\0';
	return ans;
}

char *DecInOct(int n){
	int size = (int)ceil(log2(n + 1) / 3) + 1;
	char *ans = (char *)malloc(size);
	int pos = size - 2;
	while(n > 0){
		int residue = n % 8;
		n /= 8;
		ans[pos--] = residue + '0';
	}
	ans[size - 1] = '\0';
	return ans;
}

char *DecInBin(int n){
	int size = (int)ceil(log2(n + 1)) + 1;
	char *ans = (char *)malloc(size);
	int pos = size - 2;
	while(n > 0){
		int residue = n % 2;
		n /= 2;
		ans[pos--] = residue + '0';
	}
	ans[size - 1] = '\0';
	return ans;

}

void UDecInStr(char *buff, unsigned int n){
	int size_ans = 0;
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		ans[0] = n % 10 + '0';
		n /= 10;
	}
	buff[size_ans + 1] = '\0';

}
void specifier_o(char *buff, int n){
	unsigned num = (unsigned int)n;
	UDecInStr(buff, num);
}