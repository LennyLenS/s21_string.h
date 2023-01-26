#define s21_size_t unsigned long
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t s21_strlen(const char *str);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);

int main()
{
    // insert
    char *src = "abcdef";
    char *str = "X vvvvvvvvvvvvvvvvvvvvvvv X";
    printf("%s  %s   %d\n%s", src, str, 3, (char *)s21_insert(src, str, 3));
    
    // upp low
    // char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 01234567890 *-+/=";
    // printf("%s   %ld\n", (char*)s21_to_upper(str), strlen(str));
    // printf("%s   %ld\n", (char*)s21_to_lower(str), strlen(str));

    // char *str = NULL;
    // printf("%s\n", str);
    // printf("= %s\n", (char*)s21_to_upper(str));   // for NULL
    // printf("= %s\n", (char*)s21_to_lower(str));   // for NULL
    
    return 0;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    s21_size_t i = 0;
    s21_size_t src_ind = 0;
    if(str == NULL || src == NULL) return NULL;
    s21_size_t src_len = strlen(src);
    s21_size_t str_len = strlen(str);
    if(src_len < start_index ) return NULL;

    printf("w %lu\n", start_index);
    
    char *src_new = (char *)malloc(sizeof(char) * (src_len + str_len + 1));
    if(src_new == NULL) return NULL;
    while(i < start_index){
        src_new[i] = src[i];
        i++;
        src_ind++;
    };
    while(*str != '\0'){
        src_new[i] = *str;
        str++;
        i++;
    };
    // printf("c2 %c\n", *src); 
    while(src[src_ind] != '\0'){
        // printf("c3 %c\n", src[src_ind]); 
        src_new[i] = src[src_ind];
        //src++;
        i++;
        src_ind++;
    };
    src_new[i] = '\0';
    // printf("**%s  %ld\n", src_new, sizeof(char) * (src_len + str_len + 1));
    
    return (void *)src_new;
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