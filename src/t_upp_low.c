#define s21_size_t unsigned long
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t s21_strlen(const char *str);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);

int main()
{
    char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 01234567890 *-+/=";
    printf("%s   %ld\n", (char*)s21_to_upper(str), strlen(str));
    printf("%s   %ld\n", (char*)s21_to_lower(str), strlen(str));

    // char *str = NULL;
    // printf("%s\n", str);
    // printf("= %s\n", (char*)s21_to_upper(str));   // for NULL
    // printf("= %s\n", (char*)s21_to_lower(str));   // for NULL
    
    return 0;
}

void *s21_to_upper(const char *str){
    if(str == NULL) return NULL;
    s21_size_t n = s21_strlen(str);
    char *str_copy = (char *)malloc((n+1) * sizeof(char));
    if(str_copy == NULL) return NULL;
    for(s21_size_t i = 0; i < n; i++){
        if((str[i] > 96) && (str[i] < 123)) {
            str_copy[i] = str[i] - 32;
        } else {
            str_copy[i] = str[i];
        }
    }
    str_copy[n] = '\0';
    return (void *)str_copy;
}

void *s21_to_lower(const char *str){
    s21_size_t n = s21_strlen(str);
    char *str_copy = (char *)malloc((n+1) * sizeof(char));
    if(str_copy == NULL) return NULL;
    for(s21_size_t i = 0; i < n; i++){
        if((str[i] > 64) && (str[i] < 91)) {
            str_copy[i] = str[i] + 32;
        } else {
            str_copy[i] = str[i];
        }
    }
    str_copy[n] = '\0';
    return (void *)str_copy;
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