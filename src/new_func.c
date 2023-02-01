
// Удалить string.h
#include <string.h>
#include <stdio.h>

#include "s21_string.h"

void *s21_to_upper(const char *str){
    if(str == S21_NULL) return S21_NULL;
    s21_size_t n = s21_strlen(str);
    char *str_copy = (char *)malloc((n+1) * sizeof(char));
    if(str_copy == S21_NULL) return S21_NULL;
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
    if(str_copy == S21_NULL) return S21_NULL;
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

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    s21_size_t i = 0;
    s21_size_t src_ind = 0;
    if(str == S21_NULL || src == S21_NULL) return S21_NULL;
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    if(src_len < start_index ) return S21_NULL;

    char *src_new = (char *)malloc(sizeof(char) * (src_len + str_len + 1));
    if(src_new == S21_NULL) return S21_NULL;
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
    while(src[src_ind] != '\0'){
        src_new[i] = src[src_ind];
        i++;
        src_ind++;
    };
    src_new[i] = '\0';    
    return (void *)src_new;
}

// Заменить в trim стандартные ф-ции на наши

void *s21_trim(const char *src, const char *trim_chars){
    if(src == S21_NULL) return S21_NULL;
    char trim_chars_tmp[512];
    if(trim_chars != NULL && s21_strlen(trim_chars) != 0) {
        strcpy(trim_chars_tmp, trim_chars);
    } else {
        strcpy(trim_chars_tmp, "\t\n\v\r\f ");
    };
    s21_size_t src_len = s21_strlen(src);
    char *str_new = (char *)malloc(sizeof(char) * (src_len +1));
    s21_size_t ind_bgn = s21_strspn(src, trim_chars_tmp);
    s21_size_t ind_end = src_len;  // to stand pointer on \0

    char *src_tmp = (char *)src + ind_end;
    char *src_end = src_tmp;

    while(src_tmp == src_end) {
        src_tmp--;
        src_end = strpbrk (src_tmp, trim_chars_tmp);
        if(src_end == NULL) src_end = src_tmp + 1;
        if(src_tmp != src_end) break;
    };

    if(ind_end != ind_bgn) ind_end = src_tmp - src;
    
    int i = 0;
    while(ind_bgn <= ind_end){
        *(str_new + i) = src[ind_bgn];
        ind_bgn++;
        i++;
    };
    *(str_new + i) = '\0';

    return (void *)str_new;
}