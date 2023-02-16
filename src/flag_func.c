#include "s21_string.h"
#include "s21_sprintf.h"
#include <malloc.h>

char *add_sign(char *buf_str);

char *main_func(char *str,  Prototype pr);

char *add_char(char *str, int n, char *c);

char *add_sign(char *buf_str);

// %[флаги][ширина][.точность][длина]спецификатор

int main() {
    char *a = "1234";

    char str[256];
    sprintf(str, "% 20d", 1234);
    printf("%s.\n", str);
    Prototype pr = {0};

    pr.spec = 'd';
    pr.minus_flag = 0; // выпавниваем по левому краю
    pr.plus_flag = 0; // выводит знак 
    pr.width_number = 1; // ширина
    pr.prec_number = 10; // точность 
    // int n = strlen(a); // длина

    printf("%s", main_func(a, pr));
    /*
    if (n>=pr.width_number){
        if (n >=pr.prec_number) {
            printf("%s\n", a);
        }
        else if (n < pr.prec_number) {
            // printf("xui");
            int buf = pr.prec_number - n;
            char *buf_str;
            buf_str = (char*)malloc(buf*sizeof(char));
            for (int i=0; i<buf;i++) {
                buf_str = strcat(buf_str, "0");
            }
            printf("buf_str =%s\n", buf_str);
            if (pr.spec == 'd') {
                if (pr.plus_flag == 1) {
                    buf_str = func(buf_str);
                    printf("%s\n", strcat(buf_str, a));
                }
                else {
                     printf("%s\n", strcat(buf_str, a));
                }
            }
               
        }
    }
    else if (n < pr.width_number) {
        if (n >= pr.prec_number) { // 2 case with minus flag
            int buf = pr.plus_flag == 1 ? pr.width_number - n -1: pr.width_number - n;
            char *buf_str;
            buf_str = (char*)malloc(buf*sizeof(char));
            for (int i=0; i<buf;i++) {
                buf_str = strcat(buf_str, " ");
            }
            printf("buf_str =%s.\n", buf_str);
            if (pr.spec == 'd') {
               
                if (pr.minus_flag == 1) {
                     printf("xui\n");
                     char *res;
                     res = (char*)malloc((n+buf-1)*sizeof(char));
                     res = strcat(res, a);
                     res = strcat(res, buf_str);
                     if (pr.plus_flag == 1) {
                         res = func(res);
                     }
                     printf("%s.\n", res);
                }
                else {
                     printf("%s\n", strcat(buf_str, a));
                }
                    
            }
               
        }
        else if (n < pr.prec_number) {
            // точность и ширина больше длины - херачим пробелы и нули перед числом
            if (pr.prec_number <= pr.width_number) { // 1 case with minus_flag
                // printf("хуй\n");
                //int buf = pr.width_number - n;
                int buf = pr.plus_flag == 1 ? pr.width_number - n - 1: pr.width_number - n;

                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));
                
                for (int i=0; i< pr.prec_number - n;i++) {
                    buf_str = strcat(buf_str, "0");
                }
                if (pr.minus_flag == 1) {
                    strcat(buf_str, a);
                }
                
                     for (int i=0; i< buf -(pr.prec_number - n);i++) {
                     buf_str = strcat(buf_str," ");
                }
                
                if (pr.spec == 'd' && pr.minus_flag != 1) {
                    printf("%s\n", strcat(buf_str, a));
                }
                else {
                    if (pr.plus_flag == 1) {
                         buf_str = func(buf_str);
                     }
                    printf("%s.\n", buf_str);
                }
            }
            else if (pr.prec_number > pr.width_number) {
                // printf("хуй\n");
                int buf = pr.prec_number - n;
                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));
               
                for (int i=0; i< buf;i++) {
                    buf_str = strcat(buf_str,"0");
                } 
                // printf("buf_str =%s\n", buf_str);
                if (pr.spec == 'd') {
                    if (pr.plus_flag == 1) {
                         buf_str = func(buf_str);
                     }
                     printf("%s\n", strcat(buf_str, a));
                }
                   
            }
        }
    }
    */
    return 0;
}

char *main_func(char *str,  Prototype pr) {
    char *res;
     int n = strlen(str);

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

            // for (int i=0; i<buf;i++) {
            //     buf_str = strcat(buf_str, "0");
            // }

            // printf("buf_str =%s\n", buf_str);
            if (pr.spec == 'd') {
                if (pr.plus_flag == 1) {
                    buf_str = add_sign(buf_str);
                    //printf("%s\n", strcat(buf_str, a));
                    return strcat(buf_str, str);
                }
                else {
                     // printf("%s\n", strcat(buf_str, a));
                     return  strcat(buf_str, str);
                }
            }
               
        }
    }
    else if (n < pr.width_number) {
        if (n >= pr.prec_number) { // 2 case with minus flag
            int buf = pr.plus_flag == 1 ? pr.width_number - n -1: pr.width_number - n;
            char *buf_str;
            buf_str = (char*)malloc(buf*sizeof(char));

            // for (int i=0; i<buf;i++) {
            //     buf_str = strcat(buf_str, " ");
            // }
             buf_str = add_char(buf_str, buf, " ");

            // printf("buf_str =%s.\n", buf_str);
            if (pr.spec == 'd') {
               
                if (pr.minus_flag == 1) {
                     // printf("xui\n");
                     char *res_buf;
                     res_buf = (char*)malloc((n+buf-1)*sizeof(char));
                     // res_buf = strcat(res_buf, res_buf);
                     res_buf = strcat(res_buf, buf_str);
                     if (pr.plus_flag == 1) {
                         res_buf = add_sign(res_buf);
                     }
                     // printf("%s.\n", res);
                     res = res_buf;
                }
                else {
                     // printf("%s\n", strcat(buf_str, a));
                     res = strcat(buf_str, str);
                }
                    
            }
               
        }
        else if (n < pr.prec_number) {
            // точность и ширина больше длины - херачим пробелы и нули перед числом
            if (pr.prec_number <= pr.width_number) { // 1 case with minus_flag
                // printf("хуй\n");
                //int buf = pr.width_number - n;
                int buf = pr.plus_flag == 1 ? pr.width_number - n - 1: pr.width_number - n;

                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));
                
                // for (int i=0; i< pr.prec_number - n;i++) {
                //     buf_str = strcat(buf_str, "0");
                // }
                buf_str = add_char(buf_str, buf, "0");

                if (pr.minus_flag == 1) {
                    strcat(buf_str, str);
                }
                
                    //  for (int i=0; i< buf -(pr.prec_number - n);i++) {
                    //      buf_str = strcat(buf_str," ");
                    // }
                     buf_str = add_char(buf_str, buf, " ");
                
                if (pr.spec == 'd' && pr.minus_flag != 1) {
                    // printf("%s\n", strcat(buf_str, str));
                    res = strcat(buf_str, str);
                }
                else {
                    if (pr.plus_flag == 1) {
                         buf_str = add_sign(buf_str);
                     }
                    // printf("%s.\n", buf_str);
                    res = buf_str;
                }
            }
            else if (pr.prec_number > pr.width_number) {
                // printf("хуй\n");
                int buf = pr.prec_number - n;
                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));
               
                // for (int i=0; i< buf;i++) {
                //     buf_str = strcat(buf_str,"0");
                // } 
                buf_str = add_char(buf_str, buf, "0");

                // printf("buf_str =%s\n", buf_str);
                if (pr.spec == 'd') {
                    if (pr.plus_flag == 1) {
                         buf_str = add_sign(buf_str);
                     }
                     // printf("%s\n", strcat(buf_str, a));
                     res = strcat(buf_str, str);
                }
                   
            }
        }
    }



    return res;
}

char *add_sign(char *buf_str) {
    // char *res;
    memmove( buf_str + 1, buf_str, strlen( buf_str ) + 1 );
    memset( buf_str, '+', 1 );
    return buf_str;
}

char *add_char(char *str, int n, char *c) {
     for (int i = 0; i < n;i++) {
                 str = strcat(str, c);
             }
    return str;
}