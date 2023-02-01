#define s21_size_t unsigned long
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

size_t s21_strlen(const char *str);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int main()
{
    // trim
    char *src = "  !!!abcdefghij!?! ";
    char *trim_chars = "";
    printf("aa /%s/   %ld\n", (char*)s21_trim(src, trim_chars), s21_strlen(src));

    // insert
    // char *src = "abcdef";
    // char *str = "X vvvvvvvvvvvvvvvvvvvvvvv X";
    // printf("%s  %s   %d\n%s", src, str, 3, (char *)s21_insert(src, str, 3));
    
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


// Доделать NULL в trim_chars


void *s21_trim(const char *src, const char *trim_chars){
    if(src == NULL) return NULL;
    char trim_chars_tmp[512];
    if(trim_chars != NULL && s21_strlen(trim_chars) != 0) {
        strcpy(trim_chars_tmp, trim_chars);
    } else {
        strcpy(trim_chars_tmp, "\t\n\v\r\f ");
    };
    printf("qq %s\n", trim_chars_tmp);
    s21_size_t src_len = s21_strlen(src);
    char *str_new = (char *)malloc(sizeof(char) * (src_len +1));
    s21_size_t ind_bgn = s21_strspn(src, trim_chars_tmp);
    s21_size_t ind_end = src_len;  // to stand pointer on \0
    
    printf("ind %ld  %ld\n", ind_bgn, ind_end);

    char *src_tmp = (char *)src + ind_end;
    char *src_end = src_tmp;

    while(src_tmp == src_end) {
        src_tmp--;
        //src_end = src_tmp;
        src_end = strpbrk (src_tmp, trim_chars_tmp);
        if(src_end == NULL) src_end = src_tmp + 1;
        if(src_tmp != src_end) break;
    };

    // int ii = 0;
    // while(ii < 33){
    //     printf("%d  %c\n", ii, src[ii]);
    //     ii++;
    // };
    printf("ind2 %ld  %ld\n", ind_bgn, ind_end);

    if(ind_end != ind_bgn) ind_end = src_tmp - src;
    
    printf("ind3 %ld  %ld\n", ind_bgn, ind_end);
    int i = 0;
    while(ind_bgn <= ind_end){
        // printf("ee %c", src[ind_bgn]);
        *(str_new + i) = src[ind_bgn];
        ind_bgn++;
        i++;
    };
    *(str_new + i) = '\0';
    printf("ind4 %ld  %ld\n", ind_bgn, ind_end);
    //printf("\n");
    
    //printf("end #%s   @%s  %ld\n", src_tmp, src_end, src_tmp - src);
    //printf("ib %ld   %c\n", ind_bgn, src[ind_end]);

    return (void *)str_new;
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
    s21_size_t size = 0;
    const char *p = str;
    while(*p != '\0') {
        size++;
        p++;
    };
    return size;
}

size_t s21_strspn(const char *str1, const char *str2){
    size_t count = 0;
    int flag = 0;
    while(*str1 != '\0' && flag == 0) {
        const char *str_tmp = str2;
        while(*str_tmp != '\0'){
            if(*str1 == *str_tmp){
                count++;
                flag =0;
                break;
            } else {
                flag =1;
                str_tmp++;
            }
        }
        str1++;
        if(flag == 1) break;
    }
    return count;
}