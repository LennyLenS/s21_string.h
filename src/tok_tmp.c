#define s21_size_t unsigned int 


//------
#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(const char *str);

int main (void)
{    
  // Массив со строкой для поиска
  char str [44]="//$/test1//te@st2/test3//sd";
  char str2 [44]="//$/test1//te@st2/test3//sd";
//   char str [44]="uu/uuu/uuuu";
//   char str2 [44]="uu/uuu/uuuu";
  // Набор символов, которые должны входить в искомый сегмент
  char sep [10]="#/@";
//   char sep [10]="e";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  //char *istr;

  printf ("Исходная строка: %s\n", str);
  printf ("Делители: %s\n", sep);
  printf ("Результат разбиения:\n");
  
    printf("ret1 *%s  *%s\n", s21_strtok(str, sep), strtok(str2, sep));
    printf("ret2 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    printf("ret3 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    printf("ret4 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    printf("ret5 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    printf("ret6 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    printf("ret7 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    printf("ret8 *%s  *%s\n", s21_strtok(str, sep), strtok(str2, sep));
    
    for(int i = 0; i <38; i++){
        printf("%d %c\n", i, str[i]);
    }
  return 0;
}

char *s21_strtok(char *str, const char *delim) {
    int str_ind = 0;
    static int ret_ind;
    // static int first_time;
    static char* str_cash;
    // static int glob_match = 0;

    // printf("\nww %s    %s\n", str_cash, str);
    
    if(str != NULL) {
        ret_ind = 0;
        // first_time = 0;
        str_cash = NULL;
        // glob_match = 0;
        str_cash = str;
    };
    // if(first_time == 0){
    //     str_cash = str;
    // };
    if(str == NULL) {
        str = str_cash;
    };
    // printf("strc %s    str %s\n", str_cash, str);
    // printf("d %s    %s\n", str, delim);
    // if(first_time == 0){
        while(str[str_ind] != '\0'){
            int delim_ind = 0;
            int match_count = 0;
            while(delim[delim_ind] != '\0'){
                // printf("qq %c    %c\n", str[str_ind], delim[delim_ind]);
                if(str[str_ind] == delim[delim_ind]){
                    match_count++;
                    break;
                };
                delim_ind++;
                // printf("w %d\n", match_count);
            };
            // printf("qq %d\n", match_count);
            if(match_count == 0) break;
            str_ind++;
        };
        // first_time = 1;
        //  printf("si %d\n", str_ind);   // вернет после цикла индекс \0
        //  printf("len %d\n", s21_strlen(str));
        if((int)s21_strlen(str) == str_ind) return NULL;    //  если строка пустая или полностью состоит из разделителей. --> избавится от return
        ret_ind = str_ind;
    // };
    

    // if(first_time == 1){
        ret_ind = str_ind;
        // int rep_dilim = 0;
        
        while(str[str_ind] != '\0'){
             // printf("sib %d  %d\n", str_ind, ret_ind);
            int delim_ind = 0;
            int match = 0;
            // printf("aa %d\n", rep_dilim);
            while(delim[delim_ind] != '\0'){
                // printf("qq %c    %c\n", str[str_ind], delim[delim_ind]);
                if(str[str_ind] == delim[delim_ind]){
                    // printf("ff %d\n", rep_dilim);
                    if(str_ind != 0 && (str[str_ind - 1] == '\0')) {
                        ret_ind++;
                        // rep_dilim = 1;
                        // printf("tt %d\n", rep_dilim);
                        match++;
                        break;
                    };
                    // glob_match = 1;
                    str[str_ind] = '\0';
                    match++;
                    break;
                };
                delim_ind++;
            }
            // printf("ss %d\n\n", rep_dilim);
            str_ind++;
            if(match == 1) break;
            // if(match == 0) rep_dilim = 0;
        }
    // }
    printf("end s*%d    r*%d   *%s\n", str_ind, ret_ind, str);
    // if(str[str_ind] == '\0') {
    //     return &str[ret_ind];
    // };
    if(str[ret_ind] == '\0') return NULL;
    str_cash = &str[str_ind];
    return &str[ret_ind];

    //  0. Избавится от фаз. Это решит проблему множественных разделителей и одновременно строк состоящих только из делителей.
    //  1. Разобрать этот случай
    //  2. удобавить возврат null при окончании строки или разбиения
    
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