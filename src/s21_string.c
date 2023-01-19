#include "s21_string.h"

void *memchr(const void *str, int c, size_t n){
    void *ans = NULL;
    if(str != NULL && c > 0){
        void *p = str;
        for(int i = 0 ; i < min(n, strlen(str)); ++i){
            if(*p == c){
                ans = p;
            }
            p++;
        }
    }

    return p;
}

int memcmp(const void *str1, const void *str2, size_t n){
    int res = 0;
    if(str1 == NULL || str2 == NULL){
        res = 0;
    }else{
        int len1 = strlen(str1), len2 = strlen(str2), flag = 0;
        for(int i = 0; i < min(len1, min(n, len2)); ++i){
            if(flag == 0 && str1[i] != str2[i]){
                res = str1[i] - str2[i];
                flag = 1;
            }
        }
        if(flag == 0){
            res = len1 - len2;
        }
    }

    return res;
}

void *memmove(void *dest, const void *src, size_t n){
    if(dest != NULL && src != NULL){
        for(int i = 0; i < min(n, strlen(src)); ++i){
            dest[i] = src[i];
        }
    }

    return dest;
}

void *memset(void *str, int c, size_t n){
    if(str != NULL && c > 0){
        for(int i = 0; i < min(strlen(str), n); ++i){
            str[i] = (char)c;
        }
    }
    return str;
}

s21_size_t strlen(const char *str){
    s21_size_t size = 0;
    if(str != NULL) {
        const char *p = str;
        while(*p != '\0') {
            size++;
            p++;
        }
    }
    return size;

}