#include "s21_string.h"
#include "s21_sprintf.h"
#include <malloc.h>

//char *func(char *str);

// %[флаги][ширина][.точность][длина]спецификатор

int main() {
    char *a = "1234";

    char str[256];
    sprintf(str, "%-10.6d", 1234);
    printf("%s.\n", str);
    Prototype pr = {0};

    pr.spec = 'd';
    pr.minus_flag = 1; // выпавниваем по левому краю
    pr.width_number = 10; // ширина
    pr.prec_number = 6; // точность 
    int n = strlen(a); // длина


    if (n>=pr.width_number){
        if (n >=pr.prec_number) {
            printf("%s\n", a);
        }
        else if (n < pr.prec_number) {
            int buf = pr.prec_number - n;
            char *buf_str;
            buf_str = (char*)malloc(buf*sizeof(char));
            for (int i=0; i<buf;i++) {
                buf_str = strcat(buf_str, "0");
            }
            printf("buf_str =%s\n", buf_str);
            if (pr.spec == 'd')
                printf("%s\n", strcat(buf_str, a));
            // else if (pr.spec == 'f')
            //     printf("%s\n", strcat(a, buf_str));
        }
    }
    else if (n < pr.width_number) {
        if (n >= pr.prec_number) { // 2 case with minus flag
            int buf = pr.width_number - n;
            char *buf_str;
            buf_str = (char*)malloc(buf*sizeof(char));
            for (int i=0; i<buf;i++) {
                buf_str = strcat(buf_str, " ");
            }
            printf("buf_str =%s.\n", buf_str);

            if (pr.spec == 'd') {
               
                if (pr.minus_flag == 1) {
                     // printf("xui\n");
                     char *res;
                     res = (char*)malloc((n+buf-1)*sizeof(char));
                     res = strcat(res, a);
                     res = strcat(res, buf_str);
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
                int buf = pr.width_number - n;
                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));
               
                for (int i=0; i< buf -(pr.prec_number - n);i++) {
                    buf_str = strcat(buf_str," ");
                } 
                for (int i=0; i< pr.prec_number - n;i++) {
                    buf_str = strcat(buf_str, "0");
                }

                // printf("buf_str =%s\n", buf_str);
                if (pr.spec == 'd')
                    printf("%s\n", strcat(buf_str, a));
            }
            else if (pr.prec_number > pr.width_number) {
                printf("хуй\n");
                int buf = pr.prec_number - n;
                char *buf_str;
                buf_str = (char*)malloc(buf*sizeof(char));
               
                for (int i=0; i< buf;i++) {
                    buf_str = strcat(buf_str,"0");
                } 
                // printf("buf_str =%s\n", buf_str);
                if (pr.spec == 'd')
                    printf("%s\n", strcat(buf_str, a));
            }
        }
    }
    return 0;
}
