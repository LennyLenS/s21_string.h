#include <stdio.h>
//#include <string.h>
#define s21_size_t unsigned int 


//------
#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strlen(const char *str);

int main (void)
{    
  // Массив со строкой для поиска
  char str [44]="//test1//te@st2/tes#t3/test4";
  // Набор символов, которые должны входить в искомый сегмент
  char sep [10]="#/@";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  char *istr;

  printf ("Исходная строка: %s\n", str);
  printf ("Делители: %s\n", sep);
  printf ("Результат разбиения:\n");
  
    printf("ret %s\n", s21_strtok(str, sep));
    printf("ret2 %s\n", s21_strtok(str, sep));
    printf("ret3 %s\n", s21_strtok(str, sep));
    printf("ret4 %s\n", s21_strtok(str, sep));
    
  return 0;
}

char *s21_strtok(char *str, const char *delim) {
    static int str_ind;
    static int ret_ind;
    static int first_time;
    // str_ind = 0;
    // printf("d %s    %s\n", str, delim);
    if(first_time == 0){
        for(str_ind; str[str_ind] != '\0'; str_ind++) {
            int delim_ind = 0;
            int match_count = 0;
            for(delim_ind; delim[delim_ind] != '\0'; delim_ind++){
                // printf("qq %c    %c\n", str[str_ind], delim[delim_ind]);
                if(str[str_ind] == delim[delim_ind]){
                    match_count++;
                    break;
                }
                // printf("w %d\n", match_count);
            };
            if(match_count == 0) break;
        };
        first_time = 1;
        // printf("qq %d\n", str_ind);   // вернет после цикла индекс \0
        // printf("ff %d\n", s21_strlen(str));
        if(s21_strlen(str) == str_ind) return NULL;    //  если строка пустая или полностью состоит из разделителей. --> избавится от return
        ret_ind = str_ind;
    };
    
    if(first_time == 1){
        ret_ind = str_ind;
        for(str_ind; str[str_ind] != '\0'; str_ind++) {
            // printf("si %d\n", str_ind);
            int delim_ind = 0;
            int match = 0;
            for(delim_ind; delim[delim_ind] != '\0'; delim_ind++){
                // printf("qq %c    %c\n", str[str_ind], delim[delim_ind]);
                if(str[str_ind] == delim[delim_ind]){
                    str[str_ind] = '\0';
                    match++;
                    break;
                }
            }
            if(match == 1) break;
        }
        str_ind++;
    }
    return &str[ret_ind];
    
    //  убрать повторяющиеся делители и добавить возврат null при окончании строки или разбиения
    
}
//-------- end


s21_size_t s21_strlen(const char *str) {
    s21_size_t size =0;
    const char *p = str;
    while(*p != '\0') {
        size++;
        p++;
    };
    return size;
}

//------ статическая переменная
int count (int i) ;

int main(void){
count(0);
count(0);
printf("count called %d times", count (3));
return 0;
}

int count (int i){
    static int c=0;
    
    if(i) return c;
    else c++;
    return 0;
}
//------

#include <stdio.h>  // Для printf
#include <string.h> // Для strtok
int main (void)
{    
  // Массив со строкой для поиска
  char str [44]="test1/te@st2/tes#t3/test4";
  // Набор символов, которые должны входить в искомый сегмент
  char sep [10]="#/@";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  char *istr;

  printf ("Исходная строка: %s\n", str);
  printf ("Результат разбиения:\n");
  // Выделение первой части строки
  istr = strtok (str,sep);

  // Выделение последующих частей
  while (istr != NULL)
  {
      // Вывод очередной выделенной части
      printf ("%s\n",istr);
      // Выделение очередной части строки
      istr = strtok (NULL,sep);
  }
    printf ("qq %c\n",str[6]);
  return 0;
}

#include <stdio.h>
#include <string.h>
#define s21_size_t unsigned int 

int main() {
    char p[10] = "erfwrf";
    printf("%s", strtok("fdg@rgfs@rhtr", "@"));
    return 0;
}









//  -----------
s21_size_t s21_strlen(const char *str);

int main() {
    char p[10] = "erfwrf";
    printf("%d", s21_strlen(p));

    return 0;
}

s21_size_t s21_strlen(const char *str) {
    printf("%c \n", str[1]);
    printf("%d \n", *str);
    //printf("%s \n", &str);
    
    s21_size_t size =0;
    
    const char *p = str;
    while(*p != '\0') {
        printf("%c",  *p);
        size++;
        p++;
        //printf("qq - %ld",  size);
    }
    
        printf("\nqq - %d \n",  size);
    return size;
}
//  -----------