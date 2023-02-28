#define s21_size_t unsigned int 


//------
#include <stdio.h>  // Для printf
#include <string.h> // Для strtok
#define S21_NULL ((void *)0)

char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(const char *str);

int main (void)
{    
  // Массив со строкой для поиска
//   char str[50] = "//$/test1//te@st2/test3//sd";
//   char str2[50] = "//$/test1//te@st2/test3//sd";
//   char *sep = "t";

//   char str [44]="//$/test1//te@st2/test3//sd";
//   char str2 [44]="//$/test1//te@st2/test3//sd";

//   char str [44]="uu/uuu/uuuu";
//   char str2 [44]="uu/uuu/uuuu";
  // Набор символов, которые должны входить в искомый сегмент
//   char sep [10]="@2";
//   char sep [10]="e";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  //char *istr;

  char s01[] = "\0Hello, world!";
  char s02[] = "\0Hello, world!";
  char s03[] = "\0";

  char s11[] = "\0Hello, world!";
  char s12[] = "\0Hello, world!";
  char s3[] = "";


  char *s21 = NULL;
  char *s22 = NULL;



//   printf ("Исходная строка: %s\n", str);
//   printf ("Делители: %s\n", sep);
  printf ("Результат разбиения:\n");
    printf("ret01 *%s\n", s21_strtok(s01, s03));
    printf("ret02 *%s\n", strtok(s02, s03));
  
    printf("ret11 *%s\n", s21_strtok(s11, s3));
    printf("ret12 *%s\n", strtok(s12, s3));
    
    printf("ret21 *%s\n", s21_strtok(s21, s3));
    printf("ret22 *%s\n", strtok(s22, s3));
    // printf("ret3 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    // printf("ret4 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    // printf("ret5 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    // printf("ret6 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    // printf("ret7 *%s  *%s\n", s21_strtok(NULL, sep), strtok(NULL, sep));
    // printf("ret8 *%s  *%s\n", s21_strtok(str, sep), strtok(str2, sep));
    
    // for(int i = 0; i <38; i++){
    //     printf("%d %c\n", i, str[i]);
    // }
  return 0;
}

char *s21_strtok(char *str, const char *delim) {
    int str_ind = 0;
    static int ret_ind;
    static char* str_cash;

    static int first_time;    
    if(str == S21_NULL && first_time == 0) {
        return S21_NULL;
    };
    first_time = 1;
    

    if(str != S21_NULL) {
        ret_ind = 0;
        str_cash = S21_NULL;
        str_cash = str;
    };
    if(str == S21_NULL) {
        str = str_cash;
    };
    while(str[str_ind] != '\0'){
        int delim_ind = 0;
        int match_count = 0;
        while(delim[delim_ind] != '\0'){
            if(str[str_ind] == delim[delim_ind]){
                match_count++;
                break;
            };
            delim_ind++;
        };
        if(match_count == 0) break;
        str_ind++;
    };
    if((int)s21_strlen(str) == str_ind) return S21_NULL;    //  если строка пустая или полностью состоит из разделителей.
    ret_ind = str_ind;
    
    while(str[str_ind] != '\0'){
        int delim_ind = 0;
        int match = 0;
        while(delim[delim_ind] != '\0'){
            if(str[str_ind] == delim[delim_ind]){
                str[str_ind] = '\0';
                match++;
                break;
            };
            delim_ind++;
        }
        str_ind++;
        if(match == 1) break;
    }
    if(str[ret_ind] == '\0') return S21_NULL;
    str_cash = &str[str_ind];
    return &str[ret_ind];
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