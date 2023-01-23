#include <stdio.h>  // Для printf
#include <string.h> // Для strtok

void *s21_memcpy(void *dest, const void *src, size_t n);

int main (void)
{
   // Массив источник данных
   char *src="0123456789abc";
 
   // Массив приемник данных
   unsigned char dst1[20]="qwertyuioprfvbh";
   unsigned char dst2[20]="qwertyuioprfvbh";

   // Копируем 6 байт из массива src в массив dst
   

   // Вывод массива dst на консоль
   printf ("dst: %s\n", (char *)memcpy(dst1, src, 13));
   printf ("dst: %s\n", (char *)s21_memcpy(dst2, src, 13));
   
   for(int i = 0; i < 20; i++){
       printf ("%d %c\n", i, dst2[i]);
   }
   return 0;
}

void *s21_memcpy(void *dest, const void *src, size_t n){
    size_t i = 0;
    //void *dest_tmp = dest;
    while(i < n) {
        *(char *)(dest + i) = *(char*)(src + i);
        i++;
        // dest++;
        // src++;
    }
    return dest;
}