#include <stdio.h>
#include <stdarg.h>
#include <string.h>
// #include <stdlib.h>

typedef struct {
    char spec_type;
    int minus_flag;
    int plus_flag;
    int space_flag;
    int sharp_flag;
    int zero_flag;
    int width;
    int precision;
    char length;
} option;

int s21_sprintf(char *str, const char *format, ...);
int print_spaces(char *str, int n, int j);
int prep_string(char *str, char *strng_arg, int n, int j);
void *s21_reverse (char *str);

int main(){
    char str[50];
    // char *format = "abc%%%%dwefg";
    int k =            printf("pr_ abc%d:sdwefg\n", 0xD6E);
    int jn = s21_sprintf(str, "s21 abc%d:sdwefg\n", 0xD6E);
    printf("%s", str);
    printf("\nj%d k%d  str %s/", jn, k, str);   // j возвращаемое значение, k контрольное
}


int s21_sprintf(char *str, const char *format, ...) {
    char c;
    int j = 0;
    int s_qnt = 0;


    va_list args;
    va_start(args, format);
    
        while ((c = *format) != '\0'){
        // printf("%d", j);
        if (c != '%'){
            str[j] = c;
            format++;
            j++;
            continue;
        };
        format++;

        // тут инициализируем структуру
        option spec = {'\0', 0, 0, 0, 0, 0, 0, -1, '\0'};    // инициализируем структуру и заполняем ее нулями. Второй вариант, если будут проблемы {'\0', 0, 0, 0, 0, 0, 0, 0, '\0'}
                            // потом перенести в первый while()

        // обработка %%
        if((c = *format) == '%') {
            str[j] = '%';
            j++;
            format++;
            continue;
        };

        switch(c)  // simple parser
        {
            case 'd':
                spec.spec_type = 'd';
                break;
            case 'c':
                spec.spec_type = 'c';
                spec.width = 5;
                spec.minus_flag = '-';
                break;
            case 's':
                spec.spec_type = 's';
                spec.precision = -1;
                spec.width = 10;
                spec.minus_flag = '\0';
                break;
        };

        // printf("qq %c %c  %d\n", c, spec.spec_type, j);

        // spec.width = 1;   // потом удалить
        //
        // Парсер и все остальное
        //
        
        char charbuf[512] = {'\0'};
        int len = 0;

        switch(spec.spec_type)
        {
            case 'd':
                ;
                long int num = 0;
                if(spec.length == 'h'){
                    num = (short)va_arg(args, int);
                } else if(spec.length == 'l'){
                    num = va_arg(args, long int);
                } else {
                    num = va_arg(args, int);
                };
                
                int num_i = 0;
                while (num > 0)
                {
                    int tmp_dig;
                    tmp_dig = num%10;
                    num = num / 10;
                    charbuf[num_i] = tmp_dig + '0';
                    num_i++;
                    printf("f %d: %ld  %d  %c\n", num_i, num, tmp_dig, charbuf[num_i - 1]);
                }
                s21_reverse(charbuf);
                len = num_i;
                j += prep_string(str, charbuf, len, j);


                for(int i = 0; charbuf[i] != '\0'; i++){
                    printf("cb %d %c \n", i, charbuf[i]);
                };
                printf("\ncharbuf %s \n", charbuf);

                printf("len %d\n", len);
                char sign_fld = '0';

                // str[j] = num + '0';
                // char *tt;
                // char *qq = num + '0';
                // strncpy(tt, qq);
                printf("sj :%c: %d\n", sign_fld, num_i);
                // j++;
                break;
            case 'c':
                c = va_arg(args, int);
                s_qnt = 0;
                if(spec.width > 0){
                    s_qnt = spec.width -1;
                };
                if(spec.minus_flag == '-'){
                    str[j] = c;
                    j++;
                    j += print_spaces(str, s_qnt, j);
                } else {
                    j += print_spaces(str, s_qnt, j);
                    str[j] = c;
                    j++;
                };
                break;
            case 's': 
                s_qnt = 0;
                char *strng_arg = va_arg(args, char*);

                if(spec.precision == -1) {
                    len = (int)strlen(strng_arg);
                } else {
                    len = spec.precision;
                };
                
                if(spec.width < len) spec.width = len;

                s_qnt = spec.width - len;

                // if(spec.precision > -1) {
                // } else {
                //     s_qnt = spec.width;
                // };

                if(spec.minus_flag == '-'){
                    j += prep_string(str, strng_arg, len, j);
                    j += print_spaces(str, s_qnt, j);
                } else {
                    j += print_spaces(str, s_qnt, j);
                    j += prep_string(str, strng_arg, len, j);
                };
                // str[j] = strng_arg;
                // j++;
                break;
        }
        // printf("%d  str %s\n", j, str);
        format++;
    };
    va_end(args);
    str[j] = '\0';
    // j++;
    return j;
}

int print_spaces(char *str, int n, int j) {
    for(int i = 0; i < n; i++)
        str[j + i] = ' ';
    return n;
}

int prep_string(char *str, char *strng_arg, int n, int j) {
    for(int i = 0; i < n; i++){
        str[j + i] = strng_arg[i];
    };
    return n;
}

void *s21_reverse (char *str) {   // str должен быть массивом или сделан через malloc, а не указателем на область памяти
    if(str == NULL) return NULL;
    int bgn = 0;
    int end = strlen(str) - 1;
    char temp;
    // printf("ee %s\n", str);
    // printf("d %d  %d\n", bgn, end);
    while(bgn < end) {
        temp = str[bgn];
        *(str + bgn) = *(str + end);
        *(str + end) = temp;
        bgn++;
        end--;
    }
    printf("ff %s\n", str);
    return str;
}









// #include <stdio.h>
// int main()
// {
//     int int1 = 123;
//     float fl = 123.45;
//     long long1 = 12345678L;
//     char char1 = '@';
//     char *string1 = "Привет всем!";
//     double double1 = 3.14159;
//     long double longdouble1 = double1 * double1;
//     char *s = "Hello World**!";
    
//     printf ("1 :%d %d:\n", int1, int1);
//     printf ("2 :%27s:\n",s);
//     printf ("3 :%-27s:\n",s);
//     printf ("4 :%32s:\n",s);
//     printf ("5 :%-32s:\n",s);
//     // printf ("6 :%032s:\n",s);
//     printf ("7 :%32.16s:\n",s);
//     printf ("8 :%-32.16s:\n",s);
//     printf ("9 :%.16s:\n",s);
    
//     printf("Примеры использования функции printf()\n");
//     printf("ПЕРЕМЕННАЯ         РЕЗУЛЬТАТ\n");
//     printf("int (10-e)     == :%+10.3d:\n", int1);
//     printf("int i          == :%d:\n", int1);
//     printf("int f          == %.3f\n", fl);
//     printf("int (16-e)     == %#x\n", int1);
//     printf("int (8-e)      == %#o\n", int1);
//     printf("long           == %+ld\n", long1);
//     printf("char           == %c\n", char1);
//     printf("string         == %s\n", string1);
//     printf("double         == % .7lf\n", double1);
//     printf("longdouble(1)  == %+Le\n", longdouble1);
//     printf("longdouble(2)  == %Lf\n", longdouble1);

//     return 0;
// }