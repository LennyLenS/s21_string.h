#include <stdio.h>

typedef struct {
    char spec_type;
    int flag_minus;
    int flag_plus;
    int flag_space;
    int flag_sharp;
    int flag_zero;
    int width;
    int accur;
    char length;
} option;

int main(){
    char str[50];
    char *format = "abcd%%wefg";
    
    char c;
    int j = 0;

    int k = printf("abcd%%wefg\n");
    
    option spec = {0};    // инициализируем структуру и заполняем ее нулями. Второй вариант, если будут проблемы {'\0', 0, 0, 0, 0, 0, 0, 0, '\0'}
                          // потом перенести в первый while()
    

    while (*format != '\0'){
        c = *format;
        printf("%d", j);
        if (c != '%'){
            str[j] = c;
            format++;
            j++;
            continue;
        };

        // тут инициализируем структуру

        // Simuletion of %%
        if(c == '%' && *(format - 1) == '%') {
            str[j] = '%';
            j++;
            format++;
            continue;
        };
        
        spec.width = 1;
        //
        // Парсер и все остальное
        //

        format++;
    };
    //j++;
    str[j] = '\0';
    printf("\nj%d k%d  str %s  spec.width %d ", j, k, str, spec.width);   // j возвращаемое значение, k контрольное
}





// int main()
// {
//     int int1 = 123;
//     float fl = 123.45;
//     long long1 = 12345678L;
//     char char1 = '@';
//     char *string1 = "Привет всем!";
//     double double1 = 3.14159;
//     long double longdouble1 = double1 * double1;
//     char *s = "Здравствуй, если не шутишь!";
    
//     printf ("1:%i %s %d:\n", s, int1, int1);
//     printf ("2:%27s:\n",s);
//     printf ("3:%-27s:\n",s);
//     printf ("4:%32s:\n",s);
//     printf ("5:%-32s:\n",s);
//     // printf ("6:%032s:\n",s);
//     printf ("7:%32.16s:\n",s);
//     printf ("8:%-32.16s:\n",s);
//     printf ("9:%.16s:\n",s);
    
//     printf("Примеры использования функции printf()\n");
//     printf("ПЕРЕМЕННАЯ         РЕЗУЛЬТАТ\n");
//     printf("int (10-e)     == %+10.3d\n", int1);
//     printf("int i          == %d\n", int1);
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