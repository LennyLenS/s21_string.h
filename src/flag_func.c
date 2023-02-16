#include "s21_string.h"
#include "s21_sprintf.h"
// #include <malloc.h>

char *add_sign(char *buf_str, Prototype pr, int sign);

char *main_func(char *str,  Prototype pr);

char *add_char(char *str, int n, char *c);

// char *add_sign(char *buf_str);

// %[флаги][ширина][.точность][длина]спецификатор

int main() {
    char *a = "-1234";

    char str[256];
    sprintf(str, "%+-20d", -1234);
    printf("%s.\n", str);
    Prototype pr = {0};

    pr.spec = 'd';
    pr.minus_flag = 1; // выпавниваем по левому краю
    pr.plus_flag = 1; // выводит знак 
    pr.width_number = 20; // ширина
    pr.prec_number = 0; // точность 
    // int n = strlen(a); // длина

    printf("%s", main_func(a, pr));
   
    return 0;
}

char *main_func(char *str,  Prototype pr) {
     char *res;
     int n = strlen(str), sign_of_num;
     // int sign_of_num = *str == '-' ? 1 : 0;
     if (*str == '-') {
        sign_of_num = 1;
        str = str + 1 ;
     } else {
        sign_of_num = 0;
     }
     // printf("%d\n", sign_of_num);
     // printf("test:%s\n", str);
    
     if (n>=pr.width_number){
        if (n >=pr.prec_number) {
            // printf("%s\n", a);
            res = str;
        }
        else if (n < pr.prec_number) {
            // printf("xui");
            int buf = pr.prec_number - n;
            
            char *buf_str;
            buf_str = (char*)malloc(buf*sizeof(char));

            buf_str = add_char(buf_str, buf, "0");

            if (pr.spec == 'd') {
                if (pr.plus_flag == 1) {
                    buf_str = add_sign(buf_str, pr, sign_of_num);
                    res = strcat(buf_str, str);
                }
                else {
                     res =  strcat(buf_str, str);
                }
            }
        }
    }
    else if (n < pr.width_number) {
        if (n >= pr.prec_number) { // 2 case with minus flag
            int buf = pr.plus_flag == 1 ? pr.width_number - n - 1: pr.width_number - n;
            char *buf_str;
            buf_str = (char*)malloc((buf)*sizeof(char));
            buf_str = add_char(buf_str, buf, " ");

            if (pr.spec == 'd') {
                if (pr.minus_flag == 1) {
                     printf("xui\n");
                     char *res_buf;
                    res_buf = malloc((n + buf + 1));

                    
                     res_buf = (char*)malloc((n + buf + 1)*sizeof(char));
                     str = strcat(str, buf_str);

                    //  //if (pr.plus_flag == 1 || ) {
                          res_buf = add_sign(res_buf, pr, sign_of_num);
                    //  //}
                     res = res_buf;
                }
                else {
                     res = strcat(buf_str, str);
                }
                    
            }
               
        }
        else if (n < pr.prec_number) {
            // точность и ширина больше длины - херачим пробелы и нули перед числом
            if (pr.prec_number <= pr.width_number) { // 1 case with minus_flag
                int buf = pr.plus_flag == 1 ? pr.width_number - n - 1: pr.width_number - n;

                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));

                buf_str = add_char(buf_str, buf, "0");

                if (pr.minus_flag == 1) {
                    strcat(buf_str, str);
                }
                     buf_str = add_char(buf_str, buf, " ");
                
                if (pr.spec == 'd' && pr.minus_flag != 1) {
                    res = strcat(buf_str, str);
                }
                else {
                    if (pr.plus_flag == 1) {
                         buf_str = add_sign(buf_str, pr, sign_of_num);
                     }
                    res = buf_str;
                }
            }
            else if (pr.prec_number > pr.width_number) {
                // printf("хуй\n");
                int buf = pr.prec_number - n;
                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));

                buf_str = add_char(buf_str, buf, "0");

                if (pr.spec == 'd') {
                    if (pr.plus_flag == 1) {
                         buf_str = add_sign(buf_str, pr, sign_of_num);
                     }
                     res = strcat(buf_str, str);
                }
                   
            }
        }
    }



    return res;
}

char *add_sign(char *buf_str, Prototype pr, int sign) {
    memmove( buf_str + 1, buf_str, strlen( buf_str ) + 1 );
    if (sign == 1) { // если отрицательное число то по дефолту ставим -
         memset( buf_str, '-', 1);
    } else if (sign == 0 && pr.plus_flag) {
         memset( buf_str, '+', 1 );
    } 
    return buf_str;
}

char *add_char(char *str, int n, char *c) {
     for (int i = 0; i < n;i++) {
                 str = strcat(str, c);
             }
    return str;
}