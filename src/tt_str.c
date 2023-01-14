#include <stdio.h>
//#include <string.h>
#define s21_size_t unsigned int 


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

// #include <stdio.h>  // Для printf
// #include <string.h> // Для strtok
// int main (void)
// {    
//   // Массив со строкой для поиска
//   char str [44]="test1/te@st2/tes#t3/test4";
//   // Набор символов, которые должны входить в искомый сегмент
//   char sep [10]="#/@";
//   // Переменная, в которую будут заноситься начальные адреса частей
//   // строки str
//   char *istr;

//   printf ("Исходная строка: %s\n", str);
//   printf ("Результат разбиения:\n");
//   // Выделение первой части строки
//   istr = strtok (str,sep);

//   // Выделение последующих частей
//   while (istr != NULL)
//   {
//       // Вывод очередной выделенной части
//       printf ("%s\n",istr);
//       // Выделение очередной части строки
//       istr = strtok (NULL,sep);
//   }
//     printf ("qq %c\n",str[6]);
//   return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #define s21_size_t unsigned int 

// // s21_size_t s21_strlen(const  char *str);

// int main()
// {
//     char p[10] = "erfwrf";
//     printf("%s", strtok("fdg@rgfs@rhtr", "@"));

//     return 0;
// }









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