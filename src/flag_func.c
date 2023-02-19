#include "s21_string.h"
#include "s21_sprintf.h"
// #include <malloc.h>

char *add_sign(char *buf_str, Prototype pr, int sign);

char *main_func(char *str,  Prototype pr);

char *add_char(char *str, int n, int str_size, char c);
// void add_char(char *str, int str_size);

// char *add_sign(char *buf_str);

// %[флаги][ширина][.точность][длина]спецификатор

int main() {
    char *a = "123456";

    char str[256];
    sprintf(str, "%10.20d", 123456);
    printf("in lib:\n%s.\n", str);
    Prototype pr = {0};

    pr.spec = 'd';
    pr.minus_flag = 0; // выпавниваем по левому краю
    pr.plus_flag = 0; // выводит знак 
    pr.width_number = 10; // ширина
    pr.prec_number = 20; // точность 
    // int n = strlen(a); // длина

    printf("My:\n%s", main_func(a, pr));
   
    return 0;
}

char *main_func(char *str,  Prototype pr) {
     char *res;
    int n = 4, sign_of_num; //strlen(str), sign_of_num;
     // int sign_of_num = *str == '-' ? 1 : 0;
     if (*str == '-') {
        sign_of_num = 1;
        str = str + 1 ;
     } else {
        sign_of_num = 0;
     }
     printf("sign:%d\n", sign_of_num);
     // printf("test:%s\n", str);
    
     if (n>=pr.width_number){
        if (n >=pr.prec_number) {
            // printf("%s\n", a);
            res = str;
        }
        else if (n < pr.prec_number) {
            //printf("xui\n");
            int buf = pr.prec_number - n;
            
            // char *buf_str;
            //buf_str = (char*)malloc(buf*sizeof(char));

            str = add_char(str, buf, n, '0');

            if (pr.spec == 'd') {
                      if (pr.plus_flag == 1 || sign_of_num == 1) {
                        res = add_sign(str, pr, sign_of_num);
                      } else {
                        res = str;
                      }
                //}
            }
        }
    }
    
    else if (n < pr.width_number) {
        if (n >= pr.prec_number) { // 2 case with minus flag
         // printf("xui\n");
            int buf = pr.plus_flag == 1 ? pr.width_number - n - 1: pr.width_number - n;
            //char *buf_str;
            //buf_str = (char*)malloc((buf)*sizeof(char));
            
            //str = add_char(str, buf, n, ' ');

            if (pr.spec == 'd') {
                if (pr.plus_flag == 1 || sign_of_num == 1) {
                          str = add_sign(str, pr, sign_of_num);
                         
                }
                // else {
                //      str = add_char(str, buf, n, ' ');
                //      res = str;
                // }
                 str = add_char(str, buf, n, ' ');
                     res = str;
                    
            }
               
        }
        else if (n < pr.prec_number) {
            // точность и ширина больше длины - херачим пробелы и нули перед числом
            if (pr.prec_number <= pr.width_number) { // 1 case with minus_flag
            // printf("xui\n");

                int space_num = pr.width_number - pr.prec_number;

                // char *buf_str;
                // buf_str = (char*)malloc(buf*sizeof(char));

                str = add_char(str, pr.prec_number - n-2, n+1, '0');
                if (pr.plus_flag == 1 || sign_of_num == 1) {
                         str = add_sign(str, pr, sign_of_num);
                         space_num--;
                    }
                
                //printf("prom:%s.\n", str);
                // if (pr.minus_flag == 1) {
                //     strcat(buf_str, str);
                // }

                str = add_char(str, space_num, pr.prec_number, ' ');
                
                // if (sign_of_num == 1|| pr.minus_flag != 1) {
                //     res = str; // strcat(buf_str, str);
                // }
                // else {
                //     if (pr.plus_flag == 1 || sign_of_num == 1) {
                //          str = add_sign(str, pr, sign_of_num);
                //      }
                    res = str;
                // }
            }
            
            else if (pr.prec_number > pr.width_number) {
                printf("хуй last\n");

                // int buf = pr.prec_number - n;
                // char *buf_str;
                // buf_str = (char*)malloc(buf*sizeof(char));

                str = add_char(str, pr.prec_number-n, n, '0');

                // if (pr.spec == 'd') {
                //     if (pr.plus_flag == 1) {
                //          buf_str = add_sign(buf_str, pr, sign_of_num);
                //      }
                //      res = strcat(buf_str, str);
                // }
                   
            }
        }
    }


    
    return res;
}

char *add_sign(char *buf_str, Prototype pr, int sign) {
    printf("xui 0\n");
    
    //if (pr.plus_flag == 1 || sign == 1) {
        int str_size = strlen(buf_str);
        char *res = (char *)malloc((str_size + 2)*sizeof(char));
        
        for (int i = 1; i < str_size + 2; i++) {
            res[i] = buf_str[i-1];
        }
        
        if (sign == 1) { // если отрицательное число то по дефолту ставим -
            res[0] = '-';
        } else if (sign == 0 && pr.plus_flag) {
            res[0] = '+';
        } 
    //}
    return res;
}

char *add_char(char *str, int n, int str_size, char c) {
    int j = str_size;
    char *res = (char *)malloc((str_size + n + 1)*sizeof(char));

    for(int i = str_size + n; i >= 0; i--){
		if (j >= 0) {
            // printf("%c \n", str[j]);
            res[i] = str[j];
            j--;

        } else { 
            res[i] = c;
        }
       // printf("%c \n", res[i]);
	}

    //printf("Fuck:%s", res);
    return res;
}


/*

         -0000123456
          -0000123456
*/