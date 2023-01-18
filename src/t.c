#define s21_size_t unsigned int 


//------
#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(const char *str);

int main (void)
{    
  // Массив со строкой для поиска
  char str [44]="//tast1/te@st2/tus#t3/test4";
  // Набор символов, которые должны входить в искомый сегмент
  char sep [10]="#/@";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  //char *istr;

  printf ("Исходная строка: %s\n", str);
  printf ("Делители: %s\n", sep);
  printf ("Результат разбиения:\n");
  
    printf("ret1 %s\n", s21_strtok(str, sep));
    printf("ret2 %s\n", s21_strtok(NULL, sep));
    printf("ret3 %s\n", s21_strtok(str, sep));
    printf("ret4 %s\n", s21_strtok(NULL, "#/@"));
    printf("ret5 %s\n", s21_strtok(NULL, sep));
    
  return 0;
}

char *s21_strtok(char *str, const char *delim) {
    int str_ind = 0;
    static int ret_ind;
    static int first_time;
    static char* str_cash;
    printf("\nft%d ww %s    %s\n", first_time, str_cash, str);
    
    if(str != NULL) {
        // str_ind = 0;
        ret_ind = 0;
        first_time = 0;
        str_cash = NULL;
    };
    if(first_time == 0){
        str_cash = str;
    };
    if(str == NULL) {
        str = str_cash;
        // str_ind = 0;
    };
    printf("ft%d strc %s    str %s\n", first_time, str_cash, str);
    // str_ind = 0;
    // printf("d %s    %s\n", str, delim);
    if(first_time == 0){
         // for(str_ind; str[str_ind] != '\0'; str_ind++) {
        while(str[str_ind] != '\0'){
            int delim_ind = 0;
            int match_count = 0;
            while(delim[delim_ind] != '\0'){
            // for(delim_ind; delim[delim_ind] != '\0'; delim_ind++){
                // printf("qq %c    %c\n", str[str_ind], delim[delim_ind]);
                if(str[str_ind] == delim[delim_ind]){
                    match_count++;
                    break;
                };
                delim_ind++;
                // printf("w %d\n", match_count);
            };
            if(match_count == 0) break;
            str_ind++;
        };
        first_time = 1;
        // printf("qq %d\n", str_ind);   // вернет после цикла индекс \0
        // printf("ff %d\n", s21_strlen(str));
        if((int)s21_strlen(str) == str_ind) return NULL;    //  если строка пустая или полностью состоит из разделителей. --> избавится от return
        ret_ind = str_ind;
    };
    
    if(first_time == 1){
        ret_ind = str_ind;
        while(str[str_ind] != '\0'){
            // printf("si %d\n", str_ind);
            int delim_ind = 0;
            int match = 0;
            while(delim[delim_ind] != '\0'){
                // printf("qq %c    %c\n", str[str_ind], delim[delim_ind]);
                if(str[str_ind] == delim[delim_ind]){
                    str[str_ind] = '\0';
                    match++;
                    break;
                };
                delim_ind++;
            }
            if(match == 1) break;
            str_ind++;
        }
        str_ind++;
    }
    str_cash = &str[str_ind];
    return &str[ret_ind];

    //  1. NULL аргумент - Ok!
    //  2. убрать повторяющиеся делители и добавить возврат null при окончании строки или разбиения
    
}


s21_size_t s21_strlen(const char *str) {
    s21_size_t size =0;
    const char *p = str;
    while(*p != '\0') {
        size++;
        p++;
    };
    return size;
}