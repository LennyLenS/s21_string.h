
// Удалить string.h
#include <string.h>
#include <stdio.h>

#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t size =0;
    const char *p = str;
    while(*p != '\0') {
        size++;
        p++;
    };
    return size;
}

void *s21_memcpy(void *dest, const void *src, size_t n){
    size_t i = 0;
    while(i < n) {
        *(char *)(dest + i) = *(char*)(src + i);
        i++;
    }
    return dest;
}

char *s21_strcat(char *dest, const char *src){
    int p = (int)s21_strlen(dest);
    int i = 0;
    while(*src != '\0') {
        *(dest + p +i) = *src;
        i++;
        src++;
    };
    return dest;
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

char *s21_strstr(const char *haystack, const char *needle) {
    if(*needle == '\0') return (char*)haystack;
    int i = 0;
    while(haystack[i] != '\0'){
        int j = 0;
        int k = i;
        while(needle[j] != '\0' || haystack[k] != '\0'){
            if(needle[j] != haystack[k]) break;
            k++;
            j++;
        }
        if(needle[j] == '\0') return (char*)haystack + i;
    i++;
    }
    return S21_NULL;
}

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

    if (str_new) {
        int i = 0;
        while(ind_bgn <= ind_end){
            *(str_new + i) = src[ind_bgn];
            ind_bgn++;
            i++;
        };
        if(src_len != 0) *(str_new + i) = '\0';
    };
    return (void *)str_new;
}