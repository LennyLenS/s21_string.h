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
} Prototype;

int s21_sprintf(char *str, const char *format, ...);
int print_spaces(char *str, int n, int j);
int prep_string(char *str, char *strng_arg, int n, int j);
void *s21_reverse (char *str);
int s21_spec_c(char *str, va_list args, Prototype *prot, int j);
int s21_spec_s(char *str, va_list args, Prototype *prot, int j);
int s21_spec_id(char *str, va_list args, Prototype *prot, char *charbuf, int j);
void s21_spec_n(va_list args, int j);

void UDecInNumSys(char *buff, unsigned long long int n, int mes);
void shift_str(char *str, int size);

int main(){
    char str[50];
    // char *format = "abc%%%%dwefg";
    int dk = 0;       // test %n
    int dd = 0;       // test %n
    int k =            printf("pr_ abc%n:sdwefg\n", &dk);
    int jn = s21_sprintf(str, "s21 abc%n:sdwefg\n", &dd);
    printf("%s\n", str);
    printf("dd %d   dk %d\n", dd, dk);       // test %n
    printf("\nj%d k%d  str %s/", jn, k, str);   // j возвращаемое значение, k контрольное
}


int s21_sprintf(char *str, const char *format, ...) {
    char c;
    int j = 0;
    char charbuf[512] = {'\0'};

    va_list args;
    va_start(args, format);
    
    while ((c = *format) != '\0'){
        if (c != '%'){
            str[j] = c;
            format++;
            j++;
            continue;
        };
        format++;

        Prototype prot = {'\0', 0, 0, 0, 0, 0, 0, -1, '\0'};    // инициализируем структуру и заполняем ее нулями.

        // обработка %%
        if((c = *format) == '%') {
            str[j] = '%';
            j++;
            format++;
            continue;
        };

        switch(c)  // simple parser
        {
            case 'i':
                prot.spec_type = 'i';
                break;
            case 'd':
                prot.spec_type = 'd';
                break;
            case 'c':
                prot.spec_type = 'c';
                prot.width = 5;
                prot.minus_flag = '-';
                break;
            case 's':
                prot.spec_type = 's';
                prot.precision = 5;
                prot.width = 10;
                prot.minus_flag = '-';
                break;
            case 'p':
                prot.spec_type = 'p';
                break;
            case 'n':
                prot.spec_type = 'n';
                break;
        };

        // printf("qq %c %c  %d\n", c, prot.spec_type, j);
        

        switch(prot.spec_type)
        {
            case 'i':
            case 'd':
                j += s21_spec_id(str, args, &prot, charbuf, j);
                break;
            case 'c':
                j += s21_spec_c(str, args, &prot, j);
                break;
            case 's': 
                j += s21_spec_s(str, args, &prot, j);
                break;
            case 'p':    //     указатель привести к longlongint потом конвертировать в 16тиричное число и в строку.
                ;
                // long long int num = (long long int)va_arg(args, void*);
                void *num = va_arg(args, void*);
                printf("pt1 %p \n", num);
                long long int num2 = (long long int)num;
                char buff[512] = {'\0'};
                UDecInNumSys(buff, num2, 16);
                printf("pt2 0x%s \n", buff);
                break;
            case 'n':
                s21_spec_n(args, j);

                // int count = 1;
                // printf ("this%n is a test\n", &count);
                // printf ("count%d\n", count);
                
                break;
        };
        // printf("%d  str %s\n", j, str);
        format++;
    };
    va_end(args);
    str[j] = '\0';
    // j++;
    return j;
}

void shift_str(char *str, int size){
    int size_ans = size;                        // добавил эту строчку
	for(int i = size_ans - 1; i > 0; i--){
		str[i] = str[i - 1];
	};
}


// мы вподе используем charbuf[512]
void UDecInNumSys(char *buff, unsigned long long int n, int mes){     //  изменил int n на long long int n
	int size_ans = 0;
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		if(n % mes > 9){
			buff[0] = n % mes - 10 + 'a';      // поменял 'A' на 'a'
		}else{
			buff[0] = n % mes + '0';
		}
		n /= mes;
	}
	buff[size_ans + 1] = '\0';
}



void s21_spec_n(va_list args, int j){
    int *var = va_arg(args, int*);
    *var = j;
}


// удалить все после /* */
// уточнить нужно ли возвращать длину строки
int s21_spec_id(char *str, va_list args, Prototype *prot, char *charbuf, int j) {
    int len = 0;
    int i = 0;
    long int num = 0;
    if(prot->length == 'h'){
        num = (short)va_arg(args, int);
    } else if(prot->length == 'l'){
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
    
    /* удалить все ниже до return */
    len = num_i;
    i += prep_string(str, charbuf, len, j);


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
    printf("sj :%c: num_i%d i%d\n", sign_fld, num_i, i);
    // j++;
    
    return num_i;
}

int s21_spec_s(char *str, va_list args, Prototype *prot, int j) {
    int i = 0;
    int len = 0;
    int sp_qnt = 0;
    char *strng_arg = va_arg(args, char*);

    if(prot->precision == -1) {
        len = (int)strlen(strng_arg);
    } else {
        len = prot->precision;
    };
    
    if(prot->width < len) prot->width = len;

    sp_qnt = prot->width - len;

    if(prot->minus_flag == '-'){
        i += prep_string(str, strng_arg, len, j);
        i += print_spaces(str, sp_qnt, j + i);
    } else {
        i += print_spaces(str, sp_qnt, j);
        i += prep_string(str, strng_arg, len, j + i);
    };
    return i;
}

int s21_spec_c(char *str, va_list args, Prototype *prot, int j) {
    char c = va_arg(args, int);
    int sp_qnt = 0;
    int i = 0;
    if(prot->width > 0){
        sp_qnt = prot->width -1;
    };
    if(prot->minus_flag == '-'){
        str[j] = c;
        i++;
        i += print_spaces(str, sp_qnt, j + i);
    } else {
        i += print_spaces(str, sp_qnt, j);
        str[j + i] = c;
        i++;
    };
    return i;
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

void *s21_reverse (char *str) {   // str должен быть массивом или сделан через malloc, а не указателем char * на область памяти в стеке
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
//     printf("char*          == %p\n", &char1);
//     printf("kjn09898789hkjh         == %nkj\n", &int1);
//     printf("kjn09898789hkjh         == %nkj\n");
    
//     int count =1;
//     printf ("this%n is a test\n", &count);
//     printf ("%d", count);

//     return 0;
// }

/*
+ c   Символ

+ s   Строка символов

+ d   Знаковое десятичное целое число

+ i   Знаковое целое число (может быть десятичным, восьмеричным или шестнадцатеричным)


e   Научная нотация (мантисса/экспонента) с использованием символа e (вывод чисел должен совпадать с точностью до e-6)
    Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

E   Научная нотация (мантисса/экспонента) с использованием символа Е
    Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

f   Десятичное число с плавающей точкой
    Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

g   Использует кратчайший из представлений десятичного числа
    Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)

G   Использует кратчайший из представлений десятичного числа
    Десятичное число с плавающей точкой или научная нотация (мантисса/экспонента)


o   Беззнаковое восьмеричное число

u   Беззнаковое десятичное целое число

x   Беззнаковое шестнадцатеричное целое число

X   Беззнаковое шестнадцатеричное целое число (заглавные буквы)


p   Адрес указателя

n   Количество символов, напечатанных до появления %n

+ %
*/
