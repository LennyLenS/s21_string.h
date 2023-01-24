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